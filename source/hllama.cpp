/*
 *
 * Llama.prg - Harbour wrappers for llama.cpp,
 * which allows chatting with local AI models
 *
 * This work is based on llama.cpp project
 * https://github.com/ggerganov/llama.cpp
 *
 * Copyright 2024 Alexander S.Kresin <alex@kresin.ru>
 * www - http://www.kresin.ru
*/

#include "common.h"
#include "llama.h"

#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

#if defined(__linux__) || defined(__unix__)
   #include <unistd.h>
#else
   #include <io.h>
#endif

#include "hbapi.h"
#include "hbapifs.h"
#include "hbapiitm.h"
#include "hbvm.h"
#include "item.api"

typedef struct
{
   llama_model * model;
   llama_context * ctx;
   int n_len;
   int n_cur;

} HB_LLAMAS, * PHB_LLAMAS;

static gpt_params params;
static llama_batch batch;
static short int bBatchActive = 0;

void llm_writelog( const char * sFile, const char * sTraceMsg, ... )
{
   FILE *hFile;

   if( sFile == NULL )
   {
      hFile = hb_fopen( "ac.log", "a" );
   }
   else
   {
      hFile = hb_fopen( sFile, "a" );
   }

   if( hFile )
   {
      va_list ap;

      va_start( ap, sTraceMsg );
      vfprintf( hFile, sTraceMsg, ap );
      va_end( ap );

      fclose( hFile );
   }

}

HB_FUNC( LLM_OPEN_MODEL )
{
   PHB_LLAMAS pLLM = (PHB_LLAMAS) hb_xgrab( sizeof( HB_LLAMAS ) );

   memset( pLLM, 0, sizeof(HB_LLAMAS) );

   params.model = hb_parc( 1 );
   params.prompt = ""; //hb_parc( 2 );

   // init LLM

   llama_backend_init();
   llama_numa_init(params.numa);

   // initialize the model

   //llama_model_params model_params = llama_model_default_params();

   // model_params.n_gpu_layers = 99; // offload all layers to the GPU

   //pLLM->model = llama_load_model_from_file(params.model.c_str(), model_params);
   pLLM->model = llama_load_model_from_file( params.model.c_str(),
      llama_model_params_from_gpt_params( params) );


   if( pLLM->model == NULL ) {
       fprintf(stderr , "%s: error: unable to load model\n" , __func__);
       hb_xfree( pLLM );
       return;
   }

   //pLLM->n_threads = params.n_threads;
   //pLLM->n_threads_batch = params.n_threads_batch;
   pLLM->n_len = 256;

   hb_retptr( ( void * ) pLLM );
}

HB_FUNC( LLM_CREATE_CONTEXT )
{
   PHB_LLAMAS pLLM = (PHB_LLAMAS) hb_parptr( 1 );

   // initialize the context
   llama_context_params ctx_params = llama_context_params_from_gpt_params( params ); // llama_context_default_params();

   ctx_params.seed  = 1234;
   ctx_params.n_ctx = 2048;

   ctx_params.n_threads = params.n_threads;
   ctx_params.n_threads_batch = params.n_threads_batch == -1 ? params.n_threads : params.n_threads_batch;
   //ctx_params.n_threads = pLLM->n_threads;
   //ctx_params.n_threads_batch = pLLM->n_threads_batch == -1 ? pLLM->n_threads : pLLM->n_threads_batch;

   pLLM->ctx = llama_new_context_with_model( pLLM->model, ctx_params );

   if( pLLM->ctx == NULL ) {
       hb_retni( -1 );
   } else
      hb_retni( 0 );

}

HB_FUNC( LLM_ASK )
{
   PHB_LLAMAS pLLM = (PHB_LLAMAS) hb_parptr( 1 );

   llama_context * ctx = pLLM->ctx;

   // tokenize the prompt

   std::vector<llama_token> tokens_list;
   tokens_list = ::llama_tokenize( ctx, hb_parc( 2 ), true );

   const int n_ctx    = llama_n_ctx(ctx);
   const int n_kv_req = (int) ( tokens_list.size() + (pLLM->n_len - tokens_list.size()) );

   // make sure the KV cache is big enough to hold all the prompt and generated tokens
   if (n_kv_req > n_ctx) {
       //LOG_TEE("%s: error: n_kv_req > n_ctx, the required KV cache size is not big enough\n", __func__);
       //LOG_TEE("%s:        either reduce n_len or increase n_ctx\n", __func__);
       hb_retni( 1 );
       return;
   }

   // print the prompt token-by-token
   //fprintf(stderr, "\n");
   for (auto id : tokens_list) {
       //fprintf(stderr, "%s", llama_token_to_piece(ctx, id).c_str());
       llama_token_to_piece(ctx, id).c_str();
   }
   //fflush(stderr);

   // create a llama_batch with size 512
   // we use this object to submit token data for decoding
   if( bBatchActive )
      llama_batch_free( batch );
   batch = llama_batch_init( 512, 0, 1 );
   bBatchActive = 1;

   // evaluate the initial prompt
   for( size_t i = 0; i < tokens_list.size(); i++ ) {
       llama_batch_add( batch, tokens_list[i], i, { 0 }, false );
   }

   // llama_decode will output logits only for the last token of the prompt
   batch.logits[batch.n_tokens - 1] = true;

   if (llama_decode(ctx, batch) != 0) {
       LOG_TEE("%s: llama_decode() failed\n", __func__);
       hb_retni( 2 );
       return;
   }

   pLLM->n_cur = batch.n_tokens;

   hb_retni( 0 );
}

HB_FUNC( LLM_GETNEXTTOKEN )
{

   PHB_LLAMAS pLLM = (PHB_LLAMAS) hb_parptr( 1 );

   llama_model * model = pLLM->model;
   llama_context * ctx = pLLM->ctx;

   if( pLLM->n_cur <= pLLM->n_len ) {
       // sample the next token
       auto   n_vocab = llama_n_vocab(model);
       auto * logits  = llama_get_logits_ith(ctx, batch.n_tokens - 1);
       std::vector<llama_token_data> candidates;
       candidates.reserve(n_vocab);

       for (llama_token token_id = 0; token_id < n_vocab; token_id++) {
           candidates.emplace_back(llama_token_data{ token_id, logits[token_id], 0.0f });
       }

       llama_token_data_array candidates_p = { candidates.data(), candidates.size(), false };
       // sample the most likely token
       const llama_token new_token_id = llama_sample_token_greedy(ctx, &candidates_p);

       // is it an end of stream?
       if (new_token_id == llama_token_eos(model) || pLLM->n_cur == pLLM->n_len) {
           hb_ret();
       } else {
          hb_retc( llama_token_to_piece(ctx, new_token_id).c_str() );

          // prepare the next batch
          llama_batch_clear(batch);

          // push this new token for next evaluation
          llama_batch_add(batch, new_token_id, pLLM->n_cur, { 0 }, true);

          pLLM->n_cur += 1;

          // evaluate the current batch with the transformer model
          if (llama_decode(ctx, batch)) {
             pLLM->n_cur = pLLM->n_len;
          }
       }
   }

}

HB_FUNC( LLM_CLOSE_CONTEXT )
{
   PHB_LLAMAS pLLM = (PHB_LLAMAS) hb_parptr( 1 );

   if( bBatchActive )
      llama_batch_free( batch );
   bBatchActive = 0;

   if( pLLM->ctx )
      llama_free( pLLM->ctx );
   pLLM->ctx = NULL;

   hb_retni( 0 );
}

HB_FUNC( LLM_CLOSE_MODEL )
{
   PHB_LLAMAS pLLM = (PHB_LLAMAS) hb_parptr( 1 );

   if( pLLM->model )
      llama_free_model( pLLM->model );
   pLLM->model = NULL;

   llama_backend_free();
   hb_xfree( pLLM );

}

HB_FUNC( LLM_REDIRON )
{
   int istd = ( HB_ISNIL( 1 ) ) ? 1 : hb_parni( 1 );
   int fd;

   fflush( ( istd == 1 ) ? stdout : stderr );
   fd = dup( fileno( ( istd == 1 ) ? stdout : stderr ) );
   freopen( hb_parc( 2 ), "w", ( istd == 1 ) ? stdout : stderr );
   hb_retni( fd );
}

HB_FUNC( LLM_REDIROFF )
{
#if !defined(_MSC_VER)
   int istd = ( HB_ISNIL( 1 ) ) ? 1 : hb_parni( 1 );
   int fd;

   fflush( ( istd == 1 ) ? stdout : stderr );

   if( HB_ISNIL( 2 ) )
   {
      fclose( ( istd == 1 ) ? stdout : stderr );
   }
   else
   {
      fd = hb_parni( 2 );
      dup2( fd, fileno( ( istd == 1 ) ? stdout : stderr ) );
      close( fd );
      clearerr( ( istd == 1 ) ? stdout : stderr );
   }
#endif
}

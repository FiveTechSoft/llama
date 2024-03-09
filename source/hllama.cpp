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

static llama_model * model;
static llama_context * ctx;
static gpt_params params;
static llama_batch batch;
static short int bBatchActive = 0;
static int n_len;
static int n_cur;

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

HB_FUNC( LLM_SET_PARAMS )
{
   char * cParams = (char*) hb_parc( 1 ), * ptr, * ptr2, *ptr3;
   short int bEnd = 0;
   char s1[24], s2[256];
   llama_sampling_params & sparams = params.sparams;

   ptr = ptr2 = cParams;
   while( *ptr && !bEnd ) {
      while( *(++ptr2) != '\0' && *ptr2 != '=' );
      if( !(*ptr2) )
         return;
      memcpy( s1, ptr, ptr2-ptr );
      s1[ptr2-ptr] = '\0';
      ptr2 ++;
      ptr3 = ptr2;
      while( *(++ptr3) != '\0' && *ptr3 != '\1' );
      if( !(*ptr3) )
         bEnd = 1;
      memcpy( s2, ptr2, ptr3-ptr2 );
      s2[ptr3-ptr2] = '\0';
      if( !strcmp( s1, "p" ) ) {
         params.prompt = s2;

      } else if( !strcmp( s1, "c" ) ) {

         params.n_ctx = std::stoi( ptr2 );
         //llm_writelog( NULL, "p %d\n", params.n_ctx );

      } else if( !strcmp( s1, "n" ) ) {
         params.n_predict = std::stoi( s2 );

      } else if( !strcmp( s1, "n-keep" ) ) {
         params.n_keep = std::stoi( s2 );

      } else if( !strcmp( s1, "temp" ) ) {
         sparams.temp = std::stof( s2 );
         sparams.temp = std::max(sparams.temp, 0.0f);

      } else if( !strcmp( s1, "repeat-penalty" ) ) {
         sparams.penalty_repeat = std::stof( s2 );

      } else if( !strcmp( s1, "top-k" ) ) {
         sparams.top_k = std::stoi( s2 );

      } else if( !strcmp( s1, "top-p" ) ) {
         sparams.top_p = std::stof( s2 );

      } else if( !strcmp( s1, "r" ) ) {
         params.antiprompt.emplace_back( s2 );

      }
      ptr = ptr2 = ptr3 + 1;
   }

}

HB_FUNC( LLM_OPEN_MODEL )
{

   params.model = hb_parc( 1 );
   params.prompt = "";

   // init LLM
   llama_backend_init();
   llama_numa_init(params.numa);

   // initialize the model
   model = llama_load_model_from_file( params.model.c_str(),
      llama_model_params_from_gpt_params( params) );

   if( model == NULL ) {
      hb_retni( 1 );
      return;
   }

   n_len = 256;
   hb_retni( 0 );
}

HB_FUNC( LLM_CREATE_CONTEXT )
{

   // initialize the context
   llama_context_params ctx_params = llama_context_params_from_gpt_params( params ); // llama_context_default_params();

   ctx_params.seed  = 1234;
   //ctx_params.n_ctx = 2048;

   ctx_params.n_threads = params.n_threads;
   ctx_params.n_threads_batch = params.n_threads_batch == -1 ? params.n_threads : params.n_threads_batch;

   ctx = llama_new_context_with_model( model, ctx_params );

   if( ctx == NULL ) {
       hb_retni( -1 );
   } else
      hb_retni( 0 );

}

HB_FUNC( LLM_ASK )
{

   // tokenize the prompt

   std::vector<llama_token> tokens_list;
   tokens_list = ::llama_tokenize( ctx, hb_parc( 1 ), true );

   const int n_ctx    = llama_n_ctx(ctx);
   const int n_kv_req = (int) ( tokens_list.size() + (n_len - tokens_list.size()) );

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

   n_cur = batch.n_tokens;

   hb_retni( 0 );
}

HB_FUNC( LLM_GETNEXTTOKEN )
{

   if( n_cur <= n_len ) {
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
       if (new_token_id == llama_token_eos(model) || n_cur == n_len) {
           hb_ret();
       } else {
          hb_retc( llama_token_to_piece(ctx, new_token_id).c_str() );

          // prepare the next batch
          llama_batch_clear(batch);

          // push this new token for next evaluation
          llama_batch_add(batch, new_token_id, n_cur, { 0 }, true);

          n_cur += 1;

          // evaluate the current batch with the transformer model
          if (llama_decode(ctx, batch)) {
             n_cur = n_len;
          }
       }
   }

}

HB_FUNC( LLM_CLOSE_CONTEXT )
{

   if( bBatchActive )
      llama_batch_free( batch );
   bBatchActive = 0;

   if( ctx )
      llama_free( ctx );
   ctx = NULL;

   hb_retni( 0 );
}

HB_FUNC( LLM_CLOSE_MODEL )
{

   if( model )
      llama_free_model( model );
   model = NULL;

   llama_backend_free();

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

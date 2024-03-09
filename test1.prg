
#include "inkey.ch"

STATIC aModels := {}
STATIC aHis := {}, nHisCurr := 0

Function Main()

   LOCAL pLLM
   LOCAL i, nKey
   LOCAL cQue, cAns, cAnswer
   LOCAL n2

   IniRead( "models.ini" )
   IF Empty( aModels )
      ? "No models in models.ini"
   ENDIF
   FOR i := 1 TO Len( aModels )
      ? Str(i,1) + " " + hb_fnameName( aModels[i] )
   NEXT
   ? "Select model: "

   nKey := Inkey(0)
   ? Chr( nKey )

   IF ( i := nKey - 48 ) <= 0 .OR. i > Len( aModels )
      ? "Wrong choic"
   ENDIF

   ? aModels[i] + "   Loading..."

   n2 := llm_rediron( 2, "stderr.log" )

   IF Empty( pLLM := llm_Open_Model( aModels[i] ) )
      ? " === Can't open " + aModels[i] + " ==="
      RETURN Nil
   ENDIF

   ?
   DO WHILE .T.

      ? "Your question:"
      cQue := GetLine()
      IF Empty( cQue )
         EXIT
      ENDIF

      IF Lower(cQue) == "s"
         IF !Empty( cAnswer )
            Writelog( "> " + ATail( aHis ), "test1.log" )
            Writelog( cAnswer, "test1.log" )
            cAnswer := ""
         ENDIF
         LOOP
      ENDIF

      ?
      IF llm_Create_Context( pLLM ) < 0
         ? "Can't create context"
         EXIT
      ENDIF
      llm_Ask( pLLM, cQue )
      cAnswer := ""
      DO WHILE ( cAns := llm_GetNextToken( pLLM ) ) != Nil
         //writelog( cAns )
         cAnswer += cAns
         ?? cAns
         IF Inkey() == 27
            EXIT
         ENDIF
      ENDDO
      llm_Close_Context( pLLM )
   ENDDO

   llm_Close_Model( pLLM )

   llm_rediroff( 2, n2 )

   ? "Bye"

   RETURN Nil

STATIC FUNCTION IniRead( cFileName )

   LOCAL cText := Memoread( cFileName ), aText, i, s, nPos, s1, s2

   IF Empty( cText )
      RETURN Nil
   ENDIF

   aText := hb_aTokens( cText, Chr(10) )

   FOR i := 1 TO Len( aText )
      s := Iif( Left( aText[i],1 ) == ' ', Ltrim( aText[i] ), aText[i] )
      IF Left( s, 1 ) $ ";#"
         LOOP
      ENDIF
      s := Trim( Iif( Right(s,1)==Chr(13), Left( s,Len(s)-1 ), s ) )
      IF Empty( s )
         LOOP
      ENDIF
      IF ( nPos := At( '=', s ) ) > 0
         s1 := Trim( Left(s,nPos-1) )
         s2 := Ltrim( Substr( s,nPos+1 ) )
         IF Left( s1, 5 ) == "model"
            AAdd( aModels, s2 )
         ENDIF
      ENDIF
   NEXT

   RETURN Nil

STATIC FUNCTION GetLine()

   LOCAL nKey, s := "", i, nStartCol := Col()

   DO WHILE ( nKey := Inkey( 0 ) ) != 0 .AND. nKey != K_ENTER .AND. nKey != K_ESC

      IF nKey == K_BS
         IF Len( s ) > 0
            s := hb_strShrink( s, 1 )
            DevPos( Row(), Col()-1 )
            ?? " "
            DevPos( Row(), Col()-1 )
         ENDIF
      ELSEIF nKey == K_UP
         IF nHisCurr > 1
            nHisCurr --
            DevPos( Row(), nStartCol )
            IF !Empty( s )
               ?? Space( Len(s) )
               DevPos( Row(), nStartCol )
            ENDIF
            s := aHis[nHisCurr]
            ?? s
         ENDIF
      ELSEIF nKey == K_DOWN
         IF nHisCurr < Len( aHis )
            nHisCurr ++
            DevPos( Row(), nStartCol )
            IF !Empty( s )
               ?? Space( Len(s) )
               DevPos( Row(), nStartCol )
            ENDIF
            s := aHis[nHisCurr]
            ?? s
         ENDIF
      ELSE
         ?? Chr(nKey)
         s += Chr(nKey)
      ENDIF
   ENDDO

   IF nKey == K_ENTER
      IF ( i := hb_Ascan( aHis, s,,, .T. ) ) == 0
         AAdd( aHis, s )
      ELSE
         ADel( aHis, i )
         aHis[ Len(aHis) ] := s
      ENDIF
      nHisCurr := Len( aHis ) + 1
      RETURN s
   ENDIF

   RETURN ""

STATIC FUNCTION WriteLog( cText, fname )

   LOCAL nHand

   fname := IIf( fname == Nil, "a.log", fname )
   IF ! File( fname )
      nHand := FCreate( fname )
   ELSE
      nHand := FOpen( fname, 1 )
   ENDIF
   FSeek( nHand, 0, 2 )
   FWrite( nHand, cText + Chr( 10 ) )
   FClose( nHand )

   RETURN nil

@setlocal
call "%ProgramFiles%\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64
set HB_USER_CFLAGS=-TP /Gm- /GS /arch:AVX2 /fp:precise /Zc:inline /Zc:forScope
set HB_USER_LDFLAGS=/INCREMENTAL:NO /NOLOGO /SUBSYSTEM:CONSOLE /TLBID:1 /MANIFEST /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /manifest:embed /DYNAMICBASE /NXCOMPAT
c:\harbour\bin\win\msvc64\hbmk2.exe test1.prg -lllama64
@endlocal
@setlocal
call "%ProgramFiles%\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64
rem set HB_USER_CFLAGS=-TP
c:\harbour\bin\win\msvc64\hbmk2.exe test1.prg -lllama64
@endlocal
# llama.prg
Harbour bindings for llama.cpp (https://github.com/ggerganov/llama.cpp)

## Table of Contents

1. [Quick review](#quick-review)
1. [Compiling library](#compiling-library)

## Quick review

The main goal of llama.prg project is to provide possibility to interact with local LLaMA language models from a Harbour application, GUI or console.
The project provides a llama library, which may be linked to your application.
Under Windows it demands 64-bit MSVC compiler, under Linux/Unix - the standard 64-bit GNU C.

## Compiling library

A preferred method to build the llama library and samples is HwBuilder - my utility, which builds programs, written on Harbour (http://www.kresin.ru/en/hwbuilder.html). An appropriate project file, llamalib.hwprj, is provided.
If you prefer to not use special utilities, you can build this library with following bat file:

### Windows

```powershell
if not exist lib md lib
if not exist obj md obj
if not exist obj\msvc64 md obj\msvc64

set PATH=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\\Extensions\Microsoft\IntelliCode\CLI;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\bin\HostX64\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\VC\VCPackages;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\TeamFoundation\Team Explorer;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\bin\Roslyn;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\devinit;C:\Windows Kits\10\bin\10.0.19041.0\x64;C:\Windows Kits\10\bin\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\\MSBuild\Current\Bin;C:\Windows\Microsoft.NET\Framework64\v4.0.30319;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\;C:\Program Files (x86)\Common Files\Oracle\Java\javapath;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;c:\softools\git\usr\bin;c:\tools;c:\tools\arh;c:\harbour\bin;d:\softools\mingw_w64\mingw32\bin;c:\borland\bcc55\bin;c:\softools\git\cmd;c:\softools\subversion\bin;C:\Program Files\OpenVPN\bin;C:\softools\Go\bin;C:\softools\Python\Scripts\;C:\softools\Python\;C:\Users\SYSADMIN\AppData\Local\Microsoft\WindowsApps;c:\softools\go\bin;d:\svn;c:\Program Files\Java\jdk1.8.0_231\bin;C:\Users\SYSADMIN\go\bin;c:\softools\cmake\bin;;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\Ninja
set INCLUDE=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\ATLMFC\include;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\include;C:\Windows Kits\10\include\10.0.19041.0\ucrt;C:\Windows Kits\10\include\10.0.19041.0\shared;C:\Windows Kits\10\include\10.0.19041.0\um;C:\Windows Kits\10\include\10.0.19041.0\winrt;C:\Windows Kits\10\include\10.0.19041.0\cppwinrt
set LIB=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\ATLMFC\lib\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\lib\x64;C:\Windows Kits\10\lib\10.0.19041.0\ucrt\x64;C:\Windows Kits\10\lib\10.0.19041.0\um\x64
set LIBPATH=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\ATLMFC\lib\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\lib\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\lib\x86\store\references;C:\Windows Kits\10\UnionMetadata\10.0.19041.0;C:\Windows Kits\10\References\10.0.19041.0;C:\Windows\Microsoft.NET\Framework64\v4.0.30319

set CFLAGS=/TP /W3 /nologo /c /TP /W3 /nologo /EHsc /c -Illama.cpp\common -Illama.cpp -DLOG_DISABLE_LOGS=1 /W3 /WX- /diagnostics:column /O2 /Ob2 /D _MBCS /D WIN32 /D _WINDOWS /D NDEBUG /D _CRT_SECURE_NO_WARNINGS /Gm- /MD /GS /arch:AVX2 /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /std:c11 /external:W3 /Gd /TC /errorReport:queue
set CXXFLAGS=/TP /W3 /nologo /c /TP /W3 /nologo /EHsc /c -Illama.cpp\common -Illama.cpp -DLOG_DISABLE_LOGS=1
set HB_PATH=c:\harbour

cl.exe  %CXXFLAGS% /I%HB_PATH%\include /Foobj\msvc64\hllama.obj source\hllama.cpp
cl.exe  %CXXFLAGS% /Foobj\msvc64\llama.obj llama.cpp\llama.cpp

cl.exe %CFLAGS% /Foobj\msvc64\ggml.obj llama.cpp\ggml.c
cl.exe %CFLAGS% /Foobj\msvc64\ggml-alloc.obj llama.cpp\ggml-alloc.c
cl.exe %CFLAGS% /Foobj\msvc64\ggml-backend.obj llama.cpp\ggml-backend.c
cl.exe %CFLAGS% /Foobj\msvc64\ggml-quants.obj llama.cpp\ggml-quants.c

cl.exe %CXXFLAGS% /Foobj\msvc64\common.obj llama.cpp\common\common.cpp
cl.exe %CXXFLAGS% /Foobj\msvc64\sampling.obj llama.cpp\common\sampling.cpp
cl.exe %CXXFLAGS% /Foobj\msvc64\grammar-parser.obj llama.cpp\common\grammar-parser.cpp
cl.exe %CXXFLAGS% /Foobj\msvc64\build-info.obj llama.cpp\common\build-info.cpp

lib  /out:lib\llama.lib  obj\msvc64\hllama.obj obj\msvc64\llama.obj obj\msvc64\ggml.obj obj\msvc64\ggml-alloc.obj obj\msvc64\ggml-backend.obj obj\msvc64\ggml-quants.obj obj\msvc64\common.obj obj\msvc64\sampling.obj obj\msvc64\grammar-parser.obj obj\msvc64\build-info.obj
```
Of course, you need to use your paths.

### Linux
```bash
```

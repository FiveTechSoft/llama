# llama.prg
Harbour bindings for [llama.cpp](https://github.com/ggerganov/llama.cpp)

1. [Quick review](#quick-review)
2. [Compiling library](#compiling-library)
3. [Compiling samples](#compiling-samples)

## Quick review

The main goal of llama.prg project is to provide possibility to interact with local LLaMA language models from a Harbour application, GUI or console.
The project provides a llama library, which may be linked to your application.
Under Windows it demands 64-bit MSVC compiler, under Linux/Unix - the standard 64-bit GNU C.

## Compiling library

A preferred method to build the llama library and samples is [HwBuilder](http://www.kresin.ru/en/hwbuilder.html) - my utility, which builds programs, written on Harbour. An appropriate project file, llamalib.hwprj, is provided.
Llamalib.hwprj and other hwprj files supposes, that there is a section for 64-bit MSVC compiler in your copy of hwbuild.ini, you need to tune it:
```
[C_COMPILER_6]
id=msvc64
family=msvc
...
```

If you prefer to not use special utilities, you can build this library with following bat file:

#### Windows

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

#### Linux
```bash
#!/bin/bash
# Set your Harbour path here
export HRB_DIR=/home/guest/apps/harbour
export CFLAGS="-c -Wall -std=c++11 -fPIC -O3 -Wall -Wextra -Wpedantic -Wcast-qual -Wno-unused-function -Wmissing-declarations -Wmissing-noreturn -pthread  -march=native -mtune=native -Wno-array-bounds -Wno-format-truncation -Illama.cpp -Illama.cpp/common -D_XOPEN_SOURCE=600 -D_GNU_SOURCE -DNDEBUG -DLOG_DISABLE_LOGS=1 -c -I$HRB_DIR/include"
export CXXFLAGS="-c -Wall -std=c++11 -fPIC -O3 -Wall -Wextra -Wpedantic -Wcast-qual -Wno-unused-function -Wmissing-declarations -Wmissing-noreturn -pthread  -march=native -mtune=native -Wno-array-bounds -Wno-format-truncation -Illama.cpp -Illama.cpp/common -D_XOPEN_SOURCE=600 -D_GNU_SOURCE -DNDEBUG -DLOG_DISABLE_LOGS=1 -c -xc++ -I$HRB_DIR/include"

gcc $CXXFLAGS -oobj/gcc/hllama.o source/hllama.cpp
gcc $CXXFLAGS -oobj/gcc/llama.o llama.cpp/llama.cpp
gcc $CFLAGS -oobj/gcc/ggml.o llama.cpp/ggml.c
gcc $CFLAGS -oobj/gcc/ggml-alloc.o llama.cpp/ggml-alloc.c
gcc $CFLAGS -oobj/gcc/ggml-backend.o llama.cpp/ggml-backend.c
gcc $CFLAGS -oobj/gcc/ggml-quants.o llama.cpp/ggml-quants.c
gcc $CXXFLAGS -oobj/gcc/common.o llama.cpp/common/common.cpp
gcc $CXXFLAGS -oobj/gcc/sampling.o llama.cpp/common/sampling.cpp
gcc $CXXFLAGS -oobj/gcc/grammar-parser.o llama.cpp/common/grammar-parser.cpp
gcc $CXXFLAGS -oobj/gcc/build-info.o llama.cpp/common/build-info.cpp

ar rc  lib/libllama.a  obj/gcc/hllama.o obj/gcc/llama.o obj/gcc/ggml.o obj/gcc/ggml-alloc.o obj/gcc/ggml-backend.o obj/gcc/ggml-quants.o obj/gcc/common.o obj/gcc/sampling.o obj/gcc/grammar-parser.o obj/gcc/build-info.o
```

## Compiling samples

It is better to use HwBuilder to build a sample application - test1.hwprj is provided, but you may use the following bat file:

#### Windows

```powershell
set PATH=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\\Extensions\Microsoft\IntelliCode\CLI;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\bin\HostX64\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\VC\VCPackages;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\TestWindow;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\TeamFoundation\Team Explorer;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\bin\Roslyn;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\devinit;C:\Windows Kits\10\bin\10.0.19041.0\x64;C:\Windows Kits\10\bin\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\\MSBuild\Current\Bin;C:\Windows\Microsoft.NET\Framework64\v4.0.30319;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\;C:\Program Files (x86)\Common Files\Oracle\Java\javapath;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;c:\softools\git\usr\bin;c:\tools;c:\tools\arh;c:\harbour\bin;d:\softools\mingw_w64\mingw32\bin;c:\borland\bcc55\bin;c:\softools\git\cmd;c:\softools\subversion\bin;C:\Program Files\OpenVPN\bin;C:\softools\Go\bin;C:\softools\Python\Scripts\;C:\softools\Python\;C:\Users\SYSADMIN\AppData\Local\Microsoft\WindowsApps;c:\softools\go\bin;d:\svn;c:\Program Files\Java\jdk1.8.0_231\bin;C:\Users\SYSADMIN\go\bin;c:\softools\cmake\bin;;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\Ninja
set INCLUDE=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\ATLMFC\include;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\include;C:\Windows Kits\10\include\10.0.19041.0\ucrt;C:\Windows Kits\10\include\10.0.19041.0\shared;C:\Windows Kits\10\include\10.0.19041.0\um;C:\Windows Kits\10\include\10.0.19041.0\winrt;C:\Windows Kits\10\include\10.0.19041.0\cppwinrt
set LIB=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\ATLMFC\lib\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\lib\x64;C:\Windows Kits\10\lib\10.0.19041.0\ucrt\x64;C:\Windows Kits\10\lib\10.0.19041.0\um\x64
set LIBPATH=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\ATLMFC\lib\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\lib\x64;C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\lib\x86\store\references;C:\Windows Kits\10\UnionMetadata\10.0.19041.0;C:\Windows Kits\10\References\10.0.19041.0;C:\Windows\Microsoft.NET\Framework64\v4.0.30319

set HB_PATH=c:\harbour

%HB_PATH%\bin\harbour -n -q -i%HB_PATH%\include test1.prg

cl.exe /TP /W3 /nologo /c /I%HB_PATH%\include /Fotest1.obj test1.c

link /NODEFAULTLIB:libucrt.lib /NODEFAULTLIB:msvcrt.lib /INCREMENTAL:NO /NOLOGO /SUBSYSTEM:CONSOLE /TLBID:1 /MANIFEST /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /manifest:embed /DYNAMICBASE /NXCOMPAT /MACHINE:X64  /machine:x64 /LIBPATH:d:\harbour_2023\lib\win\msvc64 /LIBPATH:d:\harbour_2023\hwgui\lib\vc /LIBPATH:lib  test1.obj gtwvt.lib hbvm.lib hbrtl.lib gtgui.lib gtwin.lib hbcpage.lib hblang.lib hbrdd.lib hbmacro.lib hbpp.lib rddntx.lib rddcdx.lib rddfpt.lib hbsix.lib hbcommon.lib hbct.lib hbcplr.lib hbpcre.lib hbzlib.lib llama.lib ucrt.lib user32.lib gdi32.lib comdlg32.lib shell32.lib comctl32.lib winspool.lib advapi32.lib winmm.lib ws2_32.lib iphlpapi.lib OleAut32.Lib Ole32.Lib
```

#### Linux
```bash
#!/bin/bash
# Set your Harbour path here
export HRB_DIR=/home/guest/apps/harbour

$HRB_DIR/bin/harbour -n -q -i$HRB_DIR/include test1.prg
gcc -c -Wall -I$HRB_DIR/include -otest1.o test1.c
gcc  test1.o -otest1 -L$HRB_DIR/lib/linux/gcc -Llib -Wl,--start-group -lgttrm -lhbvm -lhbrtl -lgtcgi -lgttrm -lhbcpage -lhblang -lhbrdd -lhbmacro -lhbpp -lrddntx -lrddcdx -lrddfpt -lhbsix -lhbcommon -lhbct -lhbcplr -lhbpcre -lhbzlib -lllama -lpthread -lm -lz -lpcre -ldl -Wl,--end-group -fPIC -O3 -Wall -lstdc++ -shared-libgcc
```

@setlocal
call "%ProgramFiles%\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64
cl -c -TP /Gm- /GS /arch:AVX2 /fp:precise /Zc:inline /Zc:forScope -Ic:\harbour\include -Illama.cpp -Illama.cpp\common /EHsc source\hllama.cpp
cl -c -TP /Gm- /GS /arch:AVX2 /fp:precise /Zc:inline /Zc:forScope -Illama.cpp -Illama.cpp\common /EHsc llama.cpp\llama.cpp
cl -c /Gm- /GS /arch:AVX2 /fp:precise /Zc:inline /Zc:forScope -Illama.cpp -Illama.cpp\common /EHsc llama.cpp\ggml.c llama.cpp\ggml-alloc.c llama.cpp\ggml-backend.c llama.cpp\ggml-quants.c llama.cpp\common\sampling.cpp llama.cpp\common\common.cpp llama.cpp\common\grammar-parser.cpp llama.cpp\common\build-info.cpp
lib /OUT:llama64.lib hllama.obj llama.obj ggml.obj ggml-alloc.obj ggml-backend.obj ggml-quants.obj sampling.obj common.obj grammar-parser.obj build-info.obj
@endlocal
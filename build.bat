@echo off

pushd bin

del /q *

set FilesToCompile=../src/main.c

set CommonCompilerFlags=/nologo /MD /EHsc /Od /Zi /W4 /wd4100 /wd4099 /wd4204 /wd4996 /wd4505 /we4702 /wd4201 /wd4200 /wd4133 /Fe"main" 
set Defines=/D_CRT_SECURE_NO_WARNINGS
set LinkLibraries=Kernel32.lib Ole32.lib


cl %CommonCompilerFlags% %Defines% %FilesToCompile% /link %AdditionalLibDirectories% %LinkLibraries%

popd

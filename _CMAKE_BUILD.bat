echo off

set SRCDIR=%~dp0
set BUILDDIR=%~dp0%2
cmake -S %SRCDIR% -B %BUILDDIR% -G %1

cmake --build %BUILDDIR% --config Debug
cmake --build %BUILDDIR% --config Release
cmake --install %BUILDDIR% --config Debug
cmake --install %BUILDDIR% --config Release
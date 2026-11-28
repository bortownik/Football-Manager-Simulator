@echo off
setlocal enabledelayedexpansion
set PATH=C:\msys64\ucrt64\bin;%PATH%
set SRC=
for %%f in (src\*.cpp) do set SRC=!SRC! %%f
g++ -std=c++17 -Wall -Wextra -pedantic %SRC% -o manager.exe
if errorlevel 1 goto :end
manager.exe
:end
@echo off
setlocal
set PATH=C:\msys64\ucrt64\bin;%PATH%
set SRC=src\main.cpp src\player.cpp src\field_player.cpp src\goalkeeper.cpp
g++ -std=c++17 -Wall -Wextra -pedantic %SRC% -o manager.exe
if errorlevel 1 goto :end
manager.exe
:end
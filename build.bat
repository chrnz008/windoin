@echo off

REM tell the linker to make the exe not to open a console window
REM see ld --help
REM https://stackoverflow.com/questions/224225/create-an-application-without-a-window
REM https://stackoverflow.com/questions/73676692/what-do-the-subsystem-windows-options-do-in-gcc

g++ wingaps.cpp -Wl,-subsystem,windows -o build\wingaps.exe

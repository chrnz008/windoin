@echo off

setlocal

set shell.startup=%APPDATA%\Microsoft\Windows\Start Menu\Programs\Startup
mklink "%shell.startup%\wingaps.exe" "%~dp0build\wingaps.exe" 

endlocal

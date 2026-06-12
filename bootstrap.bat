@echo off
setlocal EnableExtensions EnableDelayedExpansion

REM Main bootstrap script for MDE4CPP on Windows
set "DIR=%~dp0"

echo Detected OS: Windows
call "%DIR%bootstrap\Windows\bootstrap.bat" %*

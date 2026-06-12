@echo off
setlocal EnableExtensions EnableDelayedExpansion

REM ########################################
REM # Windows Bootstrap script for MDE4CPP #
REM ########################################

set "DIR=%~dp0"
call "%DIR%bootstrap\Windows\common.bat"

set "PROJECT_DIR=%~dp0"
REM Remove trailing slash for PROJECT_DIR
if "%PROJECT_DIR:~-1%"=="\" set "PROJECT_DIR=%PROJECT_DIR:~0,-1%"

for %%I in ("%PROJECT_DIR%\..") do set "PARENT_DIR=%%~fI"
set "ECLIPSE_DIR=%PARENT_DIR%\eclipse"
set "SETENV_FILE=%PROJECT_DIR%\setenv.bat"

call "%DIR%bootstrap\Windows\common.bat" print_header "bootstrap" "MDE4CPP Bootstrap Script for Windows"

call "%DIR%bootstrap\Windows\common.bat" print_header "bootstrap" "Installing system tools..."

call "%DIR%bootstrap\Windows\installJava.bat"
if errorlevel 1 (
    echo %C_ERROR%ERROR: installJava.bat failed ^(exit !errorlevel!^)%C_RESET%
    exit /b !errorlevel!
)

call "%DIR%bootstrap\Windows\installCompiler.bat"
if errorlevel 1 (
    echo %C_ERROR%ERROR: installCompiler.bat failed ^(exit !errorlevel!^)%C_RESET%
    exit /b !errorlevel!
)

call "%DIR%bootstrap\Windows\installCMake.bat"
if errorlevel 1 (
    echo %C_ERROR%ERROR: installCMake.bat failed ^(exit !errorlevel!^)%C_RESET%
    exit /b !errorlevel!
)

call "%DIR%bootstrap\Windows\installEclipse.bat"
if errorlevel 1 (
    echo %C_ERROR%ERROR: installEclipse.bat failed ^(exit !errorlevel!^)%C_RESET%
    exit /b !errorlevel!
)


call "%DIR%bootstrap\Windows\generate_setenv.bat"
if errorlevel 1 exit /b 1

call "%DIR%bootstrap\Windows\run_gradle_install.bat"
if errorlevel 1 exit /b 1

echo %C_WARN%===========================================================%C_RESET%
echo %C_SUCCESS%Bootstrap completed successfully!%C_RESET%
echo To activate the environment, please run:
echo   call setenv.bat
echo %C_WARN%===========================================================%C_RESET%

endlocal
exit /b 0



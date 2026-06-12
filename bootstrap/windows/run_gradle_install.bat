@echo off
setlocal EnableExtensions EnableDelayedExpansion

set "SCRIPT_DIR=%~dp0"
for %%I in ("%SCRIPT_DIR%\..\..") do set "REPO_ROOT=%%~fI"

if not defined PROJECT_DIR set "PROJECT_DIR=%REPO_ROOT%"
if not defined SETENV_FILE set "SETENV_FILE=%REPO_ROOT%\setenv.bat"

call "%~dp0common.bat"

call "%~dp0common.bat" print_header "run_gradle_install" "Running Gradle install to download third-party dependencies..."

call "%SETENV_FILE%"

cd /D "%PROJECT_DIR%"
set "GRADLE_WRAPPER=%PROJECT_DIR%\application\tools\gradlew.bat"
if exist "%GRADLE_WRAPPER%" (
    call "%GRADLE_WRAPPER%" install --no-daemon
    if errorlevel 1 (
        echo %C_ERROR%ERROR: Gradle install task failed ^(exit !errorlevel!^)%C_RESET%
        exit /b !errorlevel!
    )
    echo %C_SUCCESS%Gradle install completed successfully.%C_RESET%
) else (
    echo %C_ERROR%ERROR: Gradle wrapper not found at %GRADLE_WRAPPER%%C_RESET%
    exit /b 1
)

@echo off
REM Common functions for MDE4CPP Windows bootstrap scripts

if "%~1"=="load_properties" goto :load_properties
if "%~1"=="setup_colors" goto :setup_colors
exit /b 0

:load_properties
set "SCRIPT_DIR=%~dp0"
for %%I in ("%SCRIPT_DIR%..\..") do set "REPO_ROOT=%%~fI"
set "VERSIONS_FILE=%REPO_ROOT%\versions.properties"

if not exist "%VERSIONS_FILE%" (
    echo ERROR: versions.properties not found at %VERSIONS_FILE%
    exit /b 1
)

for /f "tokens=1,2 delims==" %%A in ('type "%VERSIONS_FILE%" ^| findstr /V /B /C:"#"') do (
    set "KEY=%%A"
    set "VAL=%%B"
    
    REM Set the variable cleanly if both KEY and VAL are present
    if not "!KEY!"=="" if not "!VAL!"=="" (
        for /f "tokens=* delims= " %%K in ("!KEY!") do set "KEY=%%K"
        for /f "tokens=* delims= " %%V in ("!VAL!") do set "VAL=%%V"
        set "!KEY!=!VAL!"
    )
)
exit /b 0

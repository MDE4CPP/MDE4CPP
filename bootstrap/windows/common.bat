@echo off
REM Common functions for MDE4CPP Windows bootstrap scripts

if "%~1"=="load_properties" goto :load_properties
if "%~1"=="setup_colors" goto :setup_colors
if "%~1"=="print_header" goto :print_header
if "%~1"=="" goto :auto_load
exit /b 0

:auto_load
call :setup_colors
if not defined MDE4CPP_JAVA_VERSION (
    call :load_properties
)
exit /b 0

:load_properties
set "SCRIPT_DIR=%~dp0"
for %%I in ("%SCRIPT_DIR%..\..") do set "REPO_ROOT=%%~fI"
set "TEMPLATE_FILE=%REPO_ROOT%\MDE4CPP_default.properties"
set "CUSTOM_FILE=%REPO_ROOT%\MDE4CPP_custom.properties"

if exist "%TEMPLATE_FILE%" call :parse_properties_file "%TEMPLATE_FILE%"
if exist "%CUSTOM_FILE%" call :parse_properties_file "%CUSTOM_FILE%"
exit /b 0

:parse_properties_file
for /f "tokens=1,2 delims==" %%A in ('type "%~1" ^| findstr /V /B /C:"#"') do (
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

:setup_colors
for /F %%a in ('echo prompt $E ^| cmd') do set "ESC=%%a"
set "SCRIPT_DIR=%~dp0"
for /f "tokens=1,2 delims==" %%A in ('type "%SCRIPT_DIR%..\colors.properties" 2^>nul ^| findstr /V /B /C:"#"') do (
    set "KEY=%%A"
    set "VAL=%%B"
    if not "!KEY!"=="" if not "!VAL!"=="" (
        for /f "tokens=* delims= " %%K in ("!KEY!") do set "KEY=%%K"
        for /f "tokens=* delims= " %%V in ("!VAL!") do set "VAL=%%V"
        set "!KEY!=!ESC![!VAL!"
    )
)
exit /b 0

:print_header
echo %C_WARN%===========================================================%C_RESET%
echo %C_PURPLE%[%~2]%C_WARN% %~3%C_RESET%
echo %C_WARN%===========================================================%C_RESET%
exit /b 0

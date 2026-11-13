@echo off
REM Common functions for MDE4CPP Windows bootstrap scripts
REM %PROJECT_DIR% variable is set in bootstrap.bat file

if "%~1"=="load_properties" goto :load_properties
if "%~1"=="setup_colors" goto :setup_colors
if "%~1"=="print_header" goto :print_header
if "%~1"=="download_file" goto :download_file
if "%~1"=="" goto :auto_load
exit /b 0

:auto_load
call :setup_colors
if not defined MDE4CPP_JAVA_VERSION (
    call :load_properties
)
exit /b 0

:load_properties
set "TEMPLATE_FILE=%PROJECT_DIR%\MDE4CPP_default.properties"
set "CUSTOM_FILE=%PROJECT_DIR%\MDE4CPP_custom.properties"

if exist "%TEMPLATE_FILE%" call :parse_properties_file "%TEMPLATE_FILE%"
if exist "%CUSTOM_FILE%" call :parse_properties_file "%CUSTOM_FILE%"
exit /b 0

:parse_properties_file
for /f "usebackq eol=# tokens=1* delims==" %%A in ("%~1") do (
    call :trim_ws "%%~A" KEY
    call :trim_ws "%%~B" VAL
    if defined KEY if defined VAL call set "%%KEY%%=%%VAL%%"
)
exit /b 0

:setup_colors
for /F %%a in ('echo prompt $E ^| cmd') do set "ESC=%%a"
if not exist "%PROJECT_DIR%\bootstrap\colors.properties" exit /b 0
for /f "usebackq eol=# tokens=1* delims==" %%A in ("%PROJECT_DIR%\bootstrap\colors.properties") do (
    call :trim_ws "%%~A" KEY
    call :trim_ws "%%~B" VAL
    if defined KEY if defined VAL call set "%%KEY%%=%%ESC%%[%%VAL%%"
)
exit /b 0

:trim_ws
setlocal EnableExtensions DisableDelayedExpansion
set "STR=%~1"
for /f "tokens=* delims= " %%T in ("%STR%") do set "STR=%%T"
:trim_ws_right
if not defined STR goto trim_ws_done
if "%STR:~-1%"==" " (
    set "STR=%STR:~0,-1%"
    goto trim_ws_right
)
:trim_ws_done
endlocal & set "%~2=%STR%"
exit /b 0

:print_header
echo %C_WARN%===========================================================%C_RESET%
echo %C_PURPLE%[%~2]%C_WARN% %~3%C_RESET%
echo %C_WARN%===========================================================%C_RESET%
exit /b 0

:download_file
REM Usage: call "%~dp0common.bat" download_file "URL" "DESTINATION"
set "URL=%~2"
set "DEST=%~3"
where curl >nul 2>&1
if errorlevel 1 (
    echo %C_ERROR%ERROR: curl.exe is required to download files.%C_RESET%
    exit /b 1
)
curl.exe -fL --output "%DEST%" "%URL%"
if errorlevel 1 (
    echo %C_ERROR%ERROR: Download failed for %URL%%C_RESET%
    exit /b 1
)
exit /b 0

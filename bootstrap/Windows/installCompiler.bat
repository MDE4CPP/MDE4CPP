@echo off
setlocal EnableExtensions EnableDelayedExpansion

REM When running elevated from a temp copy, skip config reading (variables are
REM already set by the wrapper) and jump directly to the install steps.
if /I "%~1"=="--elevated" goto :doInstall

call "%~dp0common.bat" load_properties
if errorlevel 1 exit /b 1

echo %C_INFO%[installCompiler]%C_RESET% MDE4CPP_COMPILER_VERSION=!MDE4CPP_COMPILER_VERSION!
if "!MDE4CPP_COMPILER_VERSION!"=="" (
    echo %C_ERROR%[installCompiler] ERROR: MDE4CPP_COMPILER_VERSION not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)

REM Resolve the install directory.
if not defined COMPILER_HOME set "COMPILER_HOME=C:\tools\MinGW"
set "INSTALL_DIR=%COMPILER_HOME%"
if not defined INSTALL_DIR (
    set /P INSTALL_DIR=[installCompiler] Enter MinGW installation directory:
)

if not defined INSTALL_DIR (
    set /P INSTALL_DIR=[installCompiler] Enter MinGW installation directory:
)

if not defined INSTALL_DIR (
    echo %C_ERROR%[installCompiler] ERROR: Installation directory is required.%C_RESET%
    exit /b 1
)

REM Skip installation when MinGW already exists in target directory.
if exist "%INSTALL_DIR%\bin\gcc.exe" (
    for /f "tokens=1" %%V in ('"%INSTALL_DIR%\bin\gcc.exe" -dumpfullversion 2^>nul') do set "INSTALLED_GCC=%%V"
    echo %C_INFO%[installCompiler]%C_RESET% MinGW is already installed at %INSTALL_DIR%.
    if defined INSTALLED_GCC (
        echo %C_INFO%[installCompiler]%C_RESET% Detected GCC version=%INSTALLED_GCC%. Skipping.
    ) else (
        echo %C_INFO%[installCompiler]%C_RESET% Detected existing gcc.exe. Skipping.
    )
    exit /b 0
)

REM Ensure the script runs with administrator rights if installation is required.
REM Elevated processes cannot access mapped network drives (e.g. Z:), so we copy
REM this script to %TEMP% (local C: drive) and run the copy elevated.
net session >nul 2>&1
if errorlevel 1 (
    echo %C_INFO%[installCompiler]%C_RESET% Administrator rights are required. Requesting elevation...
    set "LOCAL_COPY=%TEMP%\mde4cpp-installCompiler.bat"
    set "ELEVATE_BAT=%TEMP%\mde4cpp-elevate-compiler.bat"
    set "INSTALL_LOG=%TEMP%\mde4cpp-compiler-install.log"
    copy "%~f0" "!LOCAL_COPY!" >nul
    (
        echo @echo off
        echo set "MDE4CPP_COMPILER_VERSION=!MDE4CPP_COMPILER_VERSION!"
        echo set "INSTALL_DIR=!INSTALL_DIR!"
        echo call "!LOCAL_COPY!" --elevated ^> "!INSTALL_LOG!" 2^>^&1
    ) > "!ELEVATE_BAT!"

    powershell -NoProfile -ExecutionPolicy Bypass -Command "Start-Process '!ELEVATE_BAT!' -Wait -Verb RunAs"
    set "ELEV_ERR=!errorlevel!"
    del "!ELEVATE_BAT!" >nul 2>&1
    del "!LOCAL_COPY!" >nul 2>&1

    REM Show log from elevated process
    if exist "!INSTALL_LOG!" (
        echo [installCompiler] --- Elevated process log ---
        type "!INSTALL_LOG!"
        echo [installCompiler] --- End log ---
        del "!INSTALL_LOG!" >nul 2>&1
    )

    if not "!ELEV_ERR!"=="0" (
        echo %C_ERROR%[installCompiler] ERROR: Elevation was cancelled or failed.%C_RESET%
        exit /b 1
    )

    REM Verify installation
    if exist "!INSTALL_DIR!\bin\gcc.exe" (
        for /f "tokens=1" %%V in ('"!INSTALL_DIR!\bin\gcc.exe" -dumpfullversion 2^>nul') do set "INSTALLED_GCC=%%V"
        echo %C_SUCCESS%[installCompiler] Verified: MinGW installed at !INSTALL_DIR! ^(GCC !INSTALLED_GCC!^)%C_RESET%
        exit /b 0
    ) else (
        echo %C_ERROR%[installCompiler] ERROR: Installation could not be verified. gcc.exe not found at !INSTALL_DIR!%C_RESET%
        exit /b 1
    )
)

:doInstall
REM Resolve download URL and prepare temporary workspace.
REM When reaching here via --elevated, MDE4CPP_COMPILER_VERSION and INSTALL_DIR
REM are already set by the wrapper script.
set "TMP_DIR=%TEMP%\mde4cpp-mingw-%RANDOM%%RANDOM%"
set "ARCHIVE_PATH=%TMP_DIR%\mingw.zip"
set "DOWNLOAD_URL=https://github.com/brechtsanders/winlibs_mingw/releases/download/13.2.0-16.0.6-11.0.1-msvcrt-r1/winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64msvcrt-11.0.1-r1.zip"

echo %C_INFO%[installCompiler]%C_RESET% Install location=%INSTALL_DIR%
echo %C_INFO%[installCompiler]%C_RESET% Downloading %DOWNLOAD_URL%
if exist "%TMP_DIR%" rmdir /s /q "%TMP_DIR%"
mkdir "%TMP_DIR%" >nul 2>&1
if errorlevel 1 (
    echo %C_ERROR%[installCompiler] ERROR: Failed to create temp dir %TMP_DIR%.%C_RESET%
    exit /b 1
)

where curl >nul 2>&1
if errorlevel 1 (
    echo %C_ERROR%[installCompiler] ERROR: curl.exe is required to download files.%C_RESET%
    echo %C_INFO%[installCompiler]%C_RESET% Please install curl or use a Windows version that includes curl.
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

curl.exe -L -o "%ARCHIVE_PATH%" "%DOWNLOAD_URL%"
if errorlevel 1 (
    echo %C_ERROR%[installCompiler] ERROR: Download failed.%C_RESET%
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

REM Extract and copy MinGW into target install directory.
if exist "%INSTALL_DIR%" rmdir /s /q "%INSTALL_DIR%"
mkdir "%INSTALL_DIR%" >nul 2>&1
if errorlevel 1 (
    echo %C_ERROR%[installCompiler] ERROR: Failed to create install directory %INSTALL_DIR%.%C_RESET%
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

mkdir "%TMP_DIR%\extracted" >nul 2>&1
tar -xf "%ARCHIVE_PATH%" -C "%TMP_DIR%\extracted"
if errorlevel 1 (
    echo %C_ERROR%[installCompiler] ERROR: Extraction failed ^(tar^).%C_RESET%
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

if exist "%TMP_DIR%\extracted\mingw64" (
    robocopy "%TMP_DIR%\extracted\mingw64" "%INSTALL_DIR%" /E >nul
) else (
    echo %C_ERROR%[installCompiler] ERROR: Extracted MinGW folder not found.%C_RESET%
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

REM Cleanup and verify gcc installation.
rmdir /s /q "%TMP_DIR%"

if exist "%INSTALL_DIR%\bin\gcc.exe" (
    for /f "tokens=1" %%V in ('"%INSTALL_DIR%\bin\gcc.exe" -dumpfullversion 2^>nul') do set "INSTALLED_GCC=%%V"
    echo %C_SUCCESS%[installCompiler] Installed MinGW at %INSTALL_DIR%%C_RESET%
    echo %C_INFO%[installCompiler]%C_RESET% Detected GCC version=%INSTALLED_GCC%
) else (
    echo %C_ERROR%[installCompiler] ERROR: gcc.exe not found after installation.%C_RESET%
    exit /b 1
)

endlocal

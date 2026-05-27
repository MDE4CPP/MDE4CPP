@echo off
setlocal EnableExtensions

REM Step 1: Validate required compiler version input.
echo [installCompiler] MDE4CPP_COMPILER_VERSION=%MDE4CPP_COMPILER_VERSION%

if "%MDE4CPP_COMPILER_VERSION%"=="" (
    echo [installCompiler] ERROR: MDE4CPP_COMPILER_VERSION is not set.
    exit /b 1
)

REM Step 2: Resolve the install directory from setenv or prompt the user.
set "SCRIPT_DIR=%~dp0"
for %%I in ("%SCRIPT_DIR%\..\..") do set "REPO_ROOT=%%~fI"
set "SETENV_FILE=%REPO_ROOT%\setenv.bat"
if not exist "%SETENV_FILE%" set "SETENV_FILE=%REPO_ROOT%\setenv.bat.default"

set "INSTALL_DIR="
if exist "%SETENV_FILE%" (
    for /f "tokens=1,* delims==" %%A in ('findstr /R /I /C:"^[ ]*SET[ ]*COMPILER_HOME=" "%SETENV_FILE%"') do (
        set "INSTALL_DIR=%%B"
        goto :pathFound
    )
)

:pathFound
if defined INSTALL_DIR (
    set "INSTALL_DIR=%INSTALL_DIR:"=%"
    for /f "tokens=* delims= " %%P in ("%INSTALL_DIR%") do set "INSTALL_DIR=%%P"
)

if not defined INSTALL_DIR (
    set /P INSTALL_DIR=[installCompiler] Enter MinGW installation directory:
)

if not defined INSTALL_DIR (
    echo [installCompiler] ERROR: Installation directory is required.
    exit /b 1
)

REM Step 3: Skip installation when MinGW already exists in target directory.
if exist "%INSTALL_DIR%\bin\gcc.exe" (
    for /f "tokens=1" %%V in ('"%INSTALL_DIR%\bin\gcc.exe" -dumpfullversion 2^>nul') do set "INSTALLED_GCC=%%V"
    echo [installCompiler] MinGW is already installed at %INSTALL_DIR%.
    if defined INSTALLED_GCC (
        echo [installCompiler] Detected GCC version=%INSTALLED_GCC%. Skipping.
    ) else (
        echo [installCompiler] Detected existing gcc.exe. Skipping.
    )
    exit /b 0
)

REM Step 4: Ensure the script runs with administrator rights if installation is required.
net session >nul 2>&1
if errorlevel 1 (
    echo [installCompiler] ERROR: Administrator rights are required.
    echo [installCompiler] Please rerun this script in an elevated command prompt.
    exit /b 1
)

REM Step 5: Resolve download URL and prepare temporary workspace.
set "TMP_DIR=%TEMP%\mde4cpp-mingw-%RANDOM%%RANDOM%"
set "ARCHIVE_PATH=%TMP_DIR%\mingw.7z"
set "MINGW_RELEASE_TAG=%MDE4CPP_COMPILER_VERSION%-rt_v11-rev1"
set "DOWNLOAD_URL=https://github.com/niXman/mingw-builds-binaries/releases/download/%MINGW_RELEASE_TAG%/x86_64-%MDE4CPP_COMPILER_VERSION%-release-posix-seh-msvcrt-rt_v11-rev1.7z"

REM Step 5: Download MinGW archive and verify extraction tool.
echo [installCompiler] Install location=%INSTALL_DIR%
echo [installCompiler] Downloading %DOWNLOAD_URL%
if exist "%TMP_DIR%" rmdir /s /q "%TMP_DIR%"
mkdir "%TMP_DIR%" >nul 2>&1
if errorlevel 1 (
    echo [installCompiler] ERROR: Failed to create temp dir %TMP_DIR%.
    exit /b 1
)

where curl >nul 2>&1
if errorlevel 1 (
    echo [installCompiler] ERROR: curl.exe is required to download files.
    echo [installCompiler] Please install curl or use a Windows version that includes curl.
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

curl.exe -L -o "%ARCHIVE_PATH%" "%DOWNLOAD_URL%"
if errorlevel 1 (
    echo [installCompiler] ERROR: Download failed.
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

where 7z >nul 2>&1
if errorlevel 1 (
    echo [installCompiler] 7z not found. Attempting to install 7-Zip via winget...
    where winget >nul 2>&1
    if errorlevel 1 (
        echo [installCompiler] ERROR: winget is not available to install 7-Zip automatically.
        echo [installCompiler] Please install 7-Zip manually from https://www.7-zip.org/ and re-run this script.
        rmdir /s /q "%TMP_DIR%"
        exit /b 1
    ) else (
        echo [installCompiler] Running: winget install --id 7zip.7zip -e --silent --accept-source-agreements --accept-package-agreements
        winget install --id 7zip.7zip -e --silent --accept-source-agreements --accept-package-agreements
        if errorlevel 1 (
            echo [installCompiler] ERROR: winget failed to install 7-Zip.
            rmdir /s /q "%TMP_DIR%"
            exit /b 1
        )
        where 7z >nul 2>&1
        if errorlevel 1 (
            echo [installCompiler] ERROR: 7z still not found after winget install.
            rmdir /s /q "%TMP_DIR%"
            exit /b 1
        )
    )
)

REM Step 6: Extract and copy MinGW into target install directory.
if exist "%INSTALL_DIR%" rmdir /s /q "%INSTALL_DIR%"
mkdir "%INSTALL_DIR%" >nul 2>&1
if errorlevel 1 (
    echo [installCompiler] ERROR: Failed to create install directory %INSTALL_DIR%.
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

7z x "%ARCHIVE_PATH%" -o"%TMP_DIR%\extracted" -y >nul
if errorlevel 1 (
    echo [installCompiler] ERROR: Extraction failed.
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

if exist "%TMP_DIR%\extracted\mingw64" (
    robocopy "%TMP_DIR%\extracted\mingw64" "%INSTALL_DIR%" /E >nul
) else (
    echo [installCompiler] ERROR: Extracted MinGW folder not found.
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

REM Step 7: Cleanup and verify gcc installation.
rmdir /s /q "%TMP_DIR%"

if exist "%INSTALL_DIR%\bin\gcc.exe" (
    for /f "tokens=1" %%V in ('"%INSTALL_DIR%\bin\gcc.exe" -dumpfullversion 2^>nul') do set "INSTALLED_GCC=%%V"
    echo [installCompiler] Installed MinGW at %INSTALL_DIR%
    echo [installCompiler] Detected GCC version=%INSTALLED_GCC%
) else (
    echo [installCompiler] ERROR: gcc.exe not found after installation.
    exit /b 1
)

endlocal

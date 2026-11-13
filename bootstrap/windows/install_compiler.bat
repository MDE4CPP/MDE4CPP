@echo off
setlocal EnableExtensions EnableDelayedExpansion

REM When running elevated from a temp copy, skip config reading (variables are
REM already set by the wrapper) and jump directly to the install steps.
if /I "%~1"=="--elevated" goto :doInstall

call "%~dp0common.bat"
if errorlevel 1 exit /b 1

call "%~dp0common.bat" print_header "install_compiler" "Running Compiler installation..."

echo %C_PURPLE%[install_compiler]%C_ORANGE% MDE4CPP_COMPILER_VERSION=!MDE4CPP_COMPILER_VERSION!%C_RESET%
if "!MDE4CPP_COMPILER_VERSION!"=="" (
    echo %C_PURPLE%[install_compiler]%C_ERROR% ERROR: MDE4CPP_COMPILER_VERSION is not set.%C_RESET%
    exit /b 1
)
echo %C_PURPLE%[install_compiler]%C_ORANGE% MDE4CPP_COMPILER_DOWNLOAD_URL=!MDE4CPP_COMPILER_DOWNLOAD_URL!%C_RESET%
if "!MDE4CPP_COMPILER_DOWNLOAD_URL!"=="" (
    echo %C_PURPLE%[install_compiler]%C_ERROR% ERROR: MDE4CPP_COMPILER_DOWNLOAD_URL is not set.%C_RESET%
    echo %C_PURPLE%[install_compiler]%C_ERROR% Configure it in MDE4CPP_custom.properties.%C_RESET%
    exit /b 1
)

REM Resolve the install directory.
if not defined COMPILER_HOME set "COMPILER_HOME=C:\tools\MinGW"
set "INSTALL_DIR=%COMPILER_HOME%"
if not defined INSTALL_DIR (
    set /P INSTALL_DIR=[install_compiler] Enter MinGW installation directory:
)

if not defined INSTALL_DIR (
    set /P INSTALL_DIR=[install_compiler] Enter MinGW installation directory:
)

if not defined INSTALL_DIR (
    echo %C_PURPLE%[install_compiler]%C_ERROR% ERROR: Installation directory is required.%C_RESET%
    exit /b 1
)

REM Skip installation when MinGW already exists in target directory.
if exist "%INSTALL_DIR%\bin\gcc.exe" (
    for /f "tokens=1" %%V in ('"%INSTALL_DIR%\bin\gcc.exe" -dumpfullversion 2^>nul') do set "INSTALLED_GCC=%%V"
    echo %C_PURPLE%[install_compiler]%C_SUCCESS% MinGW is already installed at %INSTALL_DIR%.%C_RESET%
    if defined INSTALLED_GCC (
        echo %C_PURPLE%[install_compiler]%C_SUCCESS% Detected GCC version=%INSTALLED_GCC%. Skipping.%C_RESET%
    ) else (
        echo %C_PURPLE%[install_compiler]%C_SUCCESS% Detected existing gcc.exe. Skipping.%C_RESET%
    )

    exit /b 0
)

REM Ensure the script runs with administrator rights if installation is required.
net session >nul 2>&1
if errorlevel 1 (
    echo %C_PURPLE%[install_compiler]%C_ERROR% ERROR: Administrator rights are required.%C_RESET%
    echo %C_PURPLE%[install_compiler]%C_INFO% Please run this script in an elevated cmd.exe.%C_RESET%
    exit /b 1
)

:doInstall
REM Resolve download URL and prepare temporary workspace.
REM When reaching here via --elevated, MDE4CPP_COMPILER_VERSION and INSTALL_DIR
REM are already set by the wrapper script.
if defined MDE4CPP_COMMON_BAT (
    set "COMMON_BAT=%MDE4CPP_COMMON_BAT%"
) else (
    set "COMMON_BAT=%~dp0common.bat"
)
if not exist "%COMMON_BAT%" (
    echo %C_PURPLE%[install_compiler]%C_ERROR% ERROR: common.bat not found at %COMMON_BAT%%C_RESET%
    exit /b 1
)
set "TMP_DIR=%TEMP%\mde4cpp-mingw-%RANDOM%%RANDOM%"
set "ARCHIVE_PATH=%TMP_DIR%\mingw.zip"

if exist "%TMP_DIR%" rmdir /s /q "%TMP_DIR%"
mkdir "%TMP_DIR%" >nul 2>&1
if errorlevel 1 (
    echo %C_PURPLE%[install_compiler]%C_ERROR% ERROR: Failed to create temp dir %TMP_DIR%.%C_RESET%
    exit /b 1
)

set "DOWNLOAD_URL=%MDE4CPP_COMPILER_DOWNLOAD_URL%"

echo %C_PURPLE%[install_compiler]%C_INFO% Install location=%INSTALL_DIR%%C_RESET%
echo %C_PURPLE%[install_compiler]%C_INFO% Downloading %DOWNLOAD_URL%%C_RESET%

call "%COMMON_BAT%" download_file "%DOWNLOAD_URL%" "%ARCHIVE_PATH%"
if errorlevel 1 (
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

REM Extract and copy MinGW into target install directory.
if exist "%INSTALL_DIR%" rmdir /s /q "%INSTALL_DIR%"
mkdir "%INSTALL_DIR%" >nul 2>&1
if errorlevel 1 (
    echo %C_PURPLE%[install_compiler]%C_ERROR% ERROR: Failed to create install directory %INSTALL_DIR%.%C_RESET%
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

mkdir "%TMP_DIR%\extracted" >nul 2>&1
tar -xf "%ARCHIVE_PATH%" -C "%TMP_DIR%\extracted"
if errorlevel 1 (
    echo %C_PURPLE%[install_compiler]%C_ERROR% ERROR: Extraction failed ^(tar^).%C_RESET%
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

if exist "%TMP_DIR%\extracted\mingw64" (
    robocopy "%TMP_DIR%\extracted\mingw64" "%INSTALL_DIR%" /E >nul
) else (
    echo %C_PURPLE%[install_compiler]%C_ERROR% ERROR: Extracted MinGW folder not found.%C_RESET%
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

REM Cleanup and verify gcc installation.
rmdir /s /q "%TMP_DIR%"

if exist "%INSTALL_DIR%\bin\gcc.exe" (
    for /f "tokens=1" %%V in ('"%INSTALL_DIR%\bin\gcc.exe" -dumpfullversion 2^>nul') do set "INSTALLED_GCC=%%V"
    if not defined INSTALLED_GCC (
        for /f "tokens=3" %%V in ('"%INSTALL_DIR%\bin\gcc.exe" --version 2^>nul ^| findstr /R /C:"^gcc"') do set "INSTALLED_GCC=%%V"
    )
    echo %C_PURPLE%[install_compiler]%C_SUCCESS% Installed MinGW at %INSTALL_DIR%%C_RESET%
    echo %C_PURPLE%[install_compiler]%C_INFO% Detected GCC version=%INSTALLED_GCC%%C_RESET%
    exit /b 0
) else (
    echo %C_PURPLE%[install_compiler]%C_ERROR% ERROR: gcc.exe not found after installation.%C_RESET%
    exit /b 1
)

endlocal

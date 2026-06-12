@echo off
setlocal EnableExtensions EnableDelayedExpansion

REM When running elevated from a temp copy, skip config reading (variables are
REM already set by the wrapper) and jump directly to the install steps.
if /I "%~1"=="--elevated" goto :doInstall

call "%~dp0common.bat" load_properties
if errorlevel 1 exit /b 1

REM Use CMAKE_BUILD as CMAKE_BUILD_VERSION for compatibility
set "MDE4CPP_CMAKE_BUILD_VERSION=!MDE4CPP_CMAKE_BUILD!"

echo [installCMake] MDE4CPP_CMAKE_VERSION=!MDE4CPP_CMAKE_VERSION!
echo [installCMake] MDE4CPP_CMAKE_BUILD_VERSION=!MDE4CPP_CMAKE_BUILD_VERSION!

if "!MDE4CPP_CMAKE_VERSION!"=="" (
    echo [installCMake] ERROR: MDE4CPP_CMAKE_VERSION not found in %VERSIONS_FILE%
    exit /b 1
)
if "!MDE4CPP_CMAKE_BUILD_VERSION!"=="" (
    echo [installCMake] ERROR: MDE4CPP_CMAKE_BUILD not found in %VERSIONS_FILE%
    exit /b 1
)

REM Step 2: Resolve versions and download paths.
set "CMAKE_FULL_VERSION=%MDE4CPP_CMAKE_VERSION%.%MDE4CPP_CMAKE_BUILD_VERSION%"

REM Step 3: Skip when the requested CMake version is already installed.
set "INSTALLED_VERSION="
for /f "tokens=3" %%V in ('cmake --version 2^>nul ^| findstr /b "cmake version"') do set "INSTALLED_VERSION=%%V"
if not "%INSTALLED_VERSION%"=="" (
    if "%INSTALLED_VERSION%"=="%CMAKE_FULL_VERSION%" (
        echo [installCMake] CMake %CMAKE_FULL_VERSION% is already installed. Skipping.
        exit /b 0
    ) else (
        echo [installCMake] Found installed CMake %INSTALLED_VERSION%. Installing %CMAKE_FULL_VERSION%.
    )
) else (
    echo [installCMake] CMake is not installed. Installing %CMAKE_FULL_VERSION%.
)

REM Step 4: Ensure the script runs with administrator rights only if installation is required.
REM Elevated processes cannot access mapped network drives (e.g. Z:), so we copy
REM this script to %TEMP% (local C: drive) and run the copy elevated.
net session >nul 2>&1
if errorlevel 1 (
    echo [installCMake] Administrator rights are required. Requesting elevation...
    set "LOCAL_COPY=%TEMP%\mde4cpp-installCMake.bat"
    set "ELEVATE_BAT=%TEMP%\mde4cpp-elevate-cmake.bat"
    copy "%~f0" "!LOCAL_COPY!" >nul
    (
        echo @echo off
        echo set "MDE4CPP_CMAKE_VERSION=!MDE4CPP_CMAKE_VERSION!"
        echo set "MDE4CPP_CMAKE_BUILD_VERSION=!MDE4CPP_CMAKE_BUILD_VERSION!"
        echo set "CMAKE_FULL_VERSION=!CMAKE_FULL_VERSION!"
        echo call "!LOCAL_COPY!" --elevated
    ) > "!ELEVATE_BAT!"

    powershell -NoProfile -ExecutionPolicy Bypass -Command "Start-Process '!ELEVATE_BAT!' -Wait -Verb RunAs"
    set "ELEV_ERR=!errorlevel!"
    del "!ELEVATE_BAT!" >nul 2>&1
    del "!LOCAL_COPY!" >nul 2>&1

    if not "!ELEV_ERR!"=="0" (
        echo [installCMake] ERROR: Elevation was cancelled or failed.
        exit /b 1
    )

    REM Verify CMake installation by re-checking PATH from registry
    set "VERIFY_CMAKE="
    for /f "tokens=2*" %%A in ('reg query "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v Path 2^>nul ^| findstr /I "Path"') do set "SYS_PATH=%%B"
    set "PATH=!SYS_PATH!;%PATH%"
    for /f "tokens=3" %%V in ('cmake --version 2^>nul ^| findstr /b "cmake version"') do set "VERIFY_CMAKE=%%V"
    if defined VERIFY_CMAKE (
        echo [installCMake] Verified: CMake !VERIFY_CMAKE! installed.
        exit /b 0
    ) else (
        echo [installCMake] WARNING: Could not verify CMake after elevation. It may require a new shell.
        exit /b 0
    )
)

:doInstall
REM Step 5: Prepare workspace and download the MSI installer.
REM When reaching here via --elevated, CMAKE_FULL_VERSION and related variables
REM are already set by the wrapper script.
set "TMP_DIR=%TEMP%\mde4cpp-cmake-%RANDOM%%RANDOM%"
set "INSTALLER_PATH=%TMP_DIR%\cmake.msi"
set "DOWNLOAD_URL=https://github.com/Kitware/CMake/releases/download/v%CMAKE_FULL_VERSION%/cmake-%CMAKE_FULL_VERSION%-windows-x86_64.msi"

echo [installCMake] Install mode=system application
echo [installCMake] Using CMake version=%CMAKE_FULL_VERSION%
echo [installCMake] Downloading %DOWNLOAD_URL%

if exist "%TMP_DIR%" rmdir /s /q "%TMP_DIR%"
mkdir "%TMP_DIR%" >nul 2>&1
if errorlevel 1 (
    echo [installCMake] ERROR: Failed to create temp dir %TMP_DIR%.
    exit /b 1
)

where curl >nul 2>&1
if errorlevel 1 (
    echo [installCMake] ERROR: curl.exe is required to download files.
    echo [installCMake] Please install curl or use a Windows version that includes curl.
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

curl.exe -L -o "%INSTALLER_PATH%" "%DOWNLOAD_URL%"
if errorlevel 1 (
    echo [installCMake] ERROR: Download failed.
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

REM Step 6: Install CMake system-wide.
msiexec /i "%INSTALLER_PATH%" /qn ADD_CMAKE_TO_PATH=System
if errorlevel 1 (
    echo [installCMake] ERROR: MSI installation failed. Try running as Administrator.
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

REM Step 7: Cleanup and report installed binary location.
rmdir /s /q "%TMP_DIR%"
echo [installCMake] Installed system CMake %CMAKE_FULL_VERSION%
where cmake >nul 2>&1
if errorlevel 1 (
    echo [installCMake] WARNING: cmake is not on PATH yet. Open a new shell.
) else (
    for /f "delims=" %%P in ('where cmake') do (
        echo [installCMake] Binary: %%P
        goto :done
    )
)
:done

endlocal

@echo off
setlocal EnableExtensions EnableDelayedExpansion

REM When running elevated from a temp copy, skip config reading (variables are
REM already set by the wrapper) and jump directly to the install steps.
if /I "%~1"=="--elevated" goto :doInstall

call "%~dp0common.bat"
if errorlevel 1 exit /b 1

call "%~dp0common.bat" print_header "installCMake" "Running CMake installation..."

REM Use CMAKE_BUILD as CMAKE_BUILD_VERSION for compatibility
set "MDE4CPP_CMAKE_BUILD_VERSION=!MDE4CPP_CMAKE_BUILD!"

echo %C_PURPLE%[installCMake]%C_ORANGE% MDE4CPP_CMAKE_VERSION=!MDE4CPP_CMAKE_VERSION!%C_RESET%
echo %C_PURPLE%[installCMake]%C_ORANGE% MDE4CPP_CMAKE_BUILD_VERSION=!MDE4CPP_CMAKE_BUILD_VERSION!%C_RESET%

if "!MDE4CPP_CMAKE_VERSION!"=="" (
    echo %C_PURPLE%[installCMake]%C_ERROR% ERROR: MDE4CPP_CMAKE_VERSION not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)
if "!MDE4CPP_CMAKE_BUILD_VERSION!"=="" (
    echo %C_PURPLE%[installCMake]%C_ERROR% ERROR: MDE4CPP_CMAKE_BUILD not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)

REM Resolve versions and download paths.
set "CMAKE_FULL_VERSION=%MDE4CPP_CMAKE_VERSION%.%MDE4CPP_CMAKE_BUILD_VERSION%"

REM Skip when the requested CMake version is already installed.
set "INSTALLED_VERSION="
for /f "tokens=3" %%V in ('cmake --version 2^>nul ^| findstr /b "cmake version"') do set "INSTALLED_VERSION=%%V"
if not "%INSTALLED_VERSION%"=="" (
    if "%INSTALLED_VERSION%"=="%CMAKE_FULL_VERSION%" (
        echo %C_PURPLE%[installCMake]%C_SUCCESS% CMake %CMAKE_FULL_VERSION% is already installed. Skipping.%C_RESET%
        exit /b 0
    ) else (
        echo %C_PURPLE%[installCMake]%C_SUCCESS% Found installed CMake %INSTALLED_VERSION%. Installing %CMAKE_FULL_VERSION%.%C_RESET%
    )
) else (
    echo %C_PURPLE%[installCMake]%C_INFO% CMake is not installed. Installing %CMAKE_FULL_VERSION%.%C_RESET%
)

REM Ensure the script runs with administrator rights only if installation is required.
REM Elevated processes cannot access mapped network drives (e.g. Z:), so we copy
REM this script to %TEMP% (local C: drive) and run the copy elevated.
net session >nul 2>&1
if errorlevel 1 (
    echo %C_PURPLE%[installCMake]%C_INFO% Administrator rights are required. Requesting elevation...%C_RESET%
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
        echo %C_PURPLE%[installCMake]%C_ERROR% ERROR: Elevation was cancelled or failed.%C_RESET%
        exit /b 1
    )

    REM Verify CMake installation by re-checking PATH from registry
    set "VERIFY_CMAKE="
    for /f "tokens=2*" %%A in ('reg query "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v Path 2^>nul ^| findstr /I "Path"') do set "SYS_PATH=%%B"
    set "PATH=!SYS_PATH!;%PATH%"
    for /f "tokens=3" %%V in ('cmake --version 2^>nul ^| findstr /b "cmake version"') do set "VERIFY_CMAKE=%%V"
    if defined VERIFY_CMAKE (
        echo %C_PURPLE%[installCMake]%C_SUCCESS% Verified: CMake !VERIFY_CMAKE! installed.%C_RESET%
        exit /b 0
    ) else (
        echo %C_PURPLE%[installCMake]%C_INFO% WARNING: Could not verify CMake after elevation. It may require a new shell.%C_RESET%
        exit /b 0
    )
)

:doInstall
REM Prepare workspace and download the MSI installer.
REM When reaching here via --elevated, CMAKE_FULL_VERSION and related variables
REM are already set by the wrapper script.
set "TMP_DIR=%TEMP%\mde4cpp-cmake-%RANDOM%%RANDOM%"
set "INSTALLER_PATH=%TMP_DIR%\cmake.msi"
set "DOWNLOAD_URL=https://github.com/Kitware/CMake/releases/download/v%CMAKE_FULL_VERSION%/cmake-%CMAKE_FULL_VERSION%-windows-x86_64.msi"

echo %C_PURPLE%[installCMake]%C_INFO% Install mode=system application%C_RESET%
echo %C_PURPLE%[installCMake]%C_INFO% Using CMake version=%CMAKE_FULL_VERSION%%C_RESET%
echo %C_PURPLE%[installCMake]%C_INFO% Downloading %DOWNLOAD_URL%%C_RESET%

if exist "%TMP_DIR%" rmdir /s /q "%TMP_DIR%"
mkdir "%TMP_DIR%" >nul 2>&1
if errorlevel 1 (
    echo %C_PURPLE%[installCMake]%C_ERROR% ERROR: Failed to create temp dir %TMP_DIR%.%C_RESET%
    exit /b 1
)

where curl >nul 2>&1
if errorlevel 1 (
    echo %C_PURPLE%[installCMake]%C_ERROR% ERROR: curl.exe is required to download files.%C_RESET%
    echo %C_PURPLE%[installCMake]%C_INFO% Please install curl or use a Windows version that includes curl.%C_RESET%
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

curl.exe -L -o "%INSTALLER_PATH%" "%DOWNLOAD_URL%"
if errorlevel 1 (
    echo %C_PURPLE%[installCMake]%C_ERROR% ERROR: Download failed.%C_RESET%
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

REM Install CMake system-wide.
msiexec /i "%INSTALLER_PATH%" /qn ADD_CMAKE_TO_PATH=System
if errorlevel 1 (
    echo %C_PURPLE%[installCMake]%C_ERROR% ERROR: MSI installation failed. Try running as Administrator.%C_RESET%
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

REM Cleanup and report installed binary location.
rmdir /s /q "%TMP_DIR%"
echo %C_PURPLE%[installCMake]%C_INFO% Installed system CMake %CMAKE_FULL_VERSION%%C_RESET%
where cmake >nul 2>&1
if errorlevel 1 (
    echo %C_PURPLE%[installCMake]%C_INFO% WARNING: cmake is not on PATH yet. Open a new shell.%C_RESET%
) else (
    for /f "delims=" %%P in ('where cmake') do (
        echo %C_PURPLE%[installCMake]%C_INFO% Binary: %%P%C_RESET%
        goto :done
    )
)
:done

endlocal

@echo off
setlocal EnableExtensions EnableDelayedExpansion

call "%~dp0common.bat"
if errorlevel 1 exit /b 1

call "%~dp0common.bat" print_header "installEclipse" "Running Eclipse installation..."

REM Determine MDE4CPP_HOME from script location
set "SCRIPT_DIR=%~dp0"
for %%I in ("%SCRIPT_DIR%..\..") do set "MDE4CPP_HOME=%%~fI"

REM Print requested Eclipse component versions.
echo %C_PURPLE%[install_eclipse]%C_ORANGE% MDE4CPP_ECLIPSE_VERSION=!MDE4CPP_ECLIPSE_VERSION!-!MDE4CPP_ECLIPSE_MILESTONE!%C_RESET%

REM Validate required versions.
if "!MDE4CPP_HOME!"=="" (
    echo %C_PURPLE%[install_eclipse]%C_ERROR% ERROR: Could not determine MDE4CPP_HOME.%C_RESET%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_VERSION!"=="" (
    echo %C_PURPLE%[install_eclipse]%C_ERROR% ERROR: MDE4CPP_ECLIPSE_VERSION is not set.%C_RESET%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_MILESTONE!"=="" (
    echo %C_PURPLE%[install_eclipse]%C_ERROR% ERROR: MDE4CPP_ECLIPSE_MILESTONE is not set.%C_RESET%
    exit /b 1
)

REM Resolve install locations and download URLs.
for %%I in ("!MDE4CPP_HOME!\..") do set "MDE4CPP_PARENT=%%~fI"
if not "!MDE4CPP_ECLIPSE_LOCATION!"=="" (
    set "TARGET_DIR=!MDE4CPP_ECLIPSE_LOCATION!"
) else (
    set "TARGET_DIR=!MDE4CPP_PARENT!\eclipse"
)
REM Download and extract Eclipse Modeling package.
set "TMP_DIR=%TEMP%\mde4cpp-eclipse-install"
set "ARCHIVE_PATH=!TMP_DIR!\eclipse-modeling.zip"
set "ECLIPSE_ARCHIVE_URL=https://ftp.halifax.rwth-aachen.de/eclipse/technology/epp/downloads/release/!MDE4CPP_ECLIPSE_VERSION: =!/!MDE4CPP_ECLIPSE_MILESTONE: =!/eclipse-modeling-!MDE4CPP_ECLIPSE_VERSION: =!-!MDE4CPP_ECLIPSE_MILESTONE: =!-win32-x86_64.zip"

echo %C_PURPLE%[install_eclipse]%C_ORANGE% MDE4CPP_HOME=!MDE4CPP_HOME!%C_RESET%
echo %C_PURPLE%[install_eclipse]%C_INFO% Install location=!TARGET_DIR!%C_RESET%
echo %C_PURPLE%[install_eclipse]%C_INFO% Temp Installation Dir=!TMP_DIR!%C_RESET%
echo %C_PURPLE%[install_eclipse]%C_ORANGE% Using Eclipse version=!MDE4CPP_ECLIPSE_VERSION!, milestone=!MDE4CPP_ECLIPSE_MILESTONE!%C_RESET%

if exist "!TARGET_DIR!\eclipse.exe" (
    echo %C_PURPLE%[install_eclipse]%C_SUCCESS% Existing Eclipse installation found at !TARGET_DIR!.%C_RESET%
    exit /b 0
)

echo %C_PURPLE%[install_eclipse]%C_INFO% Downloading !ECLIPSE_ARCHIVE_URL!%C_RESET%

if exist "!TMP_DIR!" rmdir /s /q "!TMP_DIR!"
mkdir "!TMP_DIR!" >nul 2>&1
if errorlevel 1 (
    echo %C_PURPLE%[install_eclipse]%C_ERROR% ERROR: Failed to create temp dir !TMP_DIR!.%C_RESET%
    exit /b 1
)

call "%~dp0common.bat" download_file "!ECLIPSE_ARCHIVE_URL!" "!ARCHIVE_PATH!"
if errorlevel 1 (
    rmdir /s /q "!TMP_DIR!"
    exit /b 1
)

echo %C_PURPLE%[install_eclipse]%C_SUCCESS% Download finished, extracting archive.%C_RESET%

if exist "!TARGET_DIR!" rmdir /s /q "!TARGET_DIR!"

where tar >nul 2>&1
if not errorlevel 1 (
    tar -xzf "!ARCHIVE_PATH!" -C "!MDE4CPP_PARENT!"
    if errorlevel 1 (
        powershell -NoProfile -ExecutionPolicy Bypass -Command ^
            "Expand-Archive -Path '!ARCHIVE_PATH!' -DestinationPath '!MDE4CPP_PARENT!' -Force"
        if errorlevel 1 (
            echo %C_PURPLE%[install_eclipse]%C_ERROR% ERROR: Extraction failed.%C_RESET%
            rmdir /s /q "%TMP_DIR%"
            exit /b 1
        )
    )
) else (
    powershell -NoProfile -ExecutionPolicy Bypass -Command ^
        "Expand-Archive -Path '%ARCHIVE_PATH%' -DestinationPath '%MDE4CPP_PARENT%' -Force"
    if errorlevel 1 (
        echo %C_PURPLE%[install_eclipse]%C_ERROR% ERROR: Extraction failed.%C_RESET%
        rmdir /s /q "%TMP_DIR%"
        exit /b 1
    )
)

rmdir /s /q "%TMP_DIR%"
echo %C_PURPLE%[install_eclipse]%C_SUCCESS% Eclipse installation finished: %TARGET_DIR%%C_RESET%
endlocal

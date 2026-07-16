@echo off
setlocal EnableExtensions EnableDelayedExpansion

call "%~dp0common.bat"
if errorlevel 1 exit /b 1

call "%~dp0common.bat" print_header "installEclipse" "Running Eclipse installation..."

REM Determine MDE4CPP_HOME from script location
set "SCRIPT_DIR=%~dp0"
for %%I in ("%SCRIPT_DIR%..\..") do set "MDE4CPP_HOME=%%~fI"

REM Print requested Eclipse component versions.
echo %C_PURPLE%[installEclipse]%C_ORANGE% MDE4CPP_ECLIPSE_VERSION=!MDE4CPP_ECLIPSE_VERSION!-!MDE4CPP_ECLIPSE_MILESTONE!%C_RESET%
echo %C_PURPLE%[installEclipse]%C_ORANGE% MDE4CPP_ECLIPSE_ACCELEO_VERSION=!MDE4CPP_ECLIPSE_ACCELEO_VERSION!%C_RESET%
echo %C_PURPLE%[installEclipse]%C_ORANGE% MDE4CPP_ECLIPSE_PAPYRUS_VERSION=!MDE4CPP_ECLIPSE_PAPYRUS_VERSION!%C_RESET%
echo %C_PURPLE%[installEclipse]%C_ORANGE% MDE4CPP_ECLIPSE_PAPYRUS_UPDATE_VERSION=!MDE4CPP_ECLIPSE_PAPYRUS_UPDATE_VERSION!%C_RESET%
echo %C_PURPLE%[installEclipse]%C_ORANGE% MDE4CPP_ECLIPSE_SIRIUS_VERSION=!MDE4CPP_ECLIPSE_SIRIUS_VERSION!-!MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION!%C_RESET%

REM Validate required versions.
if "!MDE4CPP_HOME!"=="" (
    echo %C_PURPLE%[installEclipse]%C_ERROR% ERROR: Could not determine MDE4CPP_HOME.%C_RESET%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_VERSION!"=="" (
    echo %C_PURPLE%[installEclipse]%C_ERROR% ERROR: MDE4CPP_ECLIPSE_VERSION not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_MILESTONE!"=="" (
    echo %C_PURPLE%[installEclipse]%C_ERROR% ERROR: MDE4CPP_ECLIPSE_MILESTONE not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_ACCELEO_VERSION!"=="" (
    echo %C_PURPLE%[installEclipse]%C_ERROR% ERROR: MDE4CPP_ECLIPSE_ACCELEO_VERSION not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_SIRIUS_VERSION!"=="" (
    echo %C_PURPLE%[installEclipse]%C_ERROR% ERROR: MDE4CPP_ECLIPSE_SIRIUS_VERSION not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_PAPYRUS_VERSION!"=="" (
    echo %C_PURPLE%[installEclipse]%C_ERROR% ERROR: MDE4CPP_ECLIPSE_PAPYRUS_VERSION not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_PAPYRUS_UPDATE_VERSION!"=="" (
    echo %C_PURPLE%[installEclipse]%C_ERROR% ERROR: MDE4CPP_ECLIPSE_PAPYRUS_UPDATE_VERSION not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION!"=="" (
    echo %C_PURPLE%[installEclipse]%C_ERROR% ERROR: MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)

REM Resolve install locations and download URLs.
for %%I in ("!MDE4CPP_HOME!\..") do set "MDE4CPP_PARENT=%%~fI"
set "TARGET_DIR=!MDE4CPP_PARENT!\eclipse"
set "TMP_DIR=%TEMP%\mde4cpp-eclipse-install"
set "ARCHIVE_PATH=!TMP_DIR!\eclipse-modeling.zip"
set "ECLIPSE_ARCHIVE_URL=https://ftp.halifax.rwth-aachen.de/eclipse/technology/epp/downloads/release/!MDE4CPP_ECLIPSE_VERSION: =!/!MDE4CPP_ECLIPSE_MILESTONE: =!/eclipse-modeling-!MDE4CPP_ECLIPSE_VERSION: =!-!MDE4CPP_ECLIPSE_MILESTONE: =!-win32-x86_64.zip"
set "ACCELEO_REPOSITORY_URL=https://download.eclipse.org/acceleo/updates/releases/!MDE4CPP_ECLIPSE_ACCELEO_VERSION: =!"
set "SIRIUS_REPOSITORY_URL=https://download.eclipse.org/sirius/updates/releases/!MDE4CPP_ECLIPSE_SIRIUS_VERSION: =!/!MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION: =!"
set "PAPYRUS_REPOSITORY_URL=https://download.eclipse.org/modeling/mdt/papyrus/updates/releases/!MDE4CPP_ECLIPSE_PAPYRUS_UPDATE_VERSION: =!"
set "PAPYRUS_DEPENDENCIES_URL=https://download.eclipse.org/releases/!MDE4CPP_ECLIPSE_PAPYRUS_UPDATE_VERSION: =!"
set "CDT_REPOSITORY_URL=https://download.eclipse.org/releases/!MDE4CPP_ECLIPSE_VERSION: =!"

REM Download and extract Eclipse Modeling package.
echo %C_PURPLE%[installEclipse]%C_ORANGE% MDE4CPP_HOME=!MDE4CPP_HOME!%C_RESET%
echo %C_PURPLE%[installEclipse]%C_INFO% Install location=!TARGET_DIR!%C_RESET%
echo %C_PURPLE%[installEclipse]%C_INFO% Temp Installation Dir=!TMP_DIR!%C_RESET%
echo %C_PURPLE%[installEclipse]%C_ORANGE% Using Eclipse version=!MDE4CPP_ECLIPSE_VERSION!, milestone=!MDE4CPP_ECLIPSE_MILESTONE!, Acceleo=!MDE4CPP_ECLIPSE_ACCELEO_VERSION!, Sirius=!MDE4CPP_ECLIPSE_SIRIUS_VERSION!, Papyrus=!MDE4CPP_ECLIPSE_PAPYRUS_VERSION!%C_RESET%

REM Download and extract Eclipse if not already installed.
echo %C_PURPLE%[installEclipse]%C_INFO% Checking existing Eclipse installation...%C_RESET%
set "FRESH_INSTALL=0"
if exist "!TARGET_DIR!\eclipse.exe" (
    echo %C_PURPLE%[installEclipse]%C_SUCCESS% Existing Eclipse installation found at !TARGET_DIR!, skipping download and extraction.%C_RESET%
    if exist "!TMP_DIR!" rmdir /s /q "!TMP_DIR!"
    mkdir "!TMP_DIR!" >nul 2>&1
) else (
    set "FRESH_INSTALL=1"
    echo %C_PURPLE%[installEclipse]%C_INFO% Downloading !ECLIPSE_ARCHIVE_URL!%C_RESET%
    
    if exist "!TMP_DIR!" rmdir /s /q "!TMP_DIR!"
    mkdir "!TMP_DIR!" >nul 2>&1
    if errorlevel 1 (
        echo %C_PURPLE%[installEclipse]%C_ERROR% ERROR: Failed to create temp dir !TMP_DIR!.%C_RESET%
        exit /b 1
    )

    where curl >nul 2>&1
    if errorlevel 1 (
        echo %C_PURPLE%[installEclipse]%C_ERROR% ERROR: curl.exe is required to download files.%C_RESET%
        rmdir /s /q "!TMP_DIR!"
        exit /b 1
    )
    
    curl.exe --output "!ARCHIVE_PATH!" "!ECLIPSE_ARCHIVE_URL!"
    if errorlevel 1 (
        echo %C_PURPLE%[installEclipse]%C_ERROR% ERROR: Download failed.%C_RESET%
        rmdir /s /q "!TMP_DIR!"
        exit /b 1
    )

    echo %C_PURPLE%[installEclipse]%C_SUCCESS% Download finished, extracting archive.%C_RESET%

    if exist "!TARGET_DIR!" rmdir /s /q "!TARGET_DIR!"
    
    where tar >nul 2>&1
    if not errorlevel 1 (
        tar -xzf "!ARCHIVE_PATH!" -C "!MDE4CPP_PARENT!"
        if errorlevel 1 (
            powershell -NoProfile -ExecutionPolicy Bypass -Command ^
                "Expand-Archive -Path '!ARCHIVE_PATH!' -DestinationPath '!MDE4CPP_PARENT!' -Force"
            if errorlevel 1 (
                echo %C_PURPLE%[installEclipse]%C_ERROR% ERROR: Extraction failed.%C_RESET%
                rmdir /s /q "%TMP_DIR%"
                exit /b 1
            )
        )
    ) else (
        powershell -NoProfile -ExecutionPolicy Bypass -Command ^
            "Expand-Archive -Path '%ARCHIVE_PATH%' -DestinationPath '%MDE4CPP_PARENT%' -Force"
        if errorlevel 1 (
            echo %C_PURPLE%[installEclipse]%C_ERROR% ERROR: Extraction failed.%C_RESET%
            rmdir /s /q "%TMP_DIR%"
            exit /b 1
        )
    )
)



set "NEEDS_INSTALL=0"
if "!FRESH_INSTALL!"=="1" (
    set "NEEDS_INSTALL=1"
) else if exist "%TARGET_DIR%\eclipsec.exe" (
    "%TARGET_DIR%\eclipsec.exe" -nosplash -application org.eclipse.equinox.p2.director -listInstalledRoots > "%TMP_DIR%\installed.txt" 2>&1
    
    echo %C_PURPLE%[installEclipse]%C_SUCCESS% Found existing Eclipse plugins:%C_RESET%
    for /f "usebackq tokens=*" %%P in ("%SCRIPT_DIR%..\eclipse_plugins.txt") do (
        set "FOUND_VER="
        for /f "tokens=1,2 delims=/" %%A in ('findstr /b /c:"%%P/" "%TMP_DIR%\installed.txt"') do (
            set "FOUND_VER=%%B"
        )
        if defined FOUND_VER (
            echo %C_PURPLE%[installEclipse]%C_INFO% %%P: !FOUND_VER!%C_RESET%
        ) else (
            echo %C_PURPLE%[installEclipse]%C_INFO% %%P: %C_ERROR%NOT FOUND%C_RESET%
            set "NEEDS_INSTALL=1"
        )
    )
) else (
    set "NEEDS_INSTALL=1"
)

if "!NEEDS_INSTALL!"=="0" (
    echo %C_PURPLE%[installEclipse]%C_SUCCESS% Requested Eclipse plugins are already installed. Skipping.%C_RESET%
    goto :skipInstall
)

echo %C_PURPLE%[installEclipse]%C_INFO% Installing Eclipse plugins ^(Acceleo, Sirius, CDT, Papyrus^)...%C_RESET%

set "PLUGINS="
for /f "usebackq tokens=*" %%P in ("%SCRIPT_DIR%..\eclipse_plugins.txt") do (
    set "PLUGINS=!PLUGINS! -installIU %%P"
)

powershell -NoProfile -ExecutionPolicy Bypass -Command "& \"%TARGET_DIR%\eclipsec.exe\" -nosplash -application org.eclipse.equinox.p2.director -repository \"https://download.eclipse.org/releases/%MDE4CPP_ECLIPSE_VERSION: =%/,%ACCELEO_REPOSITORY_URL%,%SIRIUS_REPOSITORY_URL%,%PAPYRUS_REPOSITORY_URL%,%PAPYRUS_DEPENDENCIES_URL%,%CDT_REPOSITORY_URL%\" !PLUGINS! -destination \"%TARGET_DIR%\" -profileProperties org.eclipse.update.install.features=true -vmargs -Declipse.p2.mirrors=false -Djavax.net.ssl.trustStoreType=WINDOWS-ROOT 2> \"%TMP_DIR%\p2_stderr.log\" | ForEach-Object { [Console]::Out.WriteLine(\"$env:C_PURPLE[installEclipse]$env:C_INFO $_$env:C_RESET\") }; exit $LASTEXITCODE"
if errorlevel 1 (
    echo %C_PURPLE%[installEclipse]%C_ERROR% ERROR: Eclipse plugin installation failed.%C_RESET%
    type "%TMP_DIR%\p2_stderr.log"
    exit /b 1
)

:skipInstall

REM Cleanup and report completion.
rmdir /s /q "%TMP_DIR%"
echo %C_PURPLE%[installEclipse]%C_SUCCESS% Eclipse installation finished: %TARGET_DIR%%C_RESET%
endlocal

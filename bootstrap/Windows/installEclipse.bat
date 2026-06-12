@echo off
setlocal EnableExtensions EnableDelayedExpansion

call "%~dp0common.bat" load_properties
if errorlevel 1 exit /b 1

REM Determine MDE4CPP_HOME from script location
set "SCRIPT_DIR=%~dp0"
for %%I in ("%SCRIPT_DIR%..\..") do set "MDE4CPP_HOME=%%~fI"

REM Print requested Eclipse component versions.
echo %C_INFO%[installEclipse]%C_RESET% MDE4CPP_ECLIPSE_VERSION=!MDE4CPP_ECLIPSE_VERSION!-!MDE4CPP_ECLIPSE_MILESTONE!
echo %C_INFO%[installEclipse]%C_RESET% MDE4CPP_ECLIPSE_ACCELEO_VERSION=!MDE4CPP_ECLIPSE_ACCELEO_VERSION!
echo %C_INFO%[installEclipse]%C_RESET% MDE4CPP_ECLIPSE_SIRIUS_VERSION=!MDE4CPP_ECLIPSE_SIRIUS_VERSION!-!MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION!

REM Validate required versions.
if "!MDE4CPP_HOME!"=="" (
    echo %C_ERROR%[installEclipse] ERROR: Could not determine MDE4CPP_HOME.%C_RESET%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_VERSION!"=="" (
    echo %C_ERROR%[installEclipse] ERROR: MDE4CPP_ECLIPSE_VERSION not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_MILESTONE!"=="" (
    echo %C_ERROR%[installEclipse] ERROR: MDE4CPP_ECLIPSE_MILESTONE not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_ACCELEO_VERSION!"=="" (
    echo %C_ERROR%[installEclipse] ERROR: MDE4CPP_ECLIPSE_ACCELEO_VERSION not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_SIRIUS_VERSION!"=="" (
    echo %C_ERROR%[installEclipse] ERROR: MDE4CPP_ECLIPSE_SIRIUS_VERSION not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION!"=="" (
    echo %C_ERROR%[installEclipse] ERROR: MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION not found in %VERSIONS_FILE%%C_RESET%
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
set "CDT_REPOSITORY_URL=https://download.eclipse.org/releases/!MDE4CPP_ECLIPSE_VERSION: =!"

REM Download and extract Eclipse Modeling package.
echo %C_INFO%[installEclipse]%C_RESET% MDE4CPP_HOME=!MDE4CPP_HOME!
echo %C_INFO%[installEclipse]%C_RESET% Install location=!TARGET_DIR!
echo %C_INFO%[installEclipse]%C_RESET% Temp Installation Dir=!TMP_DIR!
echo %C_INFO%[installEclipse]%C_RESET% Using Eclipse version=!MDE4CPP_ECLIPSE_VERSION!, milestone=!MDE4CPP_ECLIPSE_MILESTONE!, Acceleo=!MDE4CPP_ECLIPSE_ACCELEO_VERSION!, Sirius=!MDE4CPP_ECLIPSE_SIRIUS_VERSION!

REM Download and extract Eclipse if not already installed.
echo %C_INFO%[installEclipse]%C_RESET% Checking existing Eclipse installation...
if exist "!TARGET_DIR!\eclipse.exe" (
    echo %C_INFO%[installEclipse]%C_RESET% Existing Eclipse installation found at !TARGET_DIR!, skipping download and extraction.
    if exist "!TMP_DIR!" rmdir /s /q "!TMP_DIR!"
    mkdir "!TMP_DIR!" >nul 2>&1
) else (
    echo %C_INFO%[installEclipse]%C_RESET% Downloading !ECLIPSE_ARCHIVE_URL!
    
    if exist "!TMP_DIR!" rmdir /s /q "!TMP_DIR!"
    mkdir "!TMP_DIR!" >nul 2>&1
    if errorlevel 1 (
        echo %C_ERROR%[installEclipse] ERROR: Failed to create temp dir !TMP_DIR!.%C_RESET%
        exit /b 1
    )

    where curl >nul 2>&1
    if errorlevel 1 (
        echo %C_ERROR%[installEclipse] ERROR: curl.exe is required to download files.%C_RESET%
        rmdir /s /q "!TMP_DIR!"
        exit /b 1
    )
    
    curl.exe --output "!ARCHIVE_PATH!" "!ECLIPSE_ARCHIVE_URL!"
    if errorlevel 1 (
        echo %C_ERROR%[installEclipse] ERROR: Download failed.%C_RESET%
        rmdir /s /q "!TMP_DIR!"
        exit /b 1
    )

    echo %C_SUCCESS%[installEclipse] Download finished, extracting archive.%C_RESET%

    if exist "!TARGET_DIR!" rmdir /s /q "!TARGET_DIR!"
    
    where tar >nul 2>&1
    if not errorlevel 1 (
        tar -xzf "!ARCHIVE_PATH!" -C "!MDE4CPP_PARENT!"
        if errorlevel 1 (
            powershell -NoProfile -ExecutionPolicy Bypass -Command ^
                "Expand-Archive -Path '!ARCHIVE_PATH!' -DestinationPath '!MDE4CPP_PARENT!' -Force"
            if errorlevel 1 (
                echo %C_ERROR%[installEclipse] ERROR: Extraction failed.%C_RESET%
                rmdir /s /q "%TMP_DIR%"
                exit /b 1
            )
        )
    ) else (
        powershell -NoProfile -ExecutionPolicy Bypass -Command ^
            "Expand-Archive -Path '%ARCHIVE_PATH%' -DestinationPath '%MDE4CPP_PARENT%' -Force"
        if errorlevel 1 (
            echo %C_ERROR%[installEclipse] ERROR: Extraction failed.%C_RESET%
            rmdir /s /q "%TMP_DIR%"
            exit /b 1
        )
    )
)

REM Install Eclipse plugins (Acceleo, Sirius, CDT)

set "NEEDS_INSTALL=0"
dir /b /ad "%TARGET_DIR%\features\org.eclipse.acceleo_*" >nul 2>&1
if errorlevel 1 set "NEEDS_INSTALL=1"
dir /b /ad "%TARGET_DIR%\features\org.eclipse.sirius.aql_*" >nul 2>&1
if errorlevel 1 set "NEEDS_INSTALL=1"
dir /b /ad "%TARGET_DIR%\features\org.eclipse.cdt_*" >nul 2>&1
if errorlevel 1 set "NEEDS_INSTALL=1"

if "!NEEDS_INSTALL!"=="0" (
    echo %C_INFO%[installEclipse]%C_RESET% Requested Eclipse plugins are already installed. Skipping.
    goto :skipInstall
)

echo %C_INFO%[installEclipse]%C_RESET% Installing Eclipse plugins ^(Acceleo, Sirius, CDT^)...

set "PLUGINS="
set "PLUGINS=!PLUGINS! -installIU org.eclipse.acceleo.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.acceleo.ui.interpreter.ocl.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.acceleo.ui.interpreter.completeocl.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.emf.sdk.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.uml2.sdk.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.ocl.all.sdk.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.acceleo.query.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.acceleo.query.source.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.antlr.runtime"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.sirius.common.acceleo.aql"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.sirius.ui.properties"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.sirius.aql.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.sirius.runtime.aql.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.sirius.properties.feature.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.sirius.aql.source.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.sirius.interpreter.feature.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.sirius.interpreter.feature.source.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.sirius.model.feature.source.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.sirius.properties.feature.source.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.sirius.runtime.aql.source.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.sirius.runtime.ide.ui.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.sirius.specifier.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.sirius.specifier.ide.ui.aql.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.sirius.specifier.ide.ui.aql.source.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.sirius.specifier.ide.ui.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.sirius.specifier.ide.ui.source.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.sirius.specifier.properties.feature.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.sirius.specifier.properties.feature.source.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.sirius.specifier.source.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.eef.ext.widgets.reference.feature.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.eef.ext.widgets.reference.feature.source.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.eef.sdk.feature.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.eef.sdk.feature.source.feature.group"
set "PLUGINS=!PLUGINS! -installIU org.eclipse.cdt.feature.group"

"%TARGET_DIR%\eclipsec.exe" ^
     -nosplash -consoleLog ^
     -application org.eclipse.equinox.p2.director ^
     -repository "https://download.eclipse.org/releases/%MDE4CPP_ECLIPSE_VERSION: =%/,%ACCELEO_REPOSITORY_URL%,%SIRIUS_REPOSITORY_URL%,%CDT_REPOSITORY_URL%" ^
     !PLUGINS! ^
     -destination "%TARGET_DIR%" ^
     -profileProperties org.eclipse.update.install.features=true ^
     -vmargs -Declipse.p2.mirrors=false -Djavax.net.ssl.trustStoreType=WINDOWS-ROOT
if errorlevel 1 (
    echo %C_ERROR%[installEclipse] ERROR: Eclipse plugin installation failed.%C_RESET%
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

:skipInstall

REM Cleanup and report completion.
rmdir /s /q "%TMP_DIR%"
echo %C_SUCCESS%[installEclipse] Eclipse installation finished: %TARGET_DIR%%C_RESET%
endlocal

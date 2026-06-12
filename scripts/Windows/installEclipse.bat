@echo off
setlocal EnableExtensions EnableDelayedExpansion

REM Step 1: Find repo root and read Eclipse versions from versions.properties
echo [installEclipse] Reading configuration from versions.properties...
set "SCRIPT_DIR=%~dp0"
for %%I in ("%SCRIPT_DIR%..\..") do set "REPO_ROOT=%%~fI"
set "VERSIONS_FILE=%REPO_ROOT%\versions.properties"

if not exist "%VERSIONS_FILE%" (
    echo [installEclipse] ERROR: versions.properties not found at %VERSIONS_FILE%
    exit /b 1
)

REM Read all Eclipse versions from properties file
for /f "tokens=1,2 delims==" %%A in ('type "%VERSIONS_FILE%" ^| findstr /B /C:"MDE4CPP_ECLIPSE_VERSION"') do (
    set "TEMP_VAL=%%B"
    for /f "tokens=* delims= " %%X in ("!TEMP_VAL!") do set "MDE4CPP_ECLIPSE_VERSION=%%X"
)

for /f "tokens=1,2 delims==" %%A in ('type "%VERSIONS_FILE%" ^| findstr /B /C:"MDE4CPP_ECLIPSE_MILESTONE"') do (
    set "TEMP_VAL=%%B"
    for /f "tokens=* delims= " %%X in ("!TEMP_VAL!") do set "MDE4CPP_ECLIPSE_MILESTONE=%%X"
)

for /f "tokens=1,2 delims==" %%A in ('type "%VERSIONS_FILE%" ^| findstr /B /C:"MDE4CPP_ECLIPSE_ACCELEO_VERSION"') do (
    set "TEMP_VAL=%%B"
    for /f "tokens=* delims= " %%X in ("!TEMP_VAL!") do set "MDE4CPP_ECLIPSE_ACCELEO_VERSION=%%X"
)

for /f "tokens=1,2 delims==" %%A in ('type "%VERSIONS_FILE%" ^| findstr /B /C:"MDE4CPP_ECLIPSE_SIRIUS_VERSION"') do (
    set "TEMP_VAL=%%B"
    for /f "tokens=* delims= " %%X in ("!TEMP_VAL!") do set "MDE4CPP_ECLIPSE_SIRIUS_VERSION=%%X"
)

for /f "tokens=1,2 delims==" %%A in ('type "%VERSIONS_FILE%" ^| findstr /B /C:"MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION"') do (
    set "TEMP_VAL=%%B"
    for /f "tokens=* delims= " %%X in ("!TEMP_VAL!") do set "MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION=%%X"
)

REM Determine MDE4CPP_HOME from script location
for %%I in ("%SCRIPT_DIR%..\..") do set "MDE4CPP_HOME=%%~fI"

REM Print requested Eclipse component versions.
echo [installEclipse] MDE4CPP_ECLIPSE_VERSION=!MDE4CPP_ECLIPSE_VERSION!-!MDE4CPP_ECLIPSE_MILESTONE!
echo [installEclipse] MDE4CPP_ECLIPSE_ACCELEO_VERSION=!MDE4CPP_ECLIPSE_ACCELEO_VERSION!
echo [installEclipse] MDE4CPP_ECLIPSE_SIRIUS_VERSION=!MDE4CPP_ECLIPSE_SIRIUS_VERSION!-!MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION!

REM Validate required versions.
if "!MDE4CPP_HOME!"=="" (
    echo [installEclipse] ERROR: Could not determine MDE4CPP_HOME.
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_VERSION!"=="" (
    echo [installEclipse] ERROR: MDE4CPP_ECLIPSE_VERSION not found in %VERSIONS_FILE%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_MILESTONE!"=="" (
    echo [installEclipse] ERROR: MDE4CPP_ECLIPSE_MILESTONE not found in %VERSIONS_FILE%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_ACCELEO_VERSION!"=="" (
    echo [installEclipse] ERROR: MDE4CPP_ECLIPSE_ACCELEO_VERSION not found in %VERSIONS_FILE%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_SIRIUS_VERSION!"=="" (
    echo [installEclipse] ERROR: MDE4CPP_ECLIPSE_SIRIUS_VERSION not found in %VERSIONS_FILE%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION!"=="" (
    echo [installEclipse] ERROR: MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION not found in %VERSIONS_FILE%
    exit /b 1
)

REM Step 3: Resolve install locations and download URLs.
for %%I in ("!MDE4CPP_HOME!\..") do set "MDE4CPP_PARENT=%%~fI"
set "TARGET_DIR=!MDE4CPP_PARENT!\eclipse"
set "TMP_DIR=%TEMP%\mde4cpp-eclipse-install"
set "ARCHIVE_PATH=!TMP_DIR!\eclipse-modeling.zip"
set "ECLIPSE_ARCHIVE_URL=https://ftp.halifax.rwth-aachen.de/eclipse/technology/epp/downloads/release/!MDE4CPP_ECLIPSE_VERSION: =!/!MDE4CPP_ECLIPSE_MILESTONE: =!/eclipse-modeling-!MDE4CPP_ECLIPSE_VERSION: =!-!MDE4CPP_ECLIPSE_MILESTONE: =!-win32-x86_64.zip"
set "ACCELEO_REPOSITORY_URL=https://download.eclipse.org/acceleo/updates/releases/!MDE4CPP_ECLIPSE_ACCELEO_VERSION: =!"
set "SIRIUS_REPOSITORY_URL=https://download.eclipse.org/sirius/updates/releases/!MDE4CPP_ECLIPSE_SIRIUS_VERSION: =!/!MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION: =!"
set "CDT_REPOSITORY_URL=https://download.eclipse.org/releases/!MDE4CPP_ECLIPSE_VERSION: =!"

REM Step 4: Download and extract Eclipse Modeling package.
echo [installEclipse] MDE4CPP_HOME=!MDE4CPP_HOME!
echo [installEclipse] Install location=!TARGET_DIR!
echo [installEclipse] Temp Installation Dir=!TMP_DIR!
echo [installEclipse] Using Eclipse version=!MDE4CPP_ECLIPSE_VERSION!, milestone=!MDE4CPP_ECLIPSE_MILESTONE!, Acceleo=!MDE4CPP_ECLIPSE_ACCELEO_VERSION!, Sirius=!MDE4CPP_ECLIPSE_SIRIUS_VERSION!

REM Step 4: Download and extract Eclipse if not already installed.
echo [installEclipse] Checking existing Eclipse installation...
if exist "!TARGET_DIR!\eclipse.exe" (
    echo [installEclipse] Existing Eclipse installation found at !TARGET_DIR!, skipping download and extraction.
    if exist "!TMP_DIR!" rmdir /s /q "!TMP_DIR!"
    mkdir "!TMP_DIR!" >nul 2>&1
) else (
    echo [installEclipse] Downloading !ECLIPSE_ARCHIVE_URL!
    
    if exist "!TMP_DIR!" rmdir /s /q "!TMP_DIR!"
    mkdir "!TMP_DIR!" >nul 2>&1
    if errorlevel 1 (
        echo [installEclipse] ERROR: Failed to create temp dir !TMP_DIR!.
        exit /b 1
    )

    where curl >nul 2>&1
    if errorlevel 1 (
        echo [installEclipse] ERROR: curl.exe is required to download files.
        rmdir /s /q "!TMP_DIR!"
        exit /b 1
    )
    
    curl.exe --output "!ARCHIVE_PATH!" "!ECLIPSE_ARCHIVE_URL!"
    if errorlevel 1 (
        echo [installEclipse] ERROR: Download failed.
        rmdir /s /q "!TMP_DIR!"
        exit /b 1
    )

    echo [installEclipse] Download finished, extracting archive.

    if exist "!TARGET_DIR!" rmdir /s /q "!TARGET_DIR!"
    
    where tar >nul 2>&1
    if not errorlevel 1 (
        tar -xzf "!ARCHIVE_PATH!" -C "!MDE4CPP_PARENT!"
        if errorlevel 1 (
            powershell -NoProfile -ExecutionPolicy Bypass -Command ^
                "Expand-Archive -Path '!ARCHIVE_PATH!' -DestinationPath '!MDE4CPP_PARENT!' -Force"
            if errorlevel 1 (
                echo [installEclipse] ERROR: Extraction failed.
                rmdir /s /q "%TMP_DIR%"
                exit /b 1
            )
        )
    ) else (
        powershell -NoProfile -ExecutionPolicy Bypass -Command ^
            "Expand-Archive -Path '%ARCHIVE_PATH%' -DestinationPath '%MDE4CPP_PARENT%' -Force"
        if errorlevel 1 (
            echo [installEclipse] ERROR: Extraction failed.
            rmdir /s /q "%TMP_DIR%"
            exit /b 1
        )
    )
)

REM Step 5: Install Acceleo into Eclipse.

echo [installEclipse] Installing EMF, UML-SDK,OCL and Acceleo from %ACCELEO_REPOSITORY_URL% and https://download.eclipse.org/releases/%MDE4CPP_ECLIPSE_VERSION%/
"%TARGET_DIR%\eclipse.exe" ^
     -nosplash ^
     -application org.eclipse.equinox.p2.director ^
     -repository "https://download.eclipse.org/releases/%MDE4CPP_ECLIPSE_VERSION: =%/,%ACCELEO_REPOSITORY_URL%" ^
     -installIU org.eclipse.acceleo.feature.group ^
     -installIU org.eclipse.acceleo.ui.interpreter.ocl.feature.group ^
     -installIU org.eclipse.acceleo.ui.interpreter.completeocl.feature.group ^
     -installIU org.eclipse.emf.sdk.feature.group ^
     -installIU org.eclipse.uml2.sdk.feature.group ^
     -installIU org.eclipse.ocl.all.sdk.feature.group ^
     -installIU org.eclipse.acceleo.query.feature.group ^
     -installIU org.eclipse.acceleo.query.source.feature.group ^
     -installIU org.antlr.runtime ^
     -destination "%TARGET_DIR%" ^
     -profileProperties org.eclipse.update.install.features=true
 if errorlevel 1 (
     echo [installEclipse] ERROR: Acceleo installation failed.
     rmdir /s /q "%TMP_DIR%"
     exit /b 1
 )

REM to debug use -help to list all options, -list to list all available IUs in the given repositories, -purgeHistory to reduce footprint by purging download history.

REM Step 6: Install Sirius into Eclipse.
echo [installEclipse] Installing Sirius from %SIRIUS_REPOSITORY_URL% 
"%TARGET_DIR%\eclipse.exe" ^
    -nosplash ^
    -application org.eclipse.equinox.p2.director ^
    -repository "%SIRIUS_REPOSITORY_URL%" ^
    -installIU org.eclipse.sirius.common.acceleo.aql ^
    -installIU org.eclipse.sirius.ui.properties ^
    -installIU org.eclipse.sirius.aql.feature.group ^
    -installIU org.eclipse.sirius.common.acceleo.aql ^
    -installIU org.eclipse.sirius.runtime.aql.feature.group ^
    -installIU org.eclipse.sirius.properties.feature.feature.group ^
    -installIU org.eclipse.sirius.aql.source.feature.group ^
    -installIU org.eclipse.sirius.aql.feature.group ^
    -installIU org.eclipse.sirius.interpreter.feature.feature.group ^
    -installIU org.eclipse.sirius.interpreter.feature.source.feature.group ^
    -installIU org.eclipse.sirius.model.feature.source.feature.group ^
    -installIU org.eclipse.sirius.properties.feature.source.feature.group ^
    -installIU org.eclipse.sirius.runtime.aql.source.feature.group ^
    -installIU org.eclipse.sirius.runtime.ide.ui.feature.group ^
    -installIU org.eclipse.sirius.specifier.feature.group ^
    -installIU org.eclipse.sirius.specifier.ide.ui.aql.feature.group ^
    -installIU org.eclipse.sirius.specifier.ide.ui.aql.source.feature.group ^
    -installIU org.eclipse.sirius.specifier.ide.ui.feature.group ^
    -installIU org.eclipse.sirius.specifier.ide.ui.source.feature.group ^
    -installIU org.eclipse.sirius.specifier.properties.feature.feature.group ^
    -installIU org.eclipse.sirius.specifier.properties.feature.source.feature.group ^
    -installIU org.eclipse.sirius.specifier.source.feature.group ^
    -installIU org.eclipse.eef.ext.widgets.reference.feature.feature.group ^
    -installIU org.eclipse.eef.ext.widgets.reference.feature.source.feature.group ^
    -installIU org.eclipse.eef.sdk.feature.feature.group ^
    -installIU org.eclipse.eef.sdk.feature.source.feature.group ^
    -destination "%TARGET_DIR%" ^
    -profileProperties org.eclipse.update.install.features=true 
if errorlevel 1 (
    echo [installEclipse] ERROR: Sirius installation failed.
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

REM -purgeHistory - Purges the profile download history to reduce footprint
REM -roaming: Sets the profile as roaming, allowing the installation to be moved.
REM -list: Lists all available IUs in the given repositories.

REM Step 7: Install CDT into Eclipse.
echo [installEclipse] Installing CDT from %CDT_REPOSITORY_URL%
"%TARGET_DIR%\eclipse.exe" ^
  -nosplash ^
  -application org.eclipse.equinox.p2.director ^
  -repository "%CDT_REPOSITORY_URL%" ^
  -installIU org.eclipse.cdt.feature.group ^
  -destination "%TARGET_DIR%" ^
  -profileProperties org.eclipse.update.install.features=true
if errorlevel 1 (
    echo [installEclipse] ERROR: CDT installation failed.
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

REM Step 8: Cleanup and report completion.
rmdir /s /q "%TMP_DIR%"
echo [installEclipse] Eclipse installation finished: %TARGET_DIR%
endlocal

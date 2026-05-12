@echo off
setlocal EnableExtensions

REM Step 1: Print requested Eclipse component versions.
echo [installEclipse] MDE4CPP_ECLIPSE_VERSION=%MDE4CPP_ECLIPSE_VERSION%
echo [installEclipse] MDE4CPP_ECLIPSE_MILESTONE=%MDE4CPP_ECLIPSE_MILESTONE%
echo [installEclipse] MDE4CPP_ECLIPSE_ACCELEO_VERSION=%MDE4CPP_ECLIPSE_ACCELEO_VERSION%
echo [installEclipse] MDE4CPP_ECLIPSE_SIRIUS_VERSION=%MDE4CPP_ECLIPSE_SIRIUS_VERSION%

REM Step 2: Validate required input variables.
if "%MDE4CPP_HOME%"=="" (
    echo [installEclipse] ERROR: MDE4CPHOME is not set.
    exit /b 1
)
if "%MDE4CPP_ECLIPSE_VERSION%"=="" (
    echo [installEclipse] ERROR: MDE4CPP_ECLIPSE_VERSION is not set.
    exit /b 1
)
if "%MDE4CPP_ECLIPSE_MILESTONE%"=="" (
    echo [installEclipse] ERROR: MDE4CPP_ECLIPSE_MILESTONE is not set.
    exit /b 1
)
if "%MDE4CPP_ECLIPSE_ACCELEO_VERSION%"=="" (
    echo [installEclipse] ERROR: MDE4CPP_ECLIPSE_ACCELEO_VERSION is not set.
    exit /b 1
)
if "%MDE4CPP_ECLIPSE_SIRIUS_VERSION%"=="" (
    echo [installEclipse] ERROR: MDE4CPP_ECLIPSE_SIRIUS_VERSION is not set.
    exit /b 1
)

REM Step 3: Resolve install locations and download URLs.
for %%I in ("%MDE4CPP_HOME%\..") do set "MDE4CPP_PARENT=%%~fI"
set "TARGET_DIR=%MDE4CPP_PARENT%\eclipse"
set "TMP_DIR=%TEMP%\mde4cpp-eclipse-install"
set "ARCHIVE_PATH=%TMP_DIR%\eclipse-modeling.zip"
set "ECLIPSE_ARCHIVE_URL=https://ftp.halifax.rwth-aachen.de/eclipse/technology/epp/downloads/release/%MDE4CPP_ECLIPSE_VERSION: =%/%MDE4CPP_ECLIPSE_MILESTONE: =%/eclipse-modeling-%MDE4CPP_ECLIPSE_VERSION: =%-%MDE4CPP_ECLIPSE_MILESTONE: =%-win32-x86_64.zip"
set "ACCELEO_REPOSITORY_URL=https://download.eclipse.org/acceleo/updates/releases/%MDE4CPP_ECLIPSE_ACCELEO_VERSION: =%"
set "SIRIUS_REPOSITORY_URL=https://download.eclipse.org/sirius/updates/releases/%MDE4CPP_ECLIPSE_SIRIUS_VERSION: =%"
set "CDT_REPOSITORY_URL=https://download.eclipse.org/releases/%MDE4CPP_ECLIPSE_VERSION: =%"

REM Step 4: Download and extract Eclipse Modeling package.
echo [installEclipse] MDE4CPP_HOME=%MDE4CPP_HOME%
echo [installEclipse] Install location=%TARGET_DIR%
echo [installEclipse] Temp Installation Dir=%TMP_DIR%
echo [installEclipse] Using Eclipse version=%MDE4CPP_ECLIPSE_VERSION%, milestone=%MDE4CPP_ECLIPSE_MILESTONE%, Acceleo=%MDE4CPP_ECLIPSE_ACCELEO_VERSION%, Sirius=%MDE4CPP_ECLIPSE_SIRIUS_VERSION%
echo [installEclipse] Downloading %ECLIPSE_ARCHIVE_URL%

if exist "%TMP_DIR%" rmdir /s /q "%TMP_DIR%"
mkdir "%TMP_DIR%" >nul 2>&1
if errorlevel 1 (
    echo [installEclipse] ERROR: Failed to create temp dir %TMP_DIR%.
    exit /b 1
)

REM powershell -NoProfile -ExecutionPolicy Bypass -Command ^ "Invoke-WebRequest -Uri '%ECLIPSE_ARCHIVE_URL%' -OutFile '%ARCHIVE_PATH%'"

powershell -NoProfile -ExecutionPolicy Bypass -Command ^
    "curl.exe --output '%ARCHIVE_PATH%' '%ECLIPSE_ARCHIVE_URL%'"
if errorlevel 1 (
    echo [installEclipse] ERROR: Download failed.
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

echo [installEclipse] Dowload finished, extracting archive.

if exist "%TARGET_DIR%" rmdir /s /q "%TARGET_DIR%"
powershell -NoProfile -ExecutionPolicy Bypass -Command ^
  "Expand-Archive -Path '%ARCHIVE_PATH%' -DestinationPath '%MDE4CPP_PARENT%' -Force"
if errorlevel 1 (
    echo [installEclipse] ERROR: Extraction failed.
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

REM Step 5: Install Acceleo into Eclipse.
REM -nosplash ^
echo [installEclipse] Installing Acceleo from %ACCELEO_REPOSITORY_URL%
"%TARGET_DIR%\eclipse.exe" ^
  -application org.eclipse.equinox.p2.director ^
  -repository "%ACCELEO_REPOSITORY_URL%" ^
  -installIU org.eclipse.acceleo.feature.group ^
  -destination "%TARGET_DIR%" ^
  -profile SDKProfile ^
  -profileProperties org.eclipse.update.install.features=true ^
  -roaming
if errorlevel 1 (
    echo [installEclipse] ERROR: Acceleo installation failed.
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

REM Step 6: Install Sirius into Eclipse.
REM  -nosplash ^
echo [installEclipse] Installing Sirius from %SIRIUS_REPOSITORY_URL%
"%TARGET_DIR%\eclipse.exe" ^
  -application org.eclipse.equinox.p2.director ^
  -repository "%SIRIUS_REPOSITORY_URL%" ^
  -installIU org.eclipse.sirius.feature.group ^
  -destination "%TARGET_DIR%" ^
  -profile SDKProfile ^
  -profileProperties org.eclipse.update.install.features=true ^
  -roaming
if errorlevel 1 (
    echo [installEclipse] ERROR: Sirius installation failed.
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

REM  -nosplash ^
REM Step 7: Install CDT into Eclipse.
echo [installEclipse] Installing CDT from %CDT_REPOSITORY_URL%
"%TARGET_DIR%\eclipse.exe" ^
  -application org.eclipse.equinox.p2.director ^
  -repository "%CDT_REPOSITORY_URL%" ^
  -installIU org.eclipse.cdt.feature.group ^
  -destination "%TARGET_DIR%" ^
  -profile SDKProfile ^
  -profileProperties org.eclipse.update.install.features=true ^
  -roaming
if errorlevel 1 (
    echo [installEclipse] ERROR: CDT installation failed.
    rmdir /s /q "%TMP_DIR%"
    exit /b 1
)

REM Step 8: Cleanup and report completion.
rmdir /s /q "%TMP_DIR%"
echo [installEclipse] Eclipse installation finished: %TARGET_DIR%
endlocal

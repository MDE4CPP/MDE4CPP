@echo off
setlocal EnableExtensions EnableDelayedExpansion

REM Step 1: Find repo root and read Java version from versions.properties
echo [installJava] Reading configuration from versions.properties...
set "SCRIPT_DIR=%~dp0"
for %%I in ("%SCRIPT_DIR%..\..") do set "REPO_ROOT=%%~fI"
set "VERSIONS_FILE=%REPO_ROOT%\versions.properties"

if not exist "%VERSIONS_FILE%" (
    echo [installJava] ERROR: versions.properties not found at %VERSIONS_FILE%
    exit /b 1
)

REM Read MDE4CPP_JAVA_VERSION from properties file
for /f "tokens=1,2 delims==" %%A in ('type "%VERSIONS_FILE%" ^| findstr /B /C:"MDE4CPP_JAVA_VERSION"') do (
    set "TEMP_VAL=%%B"
    for /f "tokens=* delims= " %%X in ("!TEMP_VAL!") do set "MDE4CPP_JAVA_VERSION=%%X"
)

echo [installJava] MDE4CPP_JAVA_VERSION=!MDE4CPP_JAVA_VERSION!
if "!MDE4CPP_JAVA_VERSION!"=="" (
    echo [installJava] ERROR: MDE4CPP_JAVA_VERSION not found in %VERSIONS_FILE%
    exit /b 1
)

REM Step 2: Check if the required Java version is already installed.
set "INSTALLED_MAJOR="
where java >nul 2>&1
if not errorlevel 1 (
    for /f "tokens=*" %%A in ('java -version 2^>^&1 ^| findstr version') do (
        for /f "tokens=1,2 delims=.^" %%B in ('%%A') do (
            if "%%C"=="" (
                set "INSTALLED_MAJOR=%%B"
            ) else (
                set "INSTALLED_MAJOR=%%B"
            )
        )
    )
)

if defined INSTALLED_MAJOR (
    if "%INSTALLED_MAJOR%"=="%MDE4CPP_JAVA_VERSION%" (
        echo [installJava] Java %MDE4CPP_JAVA_VERSION% is already installed. Skipping.
        exit /b 0
    ) else (
        echo [installJava] Found Java %INSTALLED_MAJOR%. Installing Java %MDE4CPP_JAVA_VERSION%.
    )
) else (
    echo [installJava] Java is not installed. Installing Java %MDE4CPP_JAVA_VERSION%.
)

REM Step 3: Request administrator rights only if installation is necessary.
if /I not "%~1"=="--elevated" (
    net session >nul 2>&1
    if errorlevel 1 (
        echo [installJava] Administrator rights are required. Requesting elevation...
        powershell -NoProfile -ExecutionPolicy Bypass -Command "Start-Process cmd.exe -Wait -Verb RunAs -ArgumentList '/c', 'set ""MDE4CPP_JAVA_VERSION=%MDE4CPP_JAVA_VERSION%"" && call ""%~f0"" --elevated'"
        if errorlevel 1 (
            echo [installJava] ERROR: Elevation was cancelled or failed.
            exit /b 1
        )
        exit /b 0
    )
)

REM Step 4: Install requested Microsoft OpenJDK using winget.
where winget >nul 2>&1
if errorlevel 1 (
    echo [installJava] ERROR: winget is not available on this system.
    exit /b 1
)
set "WINGET_ID=Microsoft.OpenJDK.%MDE4CPP_JAVA_VERSION%"
winget install --id "%WINGET_ID%" --exact --accept-source-agreements --accept-package-agreements --silent
if errorlevel 1 (
    echo [installJava] ERROR: Java installation via winget failed.
    exit /b 1
)

REM Step 5: Verify and report installed Java version.
java -version

endlocal

@echo off
setlocal EnableExtensions

REM Step 1: Validate required Java version input.
echo [installJava] MDE4CPP_JAVA_VERSION=%MDE4CPP_JAVA_VERSION%
if "%MDE4CPP_JAVA_VERSION%"=="" (
    echo [installJava] ERROR: MDE4CPP_JAVA_VERSION is not set.
    exit /b 1
)

REM Step 2: Skip installation when requested version is already installed.
set "INSTALLED_MAJOR="
for /f "delims=" %%V in ('powershell -NoProfile -ExecutionPolicy Bypass -Command "$v = java -version 2>&1 | Select-String 'version' | Select-Object -First 1; if ($v -match '\"(\\d+)') { $matches[1] }"') do (
    set "INSTALLED_MAJOR=%%V"
    goto :haveJavaVersion
)
:haveJavaVersion
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

REM Step 3: Ensure the script runs with administrator rights if installation is required.
if /I not "%~1"=="--elevated" (
    net session >nul 2>&1
    if errorlevel 1 (
        echo [installJava] Administrator rights are required. Requesting elevation...
        powershell -NoProfile -ExecutionPolicy Bypass -Command ^
          "Start-Process -FilePath 'cmd.exe' -Verb RunAs -ArgumentList '/c set ""MDE4CPP_JAVA_VERSION=%MDE4CPP_JAVA_VERSION%"" ^&^& call ""%~f0"" --elevated'"
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

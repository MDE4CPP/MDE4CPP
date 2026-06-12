@echo off
setlocal EnableExtensions EnableDelayedExpansion

call "%~dp0common.bat" load_properties
if errorlevel 1 exit /b 1
echo [installJava] MDE4CPP_JAVA_VERSION=!MDE4CPP_JAVA_VERSION!
if "!MDE4CPP_JAVA_VERSION!"=="" (
    echo [installJava] ERROR: MDE4CPP_JAVA_VERSION not found in %VERSIONS_FILE%
    exit /b 1
)

REM Detect existing Java installation using multiple strategies.
set "JAVA_EXE="

REM Read JAVA_HOME from system registry
for /f "tokens=2*" %%A in ('reg query "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v JAVA_HOME 2^>nul ^| findstr /I "JAVA_HOME"') do (
    if exist "%%B\bin\java.exe" (
        set "JAVA_EXE=%%B\bin\java.exe"
        echo [installJava] Found Java via registry: %%B
    )
)

REM Scan common installation directories
if not defined JAVA_EXE (
    for %%V in ("Microsoft" "Eclipse Adoptium" "Java") do (
        if not defined JAVA_EXE (
            for /d %%I in ("%ProgramFiles%\%%~V\jdk-!MDE4CPP_JAVA_VERSION!*") do (
                if exist "%%~fI\bin\java.exe" (
                    set "JAVA_EXE=%%~fI\bin\java.exe"
                    echo [installJava] Found Java at: %%~fI
                )
            )
        )
    )
)

REM Check current PATH
if not defined JAVA_EXE (
    where java >nul 2>&1
    if not errorlevel 1 (
        for /f "delims=" %%P in ('where java') do set "JAVA_EXE=%%P"
    )
)

REM Parse the major version from the discovered Java executable
set "INSTALLED_MAJOR="
if defined JAVA_EXE (
    for /f "tokens=3" %%A in ('""!JAVA_EXE!" -version 2^>^&1 ^| findstr /I "version""') do (
        for /f "tokens=1 delims=." %%B in ("%%~A") do (
            if not defined INSTALLED_MAJOR set "INSTALLED_MAJOR=%%B"
        )
    )
)

if defined INSTALLED_MAJOR (
    if "!INSTALLED_MAJOR!"=="!MDE4CPP_JAVA_VERSION!" (
        echo [installJava] Java !MDE4CPP_JAVA_VERSION! is already installed. Skipping.
        exit /b 0
    )
    echo [installJava] Found Java !INSTALLED_MAJOR! but need !MDE4CPP_JAVA_VERSION!.
) else (
    echo [installJava] Java !MDE4CPP_JAVA_VERSION! not detected. Installing.
)

REM Install with elevation.
REM Elevated processes cannot access mapped network drives (e.g. Z:), so we write
REM the install commands to a temp script on the local drive instead of calling back
REM to this script via %~f0.
net session >nul 2>&1
if errorlevel 1 (
    echo [installJava] Administrator rights are required. Requesting elevation...
    set "ELEVATE_BAT=%TEMP%\mde4cpp-install-java.bat"
    (
        echo @echo off
        echo echo [installJava] Installing Microsoft.OpenJDK.!MDE4CPP_JAVA_VERSION! via winget...
        echo winget install --id "Microsoft.OpenJDK.!MDE4CPP_JAVA_VERSION!" --exact --accept-source-agreements --accept-package-agreements --silent
        echo if errorlevel 1 ^(
        echo     echo [installJava] ERROR: winget install failed.
        echo     exit /b 1
        echo ^)
        echo echo [installJava] Installation completed.
    ) > "!ELEVATE_BAT!"

    powershell -NoProfile -ExecutionPolicy Bypass -Command "Start-Process '!ELEVATE_BAT!' -Wait -Verb RunAs"
    set "ELEV_ERR=!errorlevel!"
    del "!ELEVATE_BAT!" >nul 2>&1

    if not "!ELEV_ERR!"=="0" (
        echo [installJava] ERROR: Elevation was cancelled or failed.
        exit /b 1
    )
    goto :verify
)

REM Already running elevated — run winget directly
echo [installJava] Running winget install...
winget install --id "Microsoft.OpenJDK.!MDE4CPP_JAVA_VERSION!" --exact --accept-source-agreements --accept-package-agreements --silent
if errorlevel 1 (
    echo [installJava] ERROR: winget install failed.
    exit /b 1
)

:verify
REM Verify installation succeeded.
set "VERIFY_JAVA="
for /f "tokens=2*" %%A in ('reg query "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v JAVA_HOME 2^>nul ^| findstr /I "JAVA_HOME"') do (
    if exist "%%B\bin\java.exe" set "VERIFY_JAVA=%%B"
)
if not defined VERIFY_JAVA (
    for /d %%I in ("%ProgramFiles%\Microsoft\jdk-!MDE4CPP_JAVA_VERSION!*") do (
        if exist "%%~fI\bin\java.exe" set "VERIFY_JAVA=%%~fI"
    )
)
if defined VERIFY_JAVA (
    echo [installJava] Verified: Java installed at !VERIFY_JAVA!
    "!VERIFY_JAVA!\bin\java.exe" -version 2>&1
    exit /b 0
)

echo [installJava] ERROR: Java installation could not be verified.
echo [installJava] --- Diagnostics ---
echo [installJava] ProgramFiles=%ProgramFiles%
if exist "%ProgramFiles%\Microsoft" (
    echo [installJava] Contents of "%ProgramFiles%\Microsoft":
    dir /b /ad "%ProgramFiles%\Microsoft" 2>nul | findstr /I "jdk"
    if errorlevel 1 echo [installJava]   ^(no jdk directories^)
) else (
    echo [installJava]   "%ProgramFiles%\Microsoft" does not exist
)
reg query "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v JAVA_HOME 2>nul
if errorlevel 1 echo [installJava]   JAVA_HOME not in system registry
echo [installJava] --- End diagnostics ---
exit /b 1

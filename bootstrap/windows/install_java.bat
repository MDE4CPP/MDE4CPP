@echo off
setlocal EnableExtensions EnableDelayedExpansion

call "%~dp0common.bat"
if errorlevel 1 exit /b 1

call "%~dp0common.bat" print_header "installJava" "Running Java installation..."

echo %C_PURPLE%[installJava]%C_ORANGE% MDE4CPP_JAVA_VERSION=!MDE4CPP_JAVA_VERSION!%C_RESET%
if "!MDE4CPP_JAVA_VERSION!"=="" (
    echo %C_PURPLE%[installJava]%C_ERROR% ERROR: MDE4CPP_JAVA_VERSION not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)

REM Detect existing Java installation using multiple strategies.
set "JAVA_EXE="

REM Read JAVA_HOME from system registry
for /f "tokens=2*" %%A in ('reg query "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v JAVA_HOME 2^>nul ^| findstr /I "JAVA_HOME"') do (
    if exist "%%B\bin\java.exe" (
        set "JAVA_EXE=%%B\bin\java.exe"
        echo %C_PURPLE%[installJava]%C_INFO% Found Java via registry: %%B%C_RESET%
    )
)

REM Scan common installation directories
if not defined JAVA_EXE (
    for %%V in ("Microsoft" "Eclipse Adoptium" "Java") do (
        if not defined JAVA_EXE (
            for /d %%I in ("%ProgramFiles%\%%~V\jdk-!MDE4CPP_JAVA_VERSION!*") do (
                if exist "%%~fI\bin\java.exe" (
                    set "JAVA_EXE=%%~fI\bin\java.exe"
                    echo %C_PURPLE%[installJava]%C_INFO% Found Java at: %%~fI%C_RESET%
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
set "EXPORT_JAVA_HOME="
if defined JAVA_EXE (
    for %%J in ("!JAVA_EXE!\..\..") do set "EXPORT_JAVA_HOME=%%~fJ"
    for /f "tokens=3" %%A in ('""!JAVA_EXE!" -version 2^>^&1 ^| findstr /I "version""') do (
        for /f "tokens=1 delims=." %%B in ("%%~A") do (
            if not defined INSTALLED_MAJOR set "INSTALLED_MAJOR=%%B"
        )
    )
)

if defined INSTALLED_MAJOR (
    if "!INSTALLED_MAJOR!"=="!MDE4CPP_JAVA_VERSION!" (
        echo %C_PURPLE%[installJava]%C_SUCCESS% Java !MDE4CPP_JAVA_VERSION! is already installed. Skipping.%C_RESET%
        endlocal & set "JAVA_HOME=%EXPORT_JAVA_HOME%" & exit /b 0
    )
    echo %C_PURPLE%[installJava]%C_SUCCESS% Found Java !INSTALLED_MAJOR! but need !MDE4CPP_JAVA_VERSION!.%C_RESET%
) else (
    echo %C_PURPLE%[installJava]%C_INFO% Java !MDE4CPP_JAVA_VERSION! not detected. Installing.%C_RESET%
)

REM Install with elevation.
REM Elevated processes cannot access mapped network drives (e.g. Z:), so we write
REM the install commands to a temp script on the local drive instead of calling back
REM to this script via %~f0.
net session >nul 2>&1
if errorlevel 1 (
    echo %C_PURPLE%[installJava]%C_INFO% Administrator rights are required. Requesting elevation...%C_RESET%
    set "ELEVATE_BAT=%TEMP%\mde4cpp-install-java.bat"
    (
        echo @echo off
        echo echo [installJava] Installing Microsoft.OpenJDK.!MDE4CPP_JAVA_VERSION! via winget...
        echo winget install --id "Microsoft.OpenJDK.!MDE4CPP_JAVA_VERSION!" --exact --accept-source-agreements --accept-package-agreements --silent
        echo if errorlevel 1 ^(
        echo %C_ERROR%    echo [installJava] ERROR: winget install failed.%C_RESET%
        echo     exit /b 1
        echo ^)
        echo echo [installJava] Installation completed.
    ) > "!ELEVATE_BAT!"

    powershell -NoProfile -ExecutionPolicy Bypass -Command "Start-Process '!ELEVATE_BAT!' -Wait -Verb RunAs"
    set "ELEV_ERR=!errorlevel!"
    del "!ELEVATE_BAT!" >nul 2>&1

    if not "!ELEV_ERR!"=="0" (
        echo %C_PURPLE%[installJava]%C_ERROR% ERROR: Elevation was cancelled or failed.%C_RESET%
        exit /b 1
    )
    goto :verify
)

REM Already running elevated — run winget directly
echo [installJava] Running winget install...
winget install --id "Microsoft.OpenJDK.!MDE4CPP_JAVA_VERSION!" --exact --accept-source-agreements --accept-package-agreements --silent
if errorlevel 1 (
    echo %C_PURPLE%[installJava]%C_ERROR% ERROR: winget install failed.%C_RESET%
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
    echo %C_PURPLE%[installJava]%C_SUCCESS% Verified: Java installed at !VERIFY_JAVA!%C_RESET%
    "!VERIFY_JAVA!\bin\java.exe" -version 2>&1
    endlocal & set "JAVA_HOME=%VERIFY_JAVA%" & exit /b 0
)

echo %C_PURPLE%[installJava]%C_ERROR% ERROR: Java installation could not be verified.%C_RESET%
echo [installJava] --- Diagnostics ---
echo %C_PURPLE%[installJava]%C_INFO% ProgramFiles=%ProgramFiles%%C_RESET%
if exist "%ProgramFiles%\Microsoft" (
    echo %C_PURPLE%[installJava]%C_INFO% Contents of "%ProgramFiles%\Microsoft":%C_RESET%
    dir /b /ad "%ProgramFiles%\Microsoft" 2>nul | findstr /I "jdk"
    if errorlevel 1 echo [installJava]   ^(no jdk directories^)
) else (
    echo %C_PURPLE%[installJava]%C_INFO% "%ProgramFiles%\Microsoft" does not exist%C_RESET%
)
reg query "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v JAVA_HOME 2>nul
if errorlevel 1 echo [installJava]   JAVA_HOME not in system registry
echo [installJava] --- End diagnostics ---
exit /b 1

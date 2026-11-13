@echo off
setlocal EnableExtensions EnableDelayedExpansion

call "%~dp0common.bat"
if errorlevel 1 exit /b 1

call "%~dp0common.bat" print_header "installJava" "Running Java installation..."

echo %C_PURPLE%[install_java]%C_ORANGE% MDE4CPP_JAVA_VERSION=!MDE4CPP_JAVA_VERSION!%C_RESET%
if "!MDE4CPP_JAVA_VERSION!"=="" (
    echo %C_PURPLE%[install_java]%C_ERROR% ERROR: MDE4CPP_JAVA_VERSION is not set.%C_RESET%
    exit /b 1
)

REM Detect existing Java installation using multiple strategies.
set "JAVA_EXE="

REM Read JAVA_HOME from system registry
for /f "tokens=2*" %%A in ('reg query "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v JAVA_HOME 2^>nul ^| findstr /I "JAVA_HOME"') do (
    if exist "%%B\bin\java.exe" (
        set "JAVA_EXE=%%B\bin\java.exe"
        echo %C_PURPLE%[install_java]%C_INFO% Found Java via registry: %%B%C_RESET%
    )
)

REM Scan common installation directories
if not defined JAVA_EXE (
    for %%V in ("Eclipse Adoptium" "Java") do (
        if not defined JAVA_EXE (
            for /d %%I in ("%ProgramFiles%\%%~V\jdk-!MDE4CPP_JAVA_VERSION!*") do (
                if exist "%%~fI\bin\java.exe" (
                    set "JAVA_EXE=%%~fI\bin\java.exe"
                    echo %C_PURPLE%[install_java]%C_INFO% Found Java at: %%~fI%C_RESET%
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
        echo %C_PURPLE%[install_java]%C_SUCCESS% Java !MDE4CPP_JAVA_VERSION! is already installed. Skipping.%C_RESET%
        endlocal & set "JAVA_HOME=%EXPORT_JAVA_HOME%" & exit /b 0
    )
    echo %C_PURPLE%[install_java]%C_SUCCESS% Found Java !INSTALLED_MAJOR! but need !MDE4CPP_JAVA_VERSION!.%C_RESET%
) else (
    echo %C_PURPLE%[install_java]%C_INFO% Java !MDE4CPP_JAVA_VERSION! not detected. Installing.%C_RESET%
)

REM Install with elevation.
REM Elevated processes cannot access mapped network drives (e.g. Z:), so we write
REM the install commands to a temp script on the local drive instead of calling back
REM to this script via %~f0.
set "ECLIPSE_TEMURIN_URL=https://api.adoptium.net/v3/binary/latest/!MDE4CPP_JAVA_VERSION!/ga/windows/x64/jdk/hotspot/normal/eclipse"
set "JAVA_TARGET_BASE=%ProgramFiles%\Eclipse Adoptium"

net session >nul 2>&1
if errorlevel 1 (
    echo %C_PURPLE%[install_java]%C_INFO% Administrator rights are required. Requesting elevation...%C_RESET%
    set "ELEVATE_BAT=%TEMP%\mde4cpp-install-java.bat"
    (
        echo @echo off
        echo setlocal EnableExtensions EnableDelayedExpansion
        echo set "TMP_DIR=%%TEMP%%\mde4cpp-java-install"
        echo set "ARCHIVE_PATH=!TMP_DIR!\openjdk.zip"
        echo set "ECLIPSE_TEMURIN_URL=%ECLIPSE_TEMURIN_URL%"
        echo set "JAVA_TARGET_BASE=%JAVA_TARGET_BASE%"
        echo echo [install_java] Fetching Eclipse Temurin JDK !MDE4CPP_JAVA_VERSION! archive...
        echo if exist "!TMP_DIR!" rmdir /s /q "!TMP_DIR!"
        echo mkdir "!TMP_DIR!" ^>nul 2^>^&1
        echo curl.exe -fL --output "!ARCHIVE_PATH!" "!ECLIPSE_TEMURIN_URL!"
        echo if errorlevel 1 ^(
        echo ^    echo [install_java] ERROR: Java download failed.
        echo ^    exit /b 1
        echo ^)
        echo if not exist "!JAVA_TARGET_BASE!" mkdir "!JAVA_TARGET_BASE!" ^>nul 2^>^&1
        echo powershell -NoProfile -ExecutionPolicy Bypass -Command "Expand-Archive -Path '!ARCHIVE_PATH!' -DestinationPath '!JAVA_TARGET_BASE!' -Force"
        echo if errorlevel 1 ^(
        echo ^    echo [install_java] ERROR: Java archive extraction failed.
        echo ^    exit /b 1
        echo ^)
        echo rmdir /s /q "!TMP_DIR!" ^>nul 2^>^&1
        echo echo [install_java] Installation completed.
        echo endlocal
    ) > "!ELEVATE_BAT!"

    powershell -NoProfile -ExecutionPolicy Bypass -Command "Start-Process '!ELEVATE_BAT!' -Wait -Verb RunAs"
    set "ELEV_ERR=!errorlevel!"
    del "!ELEVATE_BAT!" >nul 2>&1

    if not "!ELEV_ERR!"=="0" (
        echo %C_PURPLE%[install_java]%C_ERROR% ERROR: Elevation was cancelled or failed.%C_RESET%
        exit /b 1
    )
    goto :verify
)

REM Already running elevated — install directly from Eclipse Temurin archive
set "TMP_DIR=%TEMP%\mde4cpp-java-install"
set "ARCHIVE_PATH=%TMP_DIR%\openjdk.zip"
echo [install_java] Fetching Eclipse Temurin JDK !MDE4CPP_JAVA_VERSION! archive...
if exist "%TMP_DIR%" rmdir /s /q "%TMP_DIR%"
mkdir "%TMP_DIR%" >nul 2>&1
curl.exe -fL --output "%ARCHIVE_PATH%" "%ECLIPSE_TEMURIN_URL%"
if errorlevel 1 (
    echo %C_PURPLE%[install_java]%C_ERROR% ERROR: Java download failed.%C_RESET%
    exit /b 1
)
if not exist "%JAVA_TARGET_BASE%" mkdir "%JAVA_TARGET_BASE%" >nul 2>&1
powershell -NoProfile -ExecutionPolicy Bypass -Command "Expand-Archive -Path '%ARCHIVE_PATH%' -DestinationPath '%JAVA_TARGET_BASE%' -Force"
if errorlevel 1 (
    echo %C_PURPLE%[install_java]%C_ERROR% ERROR: Java archive extraction failed.%C_RESET%
    rmdir /s /q "%TMP_DIR%" >nul 2>&1
    exit /b 1
)
rmdir /s /q "%TMP_DIR%" >nul 2>&1

:verify
REM Verify installation succeeded.
set "VERIFY_JAVA="
for /f "tokens=2*" %%A in ('reg query "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v JAVA_HOME 2^>nul ^| findstr /I "JAVA_HOME"') do (
    if exist "%%B\bin\java.exe" set "VERIFY_JAVA=%%B"
)
if not defined VERIFY_JAVA (
    for /d %%I in ("%ProgramFiles%\Eclipse Adoptium\jdk-!MDE4CPP_JAVA_VERSION!*") do (
        if exist "%%~fI\bin\java.exe" set "VERIFY_JAVA=%%~fI"
    )
)
if defined VERIFY_JAVA (
    echo %C_PURPLE%[install_java]%C_SUCCESS% Verified: Java installed at !VERIFY_JAVA!%C_RESET%
    "!VERIFY_JAVA!\bin\java.exe" -version 2>&1
    endlocal & set "JAVA_HOME=%VERIFY_JAVA%" & exit /b 0
)

echo %C_PURPLE%[install_java]%C_ERROR% ERROR: Java installation could not be verified.%C_RESET%
echo [install_java] --- Diagnostics ---
echo %C_PURPLE%[install_java]%C_INFO% ProgramFiles=%ProgramFiles%%C_RESET%
if exist "%ProgramFiles%\Eclipse Adoptium" (
    echo %C_PURPLE%[install_java]%C_INFO% Contents of "%ProgramFiles%\Eclipse Adoptium":%C_RESET%
    dir /b /ad "%ProgramFiles%\Eclipse Adoptium" 2>nul | findstr /I "jdk"
    if errorlevel 1 echo [install_java]   ^(no jdk directories^)
) else (
    echo %C_PURPLE%[install_java]%C_INFO% "%ProgramFiles%\Eclipse Adoptium" does not exist%C_RESET%
)
reg query "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v JAVA_HOME 2>nul
if errorlevel 1 echo [install_java]   JAVA_HOME not in system registry
echo [install_java] --- End diagnostics ---
exit /b 1

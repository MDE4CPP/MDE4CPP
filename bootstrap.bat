@echo off
setlocal EnableExtensions EnableDelayedExpansion

REM ############################################
REM Bootstrap script for MDE4CPP installation
REM ############################################
REM This script runs independently of Gradle to:
REM   1. Check for existing tool installations
REM   2. Ask user to use existing or provide new paths
REM   3. Create setenv.bat with detected/selected paths
REM   4. Run install scripts (which read versions directly)
REM   5. Source setenv and run Gradle install
REM ############################################

echo [bootstrap] MDE4CPP Bootstrap Script for Windows
echo [bootstrap] Starting setup...

REM Get the directory where this script is located
set "SCRIPT_DIR=%~dp0"
set "VERSIONS_FILE=%SCRIPT_DIR%versions.properties"
set "SETENV_FILE=%SCRIPT_DIR%setenv.bat"

REM Check if versions.properties exists
if not exist "%VERSIONS_FILE%" (
    echo [bootstrap] ERROR: versions.properties not found at %VERSIONS_FILE%
    exit /b 1
)

echo [bootstrap] versions.properties found at %VERSIONS_FILE%

REM Step 1: Detect existing tool installations
echo.
echo [bootstrap] Checking for existing tool installations...
echo.

call :detectAndPromptTools
if errorlevel 1 (
    echo [bootstrap] ERROR: Failed to detect/prompt for tools
    exit /b 1
)

REM Step 2: Create setenv.bat if it doesn't exist
if not exist "%SETENV_FILE%" (
    echo.
    echo [bootstrap] Creating setenv.bat with detected paths...
    call :createSetenvFromPaths "%SETENV_FILE%"
    if errorlevel 1 (
        echo [bootstrap] ERROR: Failed to create setenv.bat
        exit /b 1
    )
    echo [bootstrap] setenv.bat created successfully
) else (
    echo [bootstrap] setenv.bat already exists, skipping creation
)

REM Step 3: Run install scripts
REM Note: Each install script reads versions directly from versions.properties
REM       so no environment variables need to be set here
echo [bootstrap] Installing required tools...

REM Install Java
echo [bootstrap] Installing Java...
call "%SCRIPT_DIR%scripts\Windows\installJava.bat"
if errorlevel 1 (
    echo [bootstrap] WARNING: Java installation failed or was skipped
) else (
    echo [bootstrap] Java installation completed
)

REM Install C++ Compiler
echo [bootstrap] Installing C++ Compiler...
call "%SCRIPT_DIR%scripts\Windows\installCompiler.bat"
if errorlevel 1 (
    echo [bootstrap] WARNING: Compiler installation failed or was skipped
) else (
    echo [bootstrap] Compiler installation completed
)

REM Install CMake
echo [bootstrap] Installing CMake...
call "%SCRIPT_DIR%scripts\Windows\installCMake.bat"
if errorlevel 1 (
    echo [bootstrap] WARNING: CMake installation failed or was skipped
) else (
    echo [bootstrap] CMake installation completed
)

REM Install Eclipse
echo [bootstrap] Installing Eclipse...
call "%SCRIPT_DIR%scripts\Windows\installEclipse.bat"
if errorlevel 1 (
    echo [bootstrap] WARNING: Eclipse installation failed or was skipped
) else (
    echo [bootstrap] Eclipse installation completed
)

echo [bootstrap] Bootstrap completed successfully

REM Step 4: Configure environment and run Gradle install
if exist "%SETENV_FILE%" (
    echo [bootstrap] Running setenv.bat to configure environment...
    call "%SETENV_FILE%"
    if errorlevel 1 (
        echo [bootstrap] WARNING: setenv.bat returned an error
    )
) else (
    echo [bootstrap] WARNING: %SETENV_FILE% not found, skipping environment setup
)

REM Run the Gradle install task using the project wrapper
echo [bootstrap] Running Gradle install via application\tools\gradlew.bat
call "%SCRIPT_DIR%application\tools\gradlew.bat" install --no-daemon
if errorlevel 1 (
    echo [bootstrap] ERROR: Gradle install task failed
    exit /b 1
)

echo [bootstrap] Bootstrap and install completed successfully
exit /b 0

REM ############################################
REM Functions
REM ############################################

REM detectAndPromptTools: detect existing tools and prompt user for paths
:detectAndPromptTools
setlocal EnableExtensions EnableDelayedExpansion

REM Initialize paths with defaults
set "JAVA_HOME_FINAL=C:\Program Files\java\jdk-21"
set "CMAKE_HOME_FINAL=C:\tools\CMake"
set "COMPILER_HOME_FINAL=C:\tools\MinGW"
set "ECLIPSE_HOME_FINAL=%SCRIPT_DIR:~0,-1%\..\eclipse"

REM Detect Java
echo [bootstrap] Detecting Java...
where java >nul 2>&1
if not errorlevel 1 (
    for /f "tokens=*" %%A in ('java -version 2^>^&1 ^| findstr version') do set "JAVA_INFO=%%A"
    echo [bootstrap]   Found: !JAVA_INFO!
    set /p USER_CHOICE="             Use existing Java? (Y/n) or enter new path: "
    if /i not "!USER_CHOICE!"=="n" (
        if "!USER_CHOICE!"=="" (
            echo [bootstrap]   Using existing Java
            for /f "tokens=*" %%A in ('where java') do set "JAVA_BIN=%%A"
            for %%I in ("!JAVA_BIN!") do for %%J in ("%%~dpI.") do set "JAVA_HOME_FINAL=%%~dpJ"
        ) else (
            set "JAVA_HOME_FINAL=!USER_CHOICE!"
        )
    ) else (
        set /p JAVA_HOME_FINAL="             Enter Java home path: "
    )
) else (
    echo [bootstrap]   Java not found
    set /p JAVA_HOME_FINAL="             Enter Java home path [C:\Program Files\java\jdk-21]: "
    if "!JAVA_HOME_FINAL!"=="" set "JAVA_HOME_FINAL=C:\Program Files\java\jdk-21"
)
echo [bootstrap]   Java path set to: !JAVA_HOME_FINAL!
echo.

REM Detect CMake
echo [bootstrap] Detecting CMake...
where cmake >nul 2>&1
if not errorlevel 1 (
    for /f "tokens=*" %%A in ('cmake --version 2^>nul ^| findstr cmake') do set "CMAKE_INFO=%%A"
    echo [bootstrap]   Found: !CMAKE_INFO!
    set /p USER_CHOICE="             Use existing CMake? (Y/n) or enter new path: "
    if /i not "!USER_CHOICE!"=="n" (
        if "!USER_CHOICE!"=="" (
            echo [bootstrap]   Using existing CMake
            for /f "tokens=*" %%A in ('where cmake') do set "CMAKE_BIN=%%A"
            for %%I in ("!CMAKE_BIN!") do for %%J in ("%%~dpI.") do set "CMAKE_HOME_FINAL=%%~dpJ"
        ) else (
            set "CMAKE_HOME_FINAL=!USER_CHOICE!"
        )
    ) else (
        set /p CMAKE_HOME_FINAL="             Enter CMake home path: "
    )
) else (
    echo [bootstrap]   CMake not found
    set /p CMAKE_HOME_FINAL="             Enter CMake home path [C:\tools\CMake]: "
    if "!CMAKE_HOME_FINAL!"=="" set "CMAKE_HOME_FINAL=C:\tools\CMake"
)
echo [bootstrap]   CMake path set to: !CMAKE_HOME_FINAL!
echo.

REM Detect C++ Compiler (g++ or gcc)
echo [bootstrap] Detecting C++ Compiler...
where g++ >nul 2>&1
if not errorlevel 1 (
    for /f "tokens=*" %%A in ('g++ --version 2^>nul ^| findstr g++') do set "COMPILER_INFO=%%A"
    echo [bootstrap]   Found: !COMPILER_INFO!
    for /f "tokens=3" %%V in ('g++ --version 2^>nul ^| findstr g++') do set "COMPILER_VERSION_DETECTED=%%V"
    set /p USER_CHOICE="             Use existing compiler? (Y/n) or enter new path: "
    if /i not "!USER_CHOICE!"=="n" (
        if "!USER_CHOICE!"=="" (
            echo [bootstrap]   Using existing compiler
            for /f "tokens=*" %%A in ('where g++') do set "COMPILER_BIN=%%A"
            for %%I in ("!COMPILER_BIN!") do for %%J in ("%%~dpI.") do set "COMPILER_HOME_FINAL=%%~dpJ"
        ) else (
            set "COMPILER_HOME_FINAL=!USER_CHOICE!"
        )
    ) else (
        set /p COMPILER_HOME_FINAL="             Enter compiler home path: "
    )
) else (
    echo [bootstrap]   C++ compiler not found
    set /p COMPILER_HOME_FINAL="             Enter compiler home path [C:\tools\MinGW]: "
    if "!COMPILER_HOME_FINAL!"=="" set "COMPILER_HOME_FINAL=C:\tools\MinGW"
)
if not defined COMPILER_VERSION_DETECTED set "COMPILER_VERSION_DETECTED=8.1.0"
echo [bootstrap]   Compiler path set to: !COMPILER_HOME_FINAL!
echo [bootstrap]   Compiler version: !COMPILER_VERSION_DETECTED!
echo.

REM Detect Eclipse
echo [bootstrap] Detecting Eclipse...
where eclipse >nul 2>&1
if not errorlevel 1 (
    echo [bootstrap]   Found in PATH
    set /p USER_CHOICE="             Use existing Eclipse? (Y/n) or enter new path: "
    if /i not "!USER_CHOICE!"=="n" (
        if "!USER_CHOICE!"=="" (
            echo [bootstrap]   Using existing Eclipse
            for /f "tokens=*" %%A in ('where eclipse') do set "ECLIPSE_BIN=%%A"
            for %%I in ("!ECLIPSE_BIN!") do set "ECLIPSE_HOME_FINAL=%%~dpI"
        ) else (
            set "ECLIPSE_HOME_FINAL=!USER_CHOICE!"
        )
    ) else (
        set /p ECLIPSE_HOME_FINAL="             Enter Eclipse home path: "
    )
) else (
    echo [bootstrap]   Eclipse not found in PATH
    set /p ECLIPSE_HOME_FINAL="             Enter Eclipse home path [parent\eclipse]: "
    if "!ECLIPSE_HOME_FINAL!"=="" (
        for %%I in ("%SCRIPT_DIR:~0,-1%\..") do set "ECLIPSE_HOME_FINAL=%%~fI\eclipse"
    )
)
echo [bootstrap]   Eclipse path set to: !ECLIPSE_HOME_FINAL!
echo.

REM Store in global variables for later use
endlocal & set "JAVA_HOME_FINAL=%JAVA_HOME_FINAL%" & set "CMAKE_HOME_FINAL=%CMAKE_HOME_FINAL%" & set "COMPILER_HOME_FINAL=%COMPILER_HOME_FINAL%" & set "ECLIPSE_HOME_FINAL=%ECLIPSE_HOME_FINAL%" & set "COMPILER_VERSION_DETECTED=%COMPILER_VERSION_DETECTED%"
exit /b 0

REM createSetenvFromPaths: creates setenv.bat with collected paths
:createSetenvFromPaths
setlocal EnableExtensions EnableDelayedExpansion
set "SETENV_PATH=%~1"

(
    echo @echo off
    echo.
    echo REM ########################################
    echo REM # Environment configuration of MDE4CPP #
    echo REM # Generated by bootstrap.bat           #
    echo REM ########################################
    echo.
    echo REM path to MDE4CPP home folder
    echo SET MDE4CPP_HOME=%%cd%%
    echo.
    echo REM path to eclipse home folder including Acceleo plugins
    echo REM required for creating the generators
    echo SET MDE4CPP_ECLIPSE_HOME="!ECLIPSE_HOME_FINAL!"
    echo.
    echo REM ##################################################
    echo REM # configure Gradle tasks and compiling processes #
    echo REM ##################################################
    echo.
    echo REM enable parallel execution of Gradle tasks permanently with value 'true', otherwise 'false'
    echo SET GRADLE_OPTS=-Dorg.gradle.parallel=true
    echo.
    echo REM configure count of worker for each compile task
    echo SET ORG_GRADLE_PROJECT_WORKER=1
    echo.
    echo REM release version will be compiled with value unequal '0' or if ORG_GRADLE_PROJECT_RELEASE and ORG_GRADLE_PROJECT_DEBUG are undefined
    echo SET ORG_GRADLE_PROJECT_RELEASE=1
    echo.
    echo REM debug version will be compiled with value unequal '0'
    echo SET ORG_GRADLE_PROJECT_DEBUG=1
    echo.
    echo REM debug messages of fUML library will be enabled with value '1'
    echo SET ORG_GRADLE_PROJECT_DEBUG_MESSAGE_FUML=0
    echo.
    echo REM #####################################################
    echo REM # configure PATH variable with minimal set of paths #
    echo REM #####################################################
    echo.
    echo REM path to cmake home folder
    echo SET CMAKE_HOME="!CMAKE_HOME_FINAL!"
    echo.
    echo REM path to compiler home folder
    echo SET COMPILER_HOME="!COMPILER_HOME_FINAL!"
    echo.
    echo REM path to java development kit
    echo SET JAVA_HOME="!JAVA_HOME_FINAL!"
    echo.
    echo REM Set combined PATH
    echo IF DEFINED CMAKE_HOME (SET "PATH=!CMAKE_HOME!\bin;!PATH!")
    echo IF DEFINED COMPILER_HOME (SET "PATH=!COMPILER_HOME!\bin;!PATH!")
    echo IF DEFINED JAVA_HOME (SET "PATH=!JAVA_HOME!\bin;!PATH!")
    echo IF DEFINED MDE4CPP_HOME (SET "PATH=!MDE4CPP_HOME!\application\bin;!MDE4CPP_HOME!\application\tools;!PATH!")
    echo.
    echo REM ###############################################################################
    echo REM # configure compiler information for include path setting inside your c++ IDE #
    echo REM ###############################################################################
    echo.
    echo REM delivery name of compiler
    echo SET COMPILER_DELIVERY_NAME=x86_64-w64-mingw32
    echo.
    echo REM compiler version for include path generation
    echo SET COMPILER_VERSION=!COMPILER_VERSION_DETECTED!
    echo.
    echo REM Optional: path to your C++ IDE executable
    echo REM SET CPP_IDE_EXECUTABLE=C:\MyEclipseCPP\eclipse.exe
) > "%SETENV_PATH%"

endlocal
exit /b 0

@echo off
setlocal EnableExtensions EnableDelayedExpansion

REM ########################################
REM # Windows Bootstrap script for MDE4CPP #
REM ########################################

set "DIR=%~dp0"
call "%DIR%bootstrap\Windows\common.bat"

set "PROJECT_DIR=%~dp0"
REM Remove trailing slash for PROJECT_DIR
if "%PROJECT_DIR:~-1%"=="\" set "PROJECT_DIR=%PROJECT_DIR:~0,-1%"

for %%I in ("%PROJECT_DIR%\..") do set "PARENT_DIR=%%~fI"
set "ECLIPSE_DIR=%PARENT_DIR%\eclipse"
set "SETENV_FILE=%PROJECT_DIR%\setenv.bat"

echo ===========================================================
echo %C_PURPLE%[bootstrap]%C_INFO% MDE4CPP Bootstrap Script for Windows%C_RESET%
echo ===========================================================

echo ===========================================================
echo Installing system tools...
echo ===========================================================

call "%DIR%bootstrap\Windows\installJava.bat"
if errorlevel 1 (
    echo %C_ERROR%ERROR: installJava.bat failed ^(exit !errorlevel!^)%C_RESET%
    exit /b !errorlevel!
)

call "%DIR%bootstrap\Windows\installCompiler.bat"
if errorlevel 1 (
    echo %C_ERROR%ERROR: installCompiler.bat failed ^(exit !errorlevel!^)%C_RESET%
    exit /b !errorlevel!
)

call "%DIR%bootstrap\Windows\installCMake.bat"
if errorlevel 1 (
    echo %C_ERROR%ERROR: installCMake.bat failed ^(exit !errorlevel!^)%C_RESET%
    exit /b !errorlevel!
)

call "%DIR%bootstrap\Windows\installEclipse.bat"
if errorlevel 1 (
    echo %C_ERROR%ERROR: installEclipse.bat failed ^(exit !errorlevel!^)%C_RESET%
    exit /b !errorlevel!
)

echo ===========================================================
echo Resolving JAVA_HOME...
echo ===========================================================

REM Reload PATH from system registry since installers modify it in a separate elevated process
for /f "tokens=2*" %%A in ('reg query "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v Path 2^>nul ^| findstr /I "Path"') do set "SYS_PATH=%%B"
for /f "tokens=2*" %%A in ('reg query "HKCU\Environment" /v Path 2^>nul ^| findstr /I "Path"') do set "USR_PATH=%%B"
if defined SYS_PATH set "PATH=!SYS_PATH!;!USR_PATH!;%PATH%"

REM Read JAVA_HOME from system registry (winget sets this here)
if "!JAVA_HOME!"=="" (
    for /f "tokens=2*" %%A in ('reg query "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v JAVA_HOME 2^>nul ^| findstr /I "JAVA_HOME"') do (
        if exist "%%B\bin\java.exe" (
            set "JAVA_HOME=%%B"
            echo %C_PURPLE%[bootstrap]%C_INFO% Loaded JAVA_HOME from system registry: !JAVA_HOME!%C_RESET%
        )
    )
)

REM Fallback: Scan common JDK 21 installation directories
if "!JAVA_HOME!"=="" (
    for /d %%I in ("%ProgramFiles%\Microsoft\jdk-21*") do (
        if exist "%%~fI\bin\java.exe" set "JAVA_HOME=%%~fI"
    )
)
if "!JAVA_HOME!"=="" (
    for /d %%I in ("%ProgramFiles%\Eclipse Adoptium\jdk-21*") do (
        if exist "%%~fI\bin\java.exe" set "JAVA_HOME=%%~fI"
    )
)
if "!JAVA_HOME!"=="" (
    for /d %%I in ("%ProgramFiles%\Java\jdk-21*") do (
        if exist "%%~fI\bin\java.exe" set "JAVA_HOME=%%~fI"
    )
)

if not "!JAVA_HOME!"=="" (
    echo %C_PURPLE%[bootstrap]%C_INFO% Using JAVA_HOME=!JAVA_HOME!%C_RESET%
) else (
    echo %C_PURPLE%[bootstrap]%C_ERROR% ERROR: Could not find Java 21.%C_RESET%
    echo [bootstrap] --- Diagnostics ---
    echo %C_PURPLE%[bootstrap]%C_INFO% ProgramFiles=%ProgramFiles%%C_RESET%
    echo %C_PURPLE%[bootstrap]%C_INFO% Registry JAVA_HOME:%C_RESET%
    reg query "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v JAVA_HOME 2>nul
    if errorlevel 1 echo [bootstrap]   ^(not set^)
    echo %C_PURPLE%[bootstrap]%C_INFO% Contents of "%ProgramFiles%\Microsoft":%C_RESET%
    if exist "%ProgramFiles%\Microsoft" (
        dir /b /ad "%ProgramFiles%\Microsoft" 2>nul | findstr /I "jdk"
        if errorlevel 1 echo [bootstrap]   ^(no jdk directories^)
    ) else (
        echo %C_PURPLE%[bootstrap]%C_INFO% ^(directory does not exist^)%C_RESET%
    )
    echo [bootstrap] --- End diagnostics ---
    exit /b 1
)

call "%DIR%bootstrap\Windows\generate_setenv.bat"
if errorlevel 1 exit /b 1

call "%DIR%bootstrap\Windows\run_gradle_install.bat"
if errorlevel 1 exit /b 1

echo ===========================================================
echo %C_SUCCESS%Bootstrap completed successfully!%C_RESET%
echo To activate the environment, please run:
echo   call setenv.bat
echo ===========================================================

endlocal
exit /b 0



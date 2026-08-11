@echo off
setlocal EnableExtensions EnableDelayedExpansion

REM ########################################
REM # Windows Bootstrap script for MDE4CPP #
REM ########################################

set "DIR=%~dp0"
call "%DIR%bootstrap\windows\common.bat"

set "PROJECT_DIR=%~dp0"
REM Remove trailing slash for PROJECT_DIR
if "%PROJECT_DIR:~-1%"=="\" set "PROJECT_DIR=%PROJECT_DIR:~0,-1%"

for %%I in ("%PROJECT_DIR%\..") do set "PARENT_DIR=%%~fI"
set "ECLIPSE_DIR=%PARENT_DIR%\eclipse"
set "SETENV_FILE=%PROJECT_DIR%\setenv.bat"

call "%DIR%bootstrap\windows\common.bat" print_header "bootstrap" "MDE4CPP Bootstrap Script for Windows"

call "%DIR%bootstrap\windows\common.bat" print_header "bootstrap" "Installing system tools..."

if not "!BOOTSTRAP_SKIP_JAVA_INSTALL!"=="true" (
    call "%DIR%bootstrap\windows\install_java.bat"
    if errorlevel 1 (
        echo %C_ERROR%ERROR: install_java.bat failed ^(exit !errorlevel!^)%C_RESET%
        exit /b !errorlevel!
    )
) else (
    echo %C_PURPLE%[bootstrap]%C_INFO% Skipping Java installation as per BOOTSTRAP_SKIP_JAVA_INSTALL%C_RESET%
)

if not "!BOOTSTRAP_SKIP_COMPILER_INSTALL!"=="true" (
    call "%DIR%bootstrap\windows\install_compiler.bat"
    if errorlevel 1 (
        echo %C_ERROR%ERROR: install_compiler.bat failed ^(exit !errorlevel!^)%C_RESET%
        exit /b !errorlevel!
    )
) else (
    echo %C_PURPLE%[bootstrap]%C_INFO% Skipping Compiler installation as per BOOTSTRAP_SKIP_COMPILER_INSTALL%C_RESET%
)

if not "!BOOTSTRAP_SKIP_CMAKE_INSTALL!"=="true" (
    call "%DIR%bootstrap\windows\install_cmake.bat"
    if errorlevel 1 (
        echo %C_ERROR%ERROR: install_cmake.bat failed ^(exit !errorlevel!^)%C_RESET%
        exit /b !errorlevel!
    )
) else (
    echo %C_PURPLE%[bootstrap]%C_INFO% Skipping CMake installation as per BOOTSTRAP_SKIP_CMAKE_INSTALL%C_RESET%
)

if not "!BOOTSTRAP_SKIP_ECLIPSE_INSTALL!"=="true" (
    call "%DIR%bootstrap\windows\install_eclipse.bat"
    if errorlevel 1 (
        echo %C_ERROR%ERROR: install_eclipse.bat failed ^(exit !errorlevel!^)%C_RESET%
        exit /b !errorlevel!
    )
) else (
    echo %C_PURPLE%[bootstrap]%C_INFO% Skipping Eclipse installation as per BOOTSTRAP_SKIP_ECLIPSE_INSTALL%C_RESET%
)

if not "!BOOTSTRAP_SKIP_ECLIPSE_PLUGINS_INSTALL!"=="true" (
    call "%DIR%bootstrap\windows\install_eclipse_plugins.bat"
    if errorlevel 1 (
        echo %C_ERROR%ERROR: install_eclipse_plugins.bat failed ^(exit !errorlevel!^)%C_RESET%
        exit /b !errorlevel!
    )
) else (
    echo %C_PURPLE%[bootstrap]%C_INFO% Skipping Eclipse plugins installation as per BOOTSTRAP_SKIP_ECLIPSE_PLUGINS_INSTALL%C_RESET%
)


if not "!BOOTSTRAP_SKIP_GENERATE_SETENV!"=="true" (
    call "%DIR%bootstrap\windows\generate_setenv.bat"
    if errorlevel 1 exit /b 1
) else (
    echo %C_PURPLE%[bootstrap]%C_INFO% Skipping generate_setenv.bat as per BOOTSTRAP_SKIP_GENERATE_SETENV%C_RESET%
)

if not "!BOOTSTRAP_SKIP_GRADLE_INSTALL!"=="true" (
    call "%DIR%bootstrap\windows\run_gradle_install.bat"
    if errorlevel 1 exit /b 1
) else (
    echo %C_PURPLE%[bootstrap]%C_INFO% Skipping Gradle installation as per BOOTSTRAP_SKIP_GRADLE_INSTALL%C_RESET%
)

echo %C_WARN%===========================================================%C_RESET%
echo %C_SUCCESS%Bootstrap completed successfully!%C_RESET%
echo To activate the environment, please run:
echo   call setenv.bat
echo %C_WARN%===========================================================%C_RESET%

endlocal
exit /b 0



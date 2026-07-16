@echo off
setlocal EnableExtensions EnableDelayedExpansion

call "%~dp0common.bat"
if errorlevel 1 exit /b 1

call "%~dp0common.bat" print_header "install_eclipse_plugins" "Running Eclipse plugins installation..."

echo %C_PURPLE%[install_eclipse_plugins]%C_ORANGE% MDE4CPP_ECLIPSE_ACCELEO_VERSION=!MDE4CPP_ECLIPSE_ACCELEO_VERSION!%C_RESET%
echo %C_PURPLE%[install_eclipse_plugins]%C_ORANGE% MDE4CPP_ECLIPSE_PAPYRUS_VERSION=!MDE4CPP_ECLIPSE_PAPYRUS_VERSION!%C_RESET%
echo %C_PURPLE%[install_eclipse_plugins]%C_ORANGE% MDE4CPP_ECLIPSE_PAPYRUS_UPDATE_VERSION=!MDE4CPP_ECLIPSE_PAPYRUS_UPDATE_VERSION!%C_RESET%
echo %C_PURPLE%[install_eclipse_plugins]%C_ORANGE% MDE4CPP_ECLIPSE_SIRIUS_VERSION=!MDE4CPP_ECLIPSE_SIRIUS_VERSION!-!MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION!%C_RESET%

set "SCRIPT_DIR=%~dp0"
for %%I in ("%SCRIPT_DIR%..\..") do set "MDE4CPP_HOME=%%~fI"

if "!MDE4CPP_HOME!"=="" (
    echo %C_PURPLE%[install_eclipse_plugins]%C_ERROR% ERROR: Could not determine MDE4CPP_HOME.%C_RESET%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_VERSION!"=="" (
    echo %C_PURPLE%[install_eclipse_plugins]%C_ERROR% ERROR: MDE4CPP_ECLIPSE_VERSION not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_ACCELEO_VERSION!"=="" (
    echo %C_PURPLE%[install_eclipse_plugins]%C_ERROR% ERROR: MDE4CPP_ECLIPSE_ACCELEO_VERSION not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_SIRIUS_VERSION!"=="" (
    echo %C_PURPLE%[install_eclipse_plugins]%C_ERROR% ERROR: MDE4CPP_ECLIPSE_SIRIUS_VERSION not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_PAPYRUS_VERSION!"=="" (
    echo %C_PURPLE%[install_eclipse_plugins]%C_ERROR% ERROR: MDE4CPP_ECLIPSE_PAPYRUS_VERSION not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_PAPYRUS_UPDATE_VERSION!"=="" (
    echo %C_PURPLE%[install_eclipse_plugins]%C_ERROR% ERROR: MDE4CPP_ECLIPSE_PAPYRUS_UPDATE_VERSION not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)
if "!MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION!"=="" (
    echo %C_PURPLE%[install_eclipse_plugins]%C_ERROR% ERROR: MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION not found in %VERSIONS_FILE%%C_RESET%
    exit /b 1
)

for %%I in ("!MDE4CPP_HOME!\..") do set "MDE4CPP_PARENT=%%~fI"
if not "!MDE4CPP_ECLIPSE_LOCATION!"=="" (
    set "TARGET_DIR=!MDE4CPP_ECLIPSE_LOCATION!"
) else (
    set "TARGET_DIR=!MDE4CPP_PARENT!\eclipse"
)

if not exist "!TARGET_DIR!\eclipsec.exe" (
    echo %C_PURPLE%[install_eclipse_plugins]%C_ERROR% ERROR: Eclipse binary not found at !TARGET_DIR!\eclipsec.exe%C_RESET%
    echo %C_PURPLE%[install_eclipse_plugins]%C_INFO% Please install Eclipse first.%C_RESET%
    exit /b 1
)

set "TMP_DIR=%TEMP%\mde4cpp-eclipse-plugins"
if exist "!TMP_DIR!" rmdir /s /q "!TMP_DIR!"
mkdir "!TMP_DIR!" >nul 2>&1

set "ACCELEO_REPOSITORY_URL=https://download.eclipse.org/acceleo/updates/releases/!MDE4CPP_ECLIPSE_ACCELEO_VERSION: =!"
set "SIRIUS_REPOSITORY_URL=https://download.eclipse.org/sirius/updates/releases/!MDE4CPP_ECLIPSE_SIRIUS_VERSION: =!/!MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION: =!"
set "PAPYRUS_REPOSITORY_URL=https://download.eclipse.org/modeling/mdt/papyrus/updates/releases/!MDE4CPP_ECLIPSE_PAPYRUS_UPDATE_VERSION: =!"
set "PAPYRUS_DEPENDENCIES_URL=https://download.eclipse.org/releases/!MDE4CPP_ECLIPSE_PAPYRUS_UPDATE_VERSION: =!"
set "CDT_REPOSITORY_URL=https://download.eclipse.org/releases/!MDE4CPP_ECLIPSE_VERSION: =!"

set "NEEDS_INSTALL=0"
echo %C_PURPLE%[install_eclipse_plugins]%C_INFO% Checking existing Eclipse installation at !TARGET_DIR!...%C_RESET%
"%TARGET_DIR%\eclipsec.exe" -nosplash -application org.eclipse.equinox.p2.director -listInstalledRoots > "%TMP_DIR%\installed.txt" 2>&1

echo %C_PURPLE%[install_eclipse_plugins]%C_SUCCESS% Found existing Eclipse plugins:%C_RESET%
for /f "usebackq eol=# tokens=*" %%P in ("%SCRIPT_DIR%..\eclipse_plugins.txt") do (
    set "FOUND_VER="
    for /f "tokens=1,2 delims=/" %%A in ('findstr /b /c:"%%P/" "%TMP_DIR%\installed.txt"') do (
        set "FOUND_VER=%%B"
    )
    if defined FOUND_VER (
        echo %C_PURPLE%[install_eclipse_plugins]%C_INFO% %%P: !FOUND_VER!%C_RESET%
    ) else (
        echo %C_PURPLE%[install_eclipse_plugins]%C_INFO% %%P: %C_ERROR%NOT FOUND%C_RESET%
        set "NEEDS_INSTALL=1"
    )
)

if "!NEEDS_INSTALL!"=="0" (
    echo %C_PURPLE%[install_eclipse_plugins]%C_SUCCESS% Requested Eclipse plugins are already installed. Skipping.%C_RESET%
    goto :skipInstall
)

echo %C_PURPLE%[install_eclipse_plugins]%C_INFO% Installing Eclipse plugins ^(Acceleo, Sirius, CDT, Papyrus^)...%C_RESET%

set "PLUGINS="
for /f "usebackq eol=# tokens=*" %%P in ("%SCRIPT_DIR%..\eclipse_plugins.txt") do (
    set "PLUGINS=!PLUGINS! -installIU %%P"
)

powershell -NoProfile -ExecutionPolicy Bypass -Command "& \"%TARGET_DIR%\eclipsec.exe\" -nosplash -application org.eclipse.equinox.p2.director -repository \"https://download.eclipse.org/releases/%MDE4CPP_ECLIPSE_VERSION: =%/,%ACCELEO_REPOSITORY_URL%,%SIRIUS_REPOSITORY_URL%,%PAPYRUS_REPOSITORY_URL%,%PAPYRUS_DEPENDENCIES_URL%,%CDT_REPOSITORY_URL%\" !PLUGINS! -destination \"%TARGET_DIR%\" -profileProperties org.eclipse.update.install.features=true -vmargs -Declipse.p2.mirrors=false -Djavax.net.ssl.trustStoreType=WINDOWS-ROOT 2> \"%TMP_DIR%\p2_stderr.log\" | ForEach-Object { [Console]::Out.WriteLine(\"$env:C_PURPLE[install_eclipse_plugins]$env:C_INFO $_$env:C_RESET\") }; exit $LASTEXITCODE"
if errorlevel 1 (
    echo %C_PURPLE%[install_eclipse_plugins]%C_ERROR% ERROR: Eclipse plugin installation failed.%C_RESET%
    type "%TMP_DIR%\p2_stderr.log"
    exit /b 1
)

:skipInstall
rmdir /s /q "%TMP_DIR%"
echo %C_PURPLE%[install_eclipse_plugins]%C_SUCCESS% Eclipse plugins installation finished.%C_RESET%
endlocal

#!/usr/bin/env bash
# Main bootstrap script for MDE4CPP

set -e

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
PROJECT_DIR="$DIR"

source "$DIR/bootstrap/unix/common.sh"

OS="$(uname -s)"
OS_DIR=""
case "$OS" in
    Linux*)     
        echo "Detected OS: Linux"
        OS_DIR="Linux"
        ;;
    Darwin*)    
        echo "Detected OS: Mac OS"
        OS_DIR="MacOS"
        ;;
    CYGWIN*|MINGW*|MSYS*) 
        echo "Detected OS: Windows"
        if [ -f "$DIR/bootstrap/Windows/bootstrap.bat" ]; then
            cmd.exe /c "$(cygpath -w "$DIR/bootstrap/Windows/bootstrap.bat")"
        else
            echo "Windows script not found."
            exit 1
        fi
        exit 0
        ;;
    *)          
        echo "Detected OS: Unknown ($OS)"
        echo "Cannot bootstrap automatically."
        exit 1
        ;;
esac

print_header "bootstrap" "Installing system tools for $OS_DIR..."

if [ "$OS_DIR" = "MacOS" ]; then
    echo "${C_PURPLE}[bootstrap]${C_INFO} Checking Homebrew...${C_RESET}"
    if ! command -v brew &> /dev/null; then
        echo "${C_PURPLE}[bootstrap]${C_INFO} Homebrew not found. Installing Homebrew...${C_RESET}"
        /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
        eval "$(/opt/homebrew/bin/brew shellenv 2>/dev/null || /usr/local/bin/brew shellenv 2>/dev/null)"
    else
        echo "${C_PURPLE}[bootstrap]${C_SUCCESS} Homebrew is installed.${C_RESET}"
    fi
fi

if [ "${MDE4CPP_SKIP_JAVA_INSTALL:-false}" != "true" ]; then
    bash "$DIR/bootstrap/unix/install_java.sh"
    if [ $? -ne 0 ]; then echo "${C_PURPLE}[bootstrap]${C_ERROR} ERROR: install_java.sh failed${C_RESET}"; exit 1; fi
else
    echo "${C_PURPLE}[bootstrap]${C_INFO} Skipping Java installation as per MDE4CPP_SKIP_JAVA_INSTALL${C_RESET}"
fi

if [ "${MDE4CPP_SKIP_COMPILER_INSTALL:-false}" != "true" ]; then
    bash "$DIR/bootstrap/unix/install_compiler.sh"
    if [ $? -ne 0 ]; then echo "${C_PURPLE}[bootstrap]${C_ERROR} ERROR: install_compiler.sh failed${C_RESET}"; exit 1; fi
else
    echo "${C_PURPLE}[bootstrap]${C_INFO} Skipping Compiler installation as per MDE4CPP_SKIP_COMPILER_INSTALL${C_RESET}"
fi

if [ "${MDE4CPP_SKIP_CMAKE_INSTALL:-false}" != "true" ]; then
    bash "$DIR/bootstrap/unix/install_cmake.sh"
    if [ $? -ne 0 ]; then echo "${C_PURPLE}[bootstrap]${C_ERROR} ERROR: install_cmake.sh failed${C_RESET}"; exit 1; fi
else
    echo "${C_PURPLE}[bootstrap]${C_INFO} Skipping CMake installation as per MDE4CPP_SKIP_CMAKE_INSTALL${C_RESET}"
fi

export MDE4CPP_HOME="$PROJECT_DIR"
if [ "${MDE4CPP_SKIP_ECLIPSE_INSTALL:-false}" != "true" ]; then
    bash "$DIR/bootstrap/unix/install_eclipse.sh"
    if [ $? -ne 0 ]; then echo "${C_PURPLE}[bootstrap]${C_ERROR} ERROR: install_eclipse.sh failed${C_RESET}"; exit 1; fi
else
    echo "${C_PURPLE}[bootstrap]${C_INFO} Skipping Eclipse installation as per MDE4CPP_SKIP_ECLIPSE_INSTALL${C_RESET}"
fi

if [ "${MDE4CPP_SKIP_ECLIPSE_PLUGINS_INSTALL:-false}" != "true" ]; then
    bash "$DIR/bootstrap/unix/install_eclipse_plugins.sh"
    if [ $? -ne 0 ]; then echo "${C_PURPLE}[bootstrap]${C_ERROR} ERROR: install_eclipse_plugins.sh failed${C_RESET}"; exit 1; fi
else
    echo "${C_PURPLE}[bootstrap]${C_INFO} Skipping Eclipse plugins installation as per MDE4CPP_SKIP_ECLIPSE_PLUGINS_INSTALL${C_RESET}"
fi

if [ "${MDE4CPP_SKIP_GENERATE_SETENV:-false}" != "true" ]; then
    bash "$DIR/bootstrap/unix/generate_setenv.sh"
    if [ $? -ne 0 ]; then echo "${C_PURPLE}[bootstrap]${C_ERROR} ERROR: generate_setenv.sh failed${C_RESET}"; exit 1; fi
else
    echo "${C_PURPLE}[bootstrap]${C_INFO} Skipping generate_setenv.sh as per MDE4CPP_SKIP_GENERATE_SETENV${C_RESET}"
fi

if [ "${MDE4CPP_SKIP_GRADLE_INSTALL:-false}" != "true" ]; then
    bash "$DIR/bootstrap/unix/run_gradle_install.sh"
    if [ $? -ne 0 ]; then echo "${C_PURPLE}[bootstrap]${C_ERROR} ERROR: run_gradle_install.sh failed${C_RESET}"; exit 1; fi
else
    echo "${C_PURPLE}[bootstrap]${C_INFO} Skipping Gradle installation as per MDE4CPP_SKIP_GRADLE_INSTALL${C_RESET}"
fi

echo "${C_WARN}===========================================================${C_RESET}"
echo "${C_SUCCESS}Bootstrap completed successfully!${C_RESET}"
echo "To activate the environment, please run:"
echo "  source setenv.sh"
echo "${C_WARN}===========================================================${C_RESET}"

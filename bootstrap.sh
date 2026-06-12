#!/usr/bin/env bash
# Main bootstrap script for MDE4CPP

set -e

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
PROJECT_DIR="$DIR"

source "$DIR/bootstrap/unix/common.sh"
PROPS_FILE="$DIR/versions.properties"
load_properties "$PROPS_FILE"

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

echo "==========================================================="
echo "Installing system tools for $OS_DIR..."
echo "==========================================================="

if [ "$OS_DIR" = "MacOS" ]; then
    echo "Checking Homebrew..."
    if ! command -v brew &> /dev/null; then
        echo "Homebrew not found. Installing Homebrew..."
        /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
        eval "$(/opt/homebrew/bin/brew shellenv 2>/dev/null || /usr/local/bin/brew shellenv 2>/dev/null)"
    else
        echo "Homebrew is installed."
    fi
fi

bash "$DIR/bootstrap/unix/installJava.sh"
bash "$DIR/bootstrap/unix/installCompiler.sh"
bash "$DIR/bootstrap/unix/installCMake.sh"

export MDE4CPP_HOME="$PROJECT_DIR"
bash "$DIR/bootstrap/unix/installEclipse.sh"



bash "$DIR/bootstrap/unix/generate_setenv.sh"
bash "$DIR/bootstrap/unix/run_gradle_install.sh"

echo "==========================================================="
echo "Bootstrap completed successfully!"
echo "To activate the environment, please run:"
echo "  source setenv.sh"
echo "==========================================================="

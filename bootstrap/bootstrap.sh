#!/usr/bin/env bash
# Main bootstrap script for MDE4CPP

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

OS="$(uname -s)"
case "$OS" in
    Linux*)     
        echo "Detected OS: Linux"
        "$DIR/bootstrap.sh"
        ;;
    Darwin*)    
        echo "Detected OS: Mac OS"
        "$DIR/bootstrap.sh"
        ;;
    CYGWIN*|MINGW*|MSYS*) 
        echo "Detected OS: Windows"
        # Call bat file or windows specific script
        if [ -f "$DIR/bootstrap.bat" ]; then
            cmd.exe /c "$(cygpath -w "$DIR/bootstrap.bat")"
        else
            echo "Windows script not found."
            exit 1
        fi
        ;;
    *)          
        echo "Detected OS: Unknown ($OS)"
        echo "Cannot bootstrap automatically."
        exit 1
        ;;
esac

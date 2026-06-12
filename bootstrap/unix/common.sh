#!/usr/bin/env bash
# Common functions for MDE4CPP bootstrap scripts

setup_colors() {
    export C_RESET=$'\033[0m'
    export C_INFO=$'\033[1;36m'
    export C_SUCCESS=$'\033[1;32m'
    export C_WARN=$'\033[1;33m'
    export C_ERROR=$'\033[1;31m'
}

# Function to read properties file and export variables
load_properties() {
    setup_colors
    local prop_file="$1"
    if [ -f "$prop_file" ]; then
        echo "Loading properties from $prop_file..."
        while IFS='=' read -r key value; do
            # Ignore comments and empty lines
            if [[ "$key" =~ ^#.* ]] || [[ -z "$key" ]]; then
                continue
            fi
            # Remove leading/trailing whitespaces and carriage returns
            key=$(echo "$key" | xargs)
            value=$(echo "$value" | tr -d '\r' | xargs)
            export "$key"="$value"
            # echo "  $key=$value"
        done < "$prop_file"
    else
        echo "Error: Properties file $prop_file not found!"
        exit 1
    fi
}

require_sudo() {
    if [[ "${1:-}" != "--elevated" ]] && [[ "${EUID}" -ne 0 ]]; then
        echo "Root privileges are required for installation. Requesting sudo elevation..."
        exec sudo -E bash "$0" --elevated
    fi
}

download_file() {
    local url="$1"
    local output="$2"
    if command -v curl >/dev/null 2>&1; then
        curl -fL "$url" -o "$output"
    elif command -v wget >/dev/null 2>&1; then
        wget -O "$output" "$url"
    else
        echo "ERROR: Neither curl nor wget is available to download $url"
        exit 1
    fi
}

get_arch() {
    local arch
    arch="$(uname -m)"
    if [[ "$arch" == "x86_64" ]]; then
        echo "x86_64"
    elif [[ "$arch" == "aarch64" || "$arch" == "arm64" ]]; then
        echo "aarch64"
    else
        echo "unknown"
    fi
}

# Auto-load properties if not already set
if [[ -z "${MDE4CPP_JAVA_VERSION:-}" ]]; then
    # Find versions.properties relative to this common.sh file
    COMMON_SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
    VERSIONS_FILE="$(cd "${COMMON_SCRIPT_DIR}/.." && pwd)/versions.properties"
    if [[ -f "$VERSIONS_FILE" ]]; then
        load_properties "$VERSIONS_FILE"
    fi
fi

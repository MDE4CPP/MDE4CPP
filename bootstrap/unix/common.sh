#!/usr/bin/env bash
# Common functions for MDE4CPP bootstrap scripts

setup_colors() {
    local common_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
    local prop_file="${common_dir}/../colors.properties"
    if [ -f "$prop_file" ]; then
        while IFS='=' read -r key value; do
            if [[ "$key" =~ ^#.* ]] || [[ -z "$key" ]]; then
                continue
            fi
            key=$(echo "$key" | xargs)
            value=$(echo "$value" | tr -d '\r' | xargs)
            export "$key"=$'\033['"$value"
        done < "$prop_file"
    fi
}

print_header() {
    local prefix="$1"
    local message="$2"
    echo "${C_WARN}===========================================================${C_RESET}"
    echo "${C_PURPLE}[${prefix}]${C_WARN} ${message}${C_RESET}"
    echo "${C_WARN}===========================================================${C_RESET}"
}

# Function to read properties file and export variables
load_properties() {
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
    # Find MDE4CPP.properties relative to this common.sh file
    COMMON_SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
    VERSIONS_FILE="$(cd "${COMMON_SCRIPT_DIR}/../.." && pwd)/MDE4CPP.properties"
    if [[ -f "$VERSIONS_FILE" ]]; then
        load_properties "$VERSIONS_FILE"
    fi
fi

setup_colors

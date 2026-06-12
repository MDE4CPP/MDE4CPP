#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "${SCRIPT_DIR}/common.sh"

print_header "installCMake" "Running CMake installation..."

if [[ -z "${MDE4CPP_CMAKE_VERSION:-}" ]]; then
    echo "${C_PURPLE}[installCMake]${C_ERROR} ERROR: MDE4CPP_CMAKE_VERSION is not set.${C_RESET}"
    exit 1
fi
if [[ -z "${MDE4CPP_CMAKE_BUILD:-}" ]]; then
    echo "${C_PURPLE}[installCMake]${C_ERROR} ERROR: MDE4CPP_CMAKE_BUILD is not set.${C_RESET}"
    exit 1
fi

CMAKE_FULL_VERSION="${MDE4CPP_CMAKE_VERSION}.${MDE4CPP_CMAKE_BUILD}"
echo "${C_PURPLE}[installCMake]${C_INFO} MDE4CPP_CMAKE_VERSION=${CMAKE_FULL_VERSION}${C_RESET}"

if [ "$(uname -s)" = "Darwin" ]; then
    if command -v cmake >/dev/null 2>&1; then
        INSTALLED_VERSION="$(cmake --version | grep -oE '[0-9]+\.[0-9]+\.[0-9]+' | head -n1)"
        if [[ "${INSTALLED_VERSION}" == "${CMAKE_FULL_VERSION}" ]]; then
            echo "${C_PURPLE}[installCMake]${C_SUCCESS} CMake ${CMAKE_FULL_VERSION} is already installed.${C_RESET}"
            exit 0
        fi
        echo "${C_PURPLE}[installCMake]${C_SUCCESS} Found CMake ${INSTALLED_VERSION}, but need ${CMAKE_FULL_VERSION}.${C_RESET}"
    fi
    echo "${C_PURPLE}[installCMake]${C_INFO} Installing cmake via Homebrew...${C_RESET}"
    brew install cmake
else
    # Linux
    if command -v cmake >/dev/null 2>&1; then
      INSTALLED_VERSION="$(cmake --version | awk 'NR==1 {print $3}')"
      if [[ "${INSTALLED_VERSION}" == "${CMAKE_FULL_VERSION}" ]]; then
        echo "${C_PURPLE}[installCMake]${C_SUCCESS} CMake ${CMAKE_FULL_VERSION} is already installed. Skipping.${C_RESET}"
        exit 0
      fi
      echo "${C_PURPLE}[installCMake]${C_SUCCESS} Found CMake ${INSTALLED_VERSION}. Installing CMake ${CMAKE_FULL_VERSION}.${C_RESET}"
    else
      echo "${C_PURPLE}[installCMake]${C_INFO} CMake is not installed. Installing CMake ${CMAKE_FULL_VERSION}.${C_RESET}"
    fi

    require_sudo "$@"

    ARCH=$(get_arch)
    if [[ "${ARCH}" == "unknown" ]]; then
      echo "${C_PURPLE}[installCMake]${C_ERROR} ERROR: Unsupported architecture: $(uname -m)${C_RESET}"
      exit 1
    fi

    ARCHIVE_NAME="cmake-${CMAKE_FULL_VERSION}-linux-${ARCH}.tar.gz"
    DOWNLOAD_URL="https://github.com/Kitware/CMake/releases/download/v${CMAKE_FULL_VERSION}/${ARCHIVE_NAME}"
    TMP_DIR="$(mktemp -d)"

    cleanup() {
      rm -rf "${TMP_DIR}"
    }
    trap cleanup EXIT

    echo "${C_PURPLE}[installCMake]${C_INFO} Downloading ${DOWNLOAD_URL}${C_RESET}"
    download_file "${DOWNLOAD_URL}" "${TMP_DIR}/${ARCHIVE_NAME}"

    echo "${C_PURPLE}[installCMake]${C_INFO} Extracting CMake to /usr/local${C_RESET}"
    tar -xzf "${TMP_DIR}/${ARCHIVE_NAME}" -C /usr/local --strip-components=1

    if ! command -v cmake >/dev/null 2>&1; then
      echo "${C_PURPLE}[installCMake]${C_ERROR} ERROR: CMake installation failed (executable not found).${C_RESET}"
      exit 1
    fi

    echo "${C_PURPLE}[installCMake]${C_INFO} Verified installation:${C_RESET}"
    cmake --version
fi

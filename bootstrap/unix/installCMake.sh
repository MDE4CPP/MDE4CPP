#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "${SCRIPT_DIR}/common.sh"

if [[ -z "${MDE4CPP_CMAKE_VERSION:-}" ]]; then
    echo "[installCMake] ERROR: MDE4CPP_CMAKE_VERSION is not set."
    exit 1
fi
if [[ -z "${MDE4CPP_CMAKE_BUILD:-}" ]]; then
    echo "[installCMake] ERROR: MDE4CPP_CMAKE_BUILD is not set."
    exit 1
fi

CMAKE_FULL_VERSION="${MDE4CPP_CMAKE_VERSION}.${MDE4CPP_CMAKE_BUILD}"
echo "[installCMake] MDE4CPP_CMAKE_VERSION=${CMAKE_FULL_VERSION}"

if [ "$(uname -s)" = "Darwin" ]; then
    if command -v cmake >/dev/null 2>&1; then
        INSTALLED_VERSION="$(cmake --version | grep -oE '[0-9]+\.[0-9]+\.[0-9]+' | head -n1)"
        if [[ "${INSTALLED_VERSION}" == "${CMAKE_FULL_VERSION}" ]]; then
            echo "[installCMake] CMake ${CMAKE_FULL_VERSION} is already installed."
            exit 0
        fi
        echo "[installCMake] Found CMake ${INSTALLED_VERSION}, but need ${CMAKE_FULL_VERSION}."
    fi
    echo "[installCMake] Installing cmake via Homebrew..."
    brew install cmake
else
    # Linux
    if command -v cmake >/dev/null 2>&1; then
      INSTALLED_VERSION="$(cmake --version | awk 'NR==1 {print $3}')"
      if [[ "${INSTALLED_VERSION}" == "${CMAKE_FULL_VERSION}" ]]; then
        echo "[installCMake] CMake ${CMAKE_FULL_VERSION} is already installed. Skipping."
        exit 0
      fi
      echo "[installCMake] Found CMake ${INSTALLED_VERSION}. Installing CMake ${CMAKE_FULL_VERSION}."
    else
      echo "[installCMake] CMake is not installed. Installing CMake ${CMAKE_FULL_VERSION}."
    fi

    require_sudo "$@"

    ARCH=$(get_arch)
    if [[ "${ARCH}" == "unknown" ]]; then
      echo "[installCMake] ERROR: Unsupported architecture: $(uname -m)"
      exit 1
    fi

    ARCHIVE_NAME="cmake-${CMAKE_FULL_VERSION}-linux-${ARCH}.tar.gz"
    DOWNLOAD_URL="https://github.com/Kitware/CMake/releases/download/v${CMAKE_FULL_VERSION}/${ARCHIVE_NAME}"
    TMP_DIR="$(mktemp -d)"

    cleanup() {
      rm -rf "${TMP_DIR}"
    }
    trap cleanup EXIT

    echo "[installCMake] Downloading ${DOWNLOAD_URL}"
    download_file "${DOWNLOAD_URL}" "${TMP_DIR}/${ARCHIVE_NAME}"

    echo "[installCMake] Extracting CMake to /usr/local"
    tar -xzf "${TMP_DIR}/${ARCHIVE_NAME}" -C /usr/local --strip-components=1

    if ! command -v cmake >/dev/null 2>&1; then
      echo "[installCMake] ERROR: CMake installation failed (executable not found)."
      exit 1
    fi

    echo "[installCMake] Verified installation:"
    cmake --version
fi

#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "${SCRIPT_DIR}/../common.sh"

echo "[installCMake] MDE4CPP_CMAKE_VERSION=${MDE4CPP_CMAKE_VERSION:-}"
echo "[installCMake] MDE4CPP_CMAKE_BUILD_VERSION=${MDE4CPP_CMAKE_BUILD:-}"

if [[ -z "${MDE4CPP_CMAKE_VERSION:-}" ]]; then
    echo "[installCMake] ERROR: MDE4CPP_CMAKE_VERSION is not set."
    exit 1
fi
if [[ -z "${MDE4CPP_CMAKE_BUILD:-}" ]]; then
    echo "[installCMake] ERROR: MDE4CPP_CMAKE_BUILD is not set."
    exit 1
fi

CMAKE_ARCH=$(get_arch)
if [[ "${CMAKE_ARCH}" == "unknown" ]]; then
  echo "[installCMake] ERROR: Unsupported architecture: $(uname -m)"
  exit 1
fi

CMAKE_FULL_VERSION="${MDE4CPP_CMAKE_VERSION}.${MDE4CPP_CMAKE_BUILD_VERSION}"
TARGET_DIR="/opt/cmake-${CMAKE_FULL_VERSION}"
TMP_DIR="$(mktemp -d)"
ARCHIVE_PATH="${TMP_DIR}/cmake.tar.gz"
DOWNLOAD_URL="https://github.com/Kitware/CMake/releases/download/v${CMAKE_FULL_VERSION}/cmake-${CMAKE_FULL_VERSION}-linux-${CMAKE_ARCH}.tar.gz"

# Step 3: Skip when requested version is already installed.
if command -v cmake >/dev/null 2>&1; then
  INSTALLED_VERSION="$(cmake --version 2>/dev/null | awk 'NR==1 {print $3}' || true)"
  if [[ "${INSTALLED_VERSION}" == "${CMAKE_FULL_VERSION}" ]]; then
    echo "[installCMake] CMake ${CMAKE_FULL_VERSION} is already installed. Skipping."
    exit 0
  fi
  echo "[installCMake] Found installed CMake ${INSTALLED_VERSION}. Installing ${CMAKE_FULL_VERSION}."
else
  echo "[installCMake] CMake is not installed. Installing ${CMAKE_FULL_VERSION}."
fi

# Step 4: Ensure elevated privileges only if installation is required.
require_sudo "$@"

# Step 5: Register cleanup for temporary files.
cleanup() {
  rm -rf "${TMP_DIR}"
}
trap cleanup EXIT

# Step 6: Download the CMake archive.
echo "[installCMake] Install location=${TARGET_DIR}"
echo "[installCMake] Using CMake version=${CMAKE_FULL_VERSION}"
echo "[installCMake] Downloading ${DOWNLOAD_URL}"

download_file "${DOWNLOAD_URL}" "${ARCHIVE_PATH}"

# Step 7: Install CMake and update the system symlink.
rm -rf "${TARGET_DIR}"
tar -xzf "${ARCHIVE_PATH}" -C "${TMP_DIR}"
mv "${TMP_DIR}/cmake-${CMAKE_FULL_VERSION}-linux-${CMAKE_ARCH}" "${TARGET_DIR}"
ln -sfn "${TARGET_DIR}/bin/cmake" /usr/local/bin/cmake

# Step 8: Report installed system location.
echo "[installCMake] Installed system CMake at ${TARGET_DIR}"
echo "[installCMake] Binary symlink: /usr/local/bin/cmake"

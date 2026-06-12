#!/usr/bin/env bash
set -euo pipefail

# Step 1: Find repo root and read CMake versions from versions.properties
echo "[installCMake] Reading configuration from versions.properties..."
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"
VERSIONS_FILE="${REPO_ROOT}/versions.properties"

if [[ ! -f "${VERSIONS_FILE}" ]]; then
    echo "[installCMake] ERROR: versions.properties not found at ${VERSIONS_FILE}"
    exit 1
fi

# Read CMake versions from properties file
MDE4CPP_CMAKE_VERSION=""
MDE4CPP_CMAKE_BUILD_VERSION=""
if [[ -f "${VERSIONS_FILE}" ]]; then
    MDE4CPP_CMAKE_VERSION=$(grep -i "^MDE4CPP_CMAKE_VERSION=" "${VERSIONS_FILE}" | cut -d'=' -f2 | tr -d ' ' | tr -d '\r')
    MDE4CPP_CMAKE_BUILD_VERSION=$(grep -i "^MDE4CPP_CMAKE_BUILD=" "${VERSIONS_FILE}" | cut -d'=' -f2 | tr -d ' ' | tr -d '\r')
fi

echo "[installCMake] MDE4CPP_CMAKE_VERSION=${MDE4CPP_CMAKE_VERSION}"
echo "[installCMake] MDE4CPP_CMAKE_BUILD_VERSION=${MDE4CPP_CMAKE_BUILD_VERSION}"
if [[ -z "${MDE4CPP_CMAKE_VERSION}" ]]; then
    echo "[installCMake] ERROR: MDE4CPP_CMAKE_VERSION not found in ${VERSIONS_FILE}"
    exit 1
fi
if [[ -z "${MDE4CPP_CMAKE_BUILD_VERSION}" ]]; then
    echo "[installCMake] ERROR: MDE4CPP_CMAKE_BUILD not found in ${VERSIONS_FILE}"
    exit 1
fi

# Step 2: Resolve target paths and download source.
ARCH=$(uname -m)
if [[ "${ARCH}" == "x86_64" ]]; then
  CMAKE_ARCH="x86_64"
elif [[ "${ARCH}" == "aarch64" || "${ARCH}" == "arm64" ]]; then
  CMAKE_ARCH="aarch64"
else
  echo "[installCMake] ERROR: Unsupported architecture: ${ARCH}"
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
if [[ "${1:-}" != "--elevated" ]] && [[ "${EUID}" -ne 0 ]]; then
  echo "[installCMake] Root privileges are required for installation. Requesting sudo elevation..."
  exec sudo -E bash "$0" --elevated
fi

# Step 5: Register cleanup for temporary files.
cleanup() {
  rm -rf "${TMP_DIR}"
}
trap cleanup EXIT

# Step 6: Download the CMake archive.
echo "[installCMake] Install location=${TARGET_DIR}"
echo "[installCMake] Using CMake version=${CMAKE_FULL_VERSION}"
echo "[installCMake] Downloading ${DOWNLOAD_URL}"

if command -v curl >/dev/null 2>&1; then
  curl -fL "${DOWNLOAD_URL}" -o "${ARCHIVE_PATH}"
elif command -v wget >/dev/null 2>&1; then
  wget -O "${ARCHIVE_PATH}" "${DOWNLOAD_URL}"
else
  echo "[installCMake] ERROR: Neither curl nor wget is available."
  exit 1
fi

# Step 7: Install CMake and update the system symlink.
rm -rf "${TARGET_DIR}"
tar -xzf "${ARCHIVE_PATH}" -C "${TMP_DIR}"
mv "${TMP_DIR}/cmake-${CMAKE_FULL_VERSION}-linux-${CMAKE_ARCH}" "${TARGET_DIR}"
ln -sfn "${TARGET_DIR}/bin/cmake" /usr/local/bin/cmake

# Step 8: Report installed system location.
echo "[installCMake] Installed system CMake at ${TARGET_DIR}"
echo "[installCMake] Binary symlink: /usr/local/bin/cmake"

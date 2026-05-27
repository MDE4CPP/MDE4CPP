#!/usr/bin/env bash
set -euo pipefail

echo "[installCMake] MDE4CPP_CMAKE_VERSION=${MDE4CPP_CMAKE_VERSION:-}"
echo "[installCMake] MDE4CPP_CMAKE_BUILD_VERSION=${MDE4CPP_CMAKE_BUILD_VERSION:-}"

if [[ -z "${MDE4CPP_CMAKE_VERSION:-}" ]]; then
  echo "[installCMake] ERROR: MDE4CPP_CMAKE_VERSION is not set."
  exit 1
fi
if [[ -z "${MDE4CPP_CMAKE_BUILD_VERSION:-}" ]]; then
  echo "[installCMake] ERROR: MDE4CPP_CMAKE_BUILD_VERSION is not set."
  exit 1
fi

if command -v cmake >/dev/null 2>&1; then
  INSTALLED_VERSION="$(cmake --version | awk 'NR==1 {print $3}')"
  REQUESTED_VERSION="${MDE4CPP_CMAKE_VERSION}.${MDE4CPP_CMAKE_BUILD_VERSION}"
  if [[ "${INSTALLED_VERSION}" == "${REQUESTED_VERSION}" ]]; then
    echo "[installCMake] CMake ${REQUESTED_VERSION} is already installed. Skipping."
    exit 0
  fi
  echo "[installCMake] Found installed CMake ${INSTALLED_VERSION}. Installing ${REQUESTED_VERSION}."
else
  echo "[installCMake] CMake is not installed. Installing ${MDE4CPP_CMAKE_VERSION}.${MDE4CPP_CMAKE_BUILD_VERSION}."
fi

if ! command -v brew >/dev/null 2>&1; then
  echo "[installCMake] ERROR: Homebrew is required on macOS. Install it from https://brew.sh/"
  exit 1
fi

echo "[installCMake] Installing CMake via Homebrew"
brew update
brew install cmake

if ! command -v cmake >/dev/null 2>&1; then
  echo "[installCMake] ERROR: CMake was not installed successfully."
  exit 1
fi

cmake --version

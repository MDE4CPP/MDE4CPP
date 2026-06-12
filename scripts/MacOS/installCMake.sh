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
  
  # Compare versions (macOS compatible, avoiding GNU sort -V)
  IS_SATISFIED=$(awk -v req="$REQUESTED_VERSION" -v inst="$INSTALLED_VERSION" '
    BEGIN {
      split(req, r, "."); split(inst, i, ".");
      for (n=1; n<=3; n++) {
        r[n] += 0; i[n] += 0;
        if (i[n] > r[n]) { print 1; exit }
        if (i[n] < r[n]) { print 0; exit }
      }
      print 1;
    }')

  if [[ "$IS_SATISFIED" == "1" ]]; then
    echo "[installCMake] CMake ${INSTALLED_VERSION} is installed (satisfies >= ${REQUESTED_VERSION}). Skipping."
    exit 0
  fi
  echo "[installCMake] Found installed CMake ${INSTALLED_VERSION}, but ${REQUESTED_VERSION} or newer is required. Installing via Homebrew."
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

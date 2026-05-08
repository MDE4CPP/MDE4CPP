#!/usr/bin/env bash
set -euo pipefail

# Step 1: Ensure elevated privileges for package installation.
if [[ "${1:-}" != "--elevated" ]] && [[ "${EUID}" -ne 0 ]]; then
  echo "[installJava] Root privileges are required. Requesting sudo elevation..."
  exec sudo -E bash "$0" --elevated
fi

# Step 2: Validate required Java version input.
echo "[installJava] MDE4CPP_JAVA_VERSION=${MDE4CPP_JAVA_VERSION:-}"
if [[ -z "${MDE4CPP_JAVA_VERSION:-}" ]]; then
  echo "[installJava] ERROR: MDE4CPP_JAVA_VERSION is not set."
  exit 1
fi

# Step 3: Skip installation when requested version is already installed.
if command -v java >/dev/null 2>&1; then
  INSTALLED_MAJOR="$(java -version 2>&1 | awk -F[\".] '/version/ {print $2; exit}')"
  if [[ "${INSTALLED_MAJOR}" == "${MDE4CPP_JAVA_VERSION}" ]]; then
    echo "[installJava] Java ${MDE4CPP_JAVA_VERSION} is already installed. Skipping."
    exit 0
  fi
  echo "[installJava] Found Java ${INSTALLED_MAJOR}. Installing Java ${MDE4CPP_JAVA_VERSION}."
else
  echo "[installJava] Java is not installed. Installing Java ${MDE4CPP_JAVA_VERSION}."
fi

# Step 4: Install requested Java version using system package manager.
export DEBIAN_FRONTEND=noninteractive
apt-get update
apt-get install -y "openjdk-${MDE4CPP_JAVA_VERSION}-jdk"

# Step 5: Verify and report installed Java version.
java -version

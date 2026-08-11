#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "${SCRIPT_DIR}/common.sh"

print_header "install_eclipse" "Running Eclipse installation..."

echo "${C_PURPLE}[install_eclipse]${C_ORANGE} MDE4CPP_ECLIPSE_VERSION=${MDE4CPP_ECLIPSE_VERSION:-}${C_RESET}"
echo "${C_PURPLE}[install_eclipse]${C_ORANGE} MDE4CPP_ECLIPSE_MILESTONE=${MDE4CPP_ECLIPSE_MILESTONE:-}${C_RESET}"

if [[ -z "${MDE4CPP_HOME:-}" ]]; then
  echo "${C_PURPLE}[install_eclipse]${C_ERROR} ERROR: MDE4CPP_HOME is not set.${C_RESET}"
  exit 1
fi
if [[ -z "${MDE4CPP_ECLIPSE_VERSION:-}" ]]; then
  echo "${C_PURPLE}[install_eclipse]${C_ERROR} ERROR: MDE4CPP_ECLIPSE_VERSION is not set.${C_RESET}"
  exit 1
fi

MDE4CPP_PARENT="$(cd "${MDE4CPP_HOME}/.." && pwd)"
if [[ -n "${MDE4CPP_ECLIPSE_LOCATION:-}" ]]; then
  TARGET_DIR="${MDE4CPP_ECLIPSE_LOCATION}"
else
  TARGET_DIR="${MDE4CPP_ECLIPSE_TARGET_DIR:-${MDE4CPP_PARENT}/eclipse}"
fi
TMP_DIR="$(mktemp -d)"

cleanup() {
  rm -rf "${TMP_DIR}"
}
trap cleanup EXIT

echo "MDE4CPP_HOME=${MDE4CPP_HOME}"
echo "Install location=${TARGET_DIR}"

ECLIPSE_BIN=""

if [ "$(uname -s)" = "Darwin" ]; then
    ARCH_SUFFIX=$(get_arch)
    ECLIPSE_ARCHIVE_URL="https://ftp.halifax.rwth-aachen.de/eclipse/technology/epp/downloads/release/${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/}/${MDE4CPP_ECLIPSE_MILESTONE//[[:space:]]/}/eclipse-modeling-${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/}-${MDE4CPP_ECLIPSE_MILESTONE//[[:space:]]/}-macosx-cocoa-${ARCH_SUFFIX}.tar.gz"
    ARCHIVE_PATH="${TMP_DIR}/eclipse-modeling.tar.gz"
    ECLIPSE_BIN="${TARGET_DIR}/Eclipse.app/Contents/MacOS/eclipse"
else
    # Linux
    ECLIPSE_ARCH=$(get_arch)
    ECLIPSE_ARCHIVE_URL="https://ftp.halifax.rwth-aachen.de/eclipse/technology/epp/downloads/release/${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/}/${MDE4CPP_ECLIPSE_MILESTONE//[[:space:]]/}/eclipse-modeling-${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/}-${MDE4CPP_ECLIPSE_MILESTONE//[[:space:]]/}-linux-gtk-${ECLIPSE_ARCH}.tar.gz"
    ARCHIVE_PATH="${TMP_DIR}/eclipse-modeling.tar.gz"
    ECLIPSE_BIN="${TARGET_DIR}/eclipse"
fi

if [[ -x "${ECLIPSE_BIN}" ]]; then
  echo "${C_PURPLE}[install_eclipse]${C_SUCCESS} Existing Eclipse installation found at ${TARGET_DIR}.${C_RESET}"
  exit 0
fi

echo "Downloading ${ECLIPSE_ARCHIVE_URL}"
download_file "${ECLIPSE_ARCHIVE_URL}" "${ARCHIVE_PATH}"

rm -rf "${TARGET_DIR}"
if [ "$(uname -s)" = "Darwin" ]; then
    mkdir -p "${TARGET_DIR}"
    tar -xzf "${ARCHIVE_PATH}" -C "${TARGET_DIR}"
else
    TARGET_PARENT="$(dirname "${TARGET_DIR}")"
    mkdir -p "${TARGET_PARENT}"
    tar -xzf "${ARCHIVE_PATH}" -C "${TARGET_PARENT}"
    if [ "$(basename "${TARGET_DIR}")" != "eclipse" ]; then
        mv "${TARGET_PARENT}/eclipse" "${TARGET_DIR}"
    fi
fi

if [[ ! -x "${ECLIPSE_BIN}" ]]; then
  echo "${C_PURPLE}[install_eclipse]${C_ERROR} ERROR: Eclipse binary not found at ${ECLIPSE_BIN}${C_RESET}"
  exit 1
fi

echo "${C_PURPLE}[install_eclipse]${C_SUCCESS} Eclipse installation finished: ${TARGET_DIR}${C_RESET}"

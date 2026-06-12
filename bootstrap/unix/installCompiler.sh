#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "${SCRIPT_DIR}/../common.sh"

echo "[installCompiler] MDE4CPP_COMPILER_VERSION=${MDE4CPP_COMPILER_VERSION:-}"
if [[ -z "${MDE4CPP_COMPILER_VERSION:-}" ]]; then
    echo "[installCompiler] ERROR: MDE4CPP_COMPILER_VERSION is not set."
    exit 1
fi

if [ "$(uname -s)" = "Darwin" ]; then
    GCC_MAJOR="${MDE4CPP_COMPILER_VERSION%%.*}"
    if command -v "g++-$GCC_MAJOR" >/dev/null 2>&1; then
        echo "[installCompiler] g++-$GCC_MAJOR is already installed."
        exit 0
    fi
    echo "[installCompiler] Installing gcc@$GCC_MAJOR via Homebrew..."
    brew install "gcc@$GCC_MAJOR"
else
    # Linux logic
    GPP_PATH=""
    CPP_PATH=""

    if command -v g++ >/dev/null 2>&1; then
      INSTALLED_GCC="$(g++ -dumpfullversion 2>&1)"
      if [[ "${INSTALLED_GCC}" == "${MDE4CPP_COMPILER_VERSION}"* ]]; then
        echo "[installCompiler] GCC ${INSTALLED_GCC} is already installed. Skipping."
        exit 0
      fi
      echo "[installCompiler] Found GCC ${INSTALLED_GCC}. Installing GCC ${MDE4CPP_COMPILER_VERSION}."
    else
      echo "[installCompiler] GCC is not installed. Installing GCC ${MDE4CPP_COMPILER_VERSION}."
    fi

    require_sudo "$@"

    pkg_mgr=""
    install_cmd=""
    update_cmd=""
    install_pkgs=""

    if command -v apt-get >/dev/null 2>&1; then
      pkg_mgr="apt"
      update_cmd="apt-get update"
      install_cmd="apt-get install -y"
      install_pkgs="g++-${MDE4CPP_COMPILER_VERSION%%.*} gcc-${MDE4CPP_COMPILER_VERSION%%.*} make"
    elif command -v dnf >/dev/null 2>&1; then
      pkg_mgr="dnf"
      update_cmd="dnf makecache"
      install_cmd="dnf install -y"
      install_pkgs="gcc-c++ gcc make"
    elif command -v yum >/dev/null 2>&1; then
      pkg_mgr="yum"
      update_cmd="yum makecache"
      install_cmd="yum install -y"
      install_pkgs="gcc-c++ gcc make"
    elif command -v zypper >/dev/null 2>&1; then
      pkg_mgr="zypper"
      update_cmd="zypper refresh"
      install_cmd="zypper install -yn"
      install_pkgs="gcc-c++ gcc make"
    elif command -v pacman >/dev/null 2>&1; then
      pkg_mgr="pacman"
      update_cmd="pacman -Sy --noconfirm"
      install_cmd="pacman -S --noconfirm"
      install_pkgs="gcc make"
    else
      echo "[installCompiler] ERROR: No supported package manager found."
      exit 1
    fi

    echo "[installCompiler] Using package manager: ${pkg_mgr}"
    ${update_cmd}
    ${install_cmd} ${install_pkgs}

    if [[ -z "${GPP_PATH}" ]]; then
      GPP_PATH="$(command -v g++)"
    fi
    if [[ -z "${CPP_PATH}" ]] && command -v cpp >/dev/null 2>&1; then
      CPP_PATH="$(command -v cpp)"
    fi

    if [[ -n "${GPP_PATH}" && -n "${CPP_PATH}" ]]; then
      echo "[installCompiler] Installed compiler versions:"
      "${GPP_PATH}" --version | head -n1
      "${CPP_PATH}" --version | head -n1
    else
      echo "[installCompiler] WARNING: Could not detect g++ or cpp path after installation."
    fi
fi

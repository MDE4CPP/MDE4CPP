#!/usr/bin/env bash
set -euo pipefail

echo "[installCompiler] MDE4CPP_COMPILER_VERSION=${MDE4CPP_COMPILER_VERSION:-}"
if [[ -z "${MDE4CPP_COMPILER_VERSION:-}" ]]; then
  echo "[installCompiler] ERROR: MDE4CPP_COMPILER_VERSION is not set."
  exit 1
fi

MAJOR="${MDE4CPP_COMPILER_VERSION%%.*}"
if ! [[ "${MAJOR}" =~ ^[0-9]+$ ]]; then
  echo "[installCompiler] ERROR: Invalid compiler version '${MDE4CPP_COMPILER_VERSION}'."
  exit 1
fi

if command -v gcc >/dev/null 2>&1; then
  INSTALLED_MAJOR="$(gcc -dumpversion | cut -d. -f1)"
  if [[ "${INSTALLED_MAJOR}" == "${MAJOR}" ]]; then
    echo "[installCompiler] GCC ${MAJOR} is already installed. Skipping."
    exit 0
  fi
  echo "[installCompiler] Found GCC ${INSTALLED_MAJOR}. Installing GCC ${MAJOR}."
else
  echo "[installCompiler] GCC is not installed. Installing GCC ${MAJOR}."
fi

if [[ "${1:-}" != "--elevated" ]] && [[ "${EUID}" -ne 0 ]]; then
  echo "[installCompiler] Root privileges are required for installation. Requesting sudo elevation..."
  exec sudo -E bash "$0" --elevated
fi

pkg_mgr=""
update_cmd=""
install_cmd=""
install_pkgs=()

if command -v apt-get >/dev/null 2>&1; then
  pkg_mgr="apt"
  update_cmd="apt-get update"
  install_cmd="apt-get install -y"
  install_pkgs=("gcc-${MAJOR}" "g++-${MAJOR}" "cpp-${MAJOR}")
elif command -v dnf >/dev/null 2>&1; then
  pkg_mgr="dnf"
  update_cmd="dnf makecache"
  install_cmd="dnf install -y"
  install_pkgs=("gcc" "gcc-c++")
elif command -v yum >/dev/null 2>&1; then
  pkg_mgr="yum"
  update_cmd="yum makecache"
  install_cmd="yum install -y"
  install_pkgs=("gcc" "gcc-c++")
elif command -v zypper >/dev/null 2>&1; then
  pkg_mgr="zypper"
  update_cmd="zypper refresh"
  install_cmd="zypper install -yn"
  install_pkgs=("gcc" "gcc-c++")
elif command -v pacman >/dev/null 2>&1; then
  pkg_mgr="pacman"
  update_cmd="pacman -Sy --noconfirm"
  install_cmd="pacman -S --noconfirm"
  install_pkgs=("gcc")
else
  echo "[installCompiler] ERROR: No supported package manager found (apt, dnf, yum, zypper, pacman)."
  exit 1
fi

echo "[installCompiler] Using package manager: ${pkg_mgr}"
${update_cmd}
${install_cmd} "${install_pkgs[@]}"

GCC_PATH=""
GPP_PATH=""
CPP_PATH=""

if [[ -x "/usr/bin/gcc-${MAJOR}" ]]; then
  GCC_PATH="/usr/bin/gcc-${MAJOR}"
fi
if [[ -x "/usr/bin/g++-${MAJOR}" ]]; then
  GPP_PATH="/usr/bin/g++-${MAJOR}"
fi
if [[ -x "/usr/bin/cpp-${MAJOR}" ]]; then
  CPP_PATH="/usr/bin/cpp-${MAJOR}"
fi

if [[ -z "${GCC_PATH}" ]]; then
  GCC_PATH="$(command -v gcc)"
fi
if [[ -z "${GPP_PATH}" ]]; then
  GPP_PATH="$(command -v g++)"
fi
if [[ -z "${CPP_PATH}" && command -v cpp >/dev/null 2>&1 ]]; then
  CPP_PATH="$(command -v cpp)"
fi

if [[ -z "${GCC_PATH}" || -z "${GPP_PATH}" ]]; then
  echo "[installCompiler] ERROR: Installed compiler binaries not found."
  exit 1
fi

PRIORITY=$((MAJOR * 10))
for tool in gcc g++; do
  if [[ "${tool}" == "g++" ]]; then
    alt_path="${GPP_PATH}"
  else
    alt_path="${GCC_PATH}"
  fi
  if [[ -x "${alt_path}" ]]; then
    if ! update-alternatives --list "${tool}" 2>/dev/null | grep -Fxq "${alt_path}"; then
      update-alternatives --install "/usr/bin/${tool}" "${tool}" "${alt_path}" "${PRIORITY}"
    fi
    update-alternatives --set "${tool}" "${alt_path}"
  fi
done

if [[ -n "${CPP_PATH}" ]]; then
  if ! update-alternatives --list cpp 2>/dev/null | grep -Fxq "${CPP_PATH}"; then
    update-alternatives --install "/usr/bin/cpp" cpp "${CPP_PATH}" "${PRIORITY}"
  fi
  update-alternatives --set cpp "${CPP_PATH}"
fi

gcc --version

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

if command -v "gcc-${MAJOR}" >/dev/null 2>&1; then
  echo "[installCompiler] GCC ${MAJOR} is already installed. Skipping."
  exit 0
fi

echo "[installCompiler] GCC ${MAJOR} is not installed or not available as gcc-${MAJOR}."

if ! command -v brew >/dev/null 2>&1; then
  echo "[installCompiler] ERROR: Homebrew is required on macOS. Install it from https://brew.sh/"
  exit 1
fi

GCC_FORMULA="gcc@${MAJOR}"
echo "[installCompiler] Installing ${GCC_FORMULA} via Homebrew"
brew update
brew install "${GCC_FORMULA}"

if command -v "gcc-${MAJOR}" >/dev/null 2>&1; then
  GCC_PATH="$(command -v gcc-${MAJOR})"
else
  GCC_PREFIX="$(brew --prefix "${GCC_FORMULA}" 2>/dev/null || true)"
  GCC_PATH="${GCC_PREFIX}/bin/gcc-${MAJOR}"
fi

if [[ ! -x "${GCC_PATH}" ]]; then
  echo "[installCompiler] ERROR: gcc-${MAJOR} was not found after installation."
  exit 1
fi

if command -v "g++-${MAJOR}" >/dev/null 2>&1; then
  GPP_PATH="$(command -v g++-${MAJOR})"
else
  GPP_PATH="$(brew --prefix "${GCC_FORMULA}" 2>/dev/null || true)/bin/g++-${MAJOR}"
fi

if [[ ! -x "${GPP_PATH}" ]]; then
  echo "[installCompiler] ERROR: g++-${MAJOR} was not found after installation."
  exit 1
fi

echo "[installCompiler] Installed GCC: ${GCC_PATH}"
echo "[installCompiler] Installed G++: ${GPP_PATH}"
"${GCC_PATH}" --version

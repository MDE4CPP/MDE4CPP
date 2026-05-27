#!/usr/bin/env bash
set -euo pipefail

echo "[installEclipse] MDE4CPP_ECLIPSE_VERSION=${MDE4CPP_ECLIPSE_VERSION:-}"
echo "[installEclipse] MDE4CPP_ECLIPSE_MILESTONE=${MDE4CPP_ECLIPSE_MILESTONE:-}"
echo "[installEclipse] MDE4CPP_ECLIPSE_ACCELEO_VERSION=${MDE4CPP_ECLIPSE_ACCELEO_VERSION:-}"
echo "[installEclipse] MDE4CPP_ECLIPSE_SIRIUS_VERSION=${MDE4CPP_ECLIPSE_SIRIUS_VERSION:-}"
echo "[installEclipse] MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION=${MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION:-}"

if [[ -z "${MDE4CPP_HOME:-}" ]]; then
  echo "[installEclipse] ERROR: MDE4CPP_HOME is not set."
  exit 1
fi
if [[ -z "${MDE4CPP_ECLIPSE_VERSION:-}" ]]; then
  echo "[installEclipse] ERROR: MDE4CPP_ECLIPSE_VERSION is not set."
  exit 1
fi
if [[ -z "${MDE4CPP_ECLIPSE_MILESTONE:-}" ]]; then
  echo "[installEclipse] ERROR: MDE4CPP_ECLIPSE_MILESTONE is not set."
  exit 1
fi
if [[ -z "${MDE4CPP_ECLIPSE_ACCELEO_VERSION:-}" ]]; then
  echo "[installEclipse] ERROR: MDE4CPP_ECLIPSE_ACCELEO_VERSION is not set."
  exit 1
fi
if [[ -z "${MDE4CPP_ECLIPSE_SIRIUS_VERSION:-}" ]]; then
  echo "[installEclipse] ERROR: MDE4CPP_ECLIPSE_SIRIUS_VERSION is not set."
  exit 1
fi
if [[ -z "${MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION:-}" ]]; then
  echo "[installEclipse] ERROR: MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION is not set."
  exit 1
fi

MDE4CPP_PARENT="$(cd "${MDE4CPP_HOME}/.." && pwd)"
TARGET_DIR="${MDE4CPP_PARENT}/eclipse"
TMP_DIR="$(mktemp -d)"
ARCHIVE_PATH="${TMP_DIR}/eclipse-modeling.tar.gz"

ARCH_SUFFIX="x86_64"
if [[ "$(uname -m)" == "arm64" ]]; then
  ARCH_SUFFIX="aarch64"
fi

ECLIPSE_ARCHIVE_URL="https://ftp.halifax.rwth-aachen.de/eclipse/technology/epp/downloads/release/${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/}/${MDE4CPP_ECLIPSE_MILESTONE//[[:space:]]/}/eclipse-modeling-${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/}-${MDE4CPP_ECLIPSE_MILESTONE//[[:space:]]/}-macosx-cocoa-${ARCH_SUFFIX}.tar.gz"
ACCELEO_REPOSITORY_URL="https://download.eclipse.org/acceleo/updates/releases/${MDE4CPP_ECLIPSE_ACCELEO_VERSION//[[:space:]]/}"
SIRIUS_REPOSITORY_URL="https://download.eclipse.org/sirius/updates/releases/${MDE4CPP_ECLIPSE_SIRIUS_VERSION//[[:space:]]/}/${MDE4CPP_ECLIPSE_SIRIUS_ECLIPSE_VERSION//[[:space:]]/}"
CDT_REPOSITORY_URL="https://download.eclipse.org/releases/${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/}"

cleanup() {
  rm -rf "${TMP_DIR}"
}
trap cleanup EXIT

SKIP_DOWNLOAD=0
if [[ -x "${TARGET_DIR}/Eclipse.app/Contents/MacOS/eclipse" ]]; then
  echo "[installEclipse] Existing Eclipse installation found at ${TARGET_DIR}, skipping download and extraction."
  mkdir -p "${TMP_DIR}"
else
  if command -v curl >/dev/null 2>&1; then
    curl -fL "${ECLIPSE_ARCHIVE_URL}" -o "${ARCHIVE_PATH}"
  elif command -v wget >/dev/null 2>&1; then
    wget -O "${ARCHIVE_PATH}" "${ECLIPSE_ARCHIVE_URL}"
  else
    echo "[installEclipse] ERROR: Neither curl nor wget is available."
    exit 1
  fi

  rm -rf "${TARGET_DIR}"
  mkdir -p "${MDE4CPP_PARENT}"
  tar -xzf "${ARCHIVE_PATH}" -C "${MDE4CPP_PARENT}"
fi

if [[ ! -x "${TARGET_DIR}/Eclipse.app/Contents/MacOS/eclipse" ]]; then
  echo "[installEclipse] ERROR: Eclipse binary not found at ${TARGET_DIR}/Eclipse.app/Contents/MacOS/eclipse"
  exit 1
fi

ECLIPSE_BIN="${TARGET_DIR}/Eclipse.app/Contents/MacOS/eclipse"

echo "[installEclipse] Installing Acceleo from ${ACCELEO_REPOSITORY_URL}"
"${ECLIPSE_BIN}" \
  -nosplash \
  -application org.eclipse.equinox.p2.director \
  -repository "https://download.eclipse.org/releases/${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/},${ACCELEO_REPOSITORY_URL}" \
  -installIU org.eclipse.acceleo.feature.group \
  -installIU org.eclipse.acceleo.ui.interpreter.ocl.feature.group \
  -installIU org.eclipse.acceleo.ui.interpreter.completeocl.feature.group \
  -installIU org.eclipse.emf.sdk.feature.group \
  -installIU org.eclipse.uml2.sdk.feature.group \
  -installIU org.eclipse.ocl.all.sdk.feature.group \
  -installIU org.eclipse.acceleo.query.feature.group \
  -installIU org.eclipse.acceleo.query.source.feature.group \
  -installIU org.antlr.runtime \
  -destination "${TARGET_DIR}" \
  -profileProperties org.eclipse.update.install.features=true

if [[ $? -ne 0 ]]; then
  echo "[installEclipse] ERROR: Acceleo installation failed."
  exit 1
fi

echo "[installEclipse] Installing Sirius from ${SIRIUS_REPOSITORY_URL}"
"${ECLIPSE_BIN}" \
  -nosplash \
  -application org.eclipse.equinox.p2.director \
  -repository "${SIRIUS_REPOSITORY_URL}" \
  -installIU org.eclipse.sirius.common.acceleo.aql \
  -installIU org.eclipse.sirius.ui.properties \
  -installIU org.eclipse.sirius.aql.feature.group \
  -installIU org.eclipse.sirius.common.acceleo.aql \
  -installIU org.eclipse.sirius.runtime.aql.feature.group \
  -installIU org.eclipse.sirius.properties.feature.feature.group \
  -installIU org.eclipse.sirius.aql.source.feature.group \
  -installIU org.eclipse.sirius.aql.feature.group \
  -installIU org.eclipse.sirius.interpreter.feature.feature.group \
  -installIU org.eclipse.sirius.interpreter.feature.source.feature.group \
  -installIU org.eclipse.sirius.model.feature.source.feature.group \
  -installIU org.eclipse.sirius.properties.feature.source.feature.group \
  -installIU org.eclipse.sirius.runtime.aql.source.feature.group \
  -installIU org.eclipse.sirius.runtime.ide.ui.feature.group \
  -installIU org.eclipse.sirius.specifier.feature.group \
  -installIU org.eclipse.sirius.specifier.ide.ui.aql.feature.group \
  -installIU org.eclipse.sirius.specifier.ide.ui.aql.source.feature.group \
  -installIU org.eclipse.sirius.specifier.ide.ui.feature.group \
  -installIU org.eclipse.sirius.specifier.ide.ui.source.feature.group \
  -installIU org.eclipse.sirius.specifier.properties.feature.feature.group \
  -installIU org.eclipse.sirius.specifier.properties.feature.source.feature.group \
  -installIU org.eclipse.sirius.specifier.source.feature.group \
  -installIU org.eclipse.eef.ext.widgets.reference.feature.feature.group \
  -installIU org.eclipse.eef.ext.widgets.reference.feature.source.feature.group \
  -installIU org.eclipse.eef.sdk.feature.feature.group \
  -installIU org.eclipse.eef.sdk.feature.source.feature.group \
  -destination "${TARGET_DIR}" \
  -profileProperties org.eclipse.update.install.features=true

if [[ $? -ne 0 ]]; then
  echo "[installEclipse] ERROR: Sirius installation failed."
  exit 1
fi

echo "[installEclipse] Installing CDT from ${CDT_REPOSITORY_URL}"
"${ECLIPSE_BIN}" \
  -nosplash \
  -application org.eclipse.equinox.p2.director \
  -repository "${CDT_REPOSITORY_URL}" \
  -installIU org.eclipse.cdt.feature.group \
  -destination "${TARGET_DIR}" \
  -profileProperties org.eclipse.update.install.features=true

if [[ $? -ne 0 ]]; then
  echo "[installEclipse] ERROR: CDT installation failed."
  exit 1
fi

echo "[installEclipse] Eclipse installation finished: ${TARGET_DIR}"

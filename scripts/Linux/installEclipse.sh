#!/usr/bin/env bash
set -euo pipefail

# Step 1: Print requested Eclipse component versions.
echo "Installing Eclipse ${MDE4CPP_ECLIPSE_VERSION} with Acceleo ${MDE4CPP_ECLIPSE_ACCELEO_VERSION} and Sirius ${MDE4CPP_ECLIPSE_SIRIUS_VERSION}"

# Step 2: Validate required input variables.
if [[ -z "${MDE4CPP_HOME:-}" ]]; then
  echo "MDE4CPP_HOME is not set."
  exit 1
fi

if [[ -z "${MDE4CPP_ECLIPSE_VERSION:-}" ]]; then
  echo "MDE4CPP_ECLIPSE_VERSION is not set."
  exit 1
fi

if [[ -z "${MDE4CPP_ECLIPSE_MILESTONE:-}" ]]; then
  echo "MDE4CPP_ECLIPSE_MILESTONE is not set."
  exit 1
fi

if [[ -z "${MDE4CPP_ECLIPSE_ACCELEO_VERSION:-}" ]]; then
  echo "MDE4CPP_ECLIPSE_ACCELEO_VERSION is not set."
  exit 1
fi

if [[ -z "${MDE4CPP_ECLIPSE_SIRIUS_VERSION:-}" ]]; then
  echo "MDE4CPP_ECLIPSE_SIRIUS_VERSION is not set."
  exit 1
fi

# Step 3: Resolve installation paths and download URLs.
MDE4CPP_PARENT="$(cd "${MDE4CPP_HOME}/.." && pwd)"
TARGET_DIR="${MDE4CPP_PARENT}/eclipse"
TMP_DIR="$(mktemp -d)"
ARCHIVE_PATH="${TMP_DIR}/eclipse-modeling.tar.gz"

ECLIPSE_ARCHIVE_URL="https://archive.eclipse.org/technology/epp/downloads/release/${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/}/${MDE4CPP_ECLIPSE_MILESTONE//[[:space:]]/}/eclipse-modeling-${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/}-${MDE4CPP_ECLIPSE_MILESTONE//[[:space:]]/}-linux-gtk-x86_64.tar.gz"
ACCELEO_REPOSITORY_URL="https://download.eclipse.org/acceleo/updates/releases/${MDE4CPP_ECLIPSE_ACCELEO_VERSION//[[:space:]]/}"
SIRIUS_REPOSITORY_URL="https://download.eclipse.org/sirius/updates/releases/${MDE4CPP_ECLIPSE_SIRIUS_VERSION//[[:space:]]/}"
CDT_REPOSITORY_URL="https://download.eclipse.org/releases/${MDE4CPP_ECLIPSE_VERSION//[[:space:]]/}"

# Step 4: Register cleanup for temporary files.
cleanup() {
  rm -rf "${TMP_DIR}"
}
trap cleanup EXIT

# Step 5: Download and extract Eclipse Modeling package.
echo "MDE4CPP_HOME=${MDE4CPP_HOME}"
echo "Install location=${TARGET_DIR}"
echo "Using Eclipse version=${MDE4CPP_ECLIPSE_VERSION}, milestone=${MDE4CPP_ECLIPSE_MILESTONE}, Acceleo=${MDE4CPP_ECLIPSE_ACCELEO_VERSION}, Sirius=${MDE4CPP_ECLIPSE_SIRIUS_VERSION}"
echo "Downloading ${ECLIPSE_ARCHIVE_URL}"

if command -v curl >/dev/null 2>&1; then
  curl -fL "${ECLIPSE_ARCHIVE_URL}" -o "${ARCHIVE_PATH}"
elif command -v wget >/dev/null 2>&1; then
  wget -O "${ARCHIVE_PATH}" "${ECLIPSE_ARCHIVE_URL}"
else
  echo "Neither curl nor wget is available."
  exit 1
fi

rm -rf "${TARGET_DIR}"
mkdir -p "${MDE4CPP_PARENT}"
tar -xzf "${ARCHIVE_PATH}" -C "${MDE4CPP_PARENT}"

# Step 6: Install Acceleo into the Eclipse installation.
echo "Installing Acceleo from ${ACCELEO_REPOSITORY_URL}"
"${TARGET_DIR}/eclipse" \
  -nosplash \
  -application org.eclipse.equinox.p2.director \
  -repository "${ACCELEO_REPOSITORY_URL}" \
  -installIU org.eclipse.acceleo.feature.group \
  -destination "${TARGET_DIR}" \
  -profile SDKProfile \
  -profileProperties org.eclipse.update.install.features=true \
  -roaming

# Step 7: Install Sirius into the Eclipse installation.
echo "Installing Sirius from ${SIRIUS_REPOSITORY_URL}"
"${TARGET_DIR}/eclipse" \
  -nosplash \
  -application org.eclipse.equinox.p2.director \
  -repository "${SIRIUS_REPOSITORY_URL}" \
  -installIU org.eclipse.sirius.feature.group \
  -destination "${TARGET_DIR}" \
  -profile SDKProfile \
  -profileProperties org.eclipse.update.install.features=true \
  -roaming

# Step 8: Report completion.
# Step 8: Install CDT into the Eclipse installation.
echo "Installing CDT from ${CDT_REPOSITORY_URL}"
"${TARGET_DIR}/eclipse" \
  -nosplash \
  -application org.eclipse.equinox.p2.director \
  -repository "${CDT_REPOSITORY_URL}" \
  -installIU org.eclipse.cdt.feature.group \
  -destination "${TARGET_DIR}" \
  -profile SDKProfile \
  -profileProperties org.eclipse.update.install.features=true \
  -roaming

# Step 9: Report completion.
echo "Eclipse installation finished: ${TARGET_DIR}"

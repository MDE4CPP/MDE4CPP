# Optimized for MDE4CPP runtime builds
ARG JAVA_VERSION=21
ARG OS_VERSION=jammy

FROM eclipse-temurin:${JAVA_VERSION}-jdk-${OS_VERSION}
ARG OS_VERSION

LABEL org.opencontainers.image.title="MDE4CPP" \
      org.opencontainers.image.description="Docker environment for MDE4CPP" \
      org.opencontainers.image.authors="MDE4CPP Team"

SHELL ["/bin/bash", "-o", "pipefail", "-c"]

ENV JAVA_HOME=/opt/java/openjdk \
    MDE4CPP_HOME=/home/mde4cpp \
    LANG=C.UTF-8 \
    LANGUAGE=C.UTF-8 \
    LC_ALL=C.UTF-8

# Configure apt caching, add Kitware repo, and install dependencies
RUN --mount=type=cache,target=/var/cache/apt,sharing=locked \
    --mount=type=cache,target=/var/lib/apt,sharing=locked \
    rm -f /etc/apt/apt.conf.d/docker-clean \
    && echo 'Binary::apt::APT::Keep-Downloaded-Packages "true";' > /etc/apt/apt.conf.d/keep-cache \
    && export DEBIAN_FRONTEND=noninteractive \
    && apt-get update && apt-get install -y --no-install-recommends ca-certificates gnupg wget \
    && mkdir -p /etc/apt/keyrings \
    && wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc | gpg --dearmor -o /etc/apt/keyrings/kitware-archive-keyring.gpg \
    && echo "deb [signed-by=/etc/apt/keyrings/kitware-archive-keyring.gpg] https://apt.kitware.com/ubuntu/ ${OS_VERSION} main" > /etc/apt/sources.list.d/kitware.list \
    && apt-get update \
    && apt-get install -y --no-install-recommends \
    bash \
    build-essential \
    cmake \
    g++ \
    g++-mingw-w64-x86-64 \
    gcc \
    gcc-mingw-w64-x86-64 \
    git \
    mingw-w64 \
    ninja-build \
    sudo \
    tar \
    unzip \
    uuid-dev \
    && update-alternatives --set x86_64-w64-mingw32-g++ /usr/bin/x86_64-w64-mingw32-g++-posix 2>/dev/null || true \
    && update-alternatives --set x86_64-w64-mingw32-gcc /usr/bin/x86_64-w64-mingw32-gcc-posix 2>/dev/null || true

ARG USER_UID=1000
ARG USER_GID=1000

# Configure non-root user with passwordless sudo
RUN groupadd --gid ${USER_GID} mde4cpp || true \
    && useradd --uid ${USER_UID} --gid ${USER_GID} -m -s /bin/bash -d /home/mde4cpp mde4cpp \
    && echo "mde4cpp ALL=(ALL) NOPASSWD:ALL" > /etc/sudoers.d/mde4cpp \
    && chmod 0440 /etc/sudoers.d/mde4cpp \
    && mkdir -p /home/eclipse \
    && chown mde4cpp:mde4cpp /home/eclipse

WORKDIR /home/mde4cpp
USER mde4cpp
CMD ["/bin/bash"]

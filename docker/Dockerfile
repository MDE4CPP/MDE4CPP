# Optimized for runtime builds via docker-compose
# System packages installed at build time, Eclipse at runtime

# ============================================================================
# Base Image with JDK
# ============================================================================
FROM eclipse-temurin:21-jdk-jammy

LABEL org.opencontainers.image.title="MDE4CPP" \
      org.opencontainers.image.description="Docker environment for MDE4CPP" \
      org.opencontainers.image.authors="MDE4CPP Team"

# Use bash and enable pipefail for safer pipe operations
SHELL ["/bin/bash", "-o", "pipefail", "-c"]

# Enable apt caching for BuildKit (fixes default Ubuntu behavior of cleaning cache)
RUN rm -f /etc/apt/apt.conf.d/docker-clean \
    && echo 'Binary::apt::APT::Keep-Downloaded-Packages "true";' > /etc/apt/apt.conf.d/keep-cache

# Install system build dependencies (these go to /usr/bin, not affected by bind mounts)
# We do this in a single layer to minimize image size
# Uses BuildKit cache to speed up rebuilds and DEBIAN_FRONTEND to suppress warnings
RUN --mount=type=cache,target=/var/cache/apt \
    --mount=type=cache,target=/var/lib/apt \
    export DEBIAN_FRONTEND=noninteractive \
    && apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates \
    gnupg \
    wget \
    && wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc | gpg --dearmor -o /usr/share/keyrings/kitware-archive-keyring.gpg \
    && echo "deb [signed-by=/usr/share/keyrings/kitware-archive-keyring.gpg] https://apt.kitware.com/ubuntu/ jammy main" > /etc/apt/sources.list.d/kitware.list \
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
    sudo \
    tar \
    unzip \
    uuid-dev \
    && update-alternatives --set x86_64-w64-mingw32-g++ /usr/bin/x86_64-w64-mingw32-g++-posix 2>/dev/null || true \
    && update-alternatives --set x86_64-w64-mingw32-gcc /usr/bin/x86_64-w64-mingw32-gcc-posix 2>/dev/null || true

# Set essential environment variables (Java, Workspace, and UTF-8 Locale)
ENV JAVA_HOME=/opt/java/openjdk \
    MDE4CPP_HOME=/home/mde4cpp \
    LANG=C.UTF-8 \
    LANGUAGE=C.UTF-8 \
    LC_ALL=C.UTF-8

# Define configurable user/group IDs for better host volume permission matching
ARG USER_UID=1000
ARG USER_GID=1000

# Create user, project directory structure, and configure passwordless sudo
RUN groupadd --gid ${USER_GID} mde4cpp || true \
    && useradd --uid ${USER_UID} --gid ${USER_GID} -m -s /bin/bash -d /home/mde4cpp mde4cpp \
    && echo "mde4cpp ALL=(ALL) NOPASSWD:ALL" > /etc/sudoers.d/mde4cpp \
    && chmod 0440 /etc/sudoers.d/mde4cpp \
    && mkdir -p /home/mde4cpp /home/eclipse \
    && chown -R mde4cpp:mde4cpp /home/mde4cpp /home/eclipse

# Set working directory
WORKDIR /home/mde4cpp

# Note: Eclipse and user-space dependencies are installed at runtime
# via bind mount and docker/scripts/install-eclipse.sh in the build-full service
# System packages (cmake, gcc, etc.) are already in the image

# Default to non-root user
USER mde4cpp

# Default command when running the container standalone
CMD ["/bin/bash"]

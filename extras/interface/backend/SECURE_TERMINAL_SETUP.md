# Secure Terminal Setup Guide

This guide explains how to set up and use the secure terminal architecture that prevents server compromise.

## Overview

The secure terminal runs each user session in an isolated Docker container with:
- **Network isolation** - No internet access
- **Resource limits** - CPU and memory restrictions
- **Read-only filesystem** - MDE4CPP_HOME mounted read-only
- **Non-root execution** - Runs as unprivileged user
- **Automatic cleanup** - Containers destroyed after inactivity

## Prerequisites

1. **Docker** must be installed and running
   - Windows: Docker Desktop
   - Linux: Docker Engine
   - macOS: Docker Desktop

2. **Node.js dependencies** installed:
   ```bash
   npm install
   ```

## Setup Steps

### 1. Build the Terminal Docker Image

**Windows:**
```powershell
cd d:\DEV\test2\MDE4CPP\interface\backend
.\scripts\build-terminal-image.ps1
```

**Linux/macOS:**
```bash
cd /path/to/MDE4CPP/interface/backend
chmod +x scripts/build-terminal-image.sh
./scripts/build-terminal-image.sh
```

**Or manually:**
```bash
docker build -f docker/Dockerfile.terminal -t mde4cpp-terminal:latest docker/
```

### 2. Verify Docker Connection

The server will automatically verify Docker connectivity on startup. If Docker is not available, you'll see an error message.

### 3. Configure Environment (Optional)

Create a `.env` file in the backend directory to customize settings:

```env
# Enable/disable containerized terminal (default: true)
TERMINAL_USE_CONTAINERS=true

# Docker image name (default: mde4cpp-terminal:latest)
TERMINAL_DOCKER_IMAGE=mde4cpp-terminal:latest

# Container memory limit in MB (default: 512)
TERMINAL_MEMORY_LIMIT_MB=512

# Container CPU shares (default: 512 = 50% of one CPU)
TERMINAL_CPU_SHARES=512

# Idle timeout in milliseconds (default: 3600000 = 1 hour)
TERMINAL_IDLE_TIMEOUT_MS=3600000

# Command timeout in milliseconds (default: 600000 = 10 minutes)
TERMINAL_COMMAND_TIMEOUT_MS=600000

# Disable network in containers (default: true)
TERMINAL_NETWORK_DISABLED=true

# Mount MDE4CPP_HOME as read-only (default: true)
TERMINAL_READONLY_MDE4CPP=true

# Maximum concurrent terminal sessions (default: 10)
TERMINAL_MAX_SESSIONS=10
```

### 4. Start the Server

```bash
npm start
```

The terminal will automatically use containers if `TERMINAL_USE_CONTAINERS=true` (default).

## Security Features

### Container Isolation
- Each terminal session runs in its own Docker container
- Containers are completely isolated from each other
- No access to host filesystem (except mounted volumes)

### Network Isolation
- Containers have no network access by default
- Prevents data exfiltration
- Prevents downloading malicious scripts

### Resource Limits
- Memory limit: 512MB per container (configurable)
- CPU limit: 50% of one CPU core (configurable)
- Prevents resource exhaustion attacks

### Filesystem Protection
- MDE4CPP_HOME mounted as read-only
- Prevents modification of server files
- Only workspace directory is writable

### User Isolation
- Containers run as non-root user (UID 1000)
- Prevents privilege escalation
- No access to system files

### Automatic Cleanup
- Idle containers destroyed after 1 hour
- Containers removed when session closes
- Prevents resource leaks

## Troubleshooting

### Docker Not Available

**Error:** `ERROR: Docker is not available`

**Solution:**
1. Ensure Docker is installed and running
2. Verify Docker socket path:
   - Windows: `//./pipe/docker_engine`
   - Linux: `/var/run/docker.sock`
3. Check Docker permissions (Linux: add user to docker group)

### Container Creation Fails

**Error:** `Failed to create container`

**Solution:**
1. Verify Docker image exists: `docker images | grep mde4cpp-terminal`
2. Rebuild image if missing
3. Check Docker logs: `docker logs <container-name>`

### Permission Denied

**Error:** `Permission denied` when accessing files

**Solution:**
1. Check file permissions in workspace directory
2. Verify user mapping (UID 1000:1000)
3. Ensure workspace directory is writable

### Container Timeout

**Error:** `Command timed out`

**Solution:**
1. Increase timeout: `TERMINAL_COMMAND_TIMEOUT_MS=1200000` (20 minutes)
2. Check if command is actually running
3. Verify resource limits aren't too restrictive

## Disabling Secure Terminal (NOT RECOMMENDED)

If you must disable containerization (NOT RECOMMENDED for production):

```env
TERMINAL_USE_CONTAINERS=false
```

**Warning:** This exposes your server to potential compromise. Only use in development environments with trusted users.

## Monitoring

### View Active Containers

```bash
docker ps --filter "label=mde4cpp.terminal=true"
```

### View Container Logs

```bash
docker logs <container-name>
```

### Check Container Resources

```bash
docker stats <container-name>
```

## Architecture Diagram

```
User Terminal Request
        ↓
WebSocket Connection
        ↓
Terminal Controller
        ↓
Secure Terminal Service
        ↓
Container Manager
        ↓
Docker Container (Isolated)
        ├─ Network: None
        ├─ Filesystem: Read-only MDE4CPP_HOME
        ├─ User: Non-root (1000:1000)
        ├─ Resources: Limited (512MB, 50% CPU)
        └─ Auto-cleanup: After 1 hour idle
```

## Best Practices

1. **Always use containers in production** - Never disable `TERMINAL_USE_CONTAINERS`
2. **Monitor resource usage** - Set appropriate limits for your server
3. **Regular cleanup** - Containers auto-cleanup, but monitor for leaks
4. **Update Docker image** - Rebuild image when base OS updates
5. **Log monitoring** - Monitor container logs for suspicious activity

## Support

For issues or questions:
1. Check Docker logs
2. Review server logs
3. Verify Docker configuration
4. Check container status

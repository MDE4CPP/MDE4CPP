# Quick Start - Secure Terminal

## Installation

1. **Install dependencies:**
   ```bash
   npm install
   ```

2. **Build the terminal Docker image:**
   
   **Windows:**
   ```powershell
   .\scripts\build-terminal-image.ps1
   ```
   
   **Linux/macOS:**
   ```bash
   chmod +x scripts/build-terminal-image.sh
   ./scripts/build-terminal-image.sh
   ```

3. **Start the server:**
   ```bash
   npm start
   ```

## Verification

The server will automatically:
- ✅ Check Docker connectivity on startup
- ✅ Create isolated containers for each terminal session
- ✅ Apply security restrictions (network isolation, resource limits, read-only filesystem)

## What's Protected

✅ **Server files** - MDE4CPP_HOME is read-only in containers  
✅ **Network access** - Containers have no internet access  
✅ **Resource exhaustion** - CPU and memory limits per container  
✅ **Privilege escalation** - Containers run as non-root user  
✅ **Data exfiltration** - No network means no way to send data out  

## Configuration

See `SECURE_TERMINAL_SETUP.md` for detailed configuration options.

## Troubleshooting

**Docker not found?**
- Ensure Docker Desktop (Windows/macOS) or Docker Engine (Linux) is running
- Verify Docker socket path in config

**Container creation fails?**
- Check if image exists: `docker images | grep mde4cpp-terminal`
- Rebuild image if missing

**Need help?**
- See `SECURE_TERMINAL_SETUP.md` for detailed troubleshooting

const Docker = require('dockerode');
const path = require('path');
const os = require('os');
const logger = require('../utils/logger');
const config = require('../config');

// Detect if running on Windows (Docker Desktop uses Linux containers but has Windows-specific limitations)
const isWindows = process.platform === 'win32';

/**
 * Container Manager Service
 * Manages Docker containers for secure terminal execution
 * Each terminal session runs in an isolated container with:
 * - Network isolation (no network access)
 * - Resource limits (CPU, memory)
 * - Read-only filesystem mounts
 * - Non-root user execution
 * - Automatic cleanup
 */
class ContainerManager {
    constructor() {
        this.docker = new Docker({ socketPath: config.terminal.docker.socketPath });
        this.containers = new Map(); // sessionId -> container info
        this.cleanupInterval = null;
        
        // Start cleanup interval
        this.startCleanupInterval();
        
        // Graceful shutdown
        process.on('SIGTERM', () => this.cleanupAll());
        process.on('SIGINT', () => this.cleanupAll());
    }
    
    /**
     * Create a new isolated container for a terminal session
     * @param {string} sessionId - Session ID
     * @returns {Promise<object>} Container info
     */
    async createContainer(sessionId) {
        try {
            // Check session limit
            if (this.containers.size >= config.terminal.maxSessions) {
                throw new Error(`Maximum terminal sessions (${config.terminal.maxSessions}) reached`);
            }
            
            const containerName = `mde4cpp-terminal-${sessionId}`;
            
            // Prepare volume mounts
            const binds = [];
            
            // Mount MDE4CPP_HOME as read-only (prevents any modifications)
            if (config.terminal.docker.readOnlyMDE4CPP) {
                binds.push(`${config.mde4cpp.home}:/mde4cpp:ro`);
            } else {
                binds.push(`${config.mde4cpp.home}:/mde4cpp:rw`);
            }
            
            // Mount workspace directory (read-write for builds)
            const workspaceDir = path.join(config.storage.root, 'builds', sessionId);
            const fs = require('fs-extra');
            await fs.ensureDir(workspaceDir);
            binds.push(`${workspaceDir}:${config.terminal.docker.workingDir}:rw`);
            
            // Container configuration with security restrictions
            const containerConfig = {
                Image: config.terminal.docker.image,
                name: containerName,
                AttachStdin: true,
                AttachStdout: true,
                AttachStderr: true,
                Tty: true,
                OpenStdin: true,
                StdinOnce: false,
                Env: [
                    `MDE4CPP_HOME=/mde4cpp`,
                    `WORKSPACE=${config.terminal.docker.workingDir}`,
                    `TERM=xterm-256color`
                ],
                WorkingDir: config.terminal.docker.workingDir,
                HostConfig: {
                    // Network isolation - NO network access
                    NetworkMode: config.terminal.docker.networkDisabled ? 'none' : 'bridge',
                    // Resource limits
                    Memory: config.terminal.docker.memory * 1024 * 1024, // Convert MB to bytes
                    CpuShares: config.terminal.docker.cpuShares,
                    // Security: Run as non-root user
                    User: config.terminal.docker.user,
                    // Read-only root filesystem (prevents system modifications) - Linux only
                    ...(isWindows ? {} : { ReadonlyRootfs: true }),
                    // Volume mounts
                    Binds: binds,
                    // Auto-remove container when it stops
                    AutoRemove: true,
                    // Security options (Linux-only features)
                    ...(isWindows ? {} : {
                        SecurityOpt: [
                            'no-new-privileges:true' // Prevent privilege escalation
                        ],
                        // Capabilities: Drop all, add only what's needed
                        CapDrop: ['ALL'],
                        CapAdd: ['CHOWN', 'FOWNER', 'FSETID', 'KILL', 'SETGID', 'SETUID', 'SETPCAP', 'NET_BIND_SERVICE', 'NET_RAW', 'SYS_CHROOT', 'MKNOD', 'AUDIT_WRITE', 'SETFCAP'],
                        // Prevent access to host devices
                        Devices: []
                        // Note: IpcMode, PidMode, and UtsMode are not supported on Windows Docker Desktop
                        // IpcMode: 'private' - Removed for Windows compatibility
                    })
                },
                // Labels for tracking
                Labels: {
                    'mde4cpp.terminal': 'true',
                    'mde4cpp.sessionId': sessionId,
                    'mde4cpp.created': new Date().toISOString()
                }
            };
            
            // Debug: Log platform detection and verify no PidMode
            logger.info(`Creating secure container for session ${sessionId} (Platform: ${process.platform}, isWindows: ${isWindows})`);
            if (containerConfig.HostConfig.PidMode) {
                logger.error('ERROR: PidMode found in config! This should not happen on Windows.');
            }
            if (containerConfig.HostConfig.UtsMode) {
                logger.error('ERROR: UtsMode found in config! This should not happen on Windows.');
            }
            
            // Create container
            const container = await this.docker.createContainer(containerConfig);
            
            // Start container
            await container.start();
            
            const containerInfo = {
                id: container.id,
                name: containerName,
                container: container,
                sessionId: sessionId,
                createdAt: new Date(),
                lastActivity: new Date()
            };
            
            this.containers.set(sessionId, containerInfo);
            
            logger.info(`Container ${containerName} created and started for session ${sessionId}`);
            
            return containerInfo;
        } catch (error) {
            logger.error(`Failed to create container for session ${sessionId}:`, error);
            throw error;
        }
    }
    
    /**
     * Execute a command in a container
     * @param {string} sessionId - Session ID
     * @param {string} command - Command to execute
     * @param {function} onOutput - Output callback
     * @param {function} onError - Error callback
     * @param {function} onExit - Exit callback
     * @returns {Promise<object>} Execution result
     */
    async executeCommand(sessionId, command, onOutput, onError, onExit) {
        const containerInfo = this.containers.get(sessionId);
        if (!containerInfo) {
            throw new Error(`Container not found for session ${sessionId}`);
        }
        
        // Update activity
        containerInfo.lastActivity = new Date();
        
        const container = containerInfo.container;
        
        return new Promise((resolve) => {
            // Create exec instance
            const execOptions = {
                Cmd: ['/bin/bash', '-c', command],
                AttachStdout: true,
                AttachStderr: true,
                Tty: false,
                User: config.terminal.docker.user
            };
            
            container.exec(execOptions, (err, exec) => {
                if (err) {
                    const errorMsg = `Failed to create exec: ${err.message}\r\n`;
                    onError(errorMsg);
                    onExit(1, 'exec_error');
                    resolve({ exitCode: 1, error: err.message });
                    return;
                }
                
                // Start exec with timeout
                const startOptions = {
                    hijack: true,
                    stdin: false
                };
                
                exec.start(startOptions, (err, stream) => {
                    if (err) {
                        const errorMsg = `Failed to start exec: ${err.message}\r\n`;
                        onError(errorMsg);
                        onExit(1, 'exec_start_error');
                        resolve({ exitCode: 1, error: err.message });
                        return;
                    }
                    
                    let stdout = '';
                    let stderr = '';
                    let hasExited = false;
                    
                    // Set command timeout
                    const timeout = setTimeout(() => {
                        if (!hasExited) {
                            try {
                                exec.kill();
                            } catch (e) {
                                // Ignore kill errors
                            }
                            const timeoutMsg = '\r\nCommand timed out\r\n';
                            stderr += timeoutMsg;
                            onError(timeoutMsg);
                            onExit(124, 'timeout');
                            resolve({ exitCode: 124, error: 'Command timed out', stdout, stderr });
                        }
                    }, config.terminal.docker.commandTimeoutMs);
                    
                    // Handle output streams
                    stream.on('readable', () => {
                        let chunk;
                        while ((chunk = stream.read()) !== null) {
                            const output = chunk.toString();
                            // Docker exec combines stdout and stderr, so we output everything
                            stdout += output;
                            onOutput(output);
                        }
                    });
                    
                    stream.on('end', () => {
                        // Stream ended, check exit code
                        if (!hasExited) {
                            exec.inspect((err, data) => {
                                if (err) {
                                    if (!hasExited) {
                                        hasExited = true;
                                        clearTimeout(timeout);
                                        onExit(1, 'inspect_error');
                                        resolve({ exitCode: 1, error: err.message, stdout, stderr });
                                    }
                                    return;
                                }
                                
                                if (data && data.Running === false && !hasExited) {
                                    hasExited = true;
                                    clearTimeout(timeout);
                                    
                                    const exitCode = data.ExitCode || 0;
                                    onExit(exitCode, 'exited');
                                    resolve({ exitCode, stdout, stderr });
                                }
                            });
                        }
                    });
                    
                    stream.on('error', (err) => {
                        if (!hasExited) {
                            hasExited = true;
                            clearTimeout(timeout);
                            const errorMsg = err.message;
                            stderr += errorMsg;
                            onError(errorMsg);
                            onExit(1, 'stream_error');
                            resolve({ exitCode: 1, error: errorMsg, stdout, stderr });
                        }
                    });
                    
                    // Poll for completion as fallback (in case stream doesn't emit 'end')
                    const checkInterval = setInterval(() => {
                        if (hasExited) {
                            clearInterval(checkInterval);
                            return;
                        }
                        
                        exec.inspect((err, data) => {
                            if (err || !data) return;
                            
                            if (data.Running === false && !hasExited) {
                                hasExited = true;
                                clearTimeout(timeout);
                                clearInterval(checkInterval);
                                
                                const exitCode = data.ExitCode || 0;
                                onExit(exitCode, 'exited');
                                resolve({ exitCode, stdout, stderr });
                            }
                        });
                    }, 500);
                });
            });
        });
    }
    
    /**
     * Destroy a container
     * @param {string} sessionId - Session ID
     * @returns {Promise<void>}
     */
    async destroyContainer(sessionId) {
        const containerInfo = this.containers.get(sessionId);
        if (!containerInfo) {
            logger.warn(`Container not found for session ${sessionId}`);
            return;
        }
        
        try {
            const container = containerInfo.container;
            
            // Stop container (force kill after 10 seconds)
            try {
                await container.stop({ t: 10 });
            } catch (error) {
                // Container might already be stopped
                logger.debug(`Container ${containerInfo.name} stop result:`, error.message);
            }
            
            // Remove container (AutoRemove should handle this, but ensure it)
            try {
                await container.remove({ force: true });
            } catch (error) {
                logger.warn(`Failed to remove container ${containerInfo.name}:`, error.message);
            }
            
            this.containers.delete(sessionId);
            logger.info(`Container ${containerInfo.name} destroyed for session ${sessionId}`);
        } catch (error) {
            logger.error(`Failed to destroy container for session ${sessionId}:`, error);
            // Remove from map even if destroy failed
            this.containers.delete(sessionId);
        }
    }
    
    /**
     * Clean up idle containers
     */
    async cleanupIdleContainers() {
        const now = new Date();
        const idleTimeout = config.terminal.docker.idleTimeoutMs;
        
        const toDestroy = [];
        
        for (const [sessionId, containerInfo] of this.containers.entries()) {
            const idleTime = now - containerInfo.lastActivity;
            if (idleTime > idleTimeout) {
                toDestroy.push(sessionId);
            }
        }
        
        for (const sessionId of toDestroy) {
            logger.info(`Cleaning up idle container for session ${sessionId}`);
            await this.destroyContainer(sessionId);
        }
        
        if (toDestroy.length > 0) {
            logger.info(`Cleaned up ${toDestroy.length} idle container(s)`);
        }
    }
    
    /**
     * Start cleanup interval
     */
    startCleanupInterval() {
        this.cleanupInterval = setInterval(() => {
            this.cleanupIdleContainers().catch(err => {
                logger.error('Error during container cleanup:', err);
            });
        }, config.terminal.cleanupIntervalMs);
    }
    
    /**
     * Clean up all containers
     */
    async cleanupAll() {
        logger.info('Cleaning up all containers...');
        
        if (this.cleanupInterval) {
            clearInterval(this.cleanupInterval);
        }
        
        const sessionIds = Array.from(this.containers.keys());
        for (const sessionId of sessionIds) {
            await this.destroyContainer(sessionId);
        }
        
        logger.info('All containers cleaned up');
    }
    
    /**
     * Get container info
     * @param {string} sessionId - Session ID
     * @returns {object|null} Container info
     */
    getContainerInfo(sessionId) {
        return this.containers.get(sessionId) || null;
    }
    
    /**
     * Update container activity
     * @param {string} sessionId - Session ID
     */
    updateActivity(sessionId) {
        const containerInfo = this.containers.get(sessionId);
        if (containerInfo) {
            containerInfo.lastActivity = new Date();
        }
    }
}

// Singleton instance
let instance = null;

module.exports = {
    getInstance: () => {
        if (!instance) {
            instance = new ContainerManager();
        }
        return instance;
    }
};

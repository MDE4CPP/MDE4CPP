const app = require('./app');
const config = require('./config');
const logger = require('./utils/logger');
const WebSocket = require('ws');
const terminalController = require('./controllers/terminal.controller');

const PORT = config.port || 8000;
const HOST = config.host || '0.0.0.0';

// Start HTTP server
const server = app.listen(PORT, HOST, () => {
    logger.info(`MDE4CPP Build Service API running on http://${HOST}:${PORT}`);
    logger.info(`Environment: ${config.env}`);
    logger.info(`MDE4CPP_HOME: ${config.mde4cpp.home}`);
});

// Set up WebSocket server for terminal
let wss;
try {
    wss = new WebSocket.Server({ 
        server,
        path: '/api/v1/terminal/ws',
        verifyClient: (info) => {
            logger.debug(`WebSocket upgrade request from ${info.origin || 'unknown origin'}`);
            return true; // Accept all connections (can add origin validation here if needed)
        }
    });

    wss.on('connection', (ws, req) => {
        logger.info(`New WebSocket connection for terminal from ${req.socket.remoteAddress || 'unknown'}`);
        terminalController.handleTerminalConnection(ws);
    });

    wss.on('error', (error) => {
        logger.error('WebSocket server error:', error);
    });

    logger.info('WebSocket server initialized on /api/v1/terminal/ws');
} catch (error) {
    logger.error('Failed to initialize WebSocket server:', error);
    logger.error('Error details:', error.stack);
    logger.error('WebSocket functionality will not be available');
}

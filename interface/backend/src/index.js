const app = require('./app');
const config = require('./config');
const logger = require('./utils/logger');

const PORT = config.port || 8000;
const HOST = config.host || '0.0.0.0';

app.listen(PORT, HOST, () => {
    logger.info(`MDE4CPP Build Service API running on http://${HOST}:${PORT}`);
    logger.info(`Environment: ${config.env}`);
    logger.info(`MDE4CPP_HOME: ${config.mde4cpp.home}`);
});

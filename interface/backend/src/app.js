const express = require('express');
const cors = require('cors');
const routes = require('./routes');
const { errorHandler } = require('./middleware/errorHandler');
const config = require('./config');

const app = express();

/** In dev, allow http-server's LAN URL (e.g. http://10.x.x.x:3001), not only 127.0.0.1 */
function isAllowedDevModelerOrigin(origin) {
    if (/^https?:\/\/(localhost|127\.0\.0\.1)(:\d+)?$/i.test(origin)) {
        return true;
    }
    if (/^https?:\/\/(10(\.\d{1,3}){3}|192\.168(\.\d{1,3}){2}|172\.(1[6-9]|2\d|3[01])(\.\d{1,3}){2})(:\d+)?$/i.test(origin)) {
        return true;
    }
    return false;
}

// CORS: allow configured origins; in development also allow local / LAN modeler URLs
const corsAllowed = config.cors.origin;
const corsList = Array.isArray(corsAllowed) ? corsAllowed : [corsAllowed];
app.use(cors({
    origin: (origin, callback) => {
        if (!origin) {
            return callback(null, true);
        }
        if (corsList.includes('*') || corsList.includes(origin)) {
            return callback(null, true);
        }
        if (config.env !== 'production' && isAllowedDevModelerOrigin(origin)) {
            return callback(null, true);
        }
        callback(null, false);
    },
    credentials: true
}));

// Body parsing middleware
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

// Routes
app.use('/api/v1', routes);

// Root endpoint
app.get('/', (req, res) => {
    res.json({
        service: 'MDE4CPP Build Service API',
        version: '1.0.0',
        endpoints: {
            health: '/api/v1/health',
            stats: '/api/v1/stats',
            build: '/api/v1/build',
            docs: 'See README.md for API documentation'
        }
    });
});

// Error handling middleware (must be last)
app.use(errorHandler);

module.exports = app;

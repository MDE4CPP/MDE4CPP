const express = require('express');
const cors = require('cors');
const routes = require('./routes');
const { errorHandler } = require('./middleware/errorHandler');
const config = require('./config');

const app = express();

// CORS configuration
app.use(cors({
    origin: config.cors.origin,
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

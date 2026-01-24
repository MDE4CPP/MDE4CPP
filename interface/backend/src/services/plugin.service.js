const { spawn } = require('child_process');
const path = require('path');
const http = require('http');
const logger = require('../utils/logger');
const config = require('../config');

// Store for created objects (in-memory for now)
// In production, this could be persisted or use the C++ API's object store
const objectStore = new Map();

// MDE4CPP_PluginAPI configuration (from config)
let PLUGIN_API_URL = null;

// Initialize API URL from config
function initPluginAPI() {
    if (config.pluginAPI.enabled) {
        PLUGIN_API_URL = `http://${config.pluginAPI.host}:${config.pluginAPI.port}`;
        logger.info(`Plugin API configured: ${PLUGIN_API_URL}`);
    } else {
        logger.info('Plugin API disabled, using fallback mode');
    }
}

// Initialize on module load
initPluginAPI();

/**
 * Make HTTP request to MDE4CPP_PluginAPI
 */
async function callPluginAPI(endpoint, method = 'GET', body = null) {
    if (!PLUGIN_API_URL) {
        throw new Error('Plugin API is not enabled');
    }
    
    return new Promise((resolve, reject) => {
        const url = new URL(endpoint, PLUGIN_API_URL);
        const timeout = config.pluginAPI.timeout || 5000;
        
        const timeoutId = setTimeout(() => {
            req.destroy();
            reject(new Error(`API request timeout after ${timeout}ms`));
        }, timeout);
        const options = {
            hostname: url.hostname,
            port: url.port,
            path: url.pathname + url.search,
            method: method,
            headers: {
                'Content-Type': 'application/json'
            }
        };

        if (body) {
            options.headers['Content-Length'] = Buffer.byteLength(JSON.stringify(body));
        }

        const req = http.request(options, (res) => {
            let data = '';
            res.on('data', (chunk) => {
                data += chunk;
            });
            res.on('end', () => {
                clearTimeout(timeoutId);
                try {
                    if (res.statusCode >= 200 && res.statusCode < 300) {
                        const jsonData = data ? JSON.parse(data) : {};
                        resolve(jsonData);
                    } else {
                        reject(new Error(`API request failed: ${res.statusCode} - ${data}`));
                    }
                } catch (error) {
                    reject(new Error(`Failed to parse API response: ${error.message}`));
                }
            });
        });

        req.on('error', (error) => {
            clearTimeout(timeoutId);
            reject(new Error(`API request error: ${error.message}`));
        });

        if (body) {
            req.write(JSON.stringify(body));
        }
        req.end();
    });
}

/**
 * Check if MDE4CPP_PluginAPI is available
 */
async function isPluginAPIAvailable() {
    if (!PLUGIN_API_URL) {
        return false;
    }
    
    try {
        await callPluginAPI('/plugins');
        return true;
    } catch (error) {
        logger.debug('MDE4CPP_PluginAPI not available:', error.message);
        return false;
    }
}

/**
 * Get all available plugins
 * Tries MDE4CPP_PluginAPI first, falls back to mock data
 */
async function getAllPlugins() {
    try {
        // Try to use MDE4CPP_PluginAPI
        if (await isPluginAPIAvailable()) {
            try {
                // Try to get detailed plugin information
                const detailsResponse = await callPluginAPI('/plugins/details');
                if (Array.isArray(detailsResponse) && detailsResponse.length > 0) {
                    logger.info(`Retrieved ${detailsResponse.length} plugins from MDE4CPP_PluginAPI`);
                    return detailsResponse;
                }
            } catch (detailsError) {
                logger.debug('Plugin details endpoint not available, trying basic plugins endpoint');
            }
            
            // Fallback to basic plugins endpoint
            const response = await callPluginAPI('/plugins');
            if (Array.isArray(response) && response.length > 0) {
                logger.info(`Retrieved ${response.length} plugins from MDE4CPP_PluginAPI (basic info)`);
                // Map to detailed format
                const plugins = response.map(name => ({ name, uri: '', prefix: name }));
                return plugins;
            }
        }
    } catch (error) {
        logger.warn('Failed to get plugins from API, using fallback mode:', error.message);
    }
    
    // Fallback to mock data
    logger.info('Using FALLBACK MODE: Mock plugin data (MDE4CPP_PluginAPI not available)');
    return getMockPlugins();
}

/**
 * Get mock plugins (fallback)
 */
function getMockPlugins() {
    return [
        { name: 'ecore', uri: 'http://www.eclipse.org/emf/2002/Ecore', prefix: 'ecore' },
        { name: 'uml', uri: 'http://www.eclipse.org/uml2/5.0.0/UML', prefix: 'uml' }
    ];
}

/**
 * Create an object from a plugin
 */
async function createObject(pluginName, className) {
    const objectId = `obj_${Date.now()}_${Math.random().toString(36).substr(2, 9)}`;
    
    try {
        // Try to use MDE4CPP_PluginAPI
        if (await isPluginAPIAvailable()) {
            // MDE4CPP_PluginAPI uses: POST /{pluginName}/objects/{className}/{objectName}
            // We'll use objectId as objectName
            const endpoint = `/${pluginName}/objects/${encodeURIComponent(className)}/${objectId}`;
            await callPluginAPI(endpoint, 'POST', {});
            
            logger.info(`Created object ${objectId} via MDE4CPP_PluginAPI`);
            
            // Store reference
            const object = {
                id: objectId,
                pluginName,
                className,
                type: className,
                features: {},
                createdAt: new Date().toISOString(),
                apiManaged: true
            };
            objectStore.set(objectId, object);
            return object;
        }
    } catch (error) {
        logger.warn('Failed to create object via API, using fallback:', error.message);
    }
    
    // Fallback: create mock object
    logger.info(`FALLBACK MODE: Creating object ${objectId} in in-memory store (MDE4CPP_PluginAPI not available)`);
    
    const object = {
        id: objectId,
        pluginName,
        className,
        type: className,
        features: {},
        createdAt: new Date().toISOString(),
        apiManaged: false
    };
    objectStore.set(objectId, object);
    return object;
}

/**
 * Get value from object feature
 */
async function getValue(objectId, featureName) {
    const object = objectStore.get(objectId);
    if (!object) {
        throw new Error('Object not found');
    }
    
    try {
        // Try to use MDE4CPP_PluginAPI
        if (object.apiManaged && await isPluginAPIAvailable()) {
            try {
                // Try feature-specific endpoint first
                const featureEndpoint = `/${object.pluginName}/objects/${encodeURIComponent(object.className)}/${objectId}/get/${featureName}`;
                const featureResponse = await callPluginAPI(featureEndpoint, 'GET');
                if (featureResponse && featureResponse.value !== undefined) {
                    return featureResponse.value;
                }
            } catch (featureError) {
                logger.debug('Feature-specific endpoint failed, trying full object endpoint');
            }
            
            // Fallback to full object endpoint
            const endpoint = `/${object.pluginName}/objects/${encodeURIComponent(object.className)}/${objectId}`;
            const response = await callPluginAPI(endpoint, 'GET');
            
            // Extract feature value from response
            if (response && response[featureName] !== undefined) {
                return response[featureName];
            }
        }
    } catch (error) {
        if (object.apiManaged) {
            logger.warn('Failed to get value via API, using fallback:', error.message);
        }
    }
    
    // Fallback: return stored value
    const value = object.features[featureName];
    if (value === undefined && !object.apiManaged) {
        logger.debug(`FALLBACK MODE: Getting feature '${featureName}' from in-memory object store`);
    }
    return value !== undefined ? value : null;
}

/**
 * Set value on object feature
 */
async function setValue(objectId, featureName, value) {
    const object = objectStore.get(objectId);
    if (!object) {
        throw new Error('Object not found');
    }
    
    try {
        // Try to use MDE4CPP_PluginAPI
        if (object.apiManaged && await isPluginAPIAvailable()) {
            try {
                // Try feature-specific endpoint first
                const featureEndpoint = `/${object.pluginName}/objects/${encodeURIComponent(object.className)}/${objectId}/set/${featureName}`;
                await callPluginAPI(featureEndpoint, 'POST', { value });
                // Update local cache
                object.features[featureName] = value;
                objectStore.set(objectId, object);
                return object;
            } catch (featureError) {
                logger.debug('Feature-specific endpoint failed, trying full object endpoint');
            }
            
            // Fallback to full object endpoint
            const updatedObject = { ...object.features, [featureName]: value };
            const endpoint = `/${object.pluginName}/objects/${encodeURIComponent(object.className)}/${objectId}`;
            await callPluginAPI(endpoint, 'PUT', updatedObject);
        }
    } catch (error) {
        if (object.apiManaged) {
            logger.warn('Failed to set value via API, using fallback:', error.message);
        }
    }
    
    // Update local store (always update for consistency)
    object.features[featureName] = value;
    objectStore.set(objectId, object);
    
    if (!object.apiManaged) {
        logger.debug(`FALLBACK MODE: Setting feature '${featureName}' to '${value}' in in-memory object store`);
    }
    
    return object;
}

/**
 * Invoke operation on object
 */
async function invokeOperation(objectId, operationName, arguments_ = []) {
    const object = objectStore.get(objectId);
    if (!object) {
        throw new Error('Object not found');
    }
    
    try {
        // Try to use MDE4CPP_PluginAPI
        if (object.apiManaged && await isPluginAPIAvailable()) {
            const endpoint = `/${object.pluginName}/objects/${encodeURIComponent(object.className)}/${objectId}/invoke/${operationName}`;
            const response = await callPluginAPI(endpoint, 'POST', { arguments: arguments_ });
            
            if (response && response.success !== undefined) {
                return {
                    success: response.success,
                    result: response.result,
                    objectId,
                    operationName,
                    arguments: arguments_
                };
            }
        }
    } catch (error) {
        if (object.apiManaged) {
            logger.warn('Failed to invoke operation via API, using fallback:', error.message);
        }
    }
    
    // Fallback: return mock result
    logger.info(`FALLBACK MODE: Invoking operation '${operationName}' on object ${objectId} with ${arguments_.length} arguments (mock result)`);
    
    return {
        success: true,
        result: `Operation ${operationName} invoked with ${arguments_.length} arguments (fallback mode - mock result)`,
        objectId,
        operationName,
        arguments: arguments_,
        fallback: true
    };
}

/**
 * Get object details including all features
 */
async function getObjectDetails(objectId) {
    const object = objectStore.get(objectId);
    if (!object) {
        throw new Error('Object not found');
    }
    
    try {
        // Try to use MDE4CPP_PluginAPI to get full object data
        if (object.apiManaged && await isPluginAPIAvailable()) {
            const endpoint = `/${object.pluginName}/objects/${encodeURIComponent(object.className)}/${objectId}`;
            const response = await callPluginAPI(endpoint, 'GET');
            
            // Update object with API data
            if (response) {
                object.features = response;
                logger.debug(`Refreshed object ${objectId} from MDE4CPP_PluginAPI`);
            }
        }
    } catch (error) {
        if (object.apiManaged) {
            logger.warn('Failed to get object details via API, using fallback:', error.message);
        }
    }
    
    if (!object.apiManaged) {
        logger.debug(`FALLBACK MODE: Getting object ${objectId} details from in-memory store`);
    }
    
    return object;
}

/**
 * List all created objects
 */
async function listObjects() {
    try {
        // Try to use MDE4CPP_PluginAPI
        if (await isPluginAPIAvailable()) {
            try {
                const response = await callPluginAPI('/objects', 'GET');
                if (Array.isArray(response) && response.length > 0) {
                    // Sync with objectStore
                    const apiObjects = response;
                    const localObjects = Array.from(objectStore.values());
                    
                    // Merge: prefer API objects, but keep local fallback objects
                    const merged = new Map();
                    apiObjects.forEach(apiObj => {
                        merged.set(apiObj.name, {
                            id: apiObj.name,
                            pluginName: apiObj.plugin || 'unknown',
                            className: apiObj.type,
                            type: apiObj.type,
                            features: {},
                            createdAt: new Date().toISOString(),
                            apiManaged: true
                        });
                    });
                    
                    // Add local fallback objects that aren't in API
                    localObjects.forEach(localObj => {
                        if (!localObj.apiManaged || !merged.has(localObj.id)) {
                            merged.set(localObj.id, localObj);
                        }
                    });
                    
                    return Array.from(merged.values());
                }
            } catch (error) {
                logger.debug('Objects endpoint not available, using local store');
            }
        }
    } catch (error) {
        logger.debug('Failed to list objects from API, using fallback');
    }
    
    // Fallback: return from local store
    const objects = Array.from(objectStore.values());
    if (objects.length > 0 && !objects[0].apiManaged) {
        logger.debug(`FALLBACK MODE: Listing ${objects.length} objects from in-memory store`);
    }
    return objects;
}

/**
 * Delete an object
 */
async function deleteObject(objectId) {
    const object = objectStore.get(objectId);
    if (!object) {
        throw new Error('Object not found');
    }
    
    try {
        // Try to use MDE4CPP_PluginAPI
        if (object.apiManaged && await isPluginAPIAvailable()) {
            // MDE4CPP_PluginAPI uses: DELETE /{pluginName}/objects/{className}/{objectName}
            const endpoint = `/${object.pluginName}/objects/${encodeURIComponent(object.className)}/${objectId}`;
            await callPluginAPI(endpoint, 'DELETE');
            logger.info(`Deleted object ${objectId} via MDE4CPP_PluginAPI`);
        }
    } catch (error) {
        if (object.apiManaged) {
            logger.warn('Failed to delete object via API, using fallback:', error.message);
        }
    }
    
    // Remove from local store
    objectStore.delete(objectId);
    
    if (!object.apiManaged) {
        logger.info(`FALLBACK MODE: Deleted object ${objectId} from in-memory store`);
    }
    
    return { success: true };
}

/**
 * Get plugin structure (packages and classifiers)
 */
async function getPluginStructure(pluginName) {
    try {
        if (await isPluginAPIAvailable()) {
            const endpoint = `/${encodeURIComponent(pluginName)}/structure`;
            const response = await callPluginAPI(endpoint, 'GET');
            if (response) {
                logger.info(`Retrieved structure for plugin ${pluginName}`);
                return response;
            }
        }
    } catch (error) {
        logger.warn(`Failed to get plugin structure for ${pluginName}:`, error.message);
    }
    
    // Fallback: return mock structure
    logger.info(`FALLBACK MODE: Returning mock structure for plugin ${pluginName}`);
    return {
        name: pluginName,
        nsURI: '',
        nsPrefix: pluginName,
        classifiers: []
    };
}

/**
 * Get all classifiers for a plugin
 */
async function getClassifiers(pluginName) {
    try {
        if (await isPluginAPIAvailable()) {
            const endpoint = `/${encodeURIComponent(pluginName)}/classifiers`;
            const response = await callPluginAPI(endpoint, 'GET');
            if (Array.isArray(response)) {
                logger.info(`Retrieved ${response.length} classifiers for plugin ${pluginName}`);
                return response;
            }
        }
    } catch (error) {
        logger.warn(`Failed to get classifiers for ${pluginName}:`, error.message);
    }
    
    // Fallback: return empty list
    logger.info(`FALLBACK MODE: Returning empty classifier list for plugin ${pluginName}`);
    return [];
}

/**
 * Get classifier details
 */
async function getClassifierDetails(pluginName, className) {
    try {
        if (await isPluginAPIAvailable()) {
            const endpoint = `/${encodeURIComponent(pluginName)}/classifiers/${encodeURIComponent(className)}`;
            const response = await callPluginAPI(endpoint, 'GET');
            if (response) {
                logger.info(`Retrieved details for classifier ${className} in plugin ${pluginName}`);
                return response;
            }
        }
    } catch (error) {
        logger.warn(`Failed to get classifier details for ${pluginName}.${className}:`, error.message);
    }
    
    // Fallback: return mock details
    logger.info(`FALLBACK MODE: Returning mock classifier details for ${pluginName}.${className}`);
    return {
        name: className,
        type: 'EClass',
        attributes: [],
        references: [],
        operations: [],
        structuralFeatures: []
    };
}

/**
 * Get object's EClass metadata
 */
async function getObjectClass(objectId) {
    const object = objectStore.get(objectId);
    if (!object) {
        throw new Error('Object not found');
    }
    
    try {
        if (object.apiManaged && await isPluginAPIAvailable()) {
            const endpoint = `/${object.pluginName}/objects/${encodeURIComponent(object.className)}/${objectId}/class`;
            const response = await callPluginAPI(endpoint, 'GET');
            if (response) {
                return response;
            }
        }
    } catch (error) {
        if (object.apiManaged) {
            logger.warn('Failed to get object class via API, using fallback:', error.message);
        }
    }
    
    // Fallback: return from object metadata
    logger.debug(`FALLBACK MODE: Getting object class for ${objectId} from local store`);
    return {
        name: object.className,
        abstract: false,
        interface: false
    };
}

/**
 * Get object's attributes with values
 */
async function getObjectAttributes(objectId) {
    const object = objectStore.get(objectId);
    if (!object) {
        throw new Error('Object not found');
    }
    
    try {
        if (object.apiManaged && await isPluginAPIAvailable()) {
            const endpoint = `/${object.pluginName}/objects/${encodeURIComponent(object.className)}/${objectId}/attributes`;
            const response = await callPluginAPI(endpoint, 'GET');
            if (Array.isArray(response)) {
                return response;
            }
        }
    } catch (error) {
        if (object.apiManaged) {
            logger.warn('Failed to get object attributes via API, using fallback:', error.message);
        }
    }
    
    // Fallback: return from object features
    logger.debug(`FALLBACK MODE: Getting attributes for ${objectId} from local store`);
    const attributes = [];
    for (const [name, value] of Object.entries(object.features)) {
        attributes.push({
            name,
            value,
            type: typeof value
        });
    }
    return attributes;
}

/**
 * Get object's operations
 */
async function getObjectOperations(objectId) {
    const object = objectStore.get(objectId);
    if (!object) {
        throw new Error('Object not found');
    }
    
    try {
        if (object.apiManaged && await isPluginAPIAvailable()) {
            const endpoint = `/${object.pluginName}/objects/${encodeURIComponent(object.className)}/${objectId}/operations`;
            const response = await callPluginAPI(endpoint, 'GET');
            if (Array.isArray(response)) {
                return response;
            }
        }
    } catch (error) {
        if (object.apiManaged) {
            logger.warn('Failed to get object operations via API, using fallback:', error.message);
        }
    }
    
    // Fallback: return empty list
    logger.debug(`FALLBACK MODE: Getting operations for ${objectId} (empty list)`);
    return [];
}

/**
 * Get object's structural features with values
 */
async function getObjectFeatures(objectId) {
    const object = objectStore.get(objectId);
    if (!object) {
        throw new Error('Object not found');
    }
    
    try {
        if (object.apiManaged && await isPluginAPIAvailable()) {
            const endpoint = `/${object.pluginName}/objects/${encodeURIComponent(object.className)}/${objectId}/features`;
            const response = await callPluginAPI(endpoint, 'GET');
            if (Array.isArray(response)) {
                return response;
            }
        }
    } catch (error) {
        if (object.apiManaged) {
            logger.warn('Failed to get object features via API, using fallback:', error.message);
        }
    }
    
    // Fallback: return from object features
    logger.debug(`FALLBACK MODE: Getting features for ${objectId} from local store`);
    const features = [];
    for (const [name, value] of Object.entries(object.features)) {
        features.push({
            name,
            value,
            featureType: 'EAttribute',
            type: typeof value,
            lowerBound: 0,
            upperBound: 1
        });
    }
    return features;
}

/**
 * Create object from classifier with initial properties
 */
async function createFromClassifier(pluginName, className, instanceName, properties = {}) {
    const objectId = instanceName || `obj_${Date.now()}_${Math.random().toString(36).substr(2, 9)}`;
    
    try {
        if (await isPluginAPIAvailable()) {
            const endpoint = `/${pluginName}/objects/${encodeURIComponent(className)}/${objectId}`;
            await callPluginAPI(endpoint, 'POST', properties);
            
            logger.info(`Created object ${objectId} via MDE4CPP_PluginAPI from classifier ${className}`);
            
            const object = {
                id: objectId,
                pluginName,
                className,
                type: className,
                features: properties,
                createdAt: new Date().toISOString(),
                apiManaged: true
            };
            objectStore.set(objectId, object);
            return object;
        }
    } catch (error) {
        logger.warn('Failed to create object via API, using fallback:', error.message);
    }
    
    // Fallback: create mock object
    logger.info(`FALLBACK MODE: Creating object ${objectId} in in-memory store`);
    const object = {
        id: objectId,
        pluginName,
        className,
        type: className,
        features: properties,
        createdAt: new Date().toISOString(),
        apiManaged: false
    };
    objectStore.set(objectId, object);
    return object;
}

module.exports = {
    getAllPlugins,
    createObject,
    getValue,
    setValue,
    invokeOperation,
    getObjectDetails,
    listObjects,
    deleteObject,
    getPluginStructure,
    getClassifiers,
    getClassifierDetails,
    getObjectClass,
    getObjectAttributes,
    getObjectOperations,
    getObjectFeatures,
    createFromClassifier
};

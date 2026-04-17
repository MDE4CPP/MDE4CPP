const pluginService = require('../services/plugin.service');
const { asyncHandler } = require('../middleware/errorHandler');

/**
 * Get all available plugins
 * GET /api/v1/plugins
 */
const getPlugins = asyncHandler(async (req, res) => {
    const plugins = await pluginService.getAllPlugins();
    res.json({ plugins });
});

/**
 * Create an object from a plugin
 * POST /api/v1/plugins/:pluginName/objects
 */
const createObject = asyncHandler(async (req, res) => {
    const { pluginName } = req.params;
    const { className } = req.body;
    
    if (!className) {
        return res.status(400).json({
            error: {
                code: 'MISSING_CLASS_NAME',
                message: 'className is required'
            }
        });
    }
    
    const object = await pluginService.createObject(pluginName, className);
    res.status(201).json({ object });
});

/**
 * Get object value (GET operation)
 * GET /api/v1/plugins/objects/:objectId/get/:featureName
 */
const getValue = asyncHandler(async (req, res) => {
    const { objectId, featureName } = req.params;
    const value = await pluginService.getValue(objectId, featureName);
    res.json({ objectId, featureName, value });
});

/**
 * Set object value (SET operation)
 * POST /api/v1/plugins/objects/:objectId/set/:featureName
 */
const setValue = asyncHandler(async (req, res) => {
    const { objectId, featureName } = req.params;
    const { value } = req.body;
    
    if (value === undefined) {
        return res.status(400).json({
            error: {
                code: 'MISSING_VALUE',
                message: 'value is required in request body'
            }
        });
    }
    
    const object = await pluginService.setValue(objectId, featureName, value);
    res.json({ object });
});

/**
 * Invoke operation on object (INVOKE operation)
 * POST /api/v1/plugins/objects/:objectId/invoke/:operationName
 */
const invokeOperation = asyncHandler(async (req, res) => {
    const { objectId, operationName } = req.params;
    const { arguments: args } = req.body;
    
    const result = await pluginService.invokeOperation(objectId, operationName, args || []);
    res.json(result);
});

/**
 * Get object details
 * GET /api/v1/plugins/objects/:objectId
 */
const getObjectDetails = asyncHandler(async (req, res) => {
    const { objectId } = req.params;
    const object = await pluginService.getObjectDetails(objectId);
    res.json({ object });
});

/**
 * List all objects
 * GET /api/v1/plugins/objects
 */
const listObjects = asyncHandler(async (req, res) => {
    const objects = await pluginService.listObjects();
    res.json({ objects });
});

/**
 * Delete an object
 * DELETE /api/v1/plugins/objects/:objectId
 */
const deleteObject = asyncHandler(async (req, res) => {
    const { objectId } = req.params;
    await pluginService.deleteObject(objectId);
    res.json({ success: true });
});

/**
 * Get plugin structure
 * GET /api/v1/plugins/:pluginName/structure
 */
const getPluginStructure = asyncHandler(async (req, res) => {
    const { pluginName } = req.params;
    const structure = await pluginService.getPluginStructure(pluginName);
    res.json(structure);
});

/**
 * Get all classifiers for a plugin
 * GET /api/v1/plugins/:pluginName/classifiers
 */
const getClassifiers = asyncHandler(async (req, res) => {
    const { pluginName } = req.params;
    const classifiers = await pluginService.getClassifiers(pluginName);
    res.json({ classifiers });
});

/**
 * Get classifier details
 * GET /api/v1/plugins/:pluginName/classifiers/:className
 */
const getClassifierDetails = asyncHandler(async (req, res) => {
    const { pluginName, className } = req.params;
    const details = await pluginService.getClassifierDetails(pluginName, className);
    res.json(details);
});

/**
 * Create object from classifier
 * POST /api/v1/plugins/:pluginName/classifiers/:className/create
 */
const createFromClassifier = asyncHandler(async (req, res) => {
    const { pluginName, className } = req.params;
    const { instanceName, properties } = req.body;
    
    const object = await pluginService.createFromClassifier(pluginName, className, instanceName, properties || {});
    res.status(201).json({ object });
});

/**
 * Get object's EClass metadata
 * GET /api/v1/plugins/objects/:objectId/class
 */
const getObjectClass = asyncHandler(async (req, res) => {
    const { objectId } = req.params;
    const classInfo = await pluginService.getObjectClass(objectId);
    res.json(classInfo);
});

/**
 * Get object's attributes
 * GET /api/v1/plugins/objects/:objectId/attributes
 */
const getObjectAttributes = asyncHandler(async (req, res) => {
    const { objectId } = req.params;
    const attributes = await pluginService.getObjectAttributes(objectId);
    res.json({ attributes });
});

/**
 * Get object's operations
 * GET /api/v1/plugins/objects/:objectId/operations
 */
const getObjectOperations = asyncHandler(async (req, res) => {
    const { objectId } = req.params;
    const operations = await pluginService.getObjectOperations(objectId);
    res.json({ operations });
});

/**
 * Get object's structural features
 * GET /api/v1/plugins/objects/:objectId/features
 */
const getObjectFeatures = asyncHandler(async (req, res) => {
    const { objectId } = req.params;
    const features = await pluginService.getObjectFeatures(objectId);
    res.json({ features });
});

/**
 * Export all objects (for download)
 * GET /api/v1/plugins/objects/export
 */
const exportObjects = asyncHandler(async (req, res) => {
    const objects = await pluginService.exportObjects();
    res.json({ objects });
});

/**
 * Get hierarchical tree structure for a plugin's objects
 * GET /api/v1/plugins/:pluginName/objects/tree
 */
const getObjectTree = asyncHandler(async (req, res) => {
    const { pluginName } = req.params;
    const tree = await pluginService.getObjectTree(pluginName);
    res.json(tree);
});

/**
 * Create a child object within a parent via containment reference
 * POST /api/v1/plugins/:pluginName/objects/:parentName/children/:className/:childName
 */
const createChildObject = asyncHandler(async (req, res) => {
    const { pluginName, parentName, className, childName } = req.params;
    const { referenceID, properties } = req.body;
    
    if (referenceID === undefined || referenceID === null) {
        return res.status(400).json({
            error: {
                code: 'MISSING_REFERENCE_ID',
                message: 'referenceID is required in request body'
            }
        });
    }
    
    await pluginService.createChildObject(pluginName, parentName, className, childName, referenceID, properties || {});
    res.status(201).json({ success: true });
});

module.exports = {
    getPlugins,
    getPluginStructure,
    getClassifiers,
    getClassifierDetails,
    createFromClassifier,
    createObject,
    getValue,
    setValue,
    invokeOperation,
    getObjectDetails,
    getObjectClass,
    getObjectAttributes,
    getObjectOperations,
    getObjectFeatures,
    listObjects,
    deleteObject,
    exportObjects,
    getObjectTree,
    createChildObject
};

const express = require('express');
const pluginController = require('../controllers/plugin.controller');

const router = express.Router();

router.get('/', pluginController.getPlugins);
router.get('/:pluginName/structure', pluginController.getPluginStructure);
router.get('/:pluginName/classifiers', pluginController.getClassifiers);
router.get('/:pluginName/classifiers/:className', pluginController.getClassifierDetails);
router.post('/:pluginName/classifiers/:className/create', pluginController.createFromClassifier);
router.post('/:pluginName/objects', pluginController.createObject);
router.get('/objects', pluginController.listObjects);
router.get('/objects/:objectId', pluginController.getObjectDetails);
router.get('/objects/:objectId/class', pluginController.getObjectClass);
router.get('/objects/:objectId/attributes', pluginController.getObjectAttributes);
router.get('/objects/:objectId/operations', pluginController.getObjectOperations);
router.get('/objects/:objectId/features', pluginController.getObjectFeatures);
router.get('/objects/:objectId/get/:featureName', pluginController.getValue);
router.post('/objects/:objectId/set/:featureName', pluginController.setValue);
router.post('/objects/:objectId/invoke/:operationName', pluginController.invokeOperation);
router.delete('/objects/:objectId', pluginController.deleteObject);

module.exports = router;

/**
 * ModelService - Model CRUD operations
 */
class ModelService {
    constructor() {
        this.cache = new Map(); // Cache for model trees
    }

    /**
     * Get hierarchical instance tree for a plugin
     * @param {string} pluginName 
     * @returns {Promise<Object>} Tree structure with roots array
     */
    async getModelTree(pluginName) {
        try {
            const tree = await pluginAPI.getObjectTree(pluginName);
            return tree || { roots: [] };
        } catch (error) {
            console.error(`Failed to get model tree for ${pluginName}:`, error);
            return { roots: [] };
        }
    }

    /**
     * Create root instance (no parent)
     * @param {string} pluginName 
     * @param {string} className 
     * @param {string} instanceName 
     * @param {Object} properties 
     * @returns {Promise<Object>} Created object
     */
    async createRootInstance(pluginName, className, instanceName, properties = {}) {
        try {
            const object = await pluginAPI.createFromClassifier(pluginName, className, instanceName, properties);
            // Clear cache for this plugin
            this.cache.delete(pluginName);
            return object;
        } catch (error) {
            console.error(`Failed to create root instance ${instanceName}:`, error);
            throw error;
        }
    }

    /**
     * Create child instance within a parent
     * @param {string} pluginName 
     * @param {string} parentName 
     * @param {string} className 
     * @param {string} childName 
     * @param {number} referenceID 
     * @returns {Promise<Object>} Success result
     */
    async createChildInstance(pluginName, parentName, className, childName, referenceID, properties = {}) {
        try {
            const result = await pluginAPI.createChildObject(pluginName, parentName, className, childName, referenceID, properties);
            // Clear cache for this plugin
            this.cache.delete(pluginName);
            return result;
        } catch (error) {
            console.error(`Failed to create child instance ${childName}:`, error);
            throw error;
        }
    }

    /**
     * Delete instance
     * @param {string} pluginName 
     * @param {string} instanceId 
     * @returns {Promise<Object>} Success result
     */
    async deleteInstance(pluginName, instanceId) {
        try {
            const result = await pluginAPI.deleteObject(instanceId);
            // Clear cache for this plugin
            this.cache.delete(pluginName);
            return result;
        } catch (error) {
            console.error(`Failed to delete instance ${instanceId}:`, error);
            throw error;
        }
    }

    /**
     * Update attribute value
     * @param {string} pluginName 
     * @param {string} instanceId 
     * @param {string} attributeName 
     * @param {*} value 
     * @returns {Promise<Object>} Updated object
     */
    async updateAttribute(pluginName, instanceId, attributeName, value) {
        try {
            const object = await pluginAPI.setFeatureValue(instanceId, attributeName, value);
            // Clear cache for this plugin
            this.cache.delete(pluginName);
            return object;
        } catch (error) {
            console.error(`Failed to update attribute ${attributeName}:`, error);
            throw error;
        }
    }

    /**
     * Set reference value (single or multi)
     * @param {string} pluginName 
     * @param {string} instanceId 
     * @param {string} referenceName 
     * @param {string|Array} targetId 
     * @returns {Promise<Object>} Updated object
     */
    async setReference(pluginName, instanceId, referenceName, targetId) {
        try {
            const object = await pluginAPI.setFeatureValue(instanceId, referenceName, targetId);
            // Clear cache for this plugin
            this.cache.delete(pluginName);
            return object;
        } catch (error) {
            console.error(`Failed to set reference ${referenceName}:`, error);
            throw error;
        }
    }

    /**
     * Get object details
     * @param {string} instanceId 
     * @returns {Promise<Object>} Object details
     */
    async getObjectDetails(instanceId) {
        try {
            const object = await pluginAPI.getObjectDetails(instanceId);
            return object;
        } catch (error) {
            console.error(`Failed to get object details for ${instanceId}:`, error);
            throw error;
        }
    }

    /**
     * Get object features (attributes and references)
     * @param {string} instanceId 
     * @returns {Promise<Array>} Array of features
     */
    async getObjectFeatures(instanceId) {
        try {
            const features = await pluginAPI.getObjectFeatures(instanceId);
            return features || [];
        } catch (error) {
            console.error(`Failed to get object features for ${instanceId}:`, error);
            return [];
        }
    }

    /**
     * Get object attributes
     * @param {string} instanceId 
     * @returns {Promise<Array>} Array of attributes
     */
    async getObjectAttributes(instanceId) {
        try {
            const attributes = await pluginAPI.getObjectAttributes(instanceId);
            return attributes || [];
        } catch (error) {
            console.error(`Failed to get object attributes for ${instanceId}:`, error);
            return [];
        }
    }

    /**
     * Get object operations
     * @param {string} instanceId 
     * @returns {Promise<Array>} Array of operations
     */
    async getObjectOperations(instanceId) {
        try {
            const operations = await pluginAPI.getObjectOperations(instanceId);
            return operations || [];
        } catch (error) {
            console.error(`Failed to get object operations for ${instanceId}:`, error);
            return [];
        }
    }

    /**
     * Invoke operation on an instance
     * @param {string} instanceId 
     * @param {string} operationName 
     * @param {Array} args 
     * @returns {Promise<Object>} Result
     */
    async invokeOperation(instanceId, operationName, args = []) {
        try {
            const result = await pluginAPI.invokeOperation(instanceId, operationName, args);
            return result;
        } catch (error) {
            console.error(`Failed to invoke ${operationName} on ${instanceId}:`, error);
            throw error;
        }
    }

    /**
     * Refresh model tree cache
     * @param {string} pluginName 
     */
    async refreshTree(pluginName) {
        this.cache.delete(pluginName);
        return await this.getModelTree(pluginName);
    }

    /**
     * Clear cache for a plugin
     * @param {string} pluginName 
     */
    clearCache(pluginName) {
        this.cache.delete(pluginName);
    }

    /**
     * Clear all cache
     */
    clearAllCache() {
        this.cache.clear();
    }
}

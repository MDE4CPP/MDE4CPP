/**
 * MetamodelService - Query and structure metamodel information
 */
class MetamodelService {
    constructor() {
        this.cache = new Map(); // Cache for classifier details
    }

    /**
     * Get all classifiers for a plugin
     * @param {string} pluginName 
     * @returns {Promise<Array>} Array of classifier objects
     */
    async getClassifiers(pluginName) {
        try {
            const classifiers = await pluginAPI.getClassifiers(pluginName);
            // Normalize classifiers - handle both string array and object array
            if (!classifiers || !Array.isArray(classifiers)) {
                return [];
            }
            return classifiers.map(c => {
                // If it's already an object with name, return as-is
                if (typeof c === 'object' && c !== null && c.name) {
                    return c;
                }
                // If it's a string, convert to object
                if (typeof c === 'string') {
                    return { name: c, type: 'EClass' };
                }
                // Fallback: try to extract name from object
                return { name: c.name || c || 'Unnamed', type: c.type || 'EClass' };
            });
        } catch (error) {
            console.error(`Failed to get classifiers for ${pluginName}:`, error);
            return [];
        }
    }

    /**
     * Get classifier details (attributes, references, operations)
     * @param {string} pluginName 
     * @param {string} className 
     * @returns {Promise<Object>} Classifier details
     */
    async getClassifierDetails(pluginName, className) {
        const cacheKey = `${pluginName}:${className}`;
        
        if (this.cache.has(cacheKey)) {
            return this.cache.get(cacheKey);
        }

        try {
            const details = await pluginAPI.getClassifierDetails(pluginName, className);
            this.cache.set(cacheKey, details);
            return details;
        } catch (error) {
            console.error(`Failed to get classifier details for ${pluginName}.${className}:`, error);
            return {
                name: className,
                type: 'EClass',
                attributes: [],
                references: [],
                operations: []
            };
        }
    }

    /**
     * Build containment tree structure from metamodel
     * @param {string} pluginName 
     * @returns {Promise<Object>} Containment tree structure
     */
    async getContainmentTree(pluginName) {
        try {
            const classifiers = await this.getClassifiers(pluginName);
            const tree = {
                plugin: pluginName,
                classifiers: []
            };

            // Build tree for each classifier
            for (const classifier of classifiers) {
                // Handle both string and object formats
                const classifierName = typeof classifier === 'string' ? classifier : (classifier.name || classifier);
                const classifierType = typeof classifier === 'object' ? (classifier.type || 'EClass') : 'EClass';
                
                const details = await this.getClassifierDetails(pluginName, classifierName);
                const classifierNode = {
                    name: classifierName,
                    type: classifierType,
                    containmentRefs: []
                };

                // Find containment references
                if (details.references && Array.isArray(details.references)) {
                    for (let i = 0; i < details.references.length; i++) {
                        const ref = details.references[i];
                        if (ref.containment === true) {
                            // Use featureID from backend if available, otherwise fallback to index
                            const featureID = ref.featureID !== undefined && ref.featureID !== null 
                                ? ref.featureID 
                                : i;
                            
                            classifierNode.containmentRefs.push({
                                name: ref.name,
                                type: ref.type,
                                lowerBound: ref.lower || 0,
                                upperBound: ref.upper === -1 ? -1 : (ref.upper || 1),
                                required: ref.required || false,
                                featureID: featureID
                            });
                        }
                    }
                }

                tree.classifiers.push(classifierNode);
            }

            return tree;
        } catch (error) {
            console.error(`Failed to build containment tree for ${pluginName}:`, error);
            return {
                plugin: pluginName,
                classifiers: []
            };
        }
    }

    /**
     * Get valid child types for a parent classifier
     * @param {string} pluginName 
     * @param {string} parentClassName 
     * @returns {Promise<Array>} Array of valid child types with reference info
     */
    async getValidChildTypes(pluginName, parentClassName) {
        try {
            const details = await this.getClassifierDetails(pluginName, parentClassName);
            const validTypes = [];

            if (details.references && Array.isArray(details.references)) {
                for (let i = 0; i < details.references.length; i++) {
                    const ref = details.references[i];
                    if (ref.containment === true && ref.type) {
                        // Use featureID from backend if available, otherwise fallback to index
                        // Note: Index fallback may not be reliable if features are reordered
                        const referenceID = ref.featureID !== undefined && ref.featureID !== null 
                            ? ref.featureID 
                            : i;
                        
                        validTypes.push({
                            name: ref.type,
                            referenceName: ref.name,
                            referenceID: referenceID,
                            lowerBound: ref.lower || 0,
                            upperBound: ref.upper === -1 ? -1 : (ref.upper || 1),
                            required: ref.required || false
                        });
                    }
                }
            }

            return validTypes;
        } catch (error) {
            console.error(`Failed to get valid child types for ${pluginName}.${parentClassName}:`, error);
            return [];
        }
    }

    /**
     * Check if parent can contain child type
     * @param {string} pluginName 
     * @param {string} parentType 
     * @param {string} childType 
     * @returns {Promise<boolean>} True if parent can contain child
     */
    async canContain(pluginName, parentType, childType) {
        const validTypes = await this.getValidChildTypes(pluginName, parentType);
        return validTypes.some(vt => vt.name === childType);
    }

    /**
     * Get containment reference info for a specific child type
     * @param {string} pluginName 
     * @param {string} parentClassName 
     * @param {string} childTypeName 
     * @returns {Promise<Object|null>} Reference info or null
     */
    async getContainmentReference(pluginName, parentClassName, childTypeName) {
        const validTypes = await this.getValidChildTypes(pluginName, parentClassName);
        return validTypes.find(vt => vt.name === childTypeName) || null;
    }

    /**
     * Clear cache for a plugin
     * @param {string} pluginName 
     */
    clearCache(pluginName) {
        const keysToDelete = [];
        for (const key of this.cache.keys()) {
            if (key.startsWith(`${pluginName}:`)) {
                keysToDelete.push(key);
            }
        }
        keysToDelete.forEach(key => this.cache.delete(key));
    }

    /**
     * Clear all cache
     */
    clearAllCache() {
        this.cache.clear();
    }
}

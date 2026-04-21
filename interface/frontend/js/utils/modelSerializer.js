/**
 * ModelSerializer - Serialize the current MDE4CPP model to canonical JSON format.
 *
 * Canonical format (schemaVersion 1.0):
 * {
 *   schemaVersion: "1.0",
 *   metadata: { modelName, generatedAt, tool },
 *   metamodel: { classes: { <ClassName>: {...} }, enums: { <EnumName>: {...} } },
 *   model: { objects: { <objectId>: {...} } }
 * }
 */
class ModelSerializer {

    /**
     * Convert bounds to human-readable multiplicity string.
     * @param {number} lowerBound
     * @param {number} upperBound (-1 means unbounded)
     * @returns {string} "0..1" | "1" | "0..*" | "1..*"
     */
    static boundsToMultiplicity(lowerBound, upperBound) {
        const lower = lowerBound !== undefined ? lowerBound : 0;
        const upper = upperBound !== undefined ? upperBound : 1;
        
        if (upper === -1) {
            // Unbounded
            return lower === 0 ? "0..*" : "1..*";
        } else if (lower === upper) {
            // Exact match
            return String(lower);
        } else {
            // Range
            return `${lower}..${upper}`;
        }
    }

    /**
     * Serialize the full model (metamodel + instances) for the given plugin.
     * @param {string} pluginName
     * @param {MetamodelService} metamodelService
     * @param {ModelService} modelService
     * @returns {Promise<Object>}
     */
    static async serializeModel(pluginName, metamodelService, modelService) {
        const json = {
            schemaVersion: "1.0",
            metadata: {
                modelName: pluginName,
                generatedAt: new Date().toISOString(),
                tool: "MDE4CPP Modeler"
            },
            metamodel: {
                classes: {},
                enums: {}
            },
            model: {
                objects: {}
            }
        };

        // ---- Metamodel classifiers ----
        const classifiers = await metamodelService.getClassifiers(pluginName);

        for (const c of classifiers) {
            const classifierName = typeof c === 'string' ? c : c.name;
            if (!classifierName) continue;

            let details;
            try {
                details = await metamodelService.getClassifierDetails(pluginName, classifierName);
            } catch (e) {
                console.warn(`Skipping classifier ${classifierName}:`, e);
                continue;
            }

            const classifierType = details.type || 'EClass';

            // Handle EEnum separately
            if (classifierType === 'EEnum') {
                const enumEntry = {
                    literals: []
                };
                
                if (Array.isArray(details.literals)) {
                    enumEntry.literals = details.literals.map(lit => {
                        // Use literal name if available, otherwise use name
                        return lit.literal || lit.name || String(lit);
                    });
                }
                
                json.metamodel.enums[classifierName] = enumEntry;
                continue;
            }

            // Handle EClass (and other types as classes)
            const classEntry = {
                attributes: {},
                references: {},
                operations: {}
            };

            // Process attributes
            if (Array.isArray(details.attributes)) {
                for (const a of details.attributes) {
                    const attrName = a.name || a;
                    if (!attrName) continue;
                    classEntry.attributes[attrName] = {
                        type: a.type || 'String'
                    };
                }
            }

            // Process references (including containmentRefs)
            const refMap = new Map();
            
            if (Array.isArray(details.references)) {
                for (const r of details.references) {
                    const refName = r.name || r;
                    if (!refName) continue;
                    refMap.set(refName, {
                        type: r.type || 'unknown',
                        containment: r.containment === true,
                        lowerBound: r.lowerBound !== undefined ? r.lowerBound : 0,
                        upperBound: r.upperBound !== undefined ? r.upperBound : -1
                    });
                }
            }

            // Also include containmentRefs if present (backend returns them separately)
            if (Array.isArray(details.containmentRefs)) {
                for (const cr of details.containmentRefs) {
                    const refName = cr.name || cr;
                    if (!refName) continue;
                    if (!refMap.has(refName)) {
                        refMap.set(refName, {
                            type: cr.type || 'unknown',
                            containment: true,
                            lowerBound: cr.lowerBound !== undefined ? cr.lowerBound : 0,
                            upperBound: cr.upperBound !== undefined ? cr.upperBound : -1
                        });
                    }
                }
            }

            // Convert references to object with multiplicity strings
            for (const [refName, refData] of refMap.entries()) {
                classEntry.references[refName] = {
                    type: refData.type,
                    containment: refData.containment,
                    multiplicity: this.boundsToMultiplicity(refData.lowerBound, refData.upperBound)
                };
            }

            // Process operations
            if (Array.isArray(details.operations)) {
                for (const op of details.operations) {
                    const opName = op.name || op.operationName || op;
                    if (!opName) continue;
                    
                    const opEntry = {
                        returnType: op.returnType || 'void',
                        parameters: {}
                    };
                    
                    if (Array.isArray(op.parameters)) {
                        for (const p of op.parameters) {
                            const paramName = p.name || p;
                            if (paramName) {
                                opEntry.parameters[paramName] = p.type || 'unknown';
                            }
                        }
                    }
                    
                    classEntry.operations[opName] = opEntry;
                }
            }

            json.metamodel.classes[classifierName] = classEntry;
        }

        // ---- Instances & hierarchy (derived from containment references) ----
        let tree;
        try {
            tree = await modelService.getModelTree(pluginName);
        } catch (e) {
            console.warn('Failed to get model tree:', e);
            tree = { roots: [] };
        }

        // Collect all instance IDs and their types from the tree, but do NOT
        // trust the tree for hierarchy – containment references define that.
        const nodeInfo = new Map(); // id -> { type }
        const collect = (node) => {
            if (!node) return;
            const id = node.name || node.id || node;
            if (!id) return;
            const type = node.type || 'unknown';
            if (!nodeInfo.has(id)) {
                nodeInfo.set(id, { type });
            } else {
                const info = nodeInfo.get(id);
                info.type = info.type || type;
            }
            if (Array.isArray(node.children)) {
                node.children.forEach(child => collect(child));
            }
        };
        if (tree && Array.isArray(tree.roots)) {
            tree.roots.forEach(root => collect(root));
        }

        const allIds = Array.from(nodeInfo.keys());
        const containedIds = new Set(); // ids that appear in containment references

        // Serialize each instance as object keyed by ID
        for (const [objectId, info] of nodeInfo.entries()) {
            const objectEntry = {
                type: info.type,
                attributes: {},
                references: {}
            };

            try {
                const features = await modelService.getObjectFeatures(objectId);
                if (Array.isArray(features)) {
                    for (const f of features) {
                        const featureName = f.name || f;
                        if (!featureName) continue;

                        // Skip unset features (null/undefined)
                        if (f.value === null || f.value === undefined) {
                            continue;
                        }

                        // Separate attributes from references
                        const isReference =
                            f.featureType === 'EReference' ||
                            f.featureType === 'EReference (containment)' ||
                            f.containment === true;

                        if (isReference) {
                            // Normalize reference targets to an array of IDs
                            const raw = f.value;
                            let targets = [];
                            if (Array.isArray(raw)) {
                                targets = raw.filter(id => id != null);
                            } else if (raw !== null && raw !== undefined) {
                                targets = [raw];
                            }
                            if (targets.length === 0) {
                                continue;
                            }

                            // Filter to known instances when possible (but keep originals if none match)
                            const knownTargets = targets.filter(id => nodeInfo.has(id));
                            const finalTargets = knownTargets.length > 0 ? knownTargets : targets;

                            // Store as single id or array, matching canonical contract
                            objectEntry.references[featureName] =
                                finalTargets.length === 1 ? finalTargets[0] : finalTargets;

                            // Containment references influence hierarchy (roots)
                            const isContainment =
                                f.featureType === 'EReference (containment)' || f.containment === true;
                            if (isContainment) {
                                for (const tid of finalTargets) {
                                    containedIds.add(tid);
                                }
                            }
                        } else {
                            // Attributes: store primitive/enum values
                            objectEntry.attributes[featureName] = f.value;
                        }
                    }
                }
            } catch (e) {
                // Instance features not available — keep empty attributes/references
                console.warn(`Failed to get features for ${objectId}:`, e);
            }

            // Only add object if it has at least type (even if no attributes/references)
            json.model.objects[objectId] = objectEntry;
        }

        // Compute roots purely from containment references:
        // start with all IDs, subtract any that are targets of containment refs.
        json.model.roots = allIds.filter(id => !containedIds.has(id));

        return json;
    }

    /**
     * Pretty-print an object as JSON with 2-space indentation.
     * @param {Object} obj
     * @returns {string}
     */
    static formatJson(obj) {
        return JSON.stringify(obj, null, 2);
    }
}

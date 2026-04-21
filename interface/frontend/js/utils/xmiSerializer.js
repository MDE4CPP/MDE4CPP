/**
 * XMISerializer - Serialize the canonical JSON model to XMI 2.0 format.
 *
 * Generates XMI-compliant XML for Ecore models with proper namespaces.
 */
class XMISerializer {

    /**
     * Escape XML special characters.
     * @param {string} str
     * @returns {string}
     */
    static escapeXml(str) {
        if (str == null) return '';
        return String(str)
            .replace(/&/g, '&amp;')
            .replace(/</g, '&lt;')
            .replace(/>/g, '&gt;')
            .replace(/"/g, '&quot;')
            .replace(/'/g, '&apos;');
    }

    /**
     * Generate XMI document from canonical JSON model.
     * @param {Object} jsonModel - Canonical JSON from ModelSerializer
     * @returns {string} XMI XML string
     */
    static serializeToXMI(jsonModel) {
        const modelName = jsonModel.metadata?.modelName || 'Model';
        const nsURI = `http://www.example.org/${modelName}`;
        const nsPrefix = modelName;

        let xml = '<?xml version="1.0" encoding="UTF-8"?>\n';
        xml += `<ecore:EPackage xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ecore="http://www.eclipse.org/emf/2002/Ecore" name="${this.escapeXml(modelName)}" nsURI="${this.escapeXml(nsURI)}" nsPrefix="${this.escapeXml(nsPrefix)}">\n`;

        // ---- Metamodel: Classes ----
        const classes = jsonModel.metamodel?.classes || {};
        for (const [className, classData] of Object.entries(classes)) {
            xml += `  <eClassifiers xsi:type="ecore:EClass" name="${this.escapeXml(className)}">\n`;

            // Attributes
            const attrs = classData.attributes || {};
            for (const [attrName, attrData] of Object.entries(attrs)) {
                const attrType = this.mapTypeToEcore(attrData.type);
                xml += `    <eStructuralFeatures xsi:type="ecore:EAttribute" name="${this.escapeXml(attrName)}" eType="${attrType}"/>\n`;
            }

            // References
            const refs = classData.references || {};
            for (const [refName, refData] of Object.entries(refs)) {
                const refType = refData.type === 'unknown' ? `#//${refData.type}` : `#//${refData.type}`;
                const containment = refData.containment ? ' containment="true"' : '';
                const multiplicity = this.multiplicityToBounds(refData.multiplicity);
                xml += `    <eStructuralFeatures xsi:type="ecore:EReference" name="${this.escapeXml(refName)}" eType="${refType}"${containment}${multiplicity}/>\n`;
            }

            // Operations
            const ops = classData.operations || {};
            for (const [opName, opData] of Object.entries(ops)) {
                const returnType = opData.returnType === 'void' ? '' : ` eType="${this.mapTypeToEcore(opData.returnType)}"`;
                xml += `    <eOperations name="${this.escapeXml(opName)}"${returnType}>\n`;
                
                const params = opData.parameters || {};
                for (const [paramName, paramType] of Object.entries(params)) {
                    xml += `      <eParameters name="${this.escapeXml(paramName)}" eType="${this.mapTypeToEcore(paramType)}"/>\n`;
                }
                
                xml += `    </eOperations>\n`;
            }

            xml += `  </eClassifiers>\n`;
        }

        // ---- Metamodel: Enums ----
        const enums = jsonModel.metamodel?.enums || {};
        for (const [enumName, enumData] of Object.entries(enums)) {
            xml += `  <eClassifiers xsi:type="ecore:EEnum" name="${this.escapeXml(enumName)}">\n`;
            
            const literals = enumData.literals || [];
            for (const literal of literals) {
                xml += `    <eLiterals name="${this.escapeXml(literal)}" literal="${this.escapeXml(literal)}"/>\n`;
            }
            
            xml += `  </eClassifiers>\n`;
        }

        xml += `</ecore:EPackage>\n`;

        // ---- Model Instances (separate root element) ----
        const objects = jsonModel.model?.objects || {};
        if (Object.keys(objects).length > 0) {
            xml += `\n<!-- Model Instances -->\n`;
            xml += `<${nsPrefix}:${modelName} xmlns:${nsPrefix}="${nsURI}" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">\n`;
            
            for (const [objectId, objectData] of Object.entries(objects)) {
                const className = objectData.type || 'Unknown';
                const parentId = objectData.parent || '';
                xml += `  <objects xsi:type="${nsPrefix}:${this.escapeXml(className)}" xmi:id="${this.escapeXml(objectId)}"`;
                if (parentId) {
                    xml += ` parent="${this.escapeXml(parentId)}"`;
                }
                
                // Attributes as XML attributes
                const attrs = objectData.attributes || {};
                for (const [attrName, attrValue] of Object.entries(attrs)) {
                    if (attrValue != null) {
                        xml += ` ${this.escapeXml(attrName)}="${this.escapeXml(String(attrValue))}"`;
                    }
                }
                
                xml += `>\n`;
                
                // References as child elements
                const refs = objectData.references || {};
                for (const [refName, refValue] of Object.entries(refs)) {
                    if (refValue != null) {
                        if (Array.isArray(refValue)) {
                            // Multiple references
                            for (const refId of refValue) {
                                if (refId != null) {
                                    xml += `    <${this.escapeXml(refName)} xmi:idref="${this.escapeXml(String(refId))}"/>\n`;
                                }
                            }
                        } else {
                            // Single reference
                            xml += `    <${this.escapeXml(refName)} xmi:idref="${this.escapeXml(String(refValue))}"/>\n`;
                        }
                    }
                }
                
                xml += `  </objects>\n`;
            }
            
            xml += `</${nsPrefix}:${modelName}>\n`;
        }

        return xml;
    }

    /**
     * Map JSON type to Ecore type URI.
     * @param {string} type
     * @returns {string}
     */
    static mapTypeToEcore(type) {
        const typeMap = {
            'String': 'ecore:EDataType platform:/plugin/org.eclipse.uml2.types/model/Types.ecore#//String',
            'Integer': 'ecore:EDataType platform:/plugin/org.eclipse.uml2.types/model/Types.ecore#//Integer',
            'Boolean': 'ecore:EDataType http://www.eclipse.org/emf/2002/Ecore#//EBoolean',
            'Number': 'ecore:EDataType platform:/plugin/org.eclipse.uml2.types/model/Types.ecore#//Integer',
            'Date': 'ecore:EDataType platform:/plugin/org.eclipse.uml2.types/model/Types.ecore#//String'
        };
        
        // If it's an enum, reference it
        if (type && !typeMap[type] && !type.startsWith('ecore:') && !type.includes('://')) {
            // Assume it's a classifier reference
            return `#//${type}`;
        }
        
        return typeMap[type] || 'ecore:EDataType platform:/plugin/org.eclipse.uml2.types/model/Types.ecore#//String';
    }

    /**
     * Convert multiplicity string to XMI bounds attributes.
     * @param {string} multiplicity - "0..1" | "1" | "0..*" | "1..*"
     * @returns {string} - " lowerBound=\"0\" upperBound=\"1\"" etc.
     */
    static multiplicityToBounds(multiplicity) {
        if (!multiplicity) return '';
        
        if (multiplicity === '0..*') {
            return ' lowerBound="0" upperBound="-1"';
        } else if (multiplicity === '1..*') {
            return ' lowerBound="1" upperBound="-1"';
        } else if (multiplicity.includes('..')) {
            const [lower, upper] = multiplicity.split('..');
            return ` lowerBound="${lower}" upperBound="${upper === '*' ? '-1' : upper}"`;
        } else {
            // Single number
            const num = parseInt(multiplicity, 10);
            return ` lowerBound="${num}" upperBound="${num}"`;
        }
    }

    /**
     * Pretty-print XML with indentation (basic).
     * @param {string} xml
     * @returns {string}
     */
    static formatXml(xml) {
        // Basic formatting - could be enhanced with proper XML parser
        return xml;
    }
}

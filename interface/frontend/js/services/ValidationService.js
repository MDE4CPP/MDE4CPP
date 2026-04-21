/**
 * ValidationService - Real-time validation
 */
class ValidationService {
    constructor() {
        this.errors = new Map();
    }

    /**
     * Validate attribute value
     * @param {Object} attribute - Attribute definition
     * @param {*} value - Value to validate
     * @returns {Object} Validation result
     */
    validateAttribute(attribute, value) {
        const errors = [];

        // Required check
        if (attribute.required && (value === null || value === undefined || value === '')) {
            errors.push({
                field: attribute.name,
                message: `${attribute.name} is required`,
                severity: 'error'
            });
        }

        // Type check
        if (value !== null && value !== undefined && value !== '') {
            const typeError = this.validateType(attribute.type, value);
            if (typeError) {
                errors.push({
                    field: attribute.name,
                    message: typeError,
                    severity: 'error'
                });
            }
        }

        // Range check for numbers
        if (this.isNumericType(attribute.type) && value !== null && value !== undefined) {
            if (attribute.lowerBound !== undefined && value < attribute.lowerBound) {
                errors.push({
                    field: attribute.name,
                    message: `${attribute.name} must be at least ${attribute.lowerBound}`,
                    severity: 'error'
                });
            }
            if (attribute.upperBound !== undefined && attribute.upperBound !== -1 && value > attribute.upperBound) {
                errors.push({
                    field: attribute.name,
                    message: `${attribute.name} must be at most ${attribute.upperBound}`,
                    severity: 'error'
                });
            }
        }

        // String length check
        if (this.isStringType(attribute.type) && typeof value === 'string') {
            if (attribute.lowerBound !== undefined && value.length < attribute.lowerBound) {
                errors.push({
                    field: attribute.name,
                    message: `${attribute.name} must be at least ${attribute.lowerBound} characters`,
                    severity: 'error'
                });
            }
            if (attribute.upperBound !== undefined && attribute.upperBound !== -1 && value.length > attribute.upperBound) {
                errors.push({
                    field: attribute.name,
                    message: `${attribute.name} must be at most ${attribute.upperBound} characters`,
                    severity: 'error'
                });
            }
        }

        return {
            valid: errors.length === 0,
            errors: errors
        };
    }

    /**
     * Validate type
     */
    validateType(type, value) {
        if (!type) return null;

        const typeLower = type.toLowerCase();

        if (typeLower.includes('string') || typeLower === 'estring') {
            if (typeof value !== 'string') {
                return `Expected string, got ${typeof value}`;
            }
        } else if (typeLower.includes('int') || typeLower === 'eint') {
            if (!Number.isInteger(value)) {
                return `Expected integer, got ${typeof value}`;
            }
        } else if (typeLower.includes('long') || typeLower === 'elong') {
            if (!Number.isInteger(value)) {
                return `Expected long integer, got ${typeof value}`;
            }
        } else if (typeLower.includes('double') || typeLower === 'edouble') {
            if (typeof value !== 'number') {
                return `Expected double, got ${typeof value}`;
            }
        } else if (typeLower.includes('float') || typeLower === 'efloat') {
            if (typeof value !== 'number') {
                return `Expected float, got ${typeof value}`;
            }
        } else if (typeLower.includes('bool') || typeLower === 'eboolean') {
            if (typeof value !== 'boolean') {
                return `Expected boolean, got ${typeof value}`;
            }
        }

        return null;
    }

    /**
     * Check if type is numeric
     */
    isNumericType(type) {
        if (!type) return false;
        const typeLower = type.toLowerCase();
        return typeLower.includes('int') || 
               typeLower.includes('long') || 
               typeLower.includes('double') || 
               typeLower.includes('float') ||
               typeLower === 'eint' ||
               typeLower === 'elong' ||
               typeLower === 'edouble' ||
               typeLower === 'efloat';
    }

    /**
     * Check if type is string
     */
    isStringType(type) {
        if (!type) return false;
        const typeLower = type.toLowerCase();
        return typeLower.includes('string') || typeLower === 'estring';
    }

    /**
     * Validate instance
     * @param {Object} instance - Instance data
     * @param {Array} attributes - Attribute definitions
     * @returns {Object} Validation result
     */
    validateInstance(instance, attributes) {
        const allErrors = [];

        for (const attr of attributes) {
            const value = instance[attr.name] !== undefined ? instance[attr.name] : attr.value;
            const result = this.validateAttribute(attr, value);
            if (!result.valid) {
                allErrors.push(...result.errors);
            }
        }

        return {
            valid: allErrors.length === 0,
            errors: allErrors
        };
    }

    /**
     * Validate reference
     * @param {Object} reference - Reference definition
     * @param {*} value - Value to validate
     * @returns {Object} Validation result
     */
    validateReference(reference, value) {
        const errors = [];

        // Required check
        if (reference.required) {
            if (reference.upperBound === 1) {
                // Single reference
                if (!value || value === null) {
                    errors.push({
                        field: reference.name,
                        message: `${reference.name} is required`,
                        severity: 'error'
                    });
                }
            } else {
                // Multi reference
                if (!value || !Array.isArray(value) || value.length === 0) {
                    errors.push({
                        field: reference.name,
                        message: `${reference.name} is required`,
                        severity: 'error'
                    });
                }
            }
        }

        // Cardinality check
        if (value !== null && value !== undefined) {
            if (reference.upperBound === 1) {
                // Single reference - value should not be array
                if (Array.isArray(value)) {
                    errors.push({
                        field: reference.name,
                        message: `${reference.name} must be a single value, not an array`,
                        severity: 'error'
                    });
                }
            } else {
                // Multi reference - value should be array
                if (!Array.isArray(value)) {
                    errors.push({
                        field: reference.name,
                        message: `${reference.name} must be an array`,
                        severity: 'error'
                    });
                } else {
                    // Check bounds
                    if (reference.lowerBound !== undefined && value.length < reference.lowerBound) {
                        errors.push({
                            field: reference.name,
                            message: `${reference.name} must have at least ${reference.lowerBound} value(s)`,
                            severity: 'error'
                        });
                    }
                    if (reference.upperBound !== undefined && reference.upperBound !== -1 && value.length > reference.upperBound) {
                        errors.push({
                            field: reference.name,
                            message: `${reference.name} must have at most ${reference.upperBound} value(s)`,
                            severity: 'error'
                        });
                    }
                }
            }
        }

        return {
            valid: errors.length === 0,
            errors: errors
        };
    }

    /**
     * Get validation errors for a field
     */
    getFieldErrors(fieldName) {
        return this.errors.get(fieldName) || [];
    }

    /**
     * Set validation errors for a field
     */
    setFieldErrors(fieldName, errors) {
        if (errors && errors.length > 0) {
            this.errors.set(fieldName, errors);
        } else {
            this.errors.delete(fieldName);
        }
    }

    /**
     * Clear all errors
     */
    clearErrors() {
        this.errors.clear();
    }

    /**
     * Clear errors for a specific field
     */
    clearFieldErrors(fieldName) {
        this.errors.delete(fieldName);
    }

    /**
     * Check if there are any errors
     */
    hasErrors() {
        return this.errors.size > 0;
    }

    /**
     * Get all errors
     */
    getAllErrors() {
        const allErrors = [];
        for (const errors of this.errors.values()) {
            allErrors.push(...errors);
        }
        return allErrors;
    }
}

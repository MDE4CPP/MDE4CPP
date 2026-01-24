class ObjectInspector {
    constructor() {
        this.currentObjectId = null;
    }

    async inspect(objectId) {
        this.currentObjectId = objectId;
        
        const inspectorSection = document.getElementById('inspector-section');
        const inspectorContent = document.getElementById('inspector-content');
        
        if (!inspectorSection || !inspectorContent) return;

        inspectorSection.classList.remove('hidden');
        inspectorContent.innerHTML = '<div class="loading">Loading object details...</div>';

        try {
            // Load all object information
            const [attributes, operations, features, objectDetails] = await Promise.all([
                pluginAPI.getObjectAttributes(objectId).catch(() => []),
                pluginAPI.getObjectOperations(objectId).catch(() => []),
                pluginAPI.getObjectFeatures(objectId).catch(() => []),
                pluginAPI.getObjectDetails(objectId).catch(() => null)
            ]);

            this.renderInspector(objectId, attributes, operations, features, objectDetails);
        } catch (error) {
            inspectorContent.innerHTML = `<div class="error">Error loading object: ${error.message}</div>`;
        }
    }

    renderInspector(objectId, attributes, operations, features, objectDetails) {
        const inspectorContent = document.getElementById('inspector-content');
        if (!inspectorContent) return;

        let html = `
            <div class="inspector-header">
                <h3>Object: ${objectId}</h3>
                ${objectDetails ? `<div class="object-info">
                    <span>Class: ${objectDetails.className || objectDetails.type || 'unknown'}</span>
                    ${objectDetails.pluginName ? `<span>Plugin: ${objectDetails.pluginName}</span>` : ''}
                </div>` : ''}
            </div>
        `;

        // Attributes section
        if (attributes && attributes.length > 0) {
            html += '<div class="inspector-section"><h4>Attributes</h4><table class="feature-table">';
            html += '<thead><tr><th>Name</th><th>Type</th><th>Value</th><th>Actions</th></tr></thead><tbody>';
            
            attributes.forEach(attr => {
                html += `
                    <tr>
                        <td><strong>${attr.name}</strong></td>
                        <td>${attr.type || 'unknown'}</td>
                        <td class="value-cell">
                            <span class="value-display" data-feature="${attr.name}">
                                ${attr.value !== null && attr.value !== undefined ? this.formatValue(attr.value) : '<em>null</em>'}
                            </span>
                        </td>
                        <td class="actions-cell">
                            <button class="btn btn-small get-btn" data-feature="${attr.name}">Get</button>
                            <button class="btn btn-small set-btn" data-feature="${attr.name}">Set</button>
                        </td>
                    </tr>
                `;
            });
            
            html += '</tbody></table></div>';
        }

        // Operations section
        if (operations && operations.length > 0) {
            html += '<div class="inspector-section"><h4>Operations</h4><ul class="operation-list">';
            
            operations.forEach(op => {
                const params = op.parameters ? op.parameters.map(p => `${p.name}: ${p.type || 'unknown'}`).join(', ') : '';
                html += `
                    <li class="operation-item">
                        <div class="operation-header">
                            <strong>${op.name}</strong>(${params})
                            ${op.returnType ? `: ${op.returnType}` : ''}
                        </div>
                        <button class="btn btn-small invoke-btn" data-operation="${op.name}">Invoke</button>
                    </li>
                `;
            });
            
            html += '</ul></div>';
        }

        // Structural Features section
        if (features && features.length > 0) {
            html += '<div class="inspector-section"><h4>Structural Features</h4><table class="feature-table">';
            html += '<thead><tr><th>Name</th><th>Type</th><th>Feature Type</th><th>Value</th><th>Actions</th></tr></thead><tbody>';
            
            features.forEach(feat => {
                html += `
                    <tr>
                        <td><strong>${feat.name}</strong></td>
                        <td>${feat.type || 'unknown'}</td>
                        <td>${feat.featureType || 'unknown'}</td>
                        <td class="value-cell">
                            <span class="value-display" data-feature="${feat.name}">
                                ${feat.value !== null && feat.value !== undefined ? this.formatValue(feat.value) : '<em>null</em>'}
                            </span>
                        </td>
                        <td class="actions-cell">
                            <button class="btn btn-small get-btn" data-feature="${feat.name}">Get</button>
                            <button class="btn btn-small set-btn" data-feature="${feat.name}">Set</button>
                        </td>
                    </tr>
                `;
            });
            
            html += '</tbody></table></div>';
        }

        inspectorContent.innerHTML = html;

        // Setup event listeners
        this.setupInspectorListeners();
    }

    setupInspectorListeners() {
        // Get buttons
        document.querySelectorAll('.get-btn').forEach(btn => {
            btn.addEventListener('click', (e) => {
                const featureName = btn.dataset.feature;
                this.getFeatureValue(featureName);
            });
        });

        // Set buttons
        document.querySelectorAll('.set-btn').forEach(btn => {
            btn.addEventListener('click', (e) => {
                const featureName = btn.dataset.feature;
                this.showSetDialog(featureName);
            });
        });

        // Invoke buttons
        document.querySelectorAll('.invoke-btn').forEach(btn => {
            btn.addEventListener('click', (e) => {
                const operationName = btn.dataset.operation;
                this.showInvokeDialog(operationName);
            });
        });
    }

    async getFeatureValue(featureName) {
        if (!this.currentObjectId) return;

        try {
            const value = await pluginAPI.getFeatureValue(this.currentObjectId, featureName);
            
            // Update display
            const valueDisplay = document.querySelector(`.value-display[data-feature="${featureName}"]`);
            if (valueDisplay) {
                valueDisplay.innerHTML = this.formatValue(value);
            }

            // Show success
            this.showMessage(`Got value for ${featureName}: ${this.formatValue(value)}`, 'success');
        } catch (error) {
            this.showMessage(`Failed to get value: ${error.message}`, 'error');
        }
    }

    showSetDialog(featureName) {
        const currentValue = this.getCurrentValue(featureName);
        const newValue = prompt(`Set value for ${featureName}:`, currentValue !== null ? currentValue : '');
        
        if (newValue !== null) {
            this.setFeatureValue(featureName, newValue);
        }
    }

    async setFeatureValue(featureName, value) {
        if (!this.currentObjectId) return;

        try {
            // Try to parse value based on context
            let parsedValue = value;
            
            // Try to parse as number if it looks like a number
            if (!isNaN(value) && value.trim() !== '') {
                parsedValue = Number(value);
            } else if (value.toLowerCase() === 'true' || value.toLowerCase() === 'false') {
                parsedValue = value.toLowerCase() === 'true';
            }

            await pluginAPI.setFeatureValue(this.currentObjectId, featureName, parsedValue);
            
            // Update display
            const valueDisplay = document.querySelector(`.value-display[data-feature="${featureName}"]`);
            if (valueDisplay) {
                valueDisplay.innerHTML = this.formatValue(parsedValue);
            }

            // Show success
            this.showMessage(`Set ${featureName} to ${this.formatValue(parsedValue)}`, 'success');
        } catch (error) {
            this.showMessage(`Failed to set value: ${error.message}`, 'error');
        }
    }

    showInvokeDialog(operationName) {
        // Simple invoke dialog - in a real implementation, this would show a form
        // to input parameters based on the operation's signature
        const confirmInvoke = confirm(`Invoke operation ${operationName}?`);
        
        if (confirmInvoke) {
            this.invokeOperation(operationName, []);
        }
    }

    async invokeOperation(operationName, arguments_) {
        if (!this.currentObjectId) return;

        try {
            // Note: The actual invoke endpoint might need to be implemented
            // For now, we'll use a placeholder
            this.showMessage(`Operation ${operationName} invoked (implementation pending)`, 'info');
        } catch (error) {
            this.showMessage(`Failed to invoke operation: ${error.message}`, 'error');
        }
    }

    getCurrentValue(featureName) {
        const valueDisplay = document.querySelector(`.value-display[data-feature="${featureName}"]`);
        if (valueDisplay) {
            const text = valueDisplay.textContent.trim();
            return text === 'null' || text === '' ? null : text;
        }
        return null;
    }

    formatValue(value) {
        if (value === null || value === undefined) {
            return '<em>null</em>';
        }
        if (typeof value === 'object') {
            return JSON.stringify(value);
        }
        return String(value);
    }

    showMessage(message, type = 'info') {
        // Simple message display - could be enhanced with a toast notification
        const messageClass = type === 'error' ? 'error' : type === 'success' ? 'success' : 'info';
        alert(`[${type.toUpperCase()}] ${message}`);
    }
}

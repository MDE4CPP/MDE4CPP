class PluginBrowser {
    constructor() {
        this.currentPlugin = null;
        this.currentClassifier = null;
        this.plugins = [];
        this.objects = [];
        this.init();
    }

    init() {
        this.setupEventListeners();
        this.checkAPIStatus();
        this.loadPlugins();
        this.loadObjects();
    }

    async checkAPIStatus() {
        const banner = document.getElementById('api-status-banner');
        const statusText = document.getElementById('api-status-text');
        if (!banner || !statusText) return;

        try {
            // Backend can respond even in fallback mode, so also check for real classifiers.
            await pluginAPI.getPlugins();

            const structure = await pluginAPI.getPluginStructure('ecore').catch(() => null);
            const hasClassifiers = !!(structure && Array.isArray(structure.classifiers) && structure.classifiers.length > 0);

            if (hasClassifiers) {
                banner.classList.remove('hidden', 'disconnected', 'warning');
                banner.classList.add('connected');
                statusText.innerHTML = '✅ Connected to MDE4CPP_PluginAPI (via backend) - Full functionality available';
            } else {
                // Backend up, but C++ API not reachable (or no plugins loaded)
                banner.classList.remove('hidden', 'connected', 'disconnected');
                banner.classList.add('warning');
                statusText.innerHTML = '⚠️ C++ API not connected (or no classifiers). <strong>To enable full features:</strong> Run MDE4CPP_PluginAPI.exe on port 8080 and refresh.';
            }
        } catch (error) {
            banner.classList.remove('hidden', 'connected', 'warning');
            banner.classList.add('disconnected');
            statusText.innerHTML = '❌ Cannot connect to backend API. Please check if the server is running.';
        }
    }

    setupEventListeners() {
        // Refresh buttons
        document.getElementById('refresh-plugins-btn')?.addEventListener('click', () => this.loadPlugins());
        document.getElementById('refresh-objects-btn')?.addEventListener('click', () => this.loadObjects());

        // Create object button
        document.getElementById('create-object-btn')?.addEventListener('click', () => this.showCreateForm());

        // Cancel create button
        document.getElementById('cancel-create-btn')?.addEventListener('click', () => this.hideCreateForm());

        // Create object form
        document.getElementById('create-object-form')?.addEventListener('submit', (e) => {
            e.preventDefault();
            this.handleCreateObject(e);
        });

        // Error modal close
        document.querySelector('.close-modal')?.addEventListener('click', () => {
            document.getElementById('error-modal').classList.add('hidden');
        });
    }

    async loadPlugins() {
        const pluginList = document.getElementById('plugin-list');
        if (!pluginList) return;

        pluginList.innerHTML = '<div class="loading">Loading plugins...</div>';

        try {
            this.plugins = await pluginAPI.getPlugins();
            this.renderPluginList();
        } catch (error) {
            pluginList.innerHTML = `<div class="error">Error loading plugins: ${error.message}</div>`;
            this.showError(error.message);
        }
    }

    renderPluginList() {
        const pluginList = document.getElementById('plugin-list');
        if (!pluginList) return;

        if (this.plugins.length === 0) {
            pluginList.innerHTML = '<div class="empty-state">No plugins found</div>';
            return;
        }

        pluginList.innerHTML = this.plugins.map(plugin => {
            const pluginName = typeof plugin === 'string' ? plugin : plugin.name;
            return `
                <div class="plugin-item" data-plugin="${pluginName}">
                    <span class="plugin-icon">📦</span>
                    <span class="plugin-name">${pluginName}</span>
                </div>
            `;
        }).join('');

        // Add click handlers
        pluginList.querySelectorAll('.plugin-item').forEach(item => {
            item.addEventListener('click', () => {
                const pluginName = item.dataset.plugin;
                this.selectPlugin(pluginName);
            });
        });
    }

    async selectPlugin(pluginName) {
        this.currentPlugin = pluginName;
        
        // Update UI
        document.querySelectorAll('.plugin-item').forEach(item => {
            item.classList.toggle('active', item.dataset.plugin === pluginName);
        });

        // Load structure
        await this.loadPluginStructure(pluginName);
    }

    async loadPluginStructure(pluginName) {
        const structureTree = document.getElementById('structure-tree');
        const structureTitle = document.getElementById('structure-title');
        
        if (!structureTree || !structureTitle) return;

        structureTitle.textContent = `Structure: ${pluginName}`;
        structureTree.innerHTML = '<div class="loading">Loading structure...</div>';

        try {
            const structure = await pluginAPI.getPluginStructure(pluginName);
            this.renderStructure(structure);
        } catch (error) {
            structureTree.innerHTML = `<div class="error">Error loading structure: ${error.message}</div>`;
            this.showError(error.message);
        }
    }

    renderStructure(structure) {
        const structureTree = document.getElementById('structure-tree');
        if (!structureTree) return;

        let html = `
            <div class="structure-item">
                <div class="structure-header">
                    <span class="structure-icon">📁</span>
                    <span class="structure-name">Package: ${structure.name || 'Root'}</span>
                </div>
                <div class="structure-details">
                    <div class="structure-meta">
                        <span>URI: ${structure.nsURI || 'N/A'}</span>
                        <span>Prefix: ${structure.nsPrefix || 'N/A'}</span>
                    </div>
                </div>
            </div>
        `;

        if (structure.classifiers && structure.classifiers.length > 0) {
            html += '<div class="classifiers-section">';
            html += '<h3>Classifiers:</h3>';
            html += '<div class="classifiers-list">';
            
            structure.classifiers.forEach(classifier => {
                const typeIcon = classifier.type === 'EClass' ? '📄' : 
                                classifier.type === 'EEnum' ? '🔢' : '📋';
                html += `
                    <div class="classifier-item" data-classifier="${classifier.name}">
                        <span class="classifier-icon">${typeIcon}</span>
                        <span class="classifier-name">${classifier.name}</span>
                        <span class="classifier-type">(${classifier.type})</span>
                    </div>
                `;
            });
            
            html += '</div></div>';
        } else {
            html += `
                <div class="classifiers-section">
                    <div class="info-box">
                        <h3>⚠️ No Classifiers Found</h3>
                        <p><strong>To see classifiers and create objects:</strong></p>
                        <ol>
                            <li>Build your model: <code>gradlew buildYourModel</code></li>
                            <li>Copy the generated .dll/.so file to the MDE4CPP_PluginAPI directory</li>
                            <li>Run MDE4CPP_PluginAPI.exe (on port 8080)</li>
                            <li>Refresh this page</li>
                        </ol>
                        <p><em>Currently using fallback mode - C++ API not connected.</em></p>
                    </div>
                </div>
            `;
        }

        structureTree.innerHTML = html;

        // Add click handlers for classifiers
        structureTree.querySelectorAll('.classifier-item').forEach(item => {
            item.addEventListener('click', () => {
                const className = item.dataset.classifier;
                this.selectClassifier(className);
            });
        });
    }

    async selectClassifier(className) {
        if (!this.currentPlugin) return;

        this.currentClassifier = className;

        // Update UI
        document.querySelectorAll('.classifier-item').forEach(item => {
            item.classList.toggle('active', item.dataset.classifier === className);
        });

        // Load classifier details
        await this.loadClassifierDetails(this.currentPlugin, className);
    }

    async loadClassifierDetails(pluginName, className) {
        const classifierSection = document.getElementById('classifier-details-section');
        const classifierTitle = document.getElementById('classifier-title');
        const classifierContent = document.getElementById('classifier-content');
        
        if (!classifierSection || !classifierTitle || !classifierContent) return;

        classifierSection.classList.remove('hidden');
        classifierTitle.textContent = `Classifier: ${className}`;
        classifierContent.innerHTML = '<div class="loading">Loading details...</div>';

        try {
            const details = await pluginAPI.getClassifierDetails(pluginName, className);
            this.renderClassifierDetails(details);
        } catch (error) {
            classifierContent.innerHTML = `<div class="error">Error loading details: ${error.message}</div>`;
            this.showError(error.message);
        }
    }

    renderClassifierDetails(details) {
        const classifierContent = document.getElementById('classifier-content');
        if (!classifierContent) return;

        let html = `
            <div class="classifier-info">
                <div class="info-row">
                    <strong>Name:</strong> ${details.name}
                </div>
                <div class="info-row">
                    <strong>Type:</strong> ${details.type}
                </div>
                ${details.abstract !== undefined ? `<div class="info-row"><strong>Abstract:</strong> ${details.abstract}</div>` : ''}
                ${details.interface !== undefined ? `<div class="info-row"><strong>Interface:</strong> ${details.interface}</div>` : ''}
            </div>
        `;

        if (details.attributes && details.attributes.length > 0) {
            html += '<div class="details-section"><h3>Attributes:</h3><ul class="feature-list">';
            details.attributes.forEach(attr => {
                const lower = attr.lower ?? attr.lowerBound;
                const upper = attr.upper ?? attr.upperBound;
                html += `
                    <li>
                        <strong>${attr.name}</strong>: ${attr.type || 'unknown'}
                        ${lower !== undefined ? ` [${lower}..${upper === -1 ? '*' : upper}]` : ''}
                        ${attr.required ? ' (required)' : ''}
                        ${attr.id ? ' (id)' : ''}
                    </li>
                `;
            });
            html += '</ul></div>';
        }

        if (details.references && details.references.length > 0) {
            html += '<div class="details-section"><h3>References:</h3><ul class="feature-list">';
            details.references.forEach(ref => {
                const lower = ref.lower ?? ref.lowerBound;
                const upper = ref.upper ?? ref.upperBound;
                html += `
                    <li>
                        <strong>${ref.name}</strong>: ${ref.type || 'unknown'}
                        ${ref.containment ? ' (containment)' : ''}
                        ${lower !== undefined ? ` [${lower}..${upper === -1 ? '*' : upper}]` : ''}
                    </li>
                `;
            });
            html += '</ul></div>';
        }

        if (details.type === 'EEnum' && details.literals && details.literals.length > 0) {
            html += '<div class="details-section"><h3>Literals:</h3><ul class="feature-list">';
            details.literals.forEach(lit => {
                html += `<li><strong>${lit.name}</strong>${lit.literal ? ` = "${lit.literal}"` : ''}${lit.value !== undefined ? ` (${lit.value})` : ''}</li>`;
            });
            html += '</ul></div>';
        }

        if (details.operations && details.operations.length > 0) {
            html += '<div class="details-section"><h3>Operations:</h3><ul class="feature-list">';
            details.operations.forEach(op => {
                const params = op.parameters ? op.parameters.map(p => `${p.name}: ${p.type || 'unknown'}`).join(', ') : '';
                html += `
                    <li>
                        <strong>${op.name}</strong>(${params})
                        ${op.returnType ? `: ${op.returnType}` : ''}
                    </li>
                `;
            });
            html += '</ul></div>';
        }

        classifierContent.innerHTML = html;
    }

    showCreateForm() {
        if (!this.currentPlugin || !this.currentClassifier) {
            this.showError('Please select a plugin and classifier first');
            return;
        }

        const createSection = document.getElementById('create-object-section');
        const propertiesContainer = document.getElementById('properties-container');
        
        if (!createSection || !propertiesContainer) return;

        // Load classifier details to build form
        pluginAPI.getClassifierDetails(this.currentPlugin, this.currentClassifier)
            .then(details => {
                let html = '';
                
                if (details.attributes && details.attributes.length > 0) {
                    details.attributes.forEach(attr => {
                        const isRequired = !!(attr.required || (attr.lower !== undefined && attr.lower > 0) || (attr.lowerBound !== undefined && attr.lowerBound > 0));
                        const isBool = (attr.type === 'EBoolean' || attr.type === 'EBooleanObject' || attr.type === 'bool' || attr.type === 'boolean');
                        const inputType = isBool ? 'checkbox' : 'text';
                        html += `
                            <div class="form-group">
                                <label for="prop-${attr.name}">${attr.name} (${attr.type || 'unknown'}):</label>
                                <input type="${inputType}" id="prop-${attr.name}" name="${attr.name}"
                                       ${isRequired ? 'required' : ''}>
                            </div>
                        `;
                    });
                }

                propertiesContainer.innerHTML = html;
                createSection.classList.remove('hidden');
            })
            .catch(error => {
                this.showError(`Failed to load classifier details: ${error.message}`);
            });
    }

    hideCreateForm() {
        const createSection = document.getElementById('create-object-section');
        if (createSection) {
            createSection.classList.add('hidden');
        }
    }

    async handleCreateObject(e) {
        e.preventDefault();
        
        if (!this.currentPlugin || !this.currentClassifier) {
            this.showError('Please select a plugin and classifier first');
            return;
        }

        const formData = new FormData(e.target);
        const instanceName = formData.get('instanceName');
        const properties = {};

        // Collect property values
        formData.forEach((value, key) => {
            if (key !== 'instanceName' && value) {
                // Handle checkboxes (FormData stores "on" when checked)
                if (value === 'on') {
                    properties[key] = true;
                } else {
                    properties[key] = value;
                }
            }
        });

        try {
            const object = await pluginAPI.createFromClassifier(
                this.currentPlugin,
                this.currentClassifier,
                instanceName,
                properties
            );

            this.hideCreateForm();
            this.loadObjects(); // Refresh objects list
            this.showSuccess(`Object ${instanceName} created successfully!`);
        } catch (error) {
            this.showError(`Failed to create object: ${error.message}`);
        }
    }

    async loadObjects() {
        const objectsList = document.getElementById('objects-list');
        if (!objectsList) return;

        try {
            this.objects = await pluginAPI.listObjects();
            this.renderObjectsList();
        } catch (error) {
            objectsList.innerHTML = `<div class="error">Error loading objects: ${error.message}</div>`;
        }
    }

    renderObjectsList() {
        const objectsList = document.getElementById('objects-list');
        if (!objectsList) return;

        if (this.objects.length === 0) {
            objectsList.innerHTML = '<div class="empty-state">No objects created yet</div>';
            return;
        }

        objectsList.innerHTML = this.objects.map(obj => {
            const objId = obj.id || obj.name || 'unknown';
            const className = obj.className || obj.type || 'unknown';
            return `
                <div class="object-item" data-object-id="${objId}">
                    <div class="object-header">
                        <span class="object-icon">📦</span>
                        <span class="object-name">${objId}</span>
                    </div>
                    <div class="object-meta">
                        <span class="object-class">${className}</span>
                    </div>
                    <div class="object-actions">
                        <button class="btn btn-small inspect-btn" data-object-id="${objId}">Inspect</button>
                        <button class="btn btn-small delete-btn" data-object-id="${objId}">Delete</button>
                    </div>
                </div>
            `;
        }).join('');

        // Add click handlers
        objectsList.querySelectorAll('.inspect-btn').forEach(btn => {
            btn.addEventListener('click', (e) => {
                e.stopPropagation();
                const objectId = btn.dataset.objectId;
                this.inspectObject(objectId);
            });
        });

        objectsList.querySelectorAll('.delete-btn').forEach(btn => {
            btn.addEventListener('click', (e) => {
                e.stopPropagation();
                const objectId = btn.dataset.objectId;
                this.deleteObject(objectId);
            });
        });
    }

    async inspectObject(objectId) {
        if (typeof ObjectInspector !== 'undefined') {
            const inspector = new ObjectInspector();
            await inspector.inspect(objectId);
        } else {
            this.showError('Object inspector not available');
        }
    }

    async deleteObject(objectId) {
        if (!confirm(`Are you sure you want to delete object ${objectId}?`)) {
            return;
        }

        try {
            await pluginAPI.deleteObject(objectId);
            this.loadObjects(); // Refresh list
            this.showSuccess(`Object ${objectId} deleted successfully`);
        } catch (error) {
            this.showError(`Failed to delete object: ${error.message}`);
        }
    }

    showError(message) {
        const errorModal = document.getElementById('error-modal');
        const errorMessage = document.getElementById('error-message');
        if (errorModal && errorMessage) {
            errorMessage.textContent = message;
            errorModal.classList.remove('hidden');
        } else {
            alert(`Error: ${message}`);
        }
    }

    showSuccess(message) {
        // Simple success notification
        alert(message);
    }
}

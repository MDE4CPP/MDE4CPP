/**
 * CreateInstanceDialog - Dialog for creating instances with attribute input
 */
class CreateInstanceDialog {
    constructor(app) {
        this.app = app;
        this.modal = document.getElementById('create-instance-modal');
        this.form = document.getElementById('create-instance-form');
        this.title = document.getElementById('create-instance-title');
        this.attributesContainer = document.getElementById('attributes-container');
        this.instanceNameInput = document.getElementById('instance-name-input');
        this.currentNode = null;
        this.currentType = null;
        
        this.setupEventListeners();
    }

    setupEventListeners() {
        // Close button
        const closeBtn = document.getElementById('close-create-modal');
        const cancelBtn = document.getElementById('cancel-create-btn');
        
        if (closeBtn) {
            closeBtn.addEventListener('click', () => this.hide());
        }
        if (cancelBtn) {
            cancelBtn.addEventListener('click', () => this.hide());
        }

        // Form submission
        if (this.form) {
            this.form.addEventListener('submit', (e) => {
                e.preventDefault();
                this.handleSubmit();
            });
        }

        // Close on Escape
        document.addEventListener('keydown', (e) => {
            if (e.key === 'Escape' && this.isVisible()) {
                this.hide();
            }
        });
    }

    /**
     * Show dialog for creating an instance
     */
    async show(node, type) {
        this.currentNode = node;
        this.currentType = type;

        if (!this.modal || !this.title) {
            console.error('CreateInstanceDialog: Modal elements not found');
            return;
        }

        console.log('CreateInstanceDialog: Showing dialog for', type.name, 'on node', node);

        // Set title
        this.title.textContent = `Create ${type.name}`;

        // Load classifier details to show attributes
        try {
            const details = await this.app.metamodelService.getClassifierDetails(
                node.plugin,
                type.name
            );

            // Clear previous content
            this.attributesContainer.innerHTML = '';

            // Add attribute fields
            if (details.attributes && details.attributes.length > 0) {
                const attrsSection = document.createElement('div');
                attrsSection.className = 'form-section';
                attrsSection.innerHTML = '<h3>Attributes</h3>';

                details.attributes.forEach(attr => {
                    const isRequired = !!(attr.required || 
                        (attr.lower !== undefined && attr.lower > 0) || 
                        (attr.lowerBound !== undefined && attr.lowerBound > 0));
                    
                    const field = this.createAttributeField(attr, isRequired);
                    attrsSection.appendChild(field);
                });

                this.attributesContainer.appendChild(attrsSection);
            } else {
                this.attributesContainer.innerHTML = '<p class="info-text">No attributes defined for this classifier.</p>';
            }

            // Show modal
            this.modal.classList.remove('hidden');
            this.instanceNameInput.focus();
        } catch (error) {
            console.error('Failed to load classifier details:', error);
            this.app.showError('Failed to load classifier details: ' + error.message);
        }
    }

    /**
     * Create attribute input field
     */
    createAttributeField(attr, isRequired) {
        const group = document.createElement('div');
        group.className = 'form-group';

        const label = document.createElement('label');
        label.htmlFor = `attr-${attr.name}`;
        label.textContent = `${attr.name} (${attr.type || 'unknown'})`;
        if (isRequired) {
            const req = document.createElement('span');
            req.className = 'required';
            req.textContent = ' *';
            label.appendChild(req);
        }

        const input = this.createInputForType(attr, isRequired);
        input.id = `attr-${attr.name}`;
        input.name = attr.name;

        group.appendChild(label);
        group.appendChild(input);

        return group;
    }

    /**
     * Create input element based on attribute type
     */
    createInputForType(attr, isRequired) {
        const type = attr.type || '';
        const input = document.createElement('input');

        // Set required
        if (isRequired) {
            input.required = true;
        }

        // Determine input type
        if (type === 'EBoolean' || type === 'EBooleanObject' || type === 'bool' || type === 'boolean') {
            input.type = 'checkbox';
        } else if (type === 'EInt' || type === 'EIntegerObject' || type === 'int' || type === 'Integer') {
            input.type = 'number';
            input.step = '1';
        } else if (type === 'ELong' || type === 'long' || type === 'Long') {
            input.type = 'number';
            input.step = '1';
        } else if (type === 'EFloat' || type === 'EDouble' || type === 'float' || type === 'double') {
            input.type = 'number';
            input.step = 'any';
        } else {
            input.type = 'text';
        }

        // Set placeholder
        input.placeholder = `Enter ${attr.name}...`;

        // Set default value if available
        if (attr.defaultValue !== undefined && attr.defaultValue !== null) {
            if (input.type === 'checkbox') {
                input.checked = attr.defaultValue === true || attr.defaultValue === 'true';
            } else {
                input.value = attr.defaultValue;
            }
        }

        return input;
    }

    /**
     * Handle form submission
     */
    async handleSubmit() {
        if (!this.currentNode || !this.currentType) return;

        const formData = new FormData(this.form);
        const instanceName = formData.get('instanceName');

        if (!instanceName || instanceName.trim() === '') {
            alert('Instance name is required');
            return;
        }

        // Collect attribute values
        const properties = {};
        const inputs = this.form.querySelectorAll('input[name]');
        inputs.forEach(input => {
            if (input.name === 'instanceName') return;
            
            let value = null;
            if (input.type === 'checkbox') {
                value = input.checked;
            } else if (input.type === 'number') {
                const numValue = parseFloat(input.value);
                if (!isNaN(numValue)) {
                    value = numValue;
                }
            } else if (input.value.trim() !== '') {
                value = input.value.trim();
            }

            // Only include non-empty values
            if (value !== null && value !== '') {
                properties[input.name] = value;
            }
        });

        // Capture node/type before hide() clears them
        const node = this.currentNode;
        const type = this.currentType;

        try {
            this.hide();

            if (node.type === 'classifier') {
                await this.app.onCreateInstance(
                    null,
                    type.name,
                    instanceName.trim(),
                    null,
                    properties
                );
            } else if (node.type === 'instance') {
                const referenceID = type.referenceID;
                if (referenceID === undefined || referenceID === null) {
                    const refInfo = await this.app.metamodelService.getContainmentReference(
                        node.plugin,
                        node.instanceType,
                        type.name
                    );
                    if (refInfo) {
                        await this.app.onCreateInstance(
                            node.instance,
                            type.name,
                            instanceName.trim(),
                            refInfo.referenceID,
                            properties
                        );
                    } else {
                        throw new Error(`Could not determine reference ID for ${type.name}`);
                    }
                } else {
                    await this.app.onCreateInstance(
                        node.instance,
                        type.name,
                        instanceName.trim(),
                        referenceID,
                        properties
                    );
                }
            }

            // Success - no need to show anything
        } catch (error) {
            console.error('Failed to create instance:', error);
            this.app.showError('Failed to create instance: ' + error.message);
        }
    }

    /**
     * Hide dialog
     */
    hide() {
        if (this.modal) {
            this.modal.classList.add('hidden');
        }
        if (this.form) {
            this.form.reset();
        }
        this.currentNode = null;
        this.currentType = null;
    }

    /**
     * Check if dialog is visible
     */
    isVisible() {
        return this.modal && !this.modal.classList.contains('hidden');
    }
}

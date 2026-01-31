/**
 * PropertiesPanel - Tabbed properties panel for selected node
 */
class PropertiesPanel {
    constructor(container, app) {
        this.container = container;
        this.app = app;
        this.currentNode = null;
        this.currentTab = 'general';
        this.invokeModal = null;
        this.invokeForm = null;
        this.invokeParamsContainer = null;
        this.pendingInvoke = null; // { operation, instanceId }
        this.setupTabs();
        this.setupInvokeModal();
    }

    /**
     * Flatten instance tree to list of { name, type } for pickers
     */
    getAllInstances() {
        const list = [];
        const tree = this.app.unifiedTree && this.app.unifiedTree.treeData && this.app.unifiedTree.treeData.instances;
        if (!tree || !tree.roots || !Array.isArray(tree.roots)) return list;
        const flatten = (nodes) => {
            for (const n of nodes) {
                const name = n.name || (typeof n === 'string' ? n : null);
                const type = n.type || '';
                if (name) list.push({ name, type });
                if (n.children && Array.isArray(n.children)) flatten(n.children);
            }
        };
        flatten(tree.roots);
        return list;
    }

    setupInvokeModal() {
        this.invokeModal = document.getElementById('invoke-operation-modal');
        this.invokeForm = document.getElementById('invoke-operation-form');
        this.invokeParamsContainer = document.getElementById('invoke-params-container');
        const titleEl = document.getElementById('invoke-operation-title');
        const closeBtn = document.getElementById('close-invoke-modal');
        const cancelBtn = document.getElementById('cancel-invoke-btn');

        if (closeBtn) closeBtn.addEventListener('click', () => this.hideInvokeModal());
        if (cancelBtn) cancelBtn.addEventListener('click', () => this.hideInvokeModal());
        if (this.invokeForm) {
            this.invokeForm.addEventListener('submit', (e) => {
                e.preventDefault();
                this.handleInvokeSubmit();
            });
        }
        document.addEventListener('keydown', (e) => {
            if (e.key === 'Escape' && this.invokeModal && !this.invokeModal.classList.contains('hidden')) {
                this.hideInvokeModal();
            }
        });
    }

    showInvokeModal(operation, instanceId) {
        this.pendingInvoke = { operation, instanceId };
        const titleEl = document.getElementById('invoke-operation-title');
        if (titleEl) titleEl.textContent = `Invoke: ${operation.name || operation.operationName}`;
        if (!this.invokeParamsContainer) return;
        this.invokeParamsContainer.innerHTML = '';
        const params = operation.parameters || [];
        const allInstances = this.getAllInstances();
        for (const p of params) {
            const pType = (p.type || '').trim();
            const isObjectParam = pType && !/^(String|EString|Integer|EInt|int|Long|ELong|Boolean|EBoolean|Double|EFloat|Float|EDouble)$/i.test(pType);
            const row = document.createElement('div');
            row.className = 'property-field';
            const label = document.createElement('label');
            label.textContent = `${p.name}: ${pType}`;
            row.appendChild(label);
            if (isObjectParam) {
                const select = document.createElement('select');
                select.dataset.paramType = 'object';
                select.dataset.paramName = p.name;
                const empty = document.createElement('option');
                empty.value = '';
                empty.textContent = '(select instance)';
                select.appendChild(empty);
                const ofType = allInstances.filter(i => i.type === pType);
                for (const inst of ofType) {
                    const opt = document.createElement('option');
                    opt.value = inst.name;
                    opt.textContent = `"${inst.name}" (${inst.type})`;
                    select.appendChild(opt);
                }
                row.appendChild(select);
            } else {
                const input = document.createElement('input');
                input.dataset.paramName = p.name;
                input.dataset.paramType = pType;
                if (/int|long|Integer|EInt|Long|ELong/i.test(pType)) {
                    input.type = 'number';
                    input.value = '0';
                } else if (/bool|Boolean|EBoolean/i.test(pType)) {
                    input.type = 'checkbox';
                    input.checked = false;
                } else {
                    input.type = 'text';
                    input.value = '';
                }
                row.appendChild(input);
            }
            this.invokeParamsContainer.appendChild(row);
        }
        if (this.invokeModal) {
            this.invokeModal.classList.remove('hidden');
        }
    }

    hideInvokeModal() {
        this.pendingInvoke = null;
        if (this.invokeModal) this.invokeModal.classList.add('hidden');
    }

    async handleInvokeSubmit() {
        if (!this.pendingInvoke || !this.invokeParamsContainer) return;
        const { operation, instanceId } = this.pendingInvoke;
        const opName = operation.name || operation.operationName;
        const params = operation.parameters || [];
        const args = [];
        for (const p of params) {
            const pType = (p.type || '').trim();
            const isObjectParam = pType && !/^(String|EString|Integer|EInt|int|Long|ELong|Boolean|EBoolean|Double|EFloat|Float|EDouble)$/i.test(pType);
            if (isObjectParam) {
                const select = this.invokeParamsContainer.querySelector(`select[data-param-name="${p.name}"]`);
                args.push(select ? select.value : '');
            } else {
                const input = this.invokeParamsContainer.querySelector(`input[data-param-name="${p.name}"]`);
                if (!input) { args.push(null); continue; }
                if (input.type === 'number') args.push(parseInt(input.value, 10) || 0);
                else if (input.type === 'checkbox') args.push(input.checked);
                else args.push(input.value);
            }
        }
        this.hideInvokeModal();
        try {
            const result = await this.app.modelService.invokeOperation(instanceId, opName, args);
            const msg = result && (result.result !== undefined) ? String(result.result) : 'Done';
            alert(`Operation ${opName}: ${msg}`);
        } catch (error) {
            console.error('Failed to execute operation:', error);
            alert(`Failed to execute operation: ${error.message}`);
        }
    }

    setupTabs() {
        // Create tab structure
        const tabsContainer = document.createElement('div');
        tabsContainer.className = 'properties-tabs';

        const tabs = ['general', 'attributes', 'references', 'operations'];
        const tabLabels = ['General', 'Attributes', 'References', 'Operations'];

        tabs.forEach((tab, index) => {
            const tabButton = document.createElement('button');
            tabButton.className = 'properties-tab';
            tabButton.textContent = tabLabels[index];
            tabButton.dataset.tab = tab;
            if (index === 0) {
                tabButton.classList.add('properties-tab-active');
            }
            tabButton.addEventListener('click', () => this.switchTab(tab));
            tabsContainer.appendChild(tabButton);
        });

        this.container.insertBefore(tabsContainer, this.container.firstChild);

        // Create tab content containers
        this.tabContents = {};
        tabs.forEach(tab => {
            const content = document.createElement('div');
            content.className = 'properties-tab-content';
            content.id = `properties-tab-${tab}`;
            if (tab === 'general') {
                content.classList.add('properties-tab-content-active');
            }
            this.container.appendChild(content);
            this.tabContents[tab] = content;
        });
    }

    /**
     * Switch tab
     */
    switchTab(tabName) {
        // Update tab buttons
        const tabs = this.container.querySelectorAll('.properties-tab');
        tabs.forEach(tab => {
            if (tab.dataset.tab === tabName) {
                tab.classList.add('properties-tab-active');
            } else {
                tab.classList.remove('properties-tab-active');
            }
        });

        // Update tab contents
        Object.keys(this.tabContents).forEach(tab => {
            if (tab === tabName) {
                this.tabContents[tab].classList.add('properties-tab-content-active');
            } else {
                this.tabContents[tab].classList.remove('properties-tab-content-active');
            }
        });

        this.currentTab = tabName;
        this.renderCurrentTab();
    }

    /**
     * Show node properties
     */
    async showNode(node) {
        this.currentNode = node;
        this.renderCurrentTab();
    }

    /**
     * Render current tab
     */
    async renderCurrentTab() {
        if (!this.currentNode) {
            Object.values(this.tabContents).forEach(content => {
                content.innerHTML = '<div class="empty-state">Select an element to view properties</div>';
            });
            return;
        }

        switch (this.currentTab) {
            case 'general':
                await this.renderGeneralTab();
                break;
            case 'attributes':
                await this.renderAttributesTab();
                break;
            case 'references':
                await this.renderReferencesTab();
                break;
            case 'operations':
                await this.renderOperationsTab();
                break;
        }
    }

    /**
     * Render General tab
     */
    async renderGeneralTab() {
        const content = this.tabContents.general;
        content.innerHTML = '';

        const node = this.currentNode;

        // Name field (editable for instances)
        const nameField = this.createField('Name', node.instance || node.classifier || node.reference || 'N/A', !node.instance);
        content.appendChild(nameField);

        // Type field
        const typeField = this.createField('Type', node.instanceType || node.classifier || node.childType || 'N/A', true);
        content.appendChild(typeField);

        // Plugin field
        const pluginField = this.createField('Plugin', node.plugin || 'N/A', true);
        content.appendChild(pluginField);

        // ID field (for instances)
        if (node.instance) {
            const idField = this.createField('ID', node.instance, true);
            content.appendChild(idField);
        }

        // Create Instance button for classifiers
        if (node.type === 'classifier') {
            const createBtn = document.createElement('button');
            createBtn.className = 'btn btn-primary create-instance-btn';
            createBtn.textContent = '+ Create Instance';
            createBtn.addEventListener('click', () => this.onCreateInstanceClick());
            content.appendChild(createBtn);
        }

        // Add Child button for instances (shows containment options)
        if (node.type === 'instance') {
            const validTypes = await this.app.metamodelService.getValidChildTypes(node.plugin, node.instanceType);
            if (validTypes && validTypes.length > 0) {
                const addChildSection = document.createElement('div');
                addChildSection.className = 'add-child-section';
                
                const label = document.createElement('div');
                label.className = 'add-child-label';
                label.textContent = 'Add Child:';
                addChildSection.appendChild(label);

                const btnContainer = document.createElement('div');
                btnContainer.className = 'add-child-buttons';
                
                for (const type of validTypes) {
                    const btn = document.createElement('button');
                    btn.className = 'btn btn-secondary add-child-btn';
                    btn.textContent = `+ ${type.name}`;
                    btn.addEventListener('click', () => this.onAddChildClick(type));
                    btnContainer.appendChild(btn);
                }
                addChildSection.appendChild(btnContainer);
                content.appendChild(addChildSection);
            }
        }
    }

    /**
     * Handle Create Instance click (for classifiers)
     */
    onCreateInstanceClick() {
        if (!this.currentNode || this.currentNode.type !== 'classifier') return;
        
        if (this.app.createInstanceDialog) {
            this.app.createInstanceDialog.show(this.currentNode, { name: this.currentNode.classifier });
        }
    }

    /**
     * Handle Add Child click (for instances)
     */
    async onAddChildClick(type) {
        if (!this.currentNode || this.currentNode.type !== 'instance') return;
        
        if (this.app.createInstanceDialog) {
            await this.app.createInstanceDialog.show(this.currentNode, type);
        }
    }

    /**
     * Render Attributes tab
     */
    async renderAttributesTab() {
        const content = this.tabContents.attributes;
        content.innerHTML = '<div class="loading">Loading attributes...</div>';

        try {
            let attributes = [];

            if (this.currentNode.type === 'instance') {
                // Get attributes from instance
                attributes = await this.app.modelService.getObjectAttributes(this.currentNode.instance);
            } else if (this.currentNode.type === 'classifier') {
                // Get attributes from classifier definition
                const details = await this.app.metamodelService.getClassifierDetails(
                    this.currentNode.plugin,
                    this.currentNode.classifier
                );
                attributes = details.attributes || [];
            } else {
                content.innerHTML = '<div class="empty-state">No attributes available</div>';
                return;
            }

            if (attributes.length === 0) {
                content.innerHTML = '<div class="empty-state">No attributes</div>';
                return;
            }

            content.innerHTML = '';

            for (const attr of attributes) {
                const field = await this.createAttributeField(attr);
                content.appendChild(field);
            }
        } catch (error) {
            console.error('Failed to render attributes:', error);
            content.innerHTML = `<div class="empty-state">Error loading attributes: ${error.message}</div>`;
        }
    }

    /**
     * Render References tab
     */
    async renderReferencesTab() {
        const content = this.tabContents.references;
        content.innerHTML = '<div class="loading">Loading references...</div>';

        try {
            let references = [];

            if (this.currentNode.type === 'instance') {
                const features = await this.app.modelService.getObjectFeatures(this.currentNode.instance);
                const details = await this.app.metamodelService.getClassifierDetails(
                    this.currentNode.plugin,
                    this.currentNode.instanceType
                );
                const refDefs = (details.references || []).filter(r => !r.containment);
                for (const ref of refDefs) {
                    const feat = features.find(f => f.name === ref.name);
                    const upper = ref.upper !== undefined ? ref.upper : (ref.upperBound !== undefined ? ref.upperBound : 1);
                    references.push({
                        ...ref,
                        value: feat ? feat.value : undefined,
                        upperBound: upper
                    });
                }
            } else if (this.currentNode.type === 'classifier') {
                const details = await this.app.metamodelService.getClassifierDetails(
                    this.currentNode.plugin,
                    this.currentNode.classifier
                );
                references = (details.references || []).filter(r => !r.containment).map(r => ({ ...r, value: undefined }));
            } else {
                content.innerHTML = '<div class="empty-state">No references available</div>';
                return;
            }

            if (references.length === 0) {
                content.innerHTML = '<div class="empty-state">No references</div>';
                return;
            }

            content.innerHTML = '';

            for (const ref of references) {
                const field = await this.createReferenceField(ref);
                content.appendChild(field);
            }
        } catch (error) {
            console.error('Failed to render references:', error);
            content.innerHTML = `<div class="empty-state">Error loading references: ${error.message}</div>`;
        }
    }

    /**
     * Render Operations tab
     */
    async renderOperationsTab() {
        const content = this.tabContents.operations;
        content.innerHTML = '<div class="loading">Loading operations...</div>';

        try {
            let operations = [];

            if (this.currentNode.type === 'instance') {
                // Get operations from instance
                operations = await this.app.modelService.getObjectOperations(this.currentNode.instance);
            } else if (this.currentNode.type === 'classifier') {
                // Get operations from classifier definition
                const details = await this.app.metamodelService.getClassifierDetails(
                    this.currentNode.plugin,
                    this.currentNode.classifier
                );
                operations = details.operations || [];
            } else {
                content.innerHTML = '<div class="empty-state">No operations available</div>';
                return;
            }

            if (operations.length === 0) {
                content.innerHTML = '<div class="empty-state">No operations</div>';
                return;
            }

            content.innerHTML = '';

            for (const op of operations) {
                const item = this.createOperationItem(op);
                content.appendChild(item);
            }
        } catch (error) {
            console.error('Failed to render operations:', error);
            content.innerHTML = `<div class="empty-state">Error loading operations: ${error.message}</div>`;
        }
    }

    /**
     * Create field element
     */
    createField(label, value, readOnly = false) {
        const field = document.createElement('div');
        field.className = 'property-field';

        const labelEl = document.createElement('label');
        labelEl.textContent = label;

        const input = document.createElement(readOnly ? 'div' : 'input');
        if (readOnly) {
            input.className = 'property-field-value';
            input.textContent = value;
        } else {
            input.type = 'text';
            input.value = value;
            input.addEventListener('change', (e) => {
                this.onAttributeChange(this.currentNode, label.toLowerCase(), e.target.value);
            });
        }

        field.appendChild(labelEl);
        field.appendChild(input);

        return field;
    }

    /**
     * Create attribute field
     */
    async createAttributeField(attr) {
        const field = document.createElement('div');
        field.className = 'property-field';

        const label = document.createElement('label');
        label.textContent = attr.name || attr.attributeName;
        if (attr.required) {
            const required = document.createElement('span');
            required.className = 'required';
            required.textContent = ' *';
            label.appendChild(required);
        }

        const input = this.createInputForType(attr.type || attr.attributeType, attr.value, (value) => {
            if (this.currentNode.type === 'instance') {
                this.onAttributeChange(this.currentNode, attr.name || attr.attributeName, value);
            }
        });

        field.appendChild(label);
        field.appendChild(input);

        if (attr.type) {
            const help = document.createElement('div');
            help.className = 'help-text';
            help.textContent = `Type: ${attr.type}`;
            field.appendChild(help);
        }

        return field;
    }

    /**
     * Create input for attribute type
     */
    createInputForType(type, value, onChange) {
        const typeLower = (type || '').toLowerCase();

        if (typeLower.includes('string') || typeLower === 'estring') {
            const input = document.createElement('input');
            input.type = 'text';
            input.value = value || '';
            input.addEventListener('change', (e) => onChange(e.target.value));
            return input;
        } else if (typeLower.includes('int') || typeLower.includes('long') || typeLower === 'eint' || typeLower === 'elong') {
            const input = document.createElement('input');
            input.type = 'number';
            input.value = value || 0;
            input.addEventListener('change', (e) => onChange(parseInt(e.target.value) || 0));
            return input;
        } else if (typeLower.includes('double') || typeLower.includes('float') || typeLower === 'edouble' || typeLower === 'efloat') {
            const input = document.createElement('input');
            input.type = 'number';
            input.step = '0.01';
            input.value = value || 0;
            input.addEventListener('change', (e) => onChange(parseFloat(e.target.value) || 0));
            return input;
        } else if (typeLower.includes('bool') || typeLower === 'eboolean') {
            const input = document.createElement('input');
            input.type = 'checkbox';
            input.checked = value === true || value === 'true';
            input.addEventListener('change', (e) => onChange(e.target.checked));
            return input;
        } else {
            // Default to text input
            const input = document.createElement('input');
            input.type = 'text';
            input.value = value || '';
            input.addEventListener('change', (e) => onChange(e.target.value));
            return input;
        }
    }

    /**
     * Create reference field (with instance picker when on instance and ref has type)
     */
    async createReferenceField(ref) {
        const field = document.createElement('div');
        field.className = 'property-field';

        const label = document.createElement('label');
        label.textContent = ref.name || ref.referenceName;
        const refType = ref.type || '';
        const upper = ref.upperBound === undefined ? (ref.upper === -1 ? -1 : (ref.upper || 1)) : ref.upperBound;
        const isMulti = upper === -1 || upper > 1;

        field.appendChild(label);

        if (this.currentNode.type === 'instance' && refType && this.app.currentPlugin) {
            const allInstances = this.getAllInstances().filter(i => i.type === refType);
            if (isMulti) {
                const select = document.createElement('select');
                select.multiple = true;
                select.dataset.refName = ref.name;
                select.size = Math.min(6, Math.max(2, allInstances.length + 1));
                const currentValues = Array.isArray(ref.value) ? ref.value : (ref.value != null ? [ref.value] : []);
                for (const inst of allInstances) {
                    const opt = document.createElement('option');
                    opt.value = inst.name;
                    opt.textContent = `"${inst.name}" (${inst.type})`;
                    if (currentValues.includes(inst.name)) opt.selected = true;
                    select.appendChild(opt);
                }
                select.addEventListener('change', () => this.onReferenceChange(ref.name, Array.from(select.selectedOptions).map(o => o.value), true));
                field.appendChild(select);
            } else {
                const select = document.createElement('select');
                select.dataset.refName = ref.name;
                const empty = document.createElement('option');
                empty.value = '';
                empty.textContent = '(none)';
                select.appendChild(empty);
                for (const inst of allInstances) {
                    const opt = document.createElement('option');
                    opt.value = inst.name;
                    opt.textContent = `"${inst.name}" (${inst.type})`;
                    const current = Array.isArray(ref.value) ? ref.value[0] : ref.value;
                    if (current === inst.name) opt.selected = true;
                    select.appendChild(opt);
                }
                select.addEventListener('change', () => this.onReferenceChange(ref.name, select.value || null, false));
                field.appendChild(select);
            }
            const help = document.createElement('div');
            help.className = 'help-text';
            help.textContent = refType + (isMulti ? ' [0..*]' : ' [0..1]');
            field.appendChild(help);
        } else {
            const display = document.createElement('div');
            display.className = 'property-field-value';
            display.textContent = ref.value != null ? (Array.isArray(ref.value) ? ref.value.join(', ') : String(ref.value)) : '(not set)';
            field.appendChild(display);
        }

        return field;
    }

    /**
     * Handle reference change (set reference value via backend)
     */
    async onReferenceChange(referenceName, value, isMulti) {
        if (this.currentNode.type !== 'instance' || !this.app.currentPlugin) return;
        try {
            await this.app.modelService.setReference(
                this.app.currentPlugin,
                this.currentNode.instance,
                referenceName,
                isMulti ? value : (value || null)
            );
            if (this.app.unifiedTree) await this.app.unifiedTree.refresh();
        } catch (error) {
            console.error('Failed to set reference:', error);
            alert(`Failed to set reference: ${error.message}`);
        }
    }

    /**
     * Create operation item
     */
    createOperationItem(op) {
        const item = document.createElement('div');
        item.className = 'operation-item';

        const name = document.createElement('div');
        name.className = 'operation-name';
        name.textContent = op.name || op.operationName;

        const params = document.createElement('div');
        params.className = 'operation-params';
        if (op.parameters && op.parameters.length > 0) {
            params.textContent = `Parameters: ${op.parameters.map(p => `${p.name}: ${p.type}`).join(', ')}`;
        } else {
            params.textContent = 'No parameters';
        }

        const button = document.createElement('button');
        button.className = 'operation-btn';
        button.textContent = 'Execute';
        button.addEventListener('click', () => {
            this.onOperationClick(op);
        });

        item.appendChild(name);
        item.appendChild(params);
        item.appendChild(button);

        return item;
    }

    /**
     * Handle attribute change
     */
    async onAttributeChange(node, attributeName, value) {
        if (node.type === 'instance' && this.app.onUpdateAttribute) {
            try {
                await this.app.onUpdateAttribute(node, attributeName, value);
            } catch (error) {
                console.error('Failed to update attribute:', error);
                alert(`Failed to update attribute: ${error.message}`);
            }
        }
    }

    /**
     * Handle operation click
     */
    async onOperationClick(operation) {
        if (this.currentNode.type !== 'instance') return;
        const opName = operation.name || operation.operationName;
        const params = operation.parameters || [];
        if (params.length > 0) {
            this.showInvokeModal(operation, this.currentNode.instance);
            return;
        }
        try {
            const result = await this.app.modelService.invokeOperation(
                this.currentNode.instance,
                opName,
                []
            );
            const msg = result && (result.result !== undefined) ? String(result.result) : 'Done';
            alert(`Operation ${opName}: ${msg}`);
        } catch (error) {
            console.error('Failed to execute operation:', error);
            alert(`Failed to execute operation: ${error.message}`);
        }
    }
}

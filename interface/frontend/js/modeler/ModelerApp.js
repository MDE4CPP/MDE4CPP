/**
 * ModelerApp - Main application class coordinating all components
 */
class ModelerApp {
    constructor() {
        this.currentPlugin = null;
        this.selectedNode = null;

        // Services
        this.metamodelService = new MetamodelService();
        this.modelService = new ModelService();
        this.validationService = new ValidationService();

        // Components
        this.unifiedTree = null;
        this.creationPalette = null;
        this.propertiesPanel = null;
        this.contextMenu = null;
        this.mainEditor = null; // Now renders in bottom children panel
        this.diagramCanvas = null; // New: center diagram
        this.createInstanceDialog = null;
        this.commandManager = new CommandManager();

        // Setup command manager listener
        this.commandManager.addListener((state) => {
            this.updateUndoRedoButtons(state);
        });
    }

    /**
     * Initialize application
     */
    async init() {
        // Initialize components
        const treeContainer = document.getElementById('unified-tree');
        const paletteContainer = document.getElementById('creation-palette');
        const propertiesContainer = document.getElementById('properties-content');
        const contextMenuContainer = document.getElementById('context-menu');
        const editorContainer = document.getElementById('children-content'); // Bottom panel for children
        const diagramContainer = document.getElementById('diagram-canvas'); // Center diagram

        this.unifiedTree = new UnifiedTree(treeContainer, this);
        this.creationPalette = new CreationPalette(paletteContainer, this);
        this.propertiesPanel = new PropertiesPanel(propertiesContainer, this);
        this.contextMenu = new ContextMenu(contextMenuContainer, this);
        this.mainEditor = new MainEditor(editorContainer, this); // Children list in bottom
        this.diagramCanvas = new DiagramCanvas(diagramContainer, this); // Diagram in center
        this.createInstanceDialog = new CreateInstanceDialog(this);

        // Setup event listeners
        this.setupEventListeners();

        // Load plugins
        await this.loadPlugins();
    }

    /**
     * Setup event listeners
     */
    setupEventListeners() {
        // Plugin selector
        const pluginSelector = document.getElementById('plugin-selector');
        if (pluginSelector) {
            pluginSelector.addEventListener('change', (e) => {
                this.selectPlugin(e.target.value);
            });
        }

        // Undo/Redo buttons
        const undoBtn = document.getElementById('undo-btn');
        const redoBtn = document.getElementById('redo-btn');
        if (undoBtn) {
            undoBtn.addEventListener('click', () => this.undo());
        }
        if (redoBtn) {
            redoBtn.addEventListener('click', () => this.redo());
        }

        // Refresh button
        const refreshBtn = document.getElementById('refresh-btn');
        if (refreshBtn) {
            refreshBtn.addEventListener('click', () => this.refresh());
        }

        // Keyboard shortcuts
        document.addEventListener('keydown', (e) => {
            this.handleKeyboard(e);
        });
    }

    /**
     * Load plugins
     */
    async loadPlugins() {
        try {
            const plugins = await pluginAPI.getPlugins();
            const selector = document.getElementById('plugin-selector');
            if (selector) {
                selector.innerHTML = '<option value="">Select a plugin...</option>';
                plugins.forEach(plugin => {
                    const option = document.createElement('option');
                    option.value = plugin.name || plugin;
                    option.textContent = plugin.name || plugin;
                    selector.appendChild(option);
                });
            }
        } catch (error) {
            console.error('Failed to load plugins:', error);
            this.showError('Failed to load plugins: ' + error.message);
        }
    }

    /**
     * Select plugin
     */
    async selectPlugin(pluginName) {
        if (!pluginName) {
            this.currentPlugin = null;
            return;
        }

        this.currentPlugin = pluginName;
        this.selectedNode = null;

        try {
            await this.unifiedTree.loadPlugin(pluginName);
        } catch (error) {
            console.error('Failed to load plugin:', error);
            this.showError('Failed to load plugin: ' + error.message);
        }
    }

    /**
     * Handle node selection
     */
    async onNodeSelect(node) {
        this.selectedNode = node;

        // Update properties panel
        await this.propertiesPanel.showNode(node);

        // Update diagram canvas (center)
        await this.diagramCanvas.showNode(node);

        // Update main editor (bottom children list)
        await this.mainEditor.showNode(node);

        // Update creation palette
        await this.creationPalette.updateForNode(node);

        // Show palette if node is a container and has valid creation options
        if (node && (node.type === 'classifier' || node.type === 'containment_ref' || node.type === 'instance')) {
            // Check if palette has items to show
            const paletteItems = document.querySelector('#creation-palette .palette-items');
            if (paletteItems && paletteItems.children.length > 0) {
                // Position palette near selected node
                const selectedElement = document.querySelector('.tree-node-selected');
                if (selectedElement) {
                    const rect = selectedElement.getBoundingClientRect();
                    this.creationPalette.show(rect.right + 10, rect.top);
                }
            } else {
                // No valid creation options, hide palette
                this.creationPalette.hide();
            }
        } else {
            this.creationPalette.hide();
        }
    }

    /**
     * Handle node right-click
     */
    async onNodeRightClick(node, event) {
        await this.contextMenu.show(event.clientX, event.clientY, node);
    }

    /**
     * Handle create instance
     */
    async onCreateInstance(parentName, className, instanceName, referenceID, properties = {}) {
        try {
            const command = new CreateInstanceCommand(
                this,
                this.currentPlugin,
                parentName,
                className,
                instanceName,
                referenceID,
                properties
            );
            await this.commandManager.execute(command);
        } catch (error) {
            console.error('Failed to create instance:', error);
            this.showError('Failed to create instance: ' + error.message);
            throw error;
        }
    }

    /**
     * Handle delete instance
     */
    async onDeleteInstance(node) {
        try {
            const command = new DeleteInstanceCommand(
                this,
                this.currentPlugin,
                node.instance,
                node.data
            );
            await this.commandManager.execute(command);
            this.selectedNode = null;
        } catch (error) {
            console.error('Failed to delete instance:', error);
            this.showError('Failed to delete instance: ' + error.message);
            throw error;
        }
    }

    /**
     * Handle update attribute
     */
    async onUpdateAttribute(node, attributeName, value) {
        try {
            // Get old value for undo
            let oldValue = null;
            try {
                const details = await this.modelService.getObjectDetails(node.instance);
                oldValue = details.features && details.features[attributeName];
            } catch (e) {
                console.warn('Could not get old value for undo:', e);
            }

            const command = new UpdateAttributeCommand(
                this,
                this.currentPlugin,
                node.instance,
                attributeName,
                oldValue,
                value
            );
            await this.commandManager.execute(command);
        } catch (error) {
            console.error('Failed to update attribute:', error);
            this.showError('Failed to update attribute: ' + error.message);
            throw error;
        }
    }

    /**
     * Undo last command
     */
    async undo() {
        try {
            await this.commandManager.undo();
        } catch (error) {
            console.error('Undo failed:', error);
            this.showError('Undo failed: ' + error.message);
        }
    }

    /**
     * Redo last undone command
     */
    async redo() {
        try {
            await this.commandManager.redo();
        } catch (error) {
            console.error('Redo failed:', error);
            this.showError('Redo failed: ' + error.message);
        }
    }

    /**
     * Refresh current view
     */
    async refresh() {
        if (this.currentPlugin) {
            await this.unifiedTree.refresh();
        } else {
            await this.loadPlugins();
        }
    }

    /**
     * Update undo/redo buttons
     */
    updateUndoRedoButtons(state) {
        const undoBtn = document.getElementById('undo-btn');
        const redoBtn = document.getElementById('redo-btn');

        if (undoBtn) {
            undoBtn.disabled = !state.canUndo;
            undoBtn.title = state.canUndo ? `Undo: ${state.undoDescription}` : 'Undo (Ctrl+Z)';
        }

        if (redoBtn) {
            redoBtn.disabled = !state.canRedo;
            redoBtn.title = state.canRedo ? `Redo: ${state.redoDescription}` : 'Redo (Ctrl+Y)';
        }
    }

    /**
     * Handle keyboard shortcuts
     */
    handleKeyboard(event) {
        // Ctrl+Z: Undo
        if ((event.ctrlKey || event.metaKey) && event.key === 'z' && !event.shiftKey) {
            event.preventDefault();
            if (this.commandManager.canUndo()) {
                this.undo();
            }
            return;
        }

        // Ctrl+Y or Ctrl+Shift+Z: Redo
        if (((event.ctrlKey || event.metaKey) && event.key === 'y') ||
            ((event.ctrlKey || event.metaKey) && event.key === 'z' && event.shiftKey)) {
            event.preventDefault();
            if (this.commandManager.canRedo()) {
                this.redo();
            }
            return;
        }

        // Delete: Delete selected instance
        if (event.key === 'Delete' && this.selectedNode && this.selectedNode.type === 'instance') {
            event.preventDefault();
            if (confirm(`Delete "${this.selectedNode.instance}"?`)) {
                this.onDeleteInstance(this.selectedNode);
            }
            return;
        }

        // F2: Rename selected instance
        if (event.key === 'F2' && this.selectedNode && this.selectedNode.type === 'instance') {
            event.preventDefault();
            const newName = prompt('Enter new name:', this.selectedNode.instance);
            if (newName && newName.trim() !== '' && newName !== this.selectedNode.instance) {
                // Future: implement rename
                alert('Rename not yet implemented');
            }
            return;
        }

        // Escape: Hide palette and context menu
        if (event.key === 'Escape') {
            this.creationPalette.hide();
            this.contextMenu.hide();
        }
    }

    /**
     * Show error message
     */
    showError(message) {
        if (!message || message.trim() === '') {
            return; // Don't show empty errors
        }
        
        const modal = document.getElementById('error-modal');
        const errorMessage = document.getElementById('error-message');
        if (modal && errorMessage) {
            errorMessage.textContent = message;
            modal.classList.remove('hidden');

            const closeBtn = modal.querySelector('.close-modal');
            if (closeBtn) {
                closeBtn.onclick = () => {
                    modal.classList.add('hidden');
                };
            }

            // Auto-close after 5 seconds
            setTimeout(() => {
                modal.classList.add('hidden');
            }, 5000);
        } else {
            alert(message);
        }
    }
}

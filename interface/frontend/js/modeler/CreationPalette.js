/**
 * CreationPalette - Floating palette showing valid creation options
 */
class CreationPalette {
    constructor(container, app) {
        this.container = container;
        this.app = app;
        this.currentNode = null;
        this.validTypes = [];
        this.setupEventListeners();
    }

    setupEventListeners() {
        // Hide palette when clicking outside
        document.addEventListener('click', (e) => {
            if (this.container && !this.container.contains(e.target)) {
                this.hide();
            }
        });

        // Handle keyboard shortcuts
        document.addEventListener('keydown', (e) => {
            if (this.isVisible() && !e.ctrlKey && !e.metaKey && !e.altKey) {
                const key = e.key;
                if (key >= '1' && key <= '9') {
                    const index = parseInt(key) - 1;
                    if (index < this.validTypes.length) {
                        e.preventDefault();
                        this.onItemClick(this.validTypes[index]);
                    }
                } else if (key === 'Escape') {
                    this.hide();
                }
            }
        });
    }

    /**
     * Update palette for selected node
     */
    async updateForNode(node) {
        this.currentNode = node;
        this.validTypes = [];

        if (!node) {
            this.hide();
            return;
        }

        // Determine valid child types based on node type
        if (node.type === 'classifier') {
            // Get containment references for this classifier
            this.validTypes = await this.app.metamodelService.getValidChildTypes(
                node.plugin,
                node.classifier
            );
        } else if (node.type === 'containment_ref') {
            // Already know the child type
            this.validTypes = [{
                name: node.childType,
                referenceName: node.reference,
                referenceID: node.referenceID
            }];
        } else if (node.type === 'instance') {
            // Get containment references for instance's type
            this.validTypes = await this.app.metamodelService.getValidChildTypes(
                node.plugin,
                node.instanceType
            );
        }

        if (this.validTypes.length === 0) {
            this.hide();
            return;
        }

        this.render();
    }

    /**
     * Render palette items
     */
    render() {
        const itemsContainer = this.container.querySelector('.palette-items');
        if (!itemsContainer) return;

        itemsContainer.innerHTML = '';

        for (let i = 0; i < this.validTypes.length; i++) {
            const type = this.validTypes[i];
            const item = this.createPaletteItem(type, i);
            itemsContainer.appendChild(item);
        }
    }

    /**
     * Create palette item element
     */
    createPaletteItem(type, index) {
        const item = document.createElement('div');
        item.className = 'palette-item';
        item.dataset.type = type.name;
        item.dataset.index = index;

        const icon = document.createElement('div');
        icon.className = 'palette-item-icon';
        icon.textContent = this.getIconForType(type.name);

        const label = document.createElement('div');
        label.className = 'palette-item-label';
        label.textContent = type.name;

        const shortcut = document.createElement('div');
        shortcut.className = 'palette-item-shortcut';
        shortcut.textContent = index < 9 ? `[${index + 1}]` : '';

        item.appendChild(icon);
        item.appendChild(label);
        item.appendChild(shortcut);

        item.addEventListener('click', () => {
            this.onItemClick(type);
        });

        // Check cardinality limits (future enhancement)
        // For now, we don't disable items

        return item;
    }

    /**
     * Get icon for type name
     */
    getIconForType(typeName) {
        const iconMap = {
            'Book': '📕',
            'Author': '👤',
            'Library': '📚',
            'LibraryModel': '📚',
            'Member': '👥',
            'Chapter': '📄',
            'Review': '💬',
            'Category': '📁'
        };

        return iconMap[typeName] || '📦';
    }

    /**
     * Handle item click
     */
    async onItemClick(type) {
        console.log('CreationPalette: Item clicked', type);
        this.hide();

        if (!this.currentNode) {
            console.warn('CreationPalette: No current node');
            return;
        }

        // Show creation dialog instead of prompt
        if (this.app.createInstanceDialog) {
            console.log('CreationPalette: Showing dialog for', type.name);
            await this.app.createInstanceDialog.show(this.currentNode, type);
        } else {
            console.warn('CreationPalette: Dialog not available, using prompt fallback');
            // Fallback to prompt if dialog not available
            const instanceName = prompt(`Enter name for new ${type.name}:`);
            if (!instanceName || instanceName.trim() === '') {
                return;
            }

            try {
                if (this.currentNode.type === 'classifier') {
                    await this.app.onCreateInstance(
                        null,
                        this.currentNode.classifier,
                        instanceName.trim(),
                        null
                    );
                } else if (this.currentNode.type === 'instance') {
                    const referenceID = type.referenceID;
                    if (referenceID === undefined || referenceID === null) {
                        const refInfo = await this.app.metamodelService.getContainmentReference(
                            this.currentNode.plugin,
                            this.currentNode.instanceType,
                            type.name
                        );
                        if (refInfo) {
                            await this.app.onCreateInstance(
                                this.currentNode.instance,
                                type.name,
                                instanceName.trim(),
                                refInfo.referenceID
                            );
                        } else {
                            alert(`Could not determine reference ID for ${type.name}`);
                        }
                    } else {
                        await this.app.onCreateInstance(
                            this.currentNode.instance,
                            type.name,
                            instanceName.trim(),
                            referenceID
                        );
                    }
                }
            } catch (error) {
                console.error('Failed to create instance:', error);
                alert(`Failed to create instance: ${error.message}`);
            }
        }
    }

    /**
     * Show palette at position
     */
    show(x, y) {
        this.container.classList.remove('hidden');
        this.container.style.left = `${x}px`;
        this.container.style.top = `${y}px`;

        // Adjust position if goes off screen
        const rect = this.container.getBoundingClientRect();
        if (rect.right > window.innerWidth) {
            this.container.style.left = `${x - rect.width}px`;
        }
        if (rect.bottom > window.innerHeight) {
            this.container.style.top = `${y - rect.height}px`;
        }
    }

    /**
     * Hide palette
     */
    hide() {
        this.container.classList.add('hidden');
        this.currentNode = null;
        this.validTypes = [];
    }

    /**
     * Check if palette is visible
     */
    isVisible() {
        return !this.container.classList.contains('hidden');
    }
}

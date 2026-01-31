/**
 * ContextMenu - Enhanced context menu with submenus
 */
class ContextMenu {
    constructor(container, app) {
        this.container = container;
        this.app = app;
        this.currentNode = null;
        this.setupEventListeners();
    }

    setupEventListeners() {
        // Hide menu when clicking outside
        document.addEventListener('click', (e) => {
            if (this.container && !this.container.contains(e.target)) {
                this.hide();
            }
        });

        // Hide menu on Escape key
        document.addEventListener('keydown', (e) => {
            if (e.key === 'Escape') {
                this.hide();
            }
        });
    }

    /**
     * Show menu at position
     */
    async show(x, y, node) {
        this.currentNode = node;
        const items = await this.buildMenuItems(node);
        this.render(items);
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
     * Hide menu
     */
    hide() {
        this.container.classList.add('hidden');
        this.currentNode = null;
    }

    /**
     * Build menu items for node type
     */
    async buildMenuItems(node) {
        const items = [];

        if (node.type === 'classifier') {
            // New Instance submenu
            const validTypes = await this.app.metamodelService.getValidChildTypes(
                node.plugin,
                node.classifier
            );

            if (validTypes.length > 0) {
                items.push({
                    type: 'submenu',
                    label: 'New Instance',
                    icon: '➕',
                    submenu: validTypes.map(type => ({
                        type: 'action',
                        label: type.name,
                        icon: '📦',
                        action: 'create_instance',
                        data: { className: type.name, referenceID: null }
                    }))
                });
            }

            items.push({ type: 'separator' });
            items.push({ type: 'action', label: 'Show Properties', action: 'show_properties' });
            items.push({ type: 'separator' });
            items.push({ type: 'action', label: 'Expand All', action: 'expand_all' });
            items.push({ type: 'action', label: 'Collapse All', action: 'collapse_all' });

        } else if (node.type === 'containment_ref') {
            // New Instance submenu (single type)
            if (node.childType) {
                items.push({
                    type: 'submenu',
                    label: 'New Instance',
                    icon: '➕',
                    submenu: [{
                        type: 'action',
                        label: node.childType,
                        icon: '📦',
                        action: 'create_instance',
                        data: { className: node.childType, referenceID: node.referenceID }
                    }]
                });
            }

            items.push({ type: 'separator' });
            items.push({ type: 'action', label: 'Show Properties', action: 'show_properties' });

        } else if (node.type === 'instance') {
            // New Child submenu
            const validTypes = await this.app.metamodelService.getValidChildTypes(
                node.plugin,
                node.instanceType
            );

            if (validTypes.length > 0) {
                items.push({
                    type: 'submenu',
                    label: 'New Child',
                    icon: '➕',
                    submenu: validTypes.map(type => ({
                        type: 'action',
                        label: type.name,
                        icon: '📦',
                        action: 'create_child',
                        data: { className: type.name, referenceID: type.referenceID }
                    }))
                });
            }

            items.push({ type: 'separator' });
            items.push({ type: 'action', label: 'Cut', shortcut: 'Ctrl+X', action: 'cut' });
            items.push({ type: 'action', label: 'Copy', shortcut: 'Ctrl+C', action: 'copy' });
            items.push({ type: 'action', label: 'Paste', shortcut: 'Ctrl+V', action: 'paste' });
            items.push({ type: 'separator' });
            items.push({ type: 'action', label: 'Delete', shortcut: 'Del', action: 'delete' });
            items.push({ type: 'action', label: 'Rename', shortcut: 'F2', action: 'rename' });
            items.push({ type: 'separator' });
            items.push({ type: 'action', label: 'Duplicate', action: 'duplicate' });
            items.push({ type: 'separator' });
            items.push({ type: 'action', label: 'Show Properties', action: 'show_properties' });
            items.push({ type: 'action', label: 'Validate', action: 'validate' });
        }

        return items;
    }

    /**
     * Render menu items
     */
    render(items) {
        const itemsContainer = this.container.querySelector('.context-menu-items');
        if (!itemsContainer) return;

        itemsContainer.innerHTML = '';

        items.forEach(item => {
            if (item.type === 'separator') {
                const separator = document.createElement('div');
                separator.className = 'context-menu-item-separator';
                itemsContainer.appendChild(separator);
            } else if (item.type === 'submenu') {
                const menuItem = this.createSubmenuItem(item);
                itemsContainer.appendChild(menuItem);
            } else if (item.type === 'action') {
                const menuItem = this.createActionItem(item);
                itemsContainer.appendChild(menuItem);
            }
        });
    }

    /**
     * Create submenu item
     */
    createSubmenuItem(item) {
        const menuItem = document.createElement('div');
        menuItem.className = 'context-menu-item';
        menuItem.dataset.type = 'submenu';

        const label = document.createElement('span');
        if (item.icon) {
            const icon = document.createElement('span');
            icon.className = 'context-menu-item-icon';
            icon.textContent = item.icon;
            label.appendChild(icon);
        }
        label.appendChild(document.createTextNode(item.label));

        const arrow = document.createElement('span');
        arrow.textContent = '▶';

        menuItem.appendChild(label);
        menuItem.appendChild(arrow);

        // Create submenu
        const submenu = document.createElement('div');
        submenu.className = 'context-submenu';

        item.submenu.forEach(subItem => {
            const subMenuItem = this.createActionItem(subItem, true);
            submenu.appendChild(subMenuItem);
        });

        menuItem.appendChild(submenu);

        return menuItem;
    }

    /**
     * Create action item
     */
    createActionItem(item, isSubmenu = false) {
        const menuItem = document.createElement('div');
        menuItem.className = 'context-menu-item';
        menuItem.dataset.action = item.action;
        if (item.disabled) {
            menuItem.classList.add('disabled');
        }

        const label = document.createElement('span');
        if (item.icon) {
            const icon = document.createElement('span');
            icon.className = 'context-menu-item-icon';
            icon.textContent = item.icon;
            label.appendChild(icon);
        }
        label.appendChild(document.createTextNode(item.label));

        menuItem.appendChild(label);

        if (item.shortcut) {
            const shortcut = document.createElement('span');
            shortcut.className = 'context-menu-item-shortcut';
            shortcut.textContent = item.shortcut;
            menuItem.appendChild(shortcut);
        }

        if (!item.disabled) {
            menuItem.addEventListener('click', (e) => {
                e.stopPropagation();
                this.onItemClick(item);
            });
        }

        return menuItem;
    }

    /**
     * Handle item click
     */
    async onItemClick(item) {
        this.hide();

        if (!this.currentNode) return;

        try {
            switch (item.action) {
                case 'create_instance':
                    await this.handleCreateInstance(item.data);
                    break;
                case 'create_child':
                    await this.handleCreateChild(item.data);
                    break;
                case 'delete':
                    await this.handleDelete();
                    break;
                case 'rename':
                    await this.handleRename();
                    break;
                case 'show_properties':
                    if (this.app.onNodeSelect) {
                        this.app.onNodeSelect(this.currentNode);
                    }
                    break;
                case 'expand_all':
                    if (this.app.unifiedTree) {
                        this.app.unifiedTree.expandAll();
                    }
                    break;
                case 'collapse_all':
                    if (this.app.unifiedTree) {
                        this.app.unifiedTree.collapseAll();
                    }
                    break;
                case 'cut':
                case 'copy':
                case 'paste':
                case 'duplicate':
                case 'validate':
                    // Future implementations
                    alert(`${item.action} not yet implemented`);
                    break;
            }
        } catch (error) {
            console.error('Context menu action failed:', error);
            alert(`Action failed: ${error.message}`);
        }
    }

    /**
     * Handle create instance
     */
    async handleCreateInstance(data) {
        if (this.app.createInstanceDialog) {
            // Use dialog for better UX
            await this.app.createInstanceDialog.show(this.currentNode, {
                name: data.className,
                referenceID: data.referenceID
            });
        } else {
            // Fallback to prompt
            const instanceName = prompt(`Enter name for new ${data.className}:`);
            if (!instanceName || instanceName.trim() === '') {
                return;
            }

            if (this.currentNode.type === 'classifier') {
                await this.app.onCreateInstance(
                    null,
                    this.currentNode.classifier,
                    instanceName.trim(),
                    null
                );
            }
        }
    }

    /**
     * Handle create child
     */
    async handleCreateChild(data) {
        if (this.app.createInstanceDialog) {
            // Use dialog for better UX
            await this.app.createInstanceDialog.show(this.currentNode, {
                name: data.className,
                referenceID: data.referenceID
            });
        } else {
            // Fallback to prompt
            const childName = prompt(`Enter name for new ${data.className}:`);
            if (!childName || childName.trim() === '') {
                return;
            }

            if (this.currentNode.type === 'instance') {
                await this.app.onCreateInstance(
                    this.currentNode.instance,
                    data.className,
                    childName.trim(),
                    data.referenceID
                );
            }
        }
    }

    /**
     * Handle delete
     */
    async handleDelete() {
        if (confirm(`Delete "${this.currentNode.instance}"?`)) {
            await this.app.onDeleteInstance(this.currentNode);
        }
    }

    /**
     * Handle rename
     */
    async handleRename() {
        const newName = prompt('Enter new name:', this.currentNode.instance);
        if (newName && newName.trim() !== '' && newName !== this.currentNode.instance) {
            // Future: implement rename
            alert('Rename not yet implemented');
        }
    }
}

/**
 * MainEditor - Center panel showing selected element's children
 */
class MainEditor {
    constructor(container, app) {
        this.container = container; // This will be the children-content container
        this.app = app;
        this.currentNode = null;
        this.breadcrumbsContainer = document.getElementById('breadcrumbs');
        this.setupToggle();
    }

    setupToggle() {
        const toggleBtn = document.getElementById('toggle-children-panel');
        const panel = document.querySelector('.children-panel');
        if (toggleBtn && panel) {
            toggleBtn.addEventListener('click', () => {
                panel.classList.toggle('collapsed');
            });
        }
    }

    /**
     * Show node in editor
     */
    async showNode(node) {
        this.currentNode = node;
        this.renderBreadcrumbs(node);
        await this.renderChildrenTree(node);
    }

    /**
     * Render breadcrumbs
     */
    renderBreadcrumbs(node) {
        if (!this.breadcrumbsContainer) return;

        const breadcrumbs = [];
        
        // Add plugin
        breadcrumbs.push({
            label: node.plugin || 'Unknown',
            action: () => {
                // Could navigate to plugin root
            }
        });

        // Add node-specific breadcrumbs
        if (node.type === 'instance') {
            breadcrumbs.push({
                label: node.instanceType || 'Instance',
                action: null
            });
            breadcrumbs.push({
                label: `"${node.instance}"`,
                action: null
            });
        } else if (node.type === 'classifier') {
            breadcrumbs.push({
                label: node.classifier || 'Classifier',
                action: null
            });
        } else if (node.type === 'containment_ref') {
            breadcrumbs.push({
                label: node.reference || 'Reference',
                action: null
            });
        }

        this.breadcrumbsContainer.innerHTML = '';

        breadcrumbs.forEach((crumb, index) => {
            const item = document.createElement('span');
            item.className = 'breadcrumb-item';
            item.textContent = crumb.label;
            
            if (crumb.action) {
                item.style.cursor = 'pointer';
                item.style.textDecoration = 'underline';
                item.addEventListener('click', crumb.action);
            }

            this.breadcrumbsContainer.appendChild(item);

            if (index < breadcrumbs.length - 1) {
                const separator = document.createElement('span');
                separator.className = 'breadcrumb-separator';
                separator.textContent = ' / ';
                this.breadcrumbsContainer.appendChild(separator);
            }
        });
    }

    /**
     * Render children tree
     */
    async renderChildrenTree(node) {
        this.container.innerHTML = '';

        if (!node) {
            this.container.innerHTML = '<div class="empty-state">Select an element to view its children</div>';
            return;
        }

        if (node.type === 'classifier') {
            // Show containment structure
            await this.renderClassifierChildren(node);
        } else if (node.type === 'instance') {
            // Show instance children
            await this.renderInstanceChildren(node);
        } else if (node.type === 'containment_ref') {
            // Show reference info
            this.container.innerHTML = `<div class="empty-state">Containment Reference: ${node.reference}<br>Type: ${node.childType}</div>`;
        } else {
            this.container.innerHTML = '<div class="empty-state">No children to display</div>';
        }
    }

    /**
     * Render classifier children (containment structure)
     */
    async renderClassifierChildren(node) {
        try {
            const details = await this.app.metamodelService.getClassifierDetails(
                node.plugin,
                node.classifier
            );

            if (!details.references || details.references.length === 0) {
                this.container.innerHTML = '<div class="empty-state">No containment references</div>';
                return;
            }

            const containmentRefs = details.references.filter(r => r.containment === true);

            if (containmentRefs.length === 0) {
                this.container.innerHTML = '<div class="empty-state">No containment references</div>';
                return;
            }

            const tree = document.createElement('div');
            tree.className = 'editor-tree';

            for (const ref of containmentRefs) {
                const refNode = this.createContainmentRefNode(ref, node);
                tree.appendChild(refNode);
            }

            this.container.appendChild(tree);
        } catch (error) {
            console.error('Failed to render classifier children:', error);
            this.container.innerHTML = `<div class="empty-state">Error: ${error.message}</div>`;
        }
    }

    /**
     * Render instance children
     */
    async renderInstanceChildren(node) {
        try {
            // Get instance details
            const instanceData = node.data || {};
            const children = instanceData.children || [];

            if (children.length === 0) {
                this.container.innerHTML = '<div class="empty-state">No children</div>';
                return;
            }

            const tree = document.createElement('div');
            tree.className = 'editor-tree';

            for (const child of children) {
                const childNode = this.createInstanceChildNode(child);
                tree.appendChild(childNode);
            }

            this.container.appendChild(tree);
        } catch (error) {
            console.error('Failed to render instance children:', error);
            this.container.innerHTML = `<div class="empty-state">Error: ${error.message}</div>`;
        }
    }

    /**
     * Create containment reference node for editor
     */
    createContainmentRefNode(ref, parentNode) {
        const nodeDiv = document.createElement('div');
        nodeDiv.className = 'editor-tree-node';

        const icon = document.createElement('span');
        icon.textContent = '📖';
        icon.style.marginRight = '0.5rem';

        const label = document.createElement('span');
        label.textContent = ref.name;

        const badge = document.createElement('span');
        badge.className = 'tree-node-badge';
        badge.style.marginLeft = '0.5rem';
        const upperBound = ref.upper === -1 ? '*' : ref.upper;
        badge.textContent = `${ref.lower || 0}..${upperBound}`;

        const createBtn = document.createElement('button');
        createBtn.className = 'toolbar-btn';
        createBtn.style.marginLeft = 'auto';
        createBtn.textContent = `+ ${ref.type || 'New'}`;
        createBtn.addEventListener('click', async () => {
            await this.onCreateClick(parentNode, ref.type, ref.featureID);
        });

        nodeDiv.appendChild(icon);
        nodeDiv.appendChild(label);
        nodeDiv.appendChild(badge);
        nodeDiv.appendChild(createBtn);

        return nodeDiv;
    }

    /**
     * Create instance child node for editor
     */
    createInstanceChildNode(child) {
        const nodeDiv = document.createElement('div');
        nodeDiv.className = 'editor-tree-node';

        const icon = document.createElement('span');
        icon.textContent = '📕';
        icon.style.marginRight = '0.5rem';

        const label = document.createElement('span');
        label.textContent = `"${child.name}"`;

        const badge = document.createElement('span');
        badge.className = 'tree-node-badge';
        badge.style.marginLeft = '0.5rem';
        badge.textContent = child.type || '';

        nodeDiv.appendChild(icon);
        nodeDiv.appendChild(label);
        nodeDiv.appendChild(badge);

        // Make clickable to select
        nodeDiv.style.cursor = 'pointer';
        nodeDiv.addEventListener('click', () => {
            if (this.app.onNodeSelect) {
                this.app.onNodeSelect({
                    type: 'instance',
                    plugin: this.currentNode.plugin,
                    instance: child.name,
                    instanceType: child.type,
                    data: child
                });
            }
        });

        return nodeDiv;
    }

    /**
     * Handle create button click
     */
    async onCreateClick(node, childType, referenceID) {
        const instanceName = prompt(`Enter name for new ${childType}:`);
        if (!instanceName || instanceName.trim() === '') {
            return;
        }

        try {
            if (node.type === 'classifier') {
                // Create root instance
                await this.app.onCreateInstance(
                    null,
                    node.classifier,
                    instanceName.trim(),
                    null
                );
            } else if (node.type === 'instance') {
                // Create child instance
                await this.app.onCreateInstance(
                    node.instance,
                    childType,
                    instanceName.trim(),
                    referenceID
                );
            }
        } catch (error) {
            console.error('Failed to create instance:', error);
            alert(`Failed to create instance: ${error.message}`);
        }
    }
}

class ModelTreeView {
    constructor(containerId, options = {}) {
        this.container = document.getElementById(containerId);
        if (!this.container) {
            throw new Error(`Container with id "${containerId}" not found`);
        }
        
        this.options = {
            onNodeSelect: options.onNodeSelect || null,
            onNodeExpand: options.onNodeExpand || null,
            onNodeCollapse: options.onNodeCollapse || null,
            onNodeRightClick: options.onNodeRightClick || null,
            ...options
        };
        
        this.expandedNodes = new Set();
        this.selectedNodeId = null;
        this.treeData = null;
    }

    renderTree(treeData) {
        this.treeData = treeData;
        this.container.innerHTML = '';
        
        if (!treeData || !treeData.roots || treeData.roots.length === 0) {
            this.container.innerHTML = '<div class="empty-state">No objects created yet</div>';
            return;
        }
        
        const treeRoot = document.createElement('div');
        treeRoot.className = 'model-tree';
        
        treeData.roots.forEach((root, index) => {
            const nodeElement = this.renderNode(root, 0, `root-${index}`);
            treeRoot.appendChild(nodeElement);
        });
        
        this.container.appendChild(treeRoot);
    }

    renderNode(node, level, nodeId) {
        const nodeElement = document.createElement('div');
        nodeElement.className = 'tree-node';
        nodeElement.dataset.nodeId = nodeId;
        nodeElement.dataset.nodeName = node.name;
        nodeElement.dataset.nodeType = node.type;
        
        const hasChildren = node.children && node.children.length > 0;
        const isExpanded = this.expandedNodes.has(nodeId);
        
        if (hasChildren) {
            nodeElement.classList.add(isExpanded ? 'tree-node-expanded' : 'tree-node-collapsed');
        } else {
            nodeElement.classList.add('tree-node-leaf');
        }
        
        if (this.selectedNodeId === nodeId) {
            nodeElement.classList.add('tree-node-selected');
        }
        
        // Indentation
        const indent = level * 20;
        
        // Node content
        const nodeContent = document.createElement('div');
        nodeContent.className = 'tree-node-content';
        nodeContent.style.paddingLeft = `${indent}px`;
        
        // Expand/collapse icon
        if (hasChildren) {
            const icon = document.createElement('span');
            icon.className = 'tree-node-icon';
            icon.textContent = isExpanded ? '▼' : '▶';
            icon.addEventListener('click', (e) => {
                e.stopPropagation();
                this.toggleNode(nodeId);
            });
            nodeContent.appendChild(icon);
        } else {
            const spacer = document.createElement('span');
            spacer.className = 'tree-node-spacer';
            spacer.textContent = '  ';
            nodeContent.appendChild(spacer);
        }
        
        // Node label
        const label = document.createElement('span');
        label.className = 'tree-node-label';
        label.textContent = `${node.name} (${node.type})`;
        label.addEventListener('click', () => {
            this.selectNode(nodeId);
        });
        nodeContent.appendChild(label);
        
        nodeElement.appendChild(nodeContent);
        
        // Children container
        if (hasChildren && isExpanded) {
            const childrenContainer = document.createElement('div');
            childrenContainer.className = 'tree-node-children';
            
            node.children.forEach((child, childIndex) => {
                const childId = `${nodeId}-child-${childIndex}`;
                const childElement = this.renderNode(child, level + 1, childId);
                childrenContainer.appendChild(childElement);
            });
            
            nodeElement.appendChild(childrenContainer);
        }
        
        // Right-click handler
        nodeElement.addEventListener('contextmenu', (e) => {
            e.preventDefault();
            if (this.options.onNodeRightClick) {
                this.options.onNodeRightClick(e, node, nodeId);
            }
        });
        
        return nodeElement;
    }

    toggleNode(nodeId) {
        if (this.expandedNodes.has(nodeId)) {
            this.expandedNodes.delete(nodeId);
            if (this.options.onNodeCollapse) {
                this.options.onNodeCollapse(nodeId);
            }
        } else {
            this.expandedNodes.add(nodeId);
            if (this.options.onNodeExpand) {
                this.options.onNodeExpand(nodeId);
            }
        }
        
        // Re-render tree to reflect changes
        if (this.treeData) {
            this.renderTree(this.treeData);
        }
    }

    selectNode(nodeId) {
        // Remove previous selection
        if (this.selectedNodeId) {
            const prevNode = this.container.querySelector(`[data-node-id="${this.selectedNodeId}"]`);
            if (prevNode) {
                prevNode.classList.remove('tree-node-selected');
            }
        }
        
        // Set new selection
        this.selectedNodeId = nodeId;
        const currentNode = this.container.querySelector(`[data-node-id="${nodeId}"]`);
        if (currentNode) {
            currentNode.classList.add('tree-node-selected');
        }
        
        if (this.options.onNodeSelect) {
            const nodeElement = this.container.querySelector(`[data-node-id="${nodeId}"]`);
            if (nodeElement) {
                const node = {
                    name: nodeElement.dataset.nodeName,
                    type: nodeElement.dataset.nodeType
                };
                this.options.onNodeSelect(node, nodeId);
            }
        }
    }

    getSelectedNode() {
        if (!this.selectedNodeId) return null;
        const nodeElement = this.container.querySelector(`[data-node-id="${this.selectedNodeId}"]`);
        if (!nodeElement) return null;
        
        return {
            name: nodeElement.dataset.nodeName,
            type: nodeElement.dataset.nodeType,
            id: this.selectedNodeId
        };
    }

    expandAll() {
        const allNodes = this.container.querySelectorAll('.tree-node');
        allNodes.forEach(node => {
            const nodeId = node.dataset.nodeId;
            if (node.classList.contains('tree-node-collapsed')) {
                this.expandedNodes.add(nodeId);
            }
        });
        if (this.treeData) {
            this.renderTree(this.treeData);
        }
    }

    collapseAll() {
        this.expandedNodes.clear();
        if (this.treeData) {
            this.renderTree(this.treeData);
        }
    }
}

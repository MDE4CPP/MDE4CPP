/**
 * UnifiedTree - Unified tree component showing both metamodel and instances
 */
class UnifiedTree {
    constructor(container, app) {
        this.container = container;
        this.app = app;
        this.currentPlugin = null;
        this.selectedNode = null;
        this.expandedNodes = new Set();
        this.treeData = null;
        
        // Node type constants
        this.NODE_TYPES = {
            PLUGIN_NODE: 'plugin',
            METAMODEL_SECTION: 'metamodel_section',
            CLASSIFIER_NODE: 'classifier',
            CONTAINMENT_REF_NODE: 'containment_ref',
            INSTANCES_SECTION: 'instances_section',
            INSTANCE_NODE: 'instance'
        };

        this.setupEventListeners();
    }

    setupEventListeners() {
        // Handle clicks outside to deselect
        document.addEventListener('click', (e) => {
            if (!this.container.contains(e.target)) {
                // Don't deselect if clicking on palette or context menu
                const palette = document.getElementById('creation-palette');
                const contextMenu = document.getElementById('context-menu');
                if (palette && !palette.contains(e.target) && 
                    contextMenu && !contextMenu.contains(e.target)) {
                    // Allow deselection
                }
            }
        });
    }

    /**
     * Load plugin and render tree
     */
    async loadPlugin(pluginName) {
        this.currentPlugin = pluginName;
        this.selectedNode = null;
        this.expandedNodes.clear();
        
        this.container.innerHTML = '<div class="loading">Loading...</div>';

        try {
            // Load metamodel and instance data in parallel
            const [metamodelTree, instanceTree] = await Promise.all([
                this.app.metamodelService.getContainmentTree(pluginName),
                this.app.modelService.getModelTree(pluginName)
            ]);

            // Debug logging
            console.log('Loaded metamodel tree:', metamodelTree);
            console.log('Loaded instance tree:', instanceTree);

            this.treeData = {
                plugin: pluginName,
                metamodel: metamodelTree,
                instances: instanceTree
            };

            this.renderTree();
        } catch (error) {
            console.error('Failed to load plugin:', error);
            this.container.innerHTML = `<div class="empty-state">Error loading plugin: ${error.message}</div>`;
        }
    }

    _refreshDebounceTimer = null;
    _refreshDebounceMs = 350;

    /**
     * Reload tree data without clearing expansion state (used by refresh after create/delete)
     */
    async reloadData() {
        if (!this.currentPlugin) return;
        try {
            const [metamodelTree, instanceTree] = await Promise.all([
                this.app.metamodelService.getContainmentTree(this.currentPlugin),
                this.app.modelService.getModelTree(this.currentPlugin)
            ]);
            this.treeData = {
                plugin: this.currentPlugin,
                metamodel: metamodelTree,
                instances: instanceTree
            };
        } catch (error) {
            console.error('Failed to reload tree data:', error);
        }
    }

    /**
     * Render tree structure
     */
    renderTree() {
        if (!this.treeData) return;

        const treeElement = document.createElement('div');
        treeElement.className = 'unified-tree-content';
        treeElement.style.width = '100%';
        treeElement.style.display = 'block';

        // Render plugin node
        const pluginNode = this.createPluginNode();
        treeElement.appendChild(pluginNode);

        this.container.innerHTML = '';
        this.container.appendChild(treeElement);
    }

    /**
     * Create plugin root node
     */
    createPluginNode() {
        const pluginDiv = document.createElement('div');
        pluginDiv.className = 'tree-node tree-node-plugin';
        pluginDiv.dataset.nodeType = this.NODE_TYPES.PLUGIN_NODE;
        pluginDiv.dataset.plugin = this.currentPlugin;

        const expandIcon = document.createElement('div');
        expandIcon.className = 'tree-node-expand';
        const isPluginExpanded = this.expandedNodes.has('plugin');
        expandIcon.textContent = isPluginExpanded ? '▼' : '▶';

        const icon = document.createElement('div');
        icon.className = 'tree-node-icon';
        icon.textContent = '📦';
        icon.style.marginRight = '0.5rem';

        const label = document.createElement('div');
        label.className = 'tree-node-label';
        label.textContent = this.currentPlugin;

        pluginDiv.appendChild(expandIcon);
        pluginDiv.appendChild(icon);
        pluginDiv.appendChild(label);

        // Add click handler for expand icon
        expandIcon.addEventListener('click', (e) => {
            e.stopPropagation();
            this.toggleNode(pluginDiv, 'plugin');
        });

        // Click handler for node - only toggle on expand icon; row click just selects
        pluginDiv.addEventListener('click', (e) => {
            e.stopPropagation();
            if (e.target === expandIcon || expandIcon.contains(e.target)) {
                return;
            }
            this.selectNode(pluginDiv, {
                type: this.NODE_TYPES.PLUGIN_NODE,
                plugin: this.currentPlugin
            });
        });

        pluginDiv.addEventListener('contextmenu', (e) => {
            e.preventDefault();
            this.onNodeRightClick(pluginDiv, e);
        });

        // Render children if expanded
        if (isPluginExpanded) {
            pluginDiv.classList.add('tree-node-expanded');
            const childrenDiv = document.createElement('div');
            childrenDiv.className = 'tree-node-children';
            
            // Metamodel section
            const metamodelSection = this.createMetamodelSection();
            childrenDiv.appendChild(metamodelSection);
            
            // Instances section
            const instancesSection = this.createInstancesSection();
            childrenDiv.appendChild(instancesSection);
            
            pluginDiv.appendChild(childrenDiv);
        }

        return pluginDiv;
    }

    /**
     * Create metamodel section
     */
    createMetamodelSection() {
        const sectionDiv = document.createElement('div');
        sectionDiv.className = 'tree-section';

        const header = document.createElement('div');
        header.className = 'tree-section-header';
        header.innerHTML = '📋 Metamodel';
        header.dataset.section = 'metamodel';

        const isExpanded = this.expandedNodes.has('metamodel');
        if (isExpanded) {
            header.innerHTML = '📋 Metamodel ▼';
        } else {
            header.innerHTML = '📋 Metamodel ▶';
        }

        header.addEventListener('click', (e) => {
            e.stopPropagation();
            this.toggleSection('metamodel', header);
        });

        sectionDiv.appendChild(header);

        if (isExpanded && this.treeData.metamodel) {
            const content = document.createElement('div');
            content.className = 'tree-section-content';

            // Containment hierarchy: show only root classifiers under Metamodel.
            // Root = classifier that is never the target type of any containment ref.
            const classifiers = this.treeData.metamodel.classifiers || [];
            const childTypes = new Set();
            for (const c of classifiers) {
                for (const ref of c.containmentRefs || []) {
                    if (ref.type) childTypes.add(ref.type);
                }
            }
            const rootClassifiers = classifiers.filter(c => {
                const name = c.name || (typeof c === 'string' ? c : null);
                return name && !childTypes.has(name);
            });

            for (const classifier of rootClassifiers) {
                if (!classifier.name && typeof classifier === 'string') {
                    classifier.name = classifier;
                }
                if (!classifier.name) continue;
                const classifierNode = this.createClassifierNode(classifier, 0);
                content.appendChild(classifierNode);
            }

            sectionDiv.appendChild(content);
        }

        return sectionDiv;
    }

    /**
     * Create classifier node
     */
    createClassifierNode(classifier, level) {
        const nodeDiv = document.createElement('div');
        nodeDiv.className = 'tree-node tree-node-metamodel tree-node-classifier';
        nodeDiv.dataset.nodeType = this.NODE_TYPES.CLASSIFIER_NODE;
        nodeDiv.dataset.classifier = classifier.name;
        // Don't add paddingLeft here - let CSS handle indentation through tree-node-children

        const expandIcon = document.createElement('div');
        expandIcon.className = 'tree-node-expand';
        expandIcon.textContent = '▶';
        
        const icon = document.createElement('div');
        icon.className = 'tree-node-icon';
        icon.textContent = '📚';

        const label = document.createElement('div');
        label.className = 'tree-node-label';
        label.textContent = classifier.name || 'Unnamed';
        label.style.color = 'inherit';

        nodeDiv.appendChild(expandIcon);
        nodeDiv.appendChild(icon);
        nodeDiv.appendChild(label);

        const nodeId = `classifier:${classifier.name}`;
        const isExpanded = this.expandedNodes.has(nodeId);

        if (classifier.containmentRefs && classifier.containmentRefs.length > 0) {
            if (isExpanded) {
                expandIcon.classList.add('tree-node-expanded');
                expandIcon.textContent = '▼';
            } else {
                expandIcon.textContent = '▶';
            }

            expandIcon.addEventListener('click', (e) => {
                e.stopPropagation();
                this.toggleNode(nodeDiv, nodeId);
            });
        } else {
            expandIcon.style.visibility = 'hidden';
        }

        nodeDiv.addEventListener('click', (e) => {
            e.stopPropagation(); // Prevent bubbling to plugin row (would collapse whole tree)
            if (e.target === expandIcon || expandIcon.contains(e.target)) {
                return;
            }
            this.selectNode(nodeDiv, {
                type: this.NODE_TYPES.CLASSIFIER_NODE,
                plugin: this.currentPlugin,
                classifier: classifier.name,
                instanceType: classifier.name, // For consistency
                data: classifier
            });
        });

        nodeDiv.addEventListener('contextmenu', (e) => {
            e.preventDefault();
            this.onNodeRightClick(nodeDiv, e, {
                type: this.NODE_TYPES.CLASSIFIER_NODE,
                plugin: this.currentPlugin,
                classifier: classifier.name,
                data: classifier
            });
        });

        // Render containment references if expanded
        if (isExpanded && classifier.containmentRefs && classifier.containmentRefs.length > 0) {
            const childrenDiv = document.createElement('div');
            childrenDiv.className = 'tree-node-children';

            for (const ref of classifier.containmentRefs) {
                const refNode = this.createContainmentRefNode(ref, 0);
                childrenDiv.appendChild(refNode);
            }

            nodeDiv.appendChild(childrenDiv);
        }

        return nodeDiv;
    }

    /**
     * Create containment reference node
     */
    createContainmentRefNode(ref, level) {
        const nodeDiv = document.createElement('div');
        nodeDiv.className = 'tree-node tree-node-metamodel tree-node-containment-ref';
        nodeDiv.dataset.nodeType = this.NODE_TYPES.CONTAINMENT_REF_NODE;
        nodeDiv.dataset.reference = ref.name;
        // Don't add paddingLeft here - let CSS handle indentation through tree-node-children

        const expandIcon = document.createElement('div');
        expandIcon.className = 'tree-node-expand';
        expandIcon.textContent = '▶';

        const icon = document.createElement('div');
        icon.className = 'tree-node-icon';
        icon.textContent = '📖';

        const label = document.createElement('div');
        label.className = 'tree-node-label';
        label.textContent = ref.name || 'Unnamed';
        label.style.color = 'inherit';

        const badge = document.createElement('div');
        badge.className = 'tree-node-badge';
        const upperBound = ref.upperBound === -1 ? '*' : ref.upperBound;
        badge.textContent = `${ref.lowerBound}..${upperBound}`;

        nodeDiv.appendChild(expandIcon);
        nodeDiv.appendChild(icon);
        nodeDiv.appendChild(label);
        nodeDiv.appendChild(badge);

        const nodeId = `ref:${ref.name}`;
        const isExpanded = this.expandedNodes.has(nodeId);

        if (ref.type) {
            if (isExpanded) {
                expandIcon.classList.add('tree-node-expanded');
                expandIcon.textContent = '▼';
            } else {
                expandIcon.textContent = '▶';
            }

            expandIcon.addEventListener('click', (e) => {
                e.stopPropagation();
                this.toggleNode(nodeDiv, nodeId);
            });
        } else {
            expandIcon.style.visibility = 'hidden';
        }

        nodeDiv.addEventListener('click', (e) => {
            e.stopPropagation(); // Prevent bubbling to plugin row (would collapse whole tree)
            if (e.target === expandIcon || expandIcon.contains(e.target)) {
                return;
            }
            this.selectNode(nodeDiv, {
                type: this.NODE_TYPES.CONTAINMENT_REF_NODE,
                plugin: this.currentPlugin,
                reference: ref.name,
                childType: ref.type,
                referenceID: ref.featureID,
                data: ref
            });
        });

        nodeDiv.addEventListener('contextmenu', (e) => {
            e.preventDefault();
            this.onNodeRightClick(nodeDiv, e, {
                type: this.NODE_TYPES.CONTAINMENT_REF_NODE,
                plugin: this.currentPlugin,
                reference: ref.name,
                childType: ref.type,
                referenceID: ref.featureID,
                data: ref
            });
        });

        // Render child classifier if expanded
        if (isExpanded && ref.type) {
            const childrenDiv = document.createElement('div');
            childrenDiv.className = 'tree-node-children';

            // Find the child classifier in metamodel
            const childClassifier = this.treeData.metamodel.classifiers.find(c => c.name === ref.type);
            if (childClassifier) {
                const childNode = this.createClassifierNode(childClassifier, 0);
                childrenDiv.appendChild(childNode);
            } else {
                // Just show the type name
                const typeNode = document.createElement('div');
                typeNode.className = 'tree-node tree-node-metamodel';
                const icon = document.createElement('div');
                icon.className = 'tree-node-icon';
                icon.textContent = '📕';
                const label = document.createElement('div');
                label.className = 'tree-node-label';
                label.textContent = ref.type;
                typeNode.appendChild(icon);
                typeNode.appendChild(label);
                childrenDiv.appendChild(typeNode);
            }

            nodeDiv.appendChild(childrenDiv);
        }

        return nodeDiv;
    }

    /**
     * Create instances section
     */
    createInstancesSection() {
        const sectionDiv = document.createElement('div');
        sectionDiv.className = 'tree-section';

        const header = document.createElement('div');
        header.className = 'tree-section-header';
        header.dataset.section = 'instances';

        const isExpanded = this.expandedNodes.has('instances');
        if (isExpanded) {
            header.innerHTML = '📋 Instances ▼';
        } else {
            header.innerHTML = '📋 Instances ▶';
        }

        header.addEventListener('click', (e) => {
            e.stopPropagation();
            this.toggleSection('instances', header);
        });

        sectionDiv.appendChild(header);

        if (isExpanded && this.treeData.instances && this.treeData.instances.roots) {
            const content = document.createElement('div');
            content.className = 'tree-section-content';

            // Render root instances
            const roots = Array.isArray(this.treeData.instances.roots) ? this.treeData.instances.roots : [];
            console.log('Rendering instance roots:', roots);
            for (const root of roots) {
                // Ensure root has name property
                if (!root.name && typeof root === 'string') {
                    root.name = root;
                }
                if (!root.name) {
                    console.warn('Instance root missing name:', root);
                    continue;
                }
                const instanceNode = this.createInstanceNode(root, 0);
                content.appendChild(instanceNode);
            }

            sectionDiv.appendChild(content);
        }

        return sectionDiv;
    }

    /**
     * Create instance node (will be completed in next todo)
     */
    createInstanceNode(instance, level) {
        const nodeDiv = document.createElement('div');
        nodeDiv.className = 'tree-node tree-node-instance';
        nodeDiv.dataset.nodeType = this.NODE_TYPES.INSTANCE_NODE;
        
        // Handle both object format and string format
        const instanceName = instance.name || instance || 'Unnamed';
        const instanceType = instance.type || '';
        
        nodeDiv.dataset.instance = instanceName;
        // Don't add paddingLeft here - let CSS handle indentation through tree-node-children

        const expandIcon = document.createElement('div');
        expandIcon.className = 'tree-node-expand';
        expandIcon.textContent = '▶';

        const icon = document.createElement('div');
        icon.className = 'tree-node-icon';
        icon.textContent = '📕';

        const label = document.createElement('div');
        label.className = 'tree-node-label';
        label.textContent = `"${instanceName}"`;
        label.style.color = 'inherit';

        const badge = document.createElement('div');
        badge.className = 'tree-node-badge';
        badge.textContent = instanceType;

        nodeDiv.appendChild(expandIcon);
        nodeDiv.appendChild(icon);
        nodeDiv.appendChild(label);
        nodeDiv.appendChild(badge);

        const nodeId = `instance:${instanceName}`;
        const isExpanded = this.expandedNodes.has(nodeId);
        const hasChildren = instance.children && Array.isArray(instance.children) && instance.children.length > 0;

        if (hasChildren) {
            if (isExpanded) {
                expandIcon.classList.add('tree-node-expanded');
                expandIcon.textContent = '▼';
            } else {
                expandIcon.textContent = '▶';
            }

            expandIcon.addEventListener('click', (e) => {
                e.stopPropagation();
                this.toggleNode(nodeDiv, nodeId);
            });
        } else {
            expandIcon.style.visibility = 'hidden';
        }

        nodeDiv.addEventListener('click', (e) => {
            e.stopPropagation(); // Prevent bubbling to plugin row (would collapse whole tree)
            if (e.target === expandIcon || expandIcon.contains(e.target)) {
                return;
            }
            this.selectNode(nodeDiv, {
                type: this.NODE_TYPES.INSTANCE_NODE,
                plugin: this.currentPlugin,
                instance: instanceName,
                instanceType: instanceType,
                classifier: instanceType, // Also set classifier for consistency
                data: instance
            });
        });

        nodeDiv.addEventListener('contextmenu', (e) => {
            e.preventDefault();
            this.onNodeRightClick(nodeDiv, e, {
                type: this.NODE_TYPES.INSTANCE_NODE,
                plugin: this.currentPlugin,
                instance: instanceName,
                instanceType: instanceType,
                data: instance
            });
        });

        // Render children if expanded
        if (isExpanded && hasChildren) {
            const childrenDiv = document.createElement('div');
            childrenDiv.className = 'tree-node-children';

            for (const child of instance.children) {
                const childNode = this.createInstanceNode(child, 0);
                childrenDiv.appendChild(childNode);
            }

            nodeDiv.appendChild(childrenDiv);
        }

        return nodeDiv;
    }

    /**
     * Toggle section expand/collapse
     */
    toggleSection(sectionName, headerElement) {
        const isExpanded = this.expandedNodes.has(sectionName);
        if (isExpanded) {
            this.expandedNodes.delete(sectionName);
            headerElement.innerHTML = headerElement.innerHTML.replace('▼', '▶');
        } else {
            this.expandedNodes.add(sectionName);
            headerElement.innerHTML = headerElement.innerHTML.replace('▶', '▼');
        }
        this.renderTree();
    }

    /**
     * Toggle node expand/collapse
     */
    toggleNode(nodeElement, nodeId) {
        if (!nodeId) {
            nodeId = nodeElement.dataset.nodeType === this.NODE_TYPES.PLUGIN_NODE ? 'plugin' : 
                     nodeElement.dataset.instance || nodeElement.dataset.classifier || nodeElement.dataset.reference;
        }

        const isExpanded = this.expandedNodes.has(nodeId);
        if (isExpanded) {
            this.expandedNodes.delete(nodeId);
        } else {
            this.expandedNodes.add(nodeId);
        }
        
        // Preserve selected node
        const selectedNode = this.selectedNode;
        this.renderTree();
        
        // Restore selection if still valid
        if (selectedNode) {
            const selectedElement = this.container.querySelector(`[data-${selectedNode.type === 'classifier' ? 'classifier' : selectedNode.type === 'instance' ? 'instance' : 'reference'}="${selectedNode.classifier || selectedNode.instance || selectedNode.reference}"]`);
            if (selectedElement) {
                selectedElement.classList.add('tree-node-selected');
            }
        }
    }

    /**
     * Select node
     */
    selectNode(nodeElement, nodeData) {
        // Remove previous selection
        const previousSelected = this.container.querySelector('.tree-node-selected');
        if (previousSelected) {
            previousSelected.classList.remove('tree-node-selected');
        }

        // Add selection to current node
        nodeElement.classList.add('tree-node-selected');
        this.selectedNode = nodeData || {
            type: nodeElement.dataset.nodeType,
            plugin: this.currentPlugin
        };

        // Notify app
        if (this.app && this.app.onNodeSelect) {
            this.app.onNodeSelect(this.selectedNode);
        }
    }

    /**
     * Get selected node
     */
    getSelectedNode() {
        return this.selectedNode;
    }

    /**
     * Handle node right-click
     */
    onNodeRightClick(nodeElement, event, nodeData) {
        const data = nodeData || {
            type: nodeElement.dataset.nodeType,
            plugin: this.currentPlugin
        };

        if (this.app && this.app.onNodeRightClick) {
            this.app.onNodeRightClick(data, event);
        }
    }

    /**
     * Expand all nodes
     */
    expandAll() {
        // Expand plugin
        this.expandedNodes.add('plugin');
        this.expandedNodes.add('metamodel');
        this.expandedNodes.add('instances');
        
        // Expand all classifiers
        if (this.treeData && this.treeData.metamodel) {
            for (const classifier of this.treeData.metamodel.classifiers) {
                this.expandedNodes.add(`classifier:${classifier.name}`);
                if (classifier.containmentRefs) {
                    for (const ref of classifier.containmentRefs) {
                        this.expandedNodes.add(`ref:${ref.name}`);
                    }
                }
            }
        }

        // Expand all instances
        const expandInstances = (instances) => {
            for (const instance of instances) {
                const instanceName = instance.name || instance || 'Unnamed';
                this.expandedNodes.add(`instance:${instanceName}`);
                if (instance.children && Array.isArray(instance.children)) {
                    expandInstances(instance.children);
                }
            }
        };

        if (this.treeData && this.treeData.instances && this.treeData.instances.roots) {
            expandInstances(this.treeData.instances.roots);
        }

        this.renderTree();
    }

    /**
     * Collapse all nodes
     */
    collapseAll() {
        this.expandedNodes.clear();
        this.renderTree();
    }

    /**
     * Refresh tree data (preserves expansion state). Debounced to avoid rapid consecutive API calls.
     */
    async refresh() {
        if (!this.currentPlugin) return;
        this.expandedNodes.add('plugin');
        this.expandedNodes.add('metamodel');
        this.expandedNodes.add('instances');
        if (this._refreshDebounceTimer) clearTimeout(this._refreshDebounceTimer);
        this._refreshDebounceTimer = setTimeout(async () => {
            this._refreshDebounceTimer = null;
            try {
                await this.reloadData();
                this.renderTree();
            } catch (e) {
                console.error('Tree refresh failed:', e);
            }
        }, this._refreshDebounceMs);
    }
}

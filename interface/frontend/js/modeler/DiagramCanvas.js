/**
 * DiagramCanvas - Visual diagram showing instances as boxes with connections
 */
class DiagramCanvas {
    constructor(container, app) {
        this.container = container;
        this.app = app;
        this.currentNode = null;
        this.instances = []; // All instances with positions
        this.edges = []; // Containment and reference edges
    }

    /**
     * Show node in diagram
     */
    async showNode(node) {
        this.currentNode = node;
        await this.render();
    }

    /**
     * Render diagram based on current node
     */
    async render() {
        this.container.innerHTML = '';

        if (!this.currentNode) {
            this.container.innerHTML = '<div class="empty-state">Select an element to view diagram</div>';
            return;
        }

        // Phase 3: Full diagram with all instances and containment edges
        if (this.currentNode.type === 'instance' || this.currentNode.type === 'plugin') {
            await this.renderFullDiagram();
        } else if (this.currentNode.type === 'classifier') {
            await this.renderClassifierInfo();
        } else {
            this.container.innerHTML = '<div class="empty-state">Select an instance to view diagram</div>';
        }
    }

    /**
     * Render full diagram with all instances and edges
     */
    async renderFullDiagram() {
        const tree = this.app.unifiedTree && this.app.unifiedTree.treeData && this.app.unifiedTree.treeData.instances;
        if (!tree || !tree.roots || tree.roots.length === 0) {
            this.container.innerHTML = '<div class="empty-state">No instances to display. Create an instance to see the diagram.</div>';
            return;
        }

        // Create SVG container for edges
        const svg = document.createElementNS('http://www.w3.org/2000/svg', 'svg');
        svg.setAttribute('class', 'diagram-svg');
        svg.style.position = 'absolute';
        svg.style.top = '0';
        svg.style.left = '0';
        svg.style.width = '100%';
        svg.style.height = '100%';
        svg.style.pointerEvents = 'none';
        svg.style.zIndex = '1';

        // Create container for boxes
        const boxesContainer = document.createElement('div');
        boxesContainer.className = 'diagram-boxes-container';
        boxesContainer.style.position = 'relative';
        boxesContainer.style.zIndex = '2';

        // Flatten all instances and calculate positions
        const allInstances = [];
        const edges = [];
        let yOffset = 50;

        const processNode = (node, parentName = null, level = 0) => {
            const name = node.name || node;
            const type = node.type || '';
            const xOffset = 50 + level * 100;
            
            allInstances.push({
                name,
                type,
                x: xOffset,
                y: yOffset,
                level,
                data: node
            });

            if (parentName) {
                edges.push({ from: parentName, to: name });
            }

            yOffset += 120;

            if (node.children && Array.isArray(node.children)) {
                for (const child of node.children) {
                    processNode(child, name, level + 1);
                }
            }
        };

        for (const root of tree.roots) {
            processNode(root, null, 0);
        }

        // Create boxes
        for (const inst of allInstances) {
            const box = this.createDiagramBox(inst);
            box.style.position = 'absolute';
            box.style.left = `${inst.x}px`;
            box.style.top = `${inst.y}px`;
            boxesContainer.appendChild(box);
        }

        // Draw edges after boxes are positioned
        setTimeout(async () => {
            // Draw containment edges
            for (const edge of edges) {
                const fromBox = boxesContainer.querySelector(`[data-instance-name="${edge.from}"]`);
                const toBox = boxesContainer.querySelector(`[data-instance-name="${edge.to}"]`);
                if (fromBox && toBox) {
                    const line = this.createEdgeLine(fromBox, toBox, 'containment');
                    svg.appendChild(line);
                }
            }

            // Phase 4: Draw reference edges (non-containment)
            await this.drawReferenceEdges(svg, boxesContainer, allInstances);
        }, 50);

        this.container.appendChild(svg);
        this.container.appendChild(boxesContainer);
    }

    /**
     * Draw reference edges (non-containment references between instances)
     */
    async drawReferenceEdges(svg, boxesContainer, allInstances) {
        for (const inst of allInstances) {
            try {
                // Get features for this instance
                const features = await this.app.modelService.getObjectFeatures(inst.name);
                
                // Get classifier details to identify non-containment references
                const details = await this.app.metamodelService.getClassifierDetails(
                    this.app.currentPlugin,
                    inst.type
                );

                if (!details.references) continue;

                const nonContainmentRefs = details.references.filter(r => !r.containment);
                
                for (const ref of nonContainmentRefs) {
                    const feature = features.find(f => f.name === ref.name);
                    if (!feature || !feature.value) continue;

                    const targets = Array.isArray(feature.value) ? feature.value : [feature.value];
                    
                    for (const targetName of targets) {
                        const fromBox = boxesContainer.querySelector(`[data-instance-name="${inst.name}"]`);
                        const toBox = boxesContainer.querySelector(`[data-instance-name="${targetName}"]`);
                        
                        if (fromBox && toBox) {
                            const line = this.createEdgeLine(fromBox, toBox, 'reference');
                            // Add reference name as label
                            const label = this.createEdgeLabel(fromBox, toBox, ref.name);
                            svg.appendChild(line);
                            if (label) svg.appendChild(label);
                        }
                    }
                }
            } catch (error) {
                console.warn(`Failed to load references for ${inst.name}:`, error);
            }
        }
    }

    /**
     * Create edge label (reference name)
     */
    createEdgeLabel(fromBox, toBox, text) {
        const fromRect = fromBox.getBoundingClientRect();
        const toRect = toBox.getBoundingClientRect();
        const containerRect = this.container.getBoundingClientRect();

        const x1 = fromRect.left - containerRect.left + fromRect.width / 2;
        const y1 = fromRect.bottom - containerRect.top;
        const x2 = toRect.left - containerRect.left + toRect.width / 2;
        const y2 = toRect.top - containerRect.top;

        const midX = (x1 + x2) / 2;
        const midY = (y1 + y2) / 2;

        const textEl = document.createElementNS('http://www.w3.org/2000/svg', 'text');
        textEl.setAttribute('x', midX);
        textEl.setAttribute('y', midY - 5);
        textEl.setAttribute('text-anchor', 'middle');
        textEl.setAttribute('fill', '#9333ea');
        textEl.setAttribute('font-size', '11');
        textEl.setAttribute('font-weight', '500');
        textEl.textContent = text;

        return textEl;
    }

    /**
     * Create diagram box for an instance
     */
    createDiagramBox(inst) {
        const box = document.createElement('div');
        box.className = 'diagram-box';
        box.dataset.instanceName = inst.name;
        box.dataset.instanceType = inst.type;

        const isSelected = this.currentNode && this.currentNode.instance === inst.name;
        if (isSelected) {
            box.classList.add('diagram-box-selected');
        }

        const icon = document.createElement('div');
        icon.className = 'diagram-box-icon';
        icon.textContent = this.getIconForType(inst.type);

        const title = document.createElement('div');
        title.className = 'diagram-box-title';
        title.textContent = `"${inst.name}"`;

        const type = document.createElement('div');
        type.className = 'diagram-box-type';
        type.textContent = inst.type;

        box.appendChild(icon);
        box.appendChild(title);
        box.appendChild(type);

        box.addEventListener('click', () => {
            this.onBoxClick(inst);
        });

        return box;
    }

    /**
     * Create edge line between two boxes
     */
    createEdgeLine(fromBox, toBox, edgeType = 'containment') {
        const fromRect = fromBox.getBoundingClientRect();
        const toRect = toBox.getBoundingClientRect();
        const containerRect = this.container.getBoundingClientRect();

        const x1 = fromRect.left - containerRect.left + fromRect.width / 2;
        const y1 = fromRect.bottom - containerRect.top;
        const x2 = toRect.left - containerRect.left + toRect.width / 2;
        const y2 = toRect.top - containerRect.top;

        const line = document.createElementNS('http://www.w3.org/2000/svg', 'line');
        line.setAttribute('x1', x1);
        line.setAttribute('y1', y1);
        line.setAttribute('x2', x2);
        line.setAttribute('y2', y2);
        line.setAttribute('stroke', edgeType === 'containment' ? '#2563eb' : '#9333ea');
        line.setAttribute('stroke-width', edgeType === 'containment' ? '2' : '1.5');
        line.setAttribute('stroke-dasharray', edgeType === 'reference' ? '5,5' : '0');
        line.setAttribute('marker-end', 'url(#arrowhead)');

        return line;
    }

    /**
     * Handle box click
     */
    onBoxClick(inst) {
        if (this.app && this.app.onNodeSelect) {
            this.app.onNodeSelect({
                type: 'instance',
                plugin: this.app.currentPlugin,
                instance: inst.name,
                instanceType: inst.type,
                classifier: inst.type,
                data: inst.data
            });
        }
    }

    /**
     * Render selected instance as a card with children
     */
    async renderInstanceCard() {
        const wrapper = document.createElement('div');
        wrapper.className = 'diagram-wrapper';

        // Main instance card
        const mainCard = this.createInstanceCard(this.currentNode, true);
        wrapper.appendChild(mainCard);

        // Get children from tree data
        const children = await this.getInstanceChildren(this.currentNode.instance);
        
        if (children && children.length > 0) {
            const childrenContainer = document.createElement('div');
            childrenContainer.className = 'diagram-children-container';
            
            for (const child of children) {
                const childCard = this.createInstanceCard({
                    instance: child.name,
                    instanceType: child.type,
                    type: 'instance',
                    plugin: this.currentNode.plugin,
                    data: child
                }, false);
                childrenContainer.appendChild(childCard);
            }
            
            wrapper.appendChild(childrenContainer);
        }

        this.container.appendChild(wrapper);
    }

    /**
     * Create instance card element
     */
    createInstanceCard(node, isMain = false) {
        const card = document.createElement('div');
        card.className = isMain ? 'instance-card instance-card-main' : 'instance-card instance-card-child';
        card.dataset.instance = node.instance;

        const header = document.createElement('div');
        header.className = 'instance-card-header';

        const icon = document.createElement('div');
        icon.className = 'instance-card-icon';
        icon.textContent = this.getIconForType(node.instanceType);

        const title = document.createElement('div');
        title.className = 'instance-card-title';
        title.textContent = `"${node.instance}"`;

        const type = document.createElement('div');
        type.className = 'instance-card-type';
        type.textContent = node.instanceType;

        header.appendChild(icon);
        header.appendChild(title);
        header.appendChild(type);
        card.appendChild(header);

        // Click handler
        card.addEventListener('click', () => {
            this.onCardClick(node);
        });

        return card;
    }

    /**
     * Get icon for instance type
     */
    getIconForType(typeName) {
        const iconMap = {
            'Library': '📚',
            'Book': '📕',
            'Writer': '✍️',
            'Member': '👤',
            'Loan': '📋',
            'BookCategory': '📁'
        };
        return iconMap[typeName] || '📦';
    }

    /**
     * Get children of an instance from tree data
     */
    async getInstanceChildren(instanceName) {
        const tree = this.app.unifiedTree && this.app.unifiedTree.treeData && this.app.unifiedTree.treeData.instances;
        if (!tree || !tree.roots) return [];

        const findInstance = (nodes, name) => {
            for (const node of nodes) {
                const nodeName = node.name || node;
                if (nodeName === name) {
                    return node.children || [];
                }
                if (node.children && Array.isArray(node.children)) {
                    const found = findInstance(node.children, name);
                    if (found) return found;
                }
            }
            return null;
        };

        return findInstance(tree.roots, instanceName) || [];
    }

    /**
     * Render classifier info (metamodel view)
     */
    async renderClassifierInfo() {
        const card = document.createElement('div');
        card.className = 'classifier-info-card';

        const title = document.createElement('h3');
        title.textContent = this.currentNode.classifier || 'Classifier';
        card.appendChild(title);

        const details = await this.app.metamodelService.getClassifierDetails(
            this.currentNode.plugin,
            this.currentNode.classifier
        );

        if (details.containmentRefs && details.containmentRefs.length > 0) {
            const section = document.createElement('div');
            section.innerHTML = '<h4>Can contain:</h4>';
            const list = document.createElement('ul');
            for (const ref of details.containmentRefs) {
                const item = document.createElement('li');
                item.textContent = `${ref.name}: ${ref.type} [${ref.lowerBound}..${ref.upperBound === -1 ? '*' : ref.upperBound}]`;
                list.appendChild(item);
            }
            section.appendChild(list);
            card.appendChild(section);
        }

        this.container.appendChild(card);
    }

    /**
     * Handle card click
     */
    onCardClick(node) {
        if (this.app && this.app.onNodeSelect) {
            this.app.onNodeSelect(node);
        }
    }

    /**
     * Refresh diagram
     */
    async refresh() {
        await this.render();
    }
}

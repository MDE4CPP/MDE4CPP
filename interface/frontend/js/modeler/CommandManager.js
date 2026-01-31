/**
 * CommandManager - Undo/redo functionality using command pattern
 */

/**
 * Base Command class
 */
class Command {
    constructor(description) {
        this.description = description;
    }

    execute() {
        throw new Error('execute() must be implemented');
    }

    undo() {
        throw new Error('undo() must be implemented');
    }

    getDescription() {
        return this.description;
    }
}

/**
 * CreateInstanceCommand
 */
class CreateInstanceCommand extends Command {
    constructor(app, pluginName, parentName, className, instanceName, referenceID, properties = {}) {
        super(`Create ${instanceName} (${className})`);
        this.app = app;
        this.pluginName = pluginName;
        this.parentName = parentName;
        this.className = className;
        this.instanceName = instanceName;
        this.referenceID = referenceID;
        this.properties = properties;
    }

    async execute() {
        try {
            if (this.parentName) {
                await this.app.modelService.createChildInstance(
                    this.pluginName,
                    this.parentName,
                    this.className,
                    this.instanceName,
                    this.referenceID
                );
            } else {
                await this.app.modelService.createRootInstance(
                    this.pluginName,
                    this.className,
                    this.instanceName,
                    this.properties
                );
            }
            // Refresh tree
            if (this.app.unifiedTree) {
                await this.app.unifiedTree.refresh();
            }
        } catch (error) {
            console.error('CreateInstanceCommand execute failed:', error);
            throw error;
        }
    }

    async undo() {
        try {
            await this.app.modelService.deleteInstance(this.pluginName, this.instanceName);
            // Refresh tree
            if (this.app.unifiedTree) {
                await this.app.unifiedTree.refresh();
            }
        } catch (error) {
            console.error('CreateInstanceCommand undo failed:', error);
            throw error;
        }
    }
}

/**
 * DeleteInstanceCommand
 */
class DeleteInstanceCommand extends Command {
    constructor(app, pluginName, instanceId, instanceData) {
        super(`Delete ${instanceId}`);
        this.app = app;
        this.pluginName = pluginName;
        this.instanceId = instanceId;
        this.instanceData = instanceData; // Store for undo
    }

    async execute() {
        try {
            // Store data before deletion for undo
            if (!this.instanceData) {
                try {
                    this.instanceData = await this.app.modelService.getObjectDetails(this.instanceId);
                } catch (e) {
                    console.warn('Could not store instance data for undo:', e);
                }
            }
            await this.app.modelService.deleteInstance(this.pluginName, this.instanceId);
            // Refresh tree
            if (this.app.unifiedTree) {
                await this.app.unifiedTree.refresh();
            }
        } catch (error) {
            console.error('DeleteInstanceCommand execute failed:', error);
            throw error;
        }
    }

    async undo() {
        // Note: Full undo of deletion would require recreating the instance with all its children
        // This is a simplified version - in production, you'd want to store full instance tree
        alert('Undo delete not fully implemented - would require recreating instance tree');
    }
}

/**
 * UpdateAttributeCommand
 */
class UpdateAttributeCommand extends Command {
    constructor(app, pluginName, instanceId, attributeName, oldValue, newValue) {
        super(`Update ${attributeName}`);
        this.app = app;
        this.pluginName = pluginName;
        this.instanceId = instanceId;
        this.attributeName = attributeName;
        this.oldValue = oldValue;
        this.newValue = newValue;
    }

    async execute() {
        try {
            await this.app.modelService.updateAttribute(
                this.pluginName,
                this.instanceId,
                this.attributeName,
                this.newValue
            );
        } catch (error) {
            console.error('UpdateAttributeCommand execute failed:', error);
            throw error;
        }
    }

    async undo() {
        try {
            await this.app.modelService.updateAttribute(
                this.pluginName,
                this.instanceId,
                this.attributeName,
                this.oldValue
            );
        } catch (error) {
            console.error('UpdateAttributeCommand undo failed:', error);
            throw error;
        }
    }
}

/**
 * CommandManager
 */
class CommandManager {
    constructor(maxHistory = 50) {
        this.undoStack = [];
        this.redoStack = [];
        this.maxHistory = maxHistory;
        this.listeners = [];
    }

    /**
     * Execute command
     */
    async execute(command) {
        try {
            await command.execute();
            this.undoStack.push(command);
            
            // Limit stack size
            if (this.undoStack.length > this.maxHistory) {
                this.undoStack.shift();
            }
            
            // Clear redo stack when new command executed
            this.redoStack = [];
            
            this.notifyListeners();
        } catch (error) {
            console.error('Command execution failed:', error);
            throw error;
        }
    }

    /**
     * Undo last command
     */
    async undo() {
        if (!this.canUndo()) {
            return;
        }

        const command = this.undoStack.pop();
        try {
            await command.undo();
            this.redoStack.push(command);
            this.notifyListeners();
        } catch (error) {
            console.error('Undo failed:', error);
            // Put command back on stack
            this.undoStack.push(command);
            throw error;
        }
    }

    /**
     * Redo last undone command
     */
    async redo() {
        if (!this.canRedo()) {
            return;
        }

        const command = this.redoStack.pop();
        try {
            await command.execute();
            this.undoStack.push(command);
            this.notifyListeners();
        } catch (error) {
            console.error('Redo failed:', error);
            // Put command back on redo stack
            this.redoStack.push(command);
            throw error;
        }
    }

    /**
     * Check if undo is possible
     */
    canUndo() {
        return this.undoStack.length > 0;
    }

    /**
     * Check if redo is possible
     */
    canRedo() {
        return this.redoStack.length > 0;
    }

    /**
     * Get description of what would be undone
     */
    getUndoDescription() {
        if (!this.canUndo()) {
            return null;
        }
        return this.undoStack[this.undoStack.length - 1].getDescription();
    }

    /**
     * Get description of what would be redone
     */
    getRedoDescription() {
        if (!this.canRedo()) {
            return null;
        }
        return this.redoStack[this.redoStack.length - 1].getDescription();
    }

    /**
     * Add listener for stack changes
     */
    addListener(listener) {
        this.listeners.push(listener);
    }

    /**
     * Remove listener
     */
    removeListener(listener) {
        const index = this.listeners.indexOf(listener);
        if (index > -1) {
            this.listeners.splice(index, 1);
        }
    }

    /**
     * Notify listeners of stack changes
     */
    notifyListeners() {
        this.listeners.forEach(listener => {
            try {
                listener({
                    canUndo: this.canUndo(),
                    canRedo: this.canRedo(),
                    undoDescription: this.getUndoDescription(),
                    redoDescription: this.getRedoDescription()
                });
            } catch (error) {
                console.error('Listener error:', error);
            }
        });
    }

    /**
     * Clear all history
     */
    clear() {
        this.undoStack = [];
        this.redoStack = [];
        this.notifyListeners();
    }
}

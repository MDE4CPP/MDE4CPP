/**
 * Terminal File Upload Component
 * Handles file uploads to terminal workspace
 */

class TerminalFileUpload {
    constructor(sessionId) {
        this.sessionId = sessionId;
        this.uploadedFiles = [];
        this.apiBaseUrl = window.API_BASE_URL || 'http://localhost:8000/api/v1';
        
        this.initializeUpload();
    }
    
    /**
     * Initialize upload component
     */
    initializeUpload() {
        const fileInput = document.getElementById('model-file-input');
        const uploadBtn = document.getElementById('upload-btn');
        const uploadStatus = document.getElementById('upload-status');
        
        if (!fileInput || !uploadBtn) {
            console.error('Upload elements not found');
            return;
        }
        
        // Click button to trigger file input
        uploadBtn.addEventListener('click', () => {
            fileInput.click();
        });
        
        // Handle file selection
        fileInput.addEventListener('change', (e) => {
            const file = e.target.files[0];
            if (file) {
                this.uploadFile(file);
            }
        });
        
        // Load existing files
        this.loadUploadedFiles();
    }
    
    /**
     * Upload file to terminal workspace
     */
    async uploadFile(file) {
        const uploadStatus = document.getElementById('upload-status');
        const uploadBtn = document.getElementById('upload-btn');
        
        // Validate file type
        const ext = file.name.toLowerCase().split('.').pop();
        if (ext !== 'ecore' && ext !== 'uml') {
            this.showStatus('error', 'Only .ecore and .uml files are allowed');
            return;
        }
        
        // Validate file size (50MB max)
        const maxSize = 50 * 1024 * 1024;
        if (file.size > maxSize) {
            this.showStatus('error', `File size exceeds maximum (50MB). File size: ${this.formatFileSize(file.size)}`);
            return;
        }
        
        // Show uploading status
        this.showStatus('uploading', `Uploading ${file.name}...`);
        uploadBtn.disabled = true;
        
        try {
            const formData = new FormData();
            formData.append('file', file);
            
            const response = await fetch(`${this.apiBaseUrl}/terminal/${this.sessionId}/upload`, {
                method: 'POST',
                body: formData
            });
            
            if (!response.ok) {
                const error = await response.json();
                throw new Error(error.error?.message || 'Upload failed');
            }
            
            const result = await response.json();
            
            // Add to uploaded files list
            this.uploadedFiles.push({
                name: result.file.name,
                originalName: result.file.originalName,
                size: result.file.size,
                path: result.workspacePath,
                uploadedAt: result.file.uploadedAt
            });
            
            // Update UI
            this.updateUploadedFilesList();
            this.showStatus('success', `File uploaded successfully: ${result.file.name}`);
            
            // Notify terminal (if terminal instance is available)
            this.notifyTerminal(result);
            
            // Reset file input
            document.getElementById('model-file-input').value = '';
            
        } catch (error) {
            console.error('Upload error:', error);
            this.showStatus('error', `Upload failed: ${error.message}`);
        } finally {
            uploadBtn.disabled = false;
        }
    }
    
    /**
     * Show upload status
     */
    showStatus(type, message) {
        const uploadStatus = document.getElementById('upload-status');
        if (!uploadStatus) return;
        
        uploadStatus.textContent = message;
        uploadStatus.className = `upload-status upload-status-${type}`;
        
        // Clear status after 5 seconds for success/error
        if (type === 'success' || type === 'error') {
            setTimeout(() => {
                uploadStatus.textContent = '';
                uploadStatus.className = 'upload-status';
            }, 5000);
        }
    }
    
    /**
     * Update uploaded files list
     */
    updateUploadedFilesList() {
        const filesContent = document.getElementById('uploaded-files-content');
        if (!filesContent) return;
        
        if (this.uploadedFiles.length === 0) {
            filesContent.innerHTML = '<p class="no-files">No files uploaded yet</p>';
            return;
        }
        
        const filesHtml = this.uploadedFiles.map(file => `
            <div class="uploaded-file-item">
                <div class="file-icon">📄</div>
                <div class="file-info">
                    <div class="file-name">${this.escapeHtml(file.name)}</div>
                    <div class="file-details">
                        <span class="file-size">${this.formatFileSize(file.size)}</span>
                        <span class="file-path">${this.escapeHtml(file.path)}</span>
                    </div>
                </div>
            </div>
        `).join('');
        
        filesContent.innerHTML = filesHtml;
    }
    
    /**
     * Load uploaded files from server
     */
    async loadUploadedFiles() {
        try {
            const response = await fetch(`${this.apiBaseUrl}/terminal/${this.sessionId}/files`);
            if (response.ok) {
                const result = await response.json();
                if (result.files && result.files.model) {
                    this.uploadedFiles = result.files.model.map(file => ({
                        name: file.name,
                        size: file.size,
                        path: `model/${file.name}`,
                        uploadedAt: file.modifiedAt
                    }));
                    this.updateUploadedFilesList();
                }
            }
        } catch (error) {
            console.error('Error loading uploaded files:', error);
        }
    }
    
    /**
     * Notify terminal about uploaded file
     */
    notifyTerminal(result) {
        // Try to get terminal instance from window
        if (window.terminalInstance && window.terminalInstance.terminal) {
            const message = `\r\n\x1b[32m✓ File uploaded successfully\x1b[0m\r\n`;
            const fileInfo = `  File: ${result.file.name}\r\n`;
            const filePath = `  Path: ${result.workspacePath}\r\n`;
            const instruction = `  Use: cd /workspace && ls model/\r\n\r\n`;
            
            window.terminalInstance.terminal.write(message + fileInfo + filePath + instruction);
            
            // Auto-scroll terminal
            if (window.terminalInstance.autoScrollEnabled) {
                setTimeout(() => window.terminalInstance.scrollToBottom(), 50);
            }
        }
    }
    
    /**
     * Format file size
     */
    formatFileSize(bytes) {
        if (bytes === 0) return '0 Bytes';
        const k = 1024;
        const sizes = ['Bytes', 'KB', 'MB', 'GB'];
        const i = Math.floor(Math.log(bytes) / Math.log(k));
        return Math.round(bytes / Math.pow(k, i) * 100) / 100 + ' ' + sizes[i];
    }
    
    /**
     * Escape HTML
     */
    escapeHtml(text) {
        const div = document.createElement('div');
        div.textContent = text;
        return div.innerHTML;
    }
    
    /**
     * Update session ID (if session changes)
     */
    setSessionId(sessionId) {
        this.sessionId = sessionId;
        this.loadUploadedFiles();
    }
}

// Make TerminalFileUpload available globally
window.TerminalFileUpload = TerminalFileUpload;

// Global instance (will be initialized when session ID is available)
window.terminalFileUpload = null;

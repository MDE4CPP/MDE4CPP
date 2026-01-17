class BuildApp {
    constructor() {
        this.currentBuildId = null;
        this.statusInterval = null;
        this.initializeEventListeners();
    }

    initializeEventListeners() {
        const dropZone = document.getElementById('drop-zone');
        const fileInput = document.getElementById('file-input');
        const fileButton = document.querySelector('.file-button');

        // Click to browse
        dropZone.addEventListener('click', () => fileInput.click());
        fileButton.addEventListener('click', (e) => {
            e.stopPropagation();
            fileInput.click();
        });

        // File input change
        fileInput.addEventListener('change', (e) => {
            if (e.target.files.length > 0) {
                this.handleFile(e.target.files[0]);
            }
        });

        // Drag and drop
        dropZone.addEventListener('dragover', (e) => {
            e.preventDefault();
            ui.setDragOver(dropZone, true);
        });

        dropZone.addEventListener('dragleave', () => {
            ui.setDragOver(dropZone, false);
        });

        dropZone.addEventListener('drop', (e) => {
            e.preventDefault();
            ui.setDragOver(dropZone, false);

            if (e.dataTransfer.files.length > 0) {
                this.handleFile(e.dataTransfer.files[0]);
            }
        });

        // Download buttons
        document.getElementById('download-all-btn').addEventListener('click', () => {
            this.download('zip');
        });

        document.getElementById('download-dlls-btn').addEventListener('click', () => {
            this.download('dll');
        });

        document.getElementById('download-exes-btn').addEventListener('click', () => {
            this.download('executable');
        });

        // Retry button
        document.getElementById('retry-btn').addEventListener('click', () => {
            ui.showUpload();
            fileInput.value = '';
        });
    }

    async handleFile(file) {
        // Validate file type
        const ext = file.name.split('.').pop().toLowerCase();
        if (ext !== 'ecore' && ext !== 'uml') {
            ui.showError('Invalid file type. Please upload a .ecore or .uml file.');
            return;
        }

        try {
            // Upload file
            const result = await api.uploadFile(file);
            this.currentBuildId = result.buildId;

            // Show status section
            ui.showStatus(this.currentBuildId);

            // Start polling for status
            this.startStatusPolling();
        } catch (error) {
            ui.showError(`Upload failed: ${error.message}`);
        }
    }

    startStatusPolling() {
        if (this.statusInterval) {
            clearInterval(this.statusInterval);
        }

        // Poll immediately
        this.checkStatus();

        // Then poll every 2 seconds
        this.statusInterval = setInterval(() => {
            this.checkStatus();
        }, 2000);
    }

    async checkStatus() {
        if (!this.currentBuildId) return;

        try {
            const status = await api.getStatus(this.currentBuildId);
            ui.updateStatus(status);

            // Show logs if building
            if (status.status === 'building') {
                try {
                    const logs = await api.getLogs(this.currentBuildId, 50);
                    ui.showLogs(logs.logs);
                } catch (error) {
                    console.error('Failed to fetch logs:', error);
                }
            }

            // If completed, show download section
            if (status.status === 'completed') {
                clearInterval(this.statusInterval);
                this.loadDownloadFiles();
            }

            // If failed, stop polling
            if (status.status === 'failed') {
                clearInterval(this.statusInterval);
                ui.showError(status.message || 'Build failed');
            }
        } catch (error) {
            console.error('Failed to check status:', error);
        }
    }

    async loadDownloadFiles() {
        try {
            const result = await api.getFiles(this.currentBuildId);
            ui.showDownload(result.files);
        } catch (error) {
            console.error('Failed to load files:', error);
        }
    }

    download(fileType) {
        if (!this.currentBuildId) return;
        api.downloadFile(this.currentBuildId, fileType);
    }
}

// Initialize app when DOM is loaded
document.addEventListener('DOMContentLoaded', () => {
    new BuildApp();
});

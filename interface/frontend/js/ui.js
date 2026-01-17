class UI {
    constructor() {
        this.uploadSection = document.getElementById('upload-section');
        this.statusSection = document.getElementById('status-section');
        this.downloadSection = document.getElementById('download-section');
        this.errorSection = document.getElementById('error-section');
        
        this.statusBadge = document.getElementById('status-badge');
        this.statusText = document.getElementById('status-text');
        this.progressFill = document.getElementById('progress-fill');
        this.progressText = document.getElementById('progress-text');
        this.stageText = document.getElementById('stage-text');
        this.messageText = document.getElementById('message-text');
        this.buildId = document.getElementById('build-id');
        this.downloadFiles = document.getElementById('download-files');
    }

    showUpload() {
        this.uploadSection.classList.remove('hidden');
        this.statusSection.classList.add('hidden');
        this.downloadSection.classList.add('hidden');
        this.errorSection.classList.add('hidden');
    }

    showStatus(buildId) {
        this.uploadSection.classList.add('hidden');
        this.statusSection.classList.remove('hidden');
        this.downloadSection.classList.add('hidden');
        this.errorSection.classList.add('hidden');
        this.buildId.textContent = buildId;
    }

    updateStatus(status) {
        this.statusText.textContent = status.status || 'Unknown';
        this.progressFill.style.width = `${status.progress || 0}%`;
        this.progressText.textContent = `${status.progress || 0}%`;
        this.stageText.textContent = status.stage || '-';
        this.messageText.textContent = status.message || '-';

        // Update badge
        this.statusBadge.className = 'status-badge';
        if (status.status === 'building') {
            this.statusBadge.classList.add('building');
        } else if (status.status === 'completed') {
            this.statusBadge.classList.add('completed');
        } else if (status.status === 'failed') {
            this.statusBadge.classList.add('failed');
        }
    }

    showDownload(files) {
        this.downloadSection.classList.remove('hidden');
        
        // Clear existing files
        this.downloadFiles.innerHTML = '';

        // Add DLL files
        if (files.dlls && files.dlls.length > 0) {
            files.dlls.forEach(file => {
                const fileItem = this.createFileItem(file.name, file.sizeFormatted, 'dll');
                this.downloadFiles.appendChild(fileItem);
            });
        }

        // Add executable files
        if (files.executables && files.executables.length > 0) {
            files.executables.forEach(file => {
                const fileItem = this.createFileItem(file.name, file.sizeFormatted, 'exe');
                this.downloadFiles.appendChild(fileItem);
            });
        }
    }

    createFileItem(name, size, type) {
        const item = document.createElement('div');
        item.className = 'file-item';
        
        const icon = type === 'dll' ? '📚' : '⚙️';
        
        item.innerHTML = `
            <div class="file-info-group">
                <div class="file-name">${icon} ${name}</div>
                <div class="file-size">${size}</div>
            </div>
        `;
        
        return item;
    }

    showError(message) {
        this.errorSection.classList.remove('hidden');
        document.getElementById('error-message').textContent = message;
        this.statusSection.classList.add('hidden');
        this.downloadSection.classList.add('hidden');
    }

    showLogs(logs) {
        const logsContainer = document.getElementById('logs-container');
        const logsContent = document.getElementById('logs-content');
        
        if (logs && logs.length > 0) {
            logsContainer.classList.remove('hidden');
            const recentLogs = logs.slice(-50).map(log => {
                const timestamp = new Date(log.timestamp).toLocaleTimeString();
                return `[${timestamp}] ${log.message}`;
            }).join('\n');
            logsContent.textContent = recentLogs;
            logsContent.scrollTop = logsContent.scrollHeight;
        }
    }

    setDragOver(element, isDragging) {
        if (isDragging) {
            element.classList.add('drag-over');
        } else {
            element.classList.remove('drag-over');
        }
    }
}

const ui = new UI();

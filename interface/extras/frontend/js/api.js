const API_BASE_URL = 'http://localhost:8001/api/v1';

class BuildAPI {
    async uploadFile(file) {
        const formData = new FormData();
        formData.append('file', file);

        const response = await fetch(`${API_BASE_URL}/build`, {
            method: 'POST',
            body: formData
        });

        if (!response.ok) {
            const error = await response.json();
            throw new Error(error.error?.message || 'Upload failed');
        }

        return await response.json();
    }

    async getStatus(buildId) {
        const response = await fetch(`${API_BASE_URL}/build/${buildId}/status`);

        if (!response.ok) {
            const error = await response.json();
            throw new Error(error.error?.message || 'Failed to get status');
        }

        return await response.json();
    }

    async getFiles(buildId) {
        const response = await fetch(`${API_BASE_URL}/build/${buildId}/files`);

        if (!response.ok) {
            const error = await response.json();
            throw new Error(error.error?.message || 'Failed to get files');
        }

        return await response.json();
    }

    async downloadFile(buildId, fileType) {
        const url = `${API_BASE_URL}/build/${buildId}/download/${fileType}`;
        window.location.href = url;
    }

    async getLogs(buildId, tail = null) {
        const url = `${API_BASE_URL}/build/${buildId}/logs${tail ? `?tail=${tail}` : ''}`;
        const response = await fetch(url);

        if (!response.ok) {
            const error = await response.json();
            throw new Error(error.error?.message || 'Failed to get logs');
        }

        return await response.json();
    }
}

const api = new BuildAPI();

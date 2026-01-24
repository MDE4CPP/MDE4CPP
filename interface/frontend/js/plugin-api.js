const API_BASE_URL = 'http://localhost:8001/api/v1';

// Helper to safely parse JSON response, handling HTML error pages
async function safeJsonParse(response) {
    const contentType = response.headers.get('content-type') || '';
    if (contentType.includes('application/json')) {
        try {
            return await response.json();
        } catch (e) {
            const text = await response.text();
            throw new Error(`Failed to parse JSON: ${text.substring(0, 200)}`);
        }
    } else {
        const text = await response.text();
        throw new Error(`Server returned ${response.status} ${response.statusText}. Expected JSON but got ${contentType}. Response: ${text.substring(0, 200)}`);
    }
}

class PluginAPI {
    async getPlugins() {
        const response = await fetch(`${API_BASE_URL}/plugins`);
        if (!response.ok) {
            const error = await safeJsonParse(response);
            throw new Error(error.error?.message || `HTTP ${response.status}: Failed to get plugins`);
        }
        const data = await response.json();
        return data.plugins || [];
    }

    async getPluginStructure(pluginName) {
        const response = await fetch(`${API_BASE_URL}/plugins/${encodeURIComponent(pluginName)}/structure`);
        if (!response.ok) {
            const error = await safeJsonParse(response);
            throw new Error(error.error?.message || `HTTP ${response.status}: Failed to get plugin structure`);
        }
        return await response.json();
    }

    async getClassifiers(pluginName) {
        const response = await fetch(`${API_BASE_URL}/plugins/${encodeURIComponent(pluginName)}/classifiers`);
        if (!response.ok) {
            const error = await safeJsonParse(response);
            throw new Error(error.error?.message || `HTTP ${response.status}: Failed to get classifiers`);
        }
        const data = await response.json();
        return data.classifiers || [];
    }

    async getClassifierDetails(pluginName, className) {
        const response = await fetch(`${API_BASE_URL}/plugins/${encodeURIComponent(pluginName)}/classifiers/${encodeURIComponent(className)}`);
        if (!response.ok) {
            const error = await safeJsonParse(response);
            throw new Error(error.error?.message || `HTTP ${response.status}: Failed to get classifier details`);
        }
        return await response.json();
    }

    async createObject(pluginName, className, properties = {}) {
        const response = await fetch(`${API_BASE_URL}/plugins/${encodeURIComponent(pluginName)}/objects`, {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ className, ...properties })
        });
        if (!response.ok) {
            const error = await safeJsonParse(response);
            throw new Error(error.error?.message || `HTTP ${response.status}: Failed to create object`);
        }
        const data = await response.json();
        return data.object;
    }

    async createFromClassifier(pluginName, className, instanceName, properties = {}) {
        const response = await fetch(`${API_BASE_URL}/plugins/${encodeURIComponent(pluginName)}/classifiers/${encodeURIComponent(className)}/create`, {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ instanceName, properties })
        });
        if (!response.ok) {
            const error = await safeJsonParse(response);
            throw new Error(error.error?.message || `HTTP ${response.status}: Failed to create object from classifier`);
        }
        const data = await response.json();
        return data.object;
    }

    async getObjectAttributes(objectId) {
        const response = await fetch(`${API_BASE_URL}/plugins/objects/${encodeURIComponent(objectId)}/attributes`);
        if (!response.ok) {
            const error = await safeJsonParse(response);
            throw new Error(error.error?.message || `HTTP ${response.status}: Failed to get object attributes`);
        }
        const data = await response.json();
        return data.attributes || [];
    }

    async getObjectOperations(objectId) {
        const response = await fetch(`${API_BASE_URL}/plugins/objects/${encodeURIComponent(objectId)}/operations`);
        if (!response.ok) {
            const error = await safeJsonParse(response);
            throw new Error(error.error?.message || `HTTP ${response.status}: Failed to get object operations`);
        }
        const data = await response.json();
        return data.operations || [];
    }

    async getObjectFeatures(objectId) {
        const response = await fetch(`${API_BASE_URL}/plugins/objects/${encodeURIComponent(objectId)}/features`);
        if (!response.ok) {
            const error = await safeJsonParse(response);
            throw new Error(error.error?.message || `HTTP ${response.status}: Failed to get object features`);
        }
        const data = await response.json();
        return data.features || [];
    }

    async getFeatureValue(objectId, featureName) {
        const response = await fetch(`${API_BASE_URL}/plugins/objects/${encodeURIComponent(objectId)}/get/${encodeURIComponent(featureName)}`);
        if (!response.ok) {
            const error = await safeJsonParse(response);
            throw new Error(error.error?.message || `HTTP ${response.status}: Failed to get feature value`);
        }
        const data = await response.json();
        return data.value;
    }

    async setFeatureValue(objectId, featureName, value) {
        const response = await fetch(`${API_BASE_URL}/plugins/objects/${encodeURIComponent(objectId)}/set/${encodeURIComponent(featureName)}`, {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ value })
        });
        if (!response.ok) {
            const error = await safeJsonParse(response);
            throw new Error(error.error?.message || `HTTP ${response.status}: Failed to set feature value`);
        }
        const data = await response.json();
        return data.object;
    }

    async getObjectDetails(objectId) {
        const response = await fetch(`${API_BASE_URL}/plugins/objects/${encodeURIComponent(objectId)}`);
        if (!response.ok) {
            const error = await safeJsonParse(response);
            throw new Error(error.error?.message || `HTTP ${response.status}: Failed to get object details`);
        }
        const data = await response.json();
        return data.object;
    }

    async listObjects() {
        const response = await fetch(`${API_BASE_URL}/plugins/objects`);
        if (!response.ok) {
            const error = await safeJsonParse(response);
            throw new Error(error.error?.message || `HTTP ${response.status}: Failed to list objects`);
        }
        const data = await response.json();
        return data.objects || [];
    }

    async deleteObject(objectId) {
        const response = await fetch(`${API_BASE_URL}/plugins/objects/${encodeURIComponent(objectId)}`, {
            method: 'DELETE'
        });
        if (!response.ok) {
            const error = await safeJsonParse(response);
            throw new Error(error.error?.message || `HTTP ${response.status}: Failed to delete object`);
        }
        return { success: true };
    }
}

const pluginAPI = new PluginAPI();

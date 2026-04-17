/**
 * ModelJsonViewer - Renders model JSON/XMI in the central panel with download support.
 *
 * Usage:
 *   const viewer = new ModelJsonViewer(containerEl, appInstance);
 *   await viewer.show();   // generate and display JSON/XMI
 *   viewer.hide();          // remove viewer and hand panel back to diagram
 */
class ModelJsonViewer {
    constructor(container, app) {
        this.container = container;
        this.app = app;
        this.jsonData = null;
        this.jsonString = '';
        this.xmiString = '';
        this.currentFormat = 'json'; // 'json' or 'xmi'
        this.isVisible = false;
    }

    // ---- Public API ----

    /** Generate JSON and render it */
    async show() {
        this.isVisible = true;
        await this.render();
    }

    /** Clear viewer */
    hide() {
        this.isVisible = false;
        this.container.innerHTML = '';
    }

    /** Re-generate JSON (e.g. after model changes) */
    async refresh() {
        if (this.isVisible) await this.render();
    }

    // ---- Internal ----

    async render() {
        if (!this.isVisible) return;
        this.container.innerHTML = '';

        if (!this.app.currentPlugin) {
            this.container.innerHTML = '<div class="json-empty-state">Select a plugin to generate JSON</div>';
            return;
        }

        // Loading indicator
        this.container.innerHTML = '<div class="json-loading">Generating model JSON…</div>';

        try {
            this.jsonData = await ModelSerializer.serializeModel(
                this.app.currentPlugin,
                this.app.metamodelService,
                this.app.modelService
            );
            this.jsonString = ModelSerializer.formatJson(this.jsonData);
            // Generate XMI from JSON
            this.xmiString = XMISerializer.serializeToXMI(this.jsonData);
        } catch (err) {
            console.error('ModelJsonViewer: serialization failed', err);
            this.container.innerHTML = `<div class="json-error">Failed to generate model: ${err.message}</div>`;
            return;
        }

        // Build viewer DOM
        this.container.innerHTML = '';

        const wrapper = document.createElement('div');
        wrapper.className = 'json-viewer-container';

        // Header bar
        const header = document.createElement('div');
        header.className = 'json-viewer-header';

        const title = document.createElement('span');
        title.className = 'json-viewer-title';
        const classCount = Object.keys(this.jsonData.metamodel?.classes || {}).length;
        const enumCount = Object.keys(this.jsonData.metamodel?.enums || {}).length;
        const instanceCount = Object.keys(this.jsonData.model?.objects || {}).length;
        title.textContent = `Model ${this.currentFormat.toUpperCase()} — ${classCount} classes, ${enumCount} enums, ${instanceCount} instances`;

        // Format selector
        const formatGroup = document.createElement('div');
        formatGroup.className = 'format-selector-group';
        
        const jsonFormatBtn = document.createElement('button');
        jsonFormatBtn.className = `format-selector-btn ${this.currentFormat === 'json' ? 'active' : ''}`;
        jsonFormatBtn.textContent = 'JSON';
        jsonFormatBtn.addEventListener('click', () => this.switchFormat('json'));
        
        const xmiFormatBtn = document.createElement('button');
        xmiFormatBtn.className = `format-selector-btn ${this.currentFormat === 'xmi' ? 'active' : ''}`;
        xmiFormatBtn.textContent = 'XMI';
        xmiFormatBtn.addEventListener('click', () => this.switchFormat('xmi'));
        
        formatGroup.appendChild(jsonFormatBtn);
        formatGroup.appendChild(xmiFormatBtn);

        const copyBtn = document.createElement('button');
        copyBtn.className = 'json-copy-btn';
        copyBtn.textContent = 'Copy';
        copyBtn.addEventListener('click', () => this.copyContent(copyBtn));

        const downloadBtn = document.createElement('button');
        downloadBtn.className = 'json-download-btn';
        downloadBtn.textContent = this.currentFormat === 'json' ? 'Download JSON' : 'Download XMI';
        downloadBtn.addEventListener('click', () => this.downloadContent());

        header.appendChild(title);
        header.appendChild(formatGroup);
        header.appendChild(copyBtn);
        header.appendChild(downloadBtn);
        wrapper.appendChild(header);

        // Code viewer
        const pre = document.createElement('pre');
        pre.className = this.currentFormat === 'json' ? 'json-code-viewer' : 'xmi-code-viewer';
        pre.textContent = this.currentFormat === 'json' ? this.jsonString : this.xmiString;
        wrapper.appendChild(pre);

        this.container.appendChild(wrapper);
    }

    /** Switch between JSON and XMI format */
    switchFormat(format) {
        if (format === this.currentFormat) return;
        this.currentFormat = format;
        // Re-render to update display
        this.render();
    }

    /** Download current format (JSON or XMI) as a file */
    downloadContent() {
        const content = this.currentFormat === 'json' ? this.jsonString : this.xmiString;
        if (!content) return;
        
        const mimeType = this.currentFormat === 'json' ? 'application/json' : 'application/xml';
        const extension = this.currentFormat === 'json' ? 'json' : 'xmi';
        
        const blob = new Blob([content], { type: mimeType });
        const url = URL.createObjectURL(blob);

        const a = document.createElement('a');
        a.href = url;
        a.download = `${this.app.currentPlugin || 'model'}_${new Date().toISOString().slice(0, 10)}.${extension}`;
        document.body.appendChild(a);
        a.click();
        document.body.removeChild(a);
        URL.revokeObjectURL(url);
    }

    /** Copy current content (JSON or XMI) to clipboard */
    async copyContent(btn) {
        const content = this.currentFormat === 'json' ? this.jsonString : this.xmiString;
        if (!content) return;
        try {
            await navigator.clipboard.writeText(content);
            const orig = btn.textContent;
            btn.textContent = 'Copied!';
            setTimeout(() => { btn.textContent = orig; }, 1500);
        } catch (e) {
            console.warn('Copy to clipboard failed:', e);
        }
    }
}

class ContextMenu {
    constructor() {
        this.menu = null;
        this.currentOptions = [];
        this.hideHandler = null;
        this.createMenuElement();
    }

    createMenuElement() {
        this.menu = document.createElement('div');
        this.menu.className = 'context-menu hidden';
        this.menu.id = 'context-menu';
        document.body.appendChild(this.menu);
        
        // Hide menu when clicking outside
        document.addEventListener('click', (e) => {
            if (this.menu && !this.menu.contains(e.target) && !this.menu.classList.contains('hidden')) {
                this.hide();
            }
        });
        
        // Hide menu on Escape key
        document.addEventListener('keydown', (e) => {
            if (e.key === 'Escape' && !this.menu.classList.contains('hidden')) {
                this.hide();
            }
        });
    }

    show(x, y, options) {
        if (!this.menu) {
            this.createMenuElement();
        }
        
        this.currentOptions = options || [];
        this.menu.innerHTML = '';
        
        options.forEach((option, index) => {
            const item = document.createElement('div');
            item.className = 'context-menu-item';
            
            if (option.disabled) {
                item.classList.add('disabled');
            }
            
            if (option.separator) {
                item.classList.add('context-menu-separator');
                this.menu.appendChild(item);
                return;
            }
            
            const label = document.createElement('span');
            label.className = 'context-menu-label';
            label.textContent = option.label || option;
            
            if (option.icon) {
                const icon = document.createElement('span');
                icon.className = 'context-menu-icon';
                icon.textContent = option.icon;
                item.appendChild(icon);
            }
            
            item.appendChild(label);
            
            if (option.submenu && option.submenu.length > 0) {
                item.classList.add('has-submenu');
                const submenuIcon = document.createElement('span');
                submenuIcon.className = 'context-menu-submenu-icon';
                submenuIcon.textContent = '▶';
                item.appendChild(submenuIcon);
                
                // Create submenu
                const submenu = document.createElement('div');
                submenu.className = 'context-menu-submenu';
                option.submenu.forEach((subOption) => {
                    const subItem = document.createElement('div');
                    subItem.className = 'context-menu-item';
                    subItem.textContent = subOption.label || subOption;
                    subItem.addEventListener('click', (e) => {
                        e.stopPropagation();
                        if (subOption.callback) {
                            subOption.callback(subOption);
                        }
                        this.hide();
                    });
                    submenu.appendChild(subItem);
                });
                item.appendChild(submenu);
                
                // Show submenu on hover
                item.addEventListener('mouseenter', () => {
                    const rect = item.getBoundingClientRect();
                    submenu.style.left = `${rect.width}px`;
                    submenu.style.top = '0px';
                });
            } else {
                item.addEventListener('click', (e) => {
                    e.stopPropagation();
                    if (!option.disabled && option.callback) {
                        option.callback(option);
                    }
                    this.hide();
                });
            }
            
            this.menu.appendChild(item);
        });
        
        // Position menu
        this.menu.style.left = `${x}px`;
        this.menu.style.top = `${y}px`;
        this.menu.classList.remove('hidden');
        
        // Adjust position if menu goes off screen
        const rect = this.menu.getBoundingClientRect();
        if (rect.right > window.innerWidth) {
            this.menu.style.left = `${x - rect.width}px`;
        }
        if (rect.bottom > window.innerHeight) {
            this.menu.style.top = `${y - rect.height}px`;
        }
    }

    hide() {
        if (this.menu) {
            this.menu.classList.add('hidden');
            this.currentOptions = [];
        }
    }

    isVisible() {
        return this.menu && !this.menu.classList.contains('hidden');
    }
}

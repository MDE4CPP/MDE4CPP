# Quick Start Guide

## 1. Setup SSH Access

```bash
# Generate SSH key (if needed)
ssh-keygen -t ed25519 -C "ansible-control"

# Copy to server
ssh-copy-id ubuntu@your-server-ip

# Test connection
ssh ubuntu@your-server-ip
```

## 2. Configure Inventory

Edit `inventory/ci-server.yml`:
```yaml
ansible_host: 192.168.1.100  # Your server IP
ansible_user: ubuntu          # Your SSH user
```

## 3. Test Connection

```bash
ansible -i inventory/ci-server.yml ci-server -m ping
```

## 4. Run Playbook (Basic)

```bash
ansible-playbook -i inventory/ci-server.yml playbook.yml
```

This installs:
- ✅ Git
- ✅ Docker
- ✅ Docker Compose
- ✅ Clones MDE4CPP_CICD repository

## 5. Run Playbook (With GitHub Runner)

### Step 1: Get Runner Token
GitHub Repo → Settings → Actions → Runners → New self-hosted runner

### Step 2: Create Vault
```bash
ansible-vault create group_vars/ci-server/vault.yml
```
Add:
```yaml
github_runner_token: "YOUR_TOKEN_HERE"
```

### Step 3: Enable Runner
Edit `inventory/ci-server.yml`:
```yaml
install_github_runner: true
```

### Step 4: Run Playbook
```bash
ansible-playbook -i inventory/ci-server.yml playbook.yml --ask-vault-pass
```

## Common Commands

```bash
# Run specific role
ansible-playbook -i inventory/ci-server.yml playbook.yml --tags docker

# Check what would change (dry-run)
ansible-playbook -i inventory/ci-server.yml playbook.yml --check

# Verbose output
ansible-playbook -i inventory/ci-server.yml playbook.yml -vvv

# Run with vault password file
ansible-playbook -i inventory/ci-server.yml playbook.yml \
  --vault-password-file ~/.ansible-vault-pass
```

## Verify Installation

```bash
ssh ubuntu@your-server-ip

# Check Docker
docker --version
docker compose version

# Check repository
ls -la ~/Projects/MDE4CPP_CICD

# Check GitHub Runner (if installed)
systemctl status actions.runner.mde4cpp-ci-linux.mde4cpp-ci-linux.service
```


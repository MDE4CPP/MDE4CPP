# MDE4CPP Ansible Playbooks

This directory contains Ansible playbooks for configuring Linux servers for MDE4CPP development and CI/CD.

## Overview

The playbook automates the installation and configuration of:
- **Git** - Version control system
- **Docker** - Container platform
- **Docker Compose** - Multi-container orchestration
- **MDE4CPP Repository** - Clones the project repository
- **GitHub Actions Runner** - Self-hosted CI/CD runner (optional)

## Prerequisites

### Control Node (Your Local Machine)

1. **Install Ansible**
   ```bash
   # Ubuntu/Debian
   sudo apt-get install ansible
   
   # macOS
   brew install ansible
   
   # Or via pip
   pip install ansible
   ```

2. **SSH Access to Server**
   ```bash
   # Generate SSH key (if you don't have one)
   ssh-keygen -t ed25519 -C "ansible-control"
   
   # Copy SSH key to server
   ssh-copy-id -i ~/.ssh/id_ed25519.pub ubuntu@your-server-ip
   
   # Test connection
   ssh ubuntu@your-server-ip
   ```

### Managed Node (Server)

- Ubuntu 20.04, 22.04, or Debian 11+
- Sudo access for the SSH user
- Internet connection

## Quick Start

### 1. Configure Inventory

Edit `inventory/ci-server.yml`:
```yaml
all:
  hosts:
    ci-server:
      ansible_host: 192.168.1.100  # Your server IP
      ansible_user: ubuntu          # Your SSH user
      ansible_ssh_private_key_file: ~/.ssh/id_ed25519
```

### 2. Test Connection

```bash
ansible -i inventory/ci-server.yml ci-server -m ping
```

### 3. Run Playbook (Without GitHub Runner)

```bash
ansible-playbook -i inventory/ci-server.yml playbook.yml
```

### 4. Run Playbook (With GitHub Runner)

First, create encrypted vault file:
```bash
ansible-vault create group_vars/ci-server/vault.yml
```

Add the GitHub Runner token:
```yaml
github_runner_token: "YOUR_TOKEN_HERE"
```

Update inventory to enable runner:
```yaml
install_github_runner: true
```

Run playbook:
```bash
ansible-playbook -i inventory/ci-server.yml playbook.yml --ask-vault-pass
```

## Usage

### Basic Installation

Install Docker, Docker Compose, Git, and clone repository:
```bash
ansible-playbook -i inventory/ci-server.yml playbook.yml
```

### With GitHub Runner

1. **Get GitHub Runner Token**
   - Go to: GitHub Repo → Settings → Actions → Runners → New self-hosted runner
   - Copy the registration token

2. **Create Vault File**
   ```bash
   ansible-vault create group_vars/ci-server/vault.yml
   ```
   Add:
   ```yaml
   github_runner_token: "YOUR_TOKEN_HERE"
   ```

3. **Enable Runner in Inventory**
   Edit `inventory/ci-server.yml`:
   ```yaml
   install_github_runner: true
   ```

4. **Run Playbook**
   ```bash
   ansible-playbook -i inventory/ci-server.yml playbook.yml --ask-vault-pass
   ```

### Run Specific Roles

```bash
# Only install Docker
ansible-playbook -i inventory/ci-server.yml playbook.yml --tags docker

# Only clone repository
ansible-playbook -i inventory/ci-server.yml playbook.yml --tags repository

# Install everything except GitHub Runner
ansible-playbook -i inventory/ci-server.yml playbook.yml --skip-tags github-runner
```

## Directory Structure

```
ansible/
├── playbook.yml              # Main playbook
├── inventory/
│   └── ci-server.yml         # Server inventory
├── group_vars/
│   └── ci-server/
│       ├── vars.yml          # Variables
│       └── vault.yml          # Encrypted secrets
├── roles/
│   ├── docker/               # Docker installation
│   ├── docker-compose/       # Docker Compose installation
│   ├── git/                  # Git installation
│   ├── repository/           # Repository clone
│   └── github-runner/        # GitHub Runner installation
├── .gitignore                # Git ignore rules
└── README.md                 # This file
```

## Variables

### Main Variables (in `group_vars/ci-server/vars.yml`)

- `github_repo_url`: Repository URL (default: git@github.com:KrishnamohanKapri/MDE4CPP_CICD.git)
- `github_repo_branch`: Repository branch (default: main)
- `project_dir`: Project directory on server (default: /home/ubuntu/Projects/MDE4CPP_CICD)
- `install_github_runner`: Enable GitHub Runner installation (default: false)
- `github_runner_name`: Runner name (default: mde4cpp-ci-linux)
- `github_runner_labels`: Runner labels (default: linux,self-hosted)

### Vault Variables (in `group_vars/ci-server/vault.yml`)

- `github_runner_token`: GitHub Runner registration token (encrypted)

## Ansible Vault

### Create Vault File

```bash
ansible-vault create group_vars/ci-server/vault.yml
```

### Edit Vault File

```bash
ansible-vault edit group_vars/ci-server/vault.yml
```

### View Vault File

```bash
ansible-vault view group_vars/ci-server/vault.yml
```

### Encrypt Existing File

```bash
ansible-vault encrypt group_vars/ci-server/vault.yml
```

### Use Vault Password File

Create `~/.ansible-vault-pass`:
```
your-vault-password-here
```

Run with password file:
```bash
ansible-playbook -i inventory/ci-server.yml playbook.yml \
  --vault-password-file ~/.ansible-vault-pass
```

## Verification

After running the playbook, verify installation:

```bash
# Test SSH connection
ssh ubuntu@your-server-ip

# Verify Docker
docker --version
docker compose version

# Verify Git
git --version

# Verify repository
ls -la ~/Projects/MDE4CPP_CICD

# Verify GitHub Runner (if installed)
systemctl status actions.runner.mde4cpp-ci-linux.mde4cpp-ci-linux.service
```

## Troubleshooting

### Connection Issues

```bash
# Test SSH connection
ssh -v ubuntu@your-server-ip

# Test Ansible connection
ansible -i inventory/ci-server.yml ci-server -m ping -vvv
```

### Permission Issues

Ensure the SSH user has sudo access:
```bash
ssh ubuntu@your-server-ip
sudo -v  # Should not prompt for password
```

### GitHub Runner Issues

Check runner logs:
```bash
ssh ubuntu@your-server-ip
journalctl -u actions.runner.mde4cpp-ci-linux.mde4cpp-ci-linux.service -f
```

Check runner status:
```bash
ssh ubuntu@your-server-ip
cd ~/Projects/MDE4CPP_CICD/actions-runner
./run.sh  # Run manually to see errors
```

## GitHub Actions Workflow

After installing the runner, use it in your workflow:

```yaml
# .github/workflows/build.yml
name: Build MDE4CPP

on:
  push:
    branches: [main]
  pull_request:
    branches: [main]

jobs:
  build:
    runs-on: self-hosted  # Uses your configured runner
    steps:
      - uses: actions/checkout@v3
      
      - name: Build with Docker Compose
        run: |
          cd ${{ github.workspace }}
          docker compose up build-full
```

## Security Notes

- **Never commit unencrypted secrets** to git
- **Use Ansible Vault** for all sensitive data
- **Rotate GitHub Runner tokens** regularly
- **Use SSH keys** instead of passwords
- **Limit sudo access** on managed nodes

## Support

For issues or questions:
1. Check the troubleshooting section
2. Review Ansible logs with `-vvv` flag
3. Check server logs: `journalctl -u <service>`

## License

Same as MDE4CPP project.


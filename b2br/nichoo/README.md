*This project has been created as part of the 42 curriculum by nichoo.*
# Born2beRoot

---

Table of contents
- [Description](#description)
- [Project goals](#project-goals)
- [Choices & rationale](#choices--rationale)
- [Prerequisites](#prerequisites)
- [Evaluation / VM signature](#evaluation--vm-signature)
- [Commands](#commands)
- [Resources](#resources)


## Description
The Born2beRoot project is about setting up and securing a Linux server inside a virtual machine (VirtualBox for this project). The goal is to configure system administration basics, including sudo and password policies, SSH, UFW, and cronjobs.

## Project goals
Key tasks implemented in this project:
- Partition and prepare the system for use (VM-based)
- Configure `sudo` with tightened policies:
  - Maximum of 3 password attempts
  - Custom message on incorrect password
  - Archive sudo input/output to `/var/log/sudo`
  - Require TTY
  - Restrict `PATH` used by sudo
- Implement a strict password policy (applies to sudo passwords too):
  - Password expires every 30 days
  - Minimum 2 days before password can be changed
  - Warning 7 days before expiration
  - Minimum 10 characters
  - Must include at least one uppercase, one lowercase, and one digit
  - No 3 consecutive identical characters
  - Password must not contain the username
  - At least 7 characters different from the previous password (not applied to root)
- Configure SSH (non-default port allowed/used)
- Configure UFW firewall with required port rules
- Provide a monitoring script that prints system info on all terminals at startup and every 10 minutes

## Choices & rationale
- Debian (Debian 13) — chosen for its documentation and ease of use for this scope.
- AppArmor — default in Debian and sufficient for this project.
- UFW — simpler and adequate for exercise goals.
- VirtualBox — mandatory per subject unless impossible; otherwise UTM (macOS) is an option.

## Prerequisites
- Host: VirtualBox installed (the evaluation will inspect the VM file)
- VM: Debian 13 (as used for this project)
- Root/sudo access to inspect/verify configuration

## Evaluation / VM signature
The evaluation script on the subject will compare the SHA-1 signature of the VM disk to the one in `signature.txt`. 

- Windows (PowerShell / CMD)
  - Go to the folder where the VirtualBox VMs are stored:
    ```
    %HOMEDRIVE%%HOMEPATH%\VirtualBox VMs\new-born2beroot\
    ```
  - Compute SHA-1:
    ```
    certUtil -hashfile new-born2beroot.vdi sha1
    ```
The signature in `signature.txt` should match the output of these commands.

## Commands
The following commands will be useful during the evaluation:

- UFW status:
  ```
  sudo ufw status
  ```

- SSH status:
  ```
  sudo service ssh status
  ```

- Kernel / OS:
  ```
  uname --kernel-version
  ```

- Check group membership:
  ```
  getent group <groupname>
  ```

- Create a new user:
  ```
  sudo adduser <username>
  ```

- Create a new group:
  ```
  sudo addgroup <groupname>
  ```

- Add user to group:
  ```
  sudo adduser <username> <groupname>
  ```

- Hostname:
  ```
  hostname
  ```

- Change hostname:
  ```
  sudo vim /etc/hostname
  sudo vim /etc/hosts
  sudo reboot
  ```

- List block devices / partitions:
  ```
  lsblk
  ```

- Verify sudo is installed:
  ```
  which sudo
  ```

- Check sudo configuration files:
  ```
  sudo ls -l /etc/sudoers.d/
  sudo cat /etc/sudoers.d/sudo_config
  ```

- Check that sudo logging exists:
  ```
  ls -l /var/log/sudo
  sudo cat /var/log/sudo/<log-file>
  ```

- UFW rules:
  ```
  sudo ufw allow <port-number>
  sudo ufw delete allow <port-number>
  ```

- Inspect root cronjobs:
  ```
  sudo crontab -u root -l
  ```


## Resources
- Project guide: https://noreply.gitbook.io/born2beroot
- UFW & OpenSSH documentation: https://documentation.ubuntu.com/server/how-to/security
- General web/server resources: MDN Web Docs

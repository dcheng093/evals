### *This project has been created as part of the 42 curriculum by yoowong (yoowong@student.42kl.edu.my).*

## **DESCRIPTION**
The goal of born2beroot project is to familarize ourselves with virtual machines(VMs) and introduce us to the wonderful world of system administration (sysadmin). This project get us to learn what is a VM, how to partition a local storage and install an OS manually in a hardware, useful command lines when working on a Linux computer without graphical user interface(GUI), and basic security measures when we set up a server.

## **PROJECT DESCRIPTION**
For this project, I chose Debian as my OS. It is known for its low idle memory usage and high performance especially on weaker hardwares. Rocky Linux is a downstream distribution of RHEL (Red Hat Enterprise Linux), which is a corporate-backed Linux distribution(distro) designed primarily for enterprise servers. Rocky Linux is an open-sourced direct replacement for CentOS, which is discontinued by Red Hat Enterprise to focus their efforts on RHEL. Debian meanwhile, is a fully community driven, popular Linux distribution(distro) for general usage and in itself is the upstream of popular distros like Ubuntu, Linux Mint, Deepin and MX Linux. They are all known to be beginner friendly.

| **DEBIAN** | **ROCKY LINUX** |
| :--- | :--- |
| Exceptionally stable but use older drivers and packages | Dependent on Red Hat development cycle, 100% bugs compatibility with RHEL |
| Runs well on older hardware | Excellent for high-performance & cloud computing |
| Fully community driven  |  More closely tied to enterprise needs |

| **AppArmor** | **SELinux** |
| :--- | :--- |
| Easier to learn and manage | More complex but offers finer control |
| Path-based approach | Label-based approach |
| Use human-readable, plain text profile, easier to debug | Requiring experties to read the logs, harder to troubleshoot |
| Lower overhead | More performance overhead |
| Well-suited for predefined application behaviour | More flexible for complex environment |

| **UFW** | **firewalld** |
| :--- | :--- |
| simple syntax | complex but offer more granular control |
| static rules | dynamic rules |
| rules-based | supports network zones for different trust levels |

| **Virtualbox** | **UTM** |
| :--- | :--- |
| cross platform | created specifically for macOS |
| Better for x86/x64 architecture | optimized for Apple Silicon |
| more feature rich | simple |

## **WALKTHROUGH**
Firstly, I have to download Oracle Virtualbox on my Fedora Linux distro. To get it working on my PC with SecureBoot on, I have to import a MOK utility tool and enroll it to sign Virtualbox drivers as it is not signed in the Linux kernel.

```
    # 1. Install the necessary tools (if not already there)
        sudo dnf install kmodtool akmods mokutil openssl

    # 2. Generate the Key Pair (Public & Private)
    # This creates the keys in /etc/pki/akmods/certs/
        sudo kmodgenca -a

    # 3. Import the Public Key into the BIOS (MOK List)
    # You will be asked to create a password. specific simply "1234" or similar.
        sudo mokutil --import /etc/pki/akmods/certs/public_key.der

    #4. Build the driver and sign it with the key
        sudo akmods --force

    #5.Restart the Virtualbox service
        sudo systemctl restart vboxdrv

    #6. Add myself as the user
        sudo usermod -a -G vboxusers $USER
```

Next, I mounted my ISO image to install Debian in my VM. I also partitioned my VM manually, encrypt the drive and create a logical volume manager as per the bonus instructions.

Upon booting, I installed sudo immediately and add users to the sudo group. Thereafter, I installed and configured the SSH and ufw(firewall). I also changed the SSH port from port 22 to 4242 as port 22 is the default port. Changing it to a port of random number like 4242 is a basic security measure through "Security through Obscurity". I also disabled root login via SSH by changing "PermitRootLogin" to no.

Right after that, I changed the password policy to comply with standard practice and as per subject pdf.

```
    #1. Create and open '/etc/sudoers.d/sudo_config' file and changed the defaults.
            passwd_tries=3
            requiretty
            secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
                secure path is to prevent a trojan horse scenario where a hacker tricks the user into executing the malware with root privilege when sudo inherit the compromised path.

    #2. Modify the password MIN and MAX days in '/etc/login.defs' file.

    #3. Configure password quality requirements
            sudo apt install libpam-pwquality
            nano /etc/pam.d/common-password
            add 'minlen=10 ucredit=-1 dcredit=-1 lcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root' after 'retry'
```

And finally, we will setup the monitoring script that will broadcast system info every 10 minutes.

```
   #1. nano monitoring.sh

   #2. sudo crontab -u root -e
        insert this line below
            */10 * * * * sh /root/monitoring.sh
```

## **INSTRUCTIONS**
Power on the VM and ask the user to insert the encryption passphrase. Login with user ID. An automated script detailing the system will be broadcasted every 10 minutes. Check and verify the difference between the retrieved signature of b2br.vdi and signature.txt.

```
    shasum b2br.vdi > yourname.txt
    diff signature.txt yourname.txt
```

## **RESOURCES**
Followed the helpful guide on https://noreply.gitbook.io/born2beroot. Credits to gemartin99.
Used Google Gemini AI for troubleshooting, installation and running Virtualbox on Fedora, and detailed explanations to fill in my knowledge gaps.
Referenced https://tuxcare.com/blog/selinux-vs-apparmor/ for comparison between apparmor and SELinux.

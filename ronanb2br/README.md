*This project has been created as part of the 42 curriculum by ryeong.*

# Project: Born2beroot
## Description
This project is about creating and running a virtual machine and use it to set up a server with specific rules.

### Project Description
#### Operating System chosen
<ins>Debian vs Rocky Linux</ins>

I chose Debian as it is generally an easier operating system for most people making it a great choice for beginners compared to Rocky which is more advanced.

Debian is also better for general use as it contains more packages while Rocky is more specialized for businesses to make a stable and more secure server.

#### Services

<ins>AppArmor vs SELinux</ins>
I chose AppArmor as its simpler and easier to configure. AppArmor is more suitable in this case as i am focusing more on ease of use.

SELinux is more complicated but it has stricter security and has more control over what actions the programs and users can do.

<ins>UFW vs firewalld</ins>

I chose UFW as it is easier to setup and it is also ideal for smaller servers as the rules are simple and static which are set manually before hand making it straightforward.

firewalld is more for big servers that require a more complex configuration to handle the large amount of devices and has more customization

<ins>VirtualBox vs UTM</ins>

Main reason I used VirtualBox is cause its already installed on the iMacs and also because i am more familiar with it. It can also host as many virtual machines as your device can handle concurrently.

UTM has it uses namely being able to host a wider variety of operating systems including older versions.


## Instructions

Refer to evaluation sheet, it has all the the things you need to check there. You can use the Command List below to assist in this.

### Command List
Check Sudo installation: `sudo -V`

Add new user: `sudo adduser <login_name>`

Add new group: `sudo addgroup <group_name>`

Add user to group: `sudo adduser <login_name> <group_name>`

Check user in group: `getent group <group_name1> <group_name2> <...>`

Check SSH installation: `sudo service ssh status`

SSH config files: `nano /etc/ssh/sshd_config` and `nano /etc/ssh/ssh_config`

Restart SSH service: `sudo service ssh restart`

Check SSH service: `sudo service ssh status`

Connect to SSH: `ssh <username>@localhost -p 4242`

Check UFW service: `sudo ufw status`

Admin login policy file: `nano /etc/sudoers.d/sudo_config`

Password policy files: 
- password aging: `nano /etc/login.defs`
- password complexity rules: `nano /etc/pam.d/common-password`

Crontab: `sudo crontab -u root -e`

Check OS: `head -n 2 /etc/os-release`

Check AppArmor: `sudo systemctl status apparmor`

Check Signature: `shasum machinename.vdi`

## Resources
#### Readme
- https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax

#### General
- https://noreply.gitbook.io/born2beroot/virtual-machine-setup/signature.txt

- https://www.reddit.com/r/debian/comments/1niq3xd/debian_or_rocky_linux_for_desktop/

- https://tuxcare.com/blog/selinux-vs-apparmor/

- https://www.reddit.com/r/linuxquestions/comments/upq14r/ufw_or_firewalld/

- https://www.pluralsight.com/resources/blog/software-development/linux-firewall-administration


- https://siytek.com/utm-vs-virtualbox/


### Declaration of AI Use
- Used to assist in understanding the concepts in the projects (the google search overview one)
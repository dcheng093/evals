*This project has been created as port of the 42 curriculum by wshee*

# 42 Net Practice
## Description
The objective for this project is to learn about computer networking, understanding how TCP/ IP addressing works, how to configure IP address, connect devices through a router, subnet mask and understand the role of a gateway within a network.

## Instruction
1. Download the file from 42 Net practice project page
2. Go into the directory
3. Run `bash run.sh`
4. A browser will be lauched automatically with  address "http://localhost:49152/index.html"
5. Key in intra id to begin the exercise
6. Clear the non-gray tab and fill in the answer
7. Click `Get my config` to save the answer in json file
Alternative:
1. Run `python3 -m http.server 49242`
2. Navigate to browser "http://localhost:49242"

## Resources
- [Net Practice Reference](https://medium.com/@imyzf/netpractice-2d2b39b6cf0a)
- [TCP/IP Introduction](https://www.geeksforgeeks.org/computer-networks/tcp-ip-model/)
- [Subnet Mask Explanation](https://www.youtube.com/watch?v=s_Ntt6eTn94)
- [CIDR Table](https://docs.netgate.com/pfsense/en/latest/network/cidr.html)
- [OSI Layer](https://www.imperva.com/learn/application-security/osi-model/)
##### Use of Artificial Intelligence (AI)
- Github Copilot model GPT5.1 was used for explanation of concept and clarification of subnet calculation

### TCP/IP addressing
#### What is IP address?
- Internet Protocol (IP) address identifies a network or a device on the internet, it is the communication over the internet
- IPv4 is a 32-bit number, consists of 4 octet, 8 bits each

##### Two parts of IP address:
1. Network ID : the network that any host can connect to it (binary in 1)
2. Host ID : uniquely identifies which host (binary in 0)
<img width="1625" height="913" alt="Image" src="https://github.com/user-attachments/assets/997fa8ff-98c1-4c39-8089-051f2a20448b" />

##### Types of IP address:
1. Static IP address : stay permanent for specific device
2. Dynamic IP address : changes frequently, when the device is restarted, then it automatically assigned

#### What is TCP/IP?
Transmission Control Protocol/Internet Protocol allow computers to communicate on a network
- IP obtains address which the data is sent to
- TCP deliver data once IP address has been found, responsible for breaking data into small packets, sending them over the network, and detects error during ttransmission
- Three-way handshake: Synchronize(SYN), Synchronize-Acknowledge(SYN-ACK), Acknowledge(ACK)

### Open System Interconnection (OSI) Layer
- rules to explain how different computer systems communicate over a network
- consists of 7 layer
<img width="1290" height="916" alt="Image" src="https://github.com/user-attachments/assets/a52d28d3-4b46-4604-bc92-8d303f662119" />
<img width="1565" height="1149" alt="Image" src="https://github.com/user-attachments/assets/4082efe9-1a29-4480-83db-ecb2c414bec5" />
- The main focus for this practice is the transport layer where TCP/IP divide the different communication tasks into layers:
1. Datalink Layer : physical layer that handles sending and receiving using Ethernet (eg. Ethernet, Wireless LAN)
2. Internet Layer : network layer that controls the movement of the packets around the internet (eg. IPv4, IPv6)
3. Transport Layer : provides reliable data connection between two devices (eg. TCP)
4. Application Layer : group of applications that requires network communication (eg. HTTP, SSH, FTP)

#### IP address that cannot connect to internet
1. Loopback address (aka localhost)
- IP range starts from 127.0.0.0 to 127.255.255.255

2. Private address
- 10.0.0.0 - 10.255.255.255
- 172.16.0.0 - 172.31.255.255
- 192.168.0.0 - 192.168.255.255

### Subnet Masks
- a 32 bit balue that separates the network and host portion
- eg. 255.255.255.0 or in CIDR (/24)
How to calculate subnet mask:
- determine how many subnets needed (depends on how many interface)
- determine how many hosts per subnet
- Total address that can be used: 2^(32 - number of binary 1) - 2
Because in every subnet, there are 2 IP address that we avoid to use:
1. First address(network address) - identifies the subnet itself
2. Last address (broasdcast address) - used to send to all devices in that subnet
- Examples:
  - /24 = 255.255.255.0 → 256 addresses, 254 usable hosts.
  - /25 = 255.255.255.128 → 128 addresses, 126 usable hosts.
- Avoid overlapping subnets to prevent routing problems.
- The same network are only able to connect using the same subnet mask.

### Default gateways
- a router that serves as a forwarding host to other networks when no other route specification matches the destination IP address
- default = 0.0.0.0/0

### Switches
- connects device within same network
- works inside local area network (LAN)
- can connect to many ip address, must have same mask

### Routers
- manage traffic between networks by forwarding data packets to the IP address
- connects local network to internet
- connects two or more packet-switched networks or subnetworks
- can connect to many mask
- must connect two way
- no overlap ip address
- allow multiple device to use the same internet connection
- Routing table made up of: Destination => Next Hop
Destination: IP address of the package sent to combined with CIDR (eg. 192.192.192.0/24)
Next Hop: IP address of the next router
<img width="726" height="364" alt="Image" src="https://github.com/user-attachments/assets/cfbddf3c-ca74-40ca-8a6b-98c99d3d8348" />

subnet masks, default gateways, and static routes — until every communication goal defined for that level is achieved.

The networks used in this project are entirely fictitious and are not connected to any real-world network or infrastructure.
Instructions

    Download and extract the project archive into a folder of your choice.
    From that folder, run the training interface with:

   ./run.sh

This launches a local web server and opens the training interface in your default web browser. 3. If run.sh does not work as expected, start the server manually:

   python3 -m http.server 49242

Then open http://localhost:49242 in your browser (or whichever port you chose). 4. On the welcome screen, enter your intranet login (afomin) in the Training tab so the Moulinette can identify your personal configuration. Alternatively, the Evaluation tab can generate a random configuration also suitable for grading. 5. For each level, adjust the unshaded (editable) fields — IP addresses, subnet masks, and routing tables — until the Check again button reports that all goals are met. The logs displayed at the bottom of the page explain why a configuration is currently failing (e.g. a missing gateway, an invalid IP, or a routing conflict). 6. Once a level is solved, click Get my config to download the configuration file for that level, then click Next level to proceed. 7. Repeat for all 10 levels. Each exported configuration file must be placed at the root of this repository, so that a total of 10 files (one per level) are submitted.
Resources

Networking concepts studied and applied throughout this project:

    TCP/IP addressing — how IPv4 addresses uniquely identify a device on a network.
    Subnet masks and CIDR notation — how a mask splits an IP address into a network part and a host part, and how it defines the size and boundaries of a subnet.
    Default gateways — how a host or router forwards traffic destined for a network outside its own directly connected subnet.
    Routing tables and static routes — how a router decides, for each destination network, which interface or next hop to use, and why directly connected interfaces on the same router must never use overlapping address ranges.
    Routers and switches — the difference between Layer 2 forwarding (switches, based on MAC addresses) and Layer 3 forwarding (routers, based on IP addresses and routing tables).
    OSI layers — situating addressing (Layer 3) and switching (Layer 2) within the broader OSI model.

General references used:

    RFC 791 — Internet Protocol
    RFC 1918 — Address Allocation for Private Internets
    Subnetting practice — subnetting.net
    Cisco Networking Basics documentation

Use of AI: An AI assistant (Claude) was used throughout this project as a learning aid, not as a code or configuration generator. It was used to:

    Clarify theoretical networking concepts (subnetting, ARP, DHCP, DNS, routing tables, default gateways) through discussion and follow-up questions.
    Help interpret the training interface's diagnostic logs (e.g. destination does not match any route, multiple interface match, invalid default route on internet I) and understand the underlying cause of each error.
    Double-check manual subnet calculations before applying them in the interface. No configuration values were generated or entered by the AI directly; every field in the submitted configuration files was calculated and entered manually.

Submission details

This repository contains 10 exported configuration files (one per level), placed at the root of the repository, as required by the project instructions. The training interface was used with the login afomin to generate these configurations.

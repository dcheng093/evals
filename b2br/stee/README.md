*This project has been created as part of the 42 curriculum by stee.*

# Overview (Description)

The project revolves much around the knowledge of the evaluatee. Hence, the evaluation is very much a test of theory of knowledge. This `README` contains the summaries of the concepts learned through this project. The Born2beRoot project is about setting up and securing a Linux server inside a virtual machine (VirtualBox for this project). The goal is to configure system administration basics, including sudo and password policies, SSH, UFW, and cronjobs.

# Instructions

This project is done on Oracle Virtual Box. Therefore, the evaluation must take place after the virtual machine is booted up on the machine. 

# Theory and Justification of Project Decisions 

## Virtual Machines
A virtual machine (VM) is a type of software that allows for the simulation of a complete computer system. The simulated environment operates like a normal physical computer and can perform tasks such as running programs. More importantly, they are usually used for their cost effectiveness - allowing the creation of multiple simulated environments within the same physical hardware system with their own dedicated resources. This means that VMs allow for multiple operating systems to run simultaneously on the same machine.

## Purpose of Virtual Machines
On the last point we discussed briefly about what virtual machines are, but generally there are 6 reasons for utilizing virtual machines.

<ol>
<li> Isolation: This means the environments are secure and inert to the activities of other environments; making it a good choice for testing and development. </li>

<li> Resource Efficiency: Allowing for multiple environments to be run on a single machine means the cost of purchasing a second machine is negated. </li>

<li> Platform Independence: Allowing multiple operating systems to be run on the same hardware. </li>

<li> Disaster Recovery: Virtual machines allow for easy backup and restoration of system states. </li>

<li> Development and Testing: Virtual machines are ideal avenues for development and testing. </li>

<li> Legacy Support: Allow for older operating systems and applications to be run. </li>
</ol>

## Debian
The project utilizes Debian over Rocky (the two operating systems allowed for the scope of this project). The rationale is encapsulated in 5 primary points. 

<ol>
<li> Debian is more <b>beginner friendly</b> which means that individuals without prior experience with system administration will have an easier time setting it up. </li>

<li> Debian also has more <b>extensive documentation</b> and <b>community support</b> which allows for the setup process to be much more seamless. </li>

<li> An extension of the previous points would be in Debian's <b>package management</b>. What this means is that the APT (advanced package tool) words extremely intuitively. </li>

<li> Lastly, Debian is also known for its <b>stability and reliability</b> in performance. </li>
</ol>

## APT vs Aptitude
APT and aptitude are package management tools for Debian systems.

| APT (Advanced Package Tool)   		            | Aptitude                             |
| -------------------------------------------- 	| ------------------------------------ 
| Low-level                                     |	High-level                           |
| CLI (Command-line interface) only             | CLI and text-based UI (user interface)|
| Faster, more lightweight                      | More features, better dependency resolution, smarter handling of orphaned packages |
| Used in scripts and automation                | More user-oriented for interactive use |

## AppArmor

AppArmor (Application Armor) is a security module in Linux that gives Mandatory Access Control (MAC) security.

<ol>
<li> Application confinement: Restricts what a program can do and its access to system resources. </li>

<li> Profile-based: Using security profiles to define what resources certain applications can access. </li>

<li> Path-based: Controls access based on file paths. </li>

<li> Default deny: Applications are denied access to resources that are not explicitly allowed by admin. </li>

<li> Complements traditional permissions: Works conjunctively with Linux file permissions. </li>
</ol>

## LVM

Logical Volume Manager is a device mapper framework used to manage logical volumes. This section talks about the flexibility and structure of LVMs, and its advantages over traditional partitioning.


<b>Flexibility</b>
<ol>
<li> Dynamic resizing of partitions without unmounting. </li>
<li> Easy management of storage across multiple devices. </li>
<li> Creates snapshots for backups. </li>
</ol>


<b>Structure</b>
<ol>
<li> Physical Volumes (PV) </li>
<li> Volume Groups (VG) </li>
<li> Logical Volumes (LV) </li>
</ol>


<b>Advantages</b>
<ol>
<li> Resize partitions dynamically </li>
<li> Moving data across storage devices </li>
<li> Consistent backups </li>
<li> Stripes data across devices for performance </li>
</ol>

# Choices & rationale
<ol>
<li> Debian (Debian 13) — chosen for its documentation and ease of use for this scope. </li>
<li> AppArmor — default in Debian and sufficient for this project. </li>
<li> UFW — simpler and adequate for exercise goals. </li>
<li> VirtualBox — mandatory per subject unless impossible; otherwise UTM (macOS) is an option. </li>
</ol>

# Conclusion (Resources)
This `README` does not cover everything required for the project evaluation, but for more information, this is a really good resource: https://noreply.gitbook.io/born2beroot

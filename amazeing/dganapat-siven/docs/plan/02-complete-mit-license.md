# 02 — Complete MIT license, correctly declared in package metadata

Source: `spec.md`

**What to build:** Anyone reading the repository — or inspecting the installed package — finds a complete, legally meaningful MIT license naming both team members. The license file currently holds a truncated opening clause with no warranty disclaimer and only one author, and the package metadata declares it using a form the build backend has deprecated.

**Blocked by:** None — can start immediately.

**Status:** ready-for-agent

- [ ] The license file contains the complete MIT text, including the permission grant in full
- [ ] The warranty and liability disclaimer is present
- [ ] The copyright line names both team members
- [ ] Package metadata declares the license using the SPDX identifier form with a separate license-files entry
- [ ] Building the package emits no license-related deprecation warning
- [ ] The license is visible after installing the package, not only in the repository

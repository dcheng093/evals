# 04 — Buildable `mazegen` distribution committed at the repository root

Source: `spec.md`

**What to build:** A peer evaluator finds a `mazegen-*` artifact at the root of the repository, creates a fresh virtual environment, runs two documented commands, and watches the same artifact rebuild from source with no warnings. They then install it into a clean environment, import the generator, and produce a maze without any other repository file present. This is the deliverable the subject's Chapter VI turns on, and it currently does not exist — today's metadata discovers zero packages and would build a distribution containing no code.

**Blocked by:**
- 01 — Restructure maze generation into an importable `mazegen` package. There is nothing to package until the package exists.
- 02 — Complete MIT license, correctly declared in package metadata. The build must be warning-free, and the deprecated license declaration is what produces the warning.
- 03 — Module documentation that ships inside the distribution. Metadata names the module readme, so the build fails or ships empty documentation if that file is absent.

**Status:** ready-for-agent

- [ ] A single build command produces both a wheel and a source distribution directly at the repository root, with no intermediate output directory and no copy step
- [ ] The artifact filename matches the `mazegen-*` pattern and carries version `1.0.0`
- [ ] The wheel contains the package's code — verified by inspecting it, not inferred from a successful build
- [ ] The wheel contains the module documentation — likewise verified by inspection
- [ ] The build tool is installed by the install target, so the evaluator installs nothing by hand
- [ ] The install target upgrades pip before installing tools, not after
- [ ] The build completes with no deprecation warnings
- [ ] Building after the virtual environment exists does not sweep third-party packages into the artifact
- [ ] Installing the artifact into a throwaway environment and importing the generator from a directory containing no project source succeeds
- [ ] Generating twice with the same seed through the installed package produces identical results
- [ ] A version control ignore file covers Python caches, compiled files, and the virtual environment
- [ ] That ignore file does not exclude distribution artifacts, and carries a comment explaining why
- [ ] The clean target still removes only caches and leaves the distribution untouched

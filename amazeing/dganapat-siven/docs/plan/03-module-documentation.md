# 03 — Module documentation that ships inside the distribution

Source: `spec.md`

**What to build:** A developer who installs the package and has never seen this repository can read its documentation, paste the example, and get a maze. The package carries its own readme covering instantiation with a runnable example, every parameter a caller may pass and its default, how to reach the generated maze structure, and how to reach a solution. Package metadata names this file as the distribution's readme, which is the mechanism that carries the documentation inside the built artifact — a Markdown file merely placed in a package directory is not included in a wheel.

**Blocked by:** 01 — Restructure maze generation into an importable `mazegen` package. The package directory must exist before it can carry a readme, and the example cannot be written against an import path that does not yet work.

**Status:** ready-for-agent

- [ ] The documentation shows instantiating the generator and generating a maze in a complete, runnable example
- [ ] Every constructor parameter is documented with its default — dimensions, seed, entry, exit, and whether the maze is perfect
- [ ] The documentation explains how to reach the generated maze structure and describes its shape
- [ ] The documentation states that the in-memory structure is not the same as the output file's hexadecimal encoding
- [ ] The documentation explains how to reach a solution and states that it is the shortest path
- [ ] The documentation states that the package needs nothing beyond the standard library
- [ ] Package metadata names this file as the distribution's readme
- [ ] The example runs as written against the installed package, not only against the source tree

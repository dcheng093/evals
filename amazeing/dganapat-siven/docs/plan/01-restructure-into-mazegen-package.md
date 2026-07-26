# 01 — Restructure maze generation into an importable `mazegen` package

Source: `spec.md`

**What to build:** Someone standing in the repository can write `from mazegen import MazeGenerator` and it works. The maze structure, the generator, and the solver live together inside a package named `mazegen` whose public surface exposes the generator class, the maze structure type, and the solver function. Config parsing, terminal rendering, the main program, and the output analyser stay outside the package as main-program code. The program still runs, still produces coherent output, and still passes lint and type checks.

**Blocked by:** None — can start immediately.

**Status:** ready-for-agent

- [ ] `from mazegen import MazeGenerator` succeeds from the repository root
- [ ] The maze structure type and the solver function are reachable from the same import
- [ ] Package discovery is restricted to names beginning with `mazegen`, so the virtual environment can never be swept into a build
- [ ] Config parsing and terminal rendering remain outside the package
- [ ] The main program's filename is unchanged, as the subject requires
- [ ] `make run` produces a maze from the default config
- [ ] The output analyser reports the generated file as coherent
- [ ] `make lint` passes — both flake8 and mypy
- [ ] No behaviour of the generator, solver, renderer, or config parser has changed beyond import statements

*This project has been created as part of the 42 curriculum by dganapat and si-wong.*

# a-maze-ing

## Description

A-maze-ing generates a rectangular maze, solves it, draws it in the terminal and
writes it to a file. A configuration file fixes the dimensions, the entry and
exit cells, the output file and whether the maze is *perfect* (exactly one route
between any two cells) or *playable* (loops, no dead ends — a board a Pac-Man-like
game could use). The "42" logo is stamped into the middle of every maze and
generation carves corridors around it.

Running the program reads the config, generates and solves a maze, writes the
hexadecimal encoding plus the entry, exit and solution to the output file, then
opens an interactive menu: re-generate, show or hide the shortest path, cycle the
wall colours, or quit.

The maze generation lives in a standalone, installable Python package, `mazegen`,
which a different project can `pip install` and import on its own.

### Features

- Random generation with an optional seed for reproducible output
- Perfect mazes, or playable boards with loops and no dead ends
- The "42" logo carved into the centre of every maze
- Shortest-path solving, shown as an overlay and as a direction string
- Coloured terminal rendering with switchable themes
- Hexadecimal output file with entry, exit and solution in the footer
- An output analyser that verifies a written maze file
- Config parsing with line-numbered error messages, and no dependencies outside
  the standard library

## Instructions

Requires **Python 3.10 or later** and `make`. Nothing else at runtime — the dev
tools (`flake8`, `mypy`, `build`) go into a local virtual environment.


```bash
git clone <git@vogsphere.42kl.edu.my:vogsphere/intra-uuid-c30577bc-8115-46ed-847e-069221cc1a12-7555063-dganapat>
cd a_maze_ing
make install
make run
```

To use a different configuration file, run the main program directly —
`venv/bin/python3 a_maze_ing.py my_config.txt`. With no argument it falls back to
`config.txt`.

### Makefile targets

| Target | What it does |
|---|---|
| `make install` | Creates `venv/`, upgrades `pip`, installs `mypy`, `flake8`, `build`. |
| `make build` | Builds the wheel and source distribution of `mazegen` into the repository root, so the committed artifact and a rebuild from source are one command. |
| `make reinstall` | Rebuilds, then force-reinstalls the wheel. One command to check a change to the package. |
| `make run` | Runs the program against `config.txt`. |
| `make debug` | Runs the program under `pdb`. |
| `make clean` | Removes `__pycache__`, `.pytest_cache` and `.pyc` files. Deliberately leaves the built distribution alone — it is a required deliverable. |
| `make lint` | Runs `flake8` and `mypy` with the project's required checks. |
| `make lint-strict` | The same `flake8` run plus `mypy --strict`. |
| `make uninstall` | Runs `clean`, then deletes the virtual environment. |

## Configuration file format

A plain-text file — `config.txt` by default. This is the one shipped with the
project:

```ini
WIDTH=20
HEIGHT=15
ENTRY=0,0
EXIT=19,14
OUTPUT_FILE=maze.txt
PERFECT=False
SEED=42
```

### Syntax

- One `KEY=VALUE` per line; blank lines ignored.
- A line starting with `#` is a comment. Whole-line only — a `#` elsewhere is
  part of the value.
- Whitespace is stripped, key names are case-insensitive, and the line splits at
  the *first* `=` so any further `=` stays in the value.
- A repeated key is an error. Unknown keys are kept as strings and ignored.

### Mandatory keys

| Key | Type | Meaning |
|---|---|---|
| `WIDTH` | integer, at least 2 | Number of cell columns. |
| `HEIGHT` | integer, at least 2 | Number of cell rows. |
| `ENTRY` | two integers, `x,y` | Start cell. `x` in `0..WIDTH-1`, `y` in `0..HEIGHT-1`. |
| `EXIT` | two integers, `x,y` | Goal cell, same ranges. Must differ from `ENTRY`. |
| `OUTPUT_FILE` | string | Path the maze is written to. Taken as given, not validated. |
| `PERFECT` | `True` / `False`, case-insensitive | `True` produces a perfect maze: no loops, exactly one route between any two connected cells. `False` produces a playable board: dead ends removed, loops added, corners and centre forced open and reachable. |

All six must be present. `ENTRY` and `EXIT` are `x,y` — column first, row second
— counted from `0` at the top-left cell.

### Optional keys

| Key | Type | Default | Meaning |
|---|---|---|---|
| `SEED` | integer | none | Seeds the random generator, so the same seed with the same other values reproduces the same maze. Omit it and every run differs. |

## Algorithms

Two different algorithms are used — one builds the maze, one solves it.

- **Generation: depth-first search (recursive backtracker).** From the top-left
  cell, walk to a random unvisited neighbour two grid steps away, knock down the
  wall between them, recurse; back up when a cell has no unvisited neighbours
  left. Cells belonging to the "42" logo are excluded, so the logo survives
  intact. On its own this produces a perfect maze.
- **Solving: breadth-first search.** Explores outward from the entry in order of
  distance, so the first time it reaches the exit it has found a shortest route.
  Returns both the path and the cells visited on the way.

With `PERFECT=False` the depth-first result is post-processed: dead ends opened
up, loops introduced, corners and centre forced open and connected. A candidate
maze is rejected and regenerated if it contains a 3x3 block of open floor or if
the exit is unreachable; after 1000 failed attempts the generator raises.

### Why these algorithms

These were the most simple and easist algorithms to understanding visually and to
comprehend as well, so we choose them. 

## What is reusable and how

The maze generation is a self-contained package, `mazegen/`, containing three
modules and nothing else:

- `mazegen/maze.py` — the `Maze` structure: dimensions, entry, exit, grid.
- `mazegen/generator.py` — `MazeGenerator`, the single generation class, plus the
  hexadecimal encoder and the path-to-direction converter.
- `mazegen/solver.py` — `bfs_solve_maze`, the shortest-path solver.

`mazegen/__init__.py` re-exports the whole public surface, so one import is
enough. The package depends only on the standard library and on nothing else in
this repository. Left outside it, because a consumer will have its own:
`mazegen_config.py` (config parser), `mazegen_display.py` (terminal renderer),
`a_maze_ing.py` (main program), `maze_analyzer.py` (output analyser).

To reuse it, `make build` then `pip install mazegen-1.0.0-py3-none-any.whl`.
Installing adds exactly one name, `mazegen`, to the environment. The package's
own documentation ships inside the distribution, and is repeated in full below.

## Module documentation

The following is the documentation that ships inside the `mazegen`
distribution, reproduced here in full.

### mazegen

A standalone maze generator: builds a rectangular maze, solves it, and encodes
it for output.

**Requires Python 3.10 or newer. It needs nothing beyond the standard
library** — `mazegen` declares no dependencies, and installing it pulls nothing
else in.

#### Install

```sh
pip install mazegen-1.0.0-py3-none-any.whl
```

#### Complete example

```python
from mazegen import (
    MazeGenerator,
    bfs_solve_maze,
    encode_maze_to_hex,
    path_to_direction,
)

generator = MazeGenerator(
    height=15,
    width=20,
    entry=(0, 0),
    exit=(19, 14),
    perfect=False,
    seed=42,
)

maze = generator.create_maze()

# The maze structure: a grid of (2 * height + 1) x (2 * width + 1) integers.
print("cells:", maze.width, "x", maze.height)
print("grid: ", maze.grid_width, "x", maze.grid_height)
print("cell (0, 0) is open:", maze.grid[1][1] == 0)
print("top-left corner is a wall:", maze.grid[0][0] == 1)

# The solution: shortest path (BFS), as a list of (x, y) cell coordinates.
path, explored = bfs_solve_maze(maze)
print("path length:", len(path), "cells")
print("first three steps:", path[:3])
print("directions:", path_to_direction(path))
print("cells visited while searching:", len(explored))

# create_maze() already solved it: the same values are cached on the generator.
print("cached path matches:", generator.path == path)

# The hexadecimal encoding is a separate, file-facing representation.
print("first hex row:", encode_maze_to_hex(maze)[0])
```

Output:

```
cells: 20 x 15
grid:  41 x 31
cell (0, 0) is open: True
top-left corner is a wall: True
path length: 75 cells
first three steps: [(0, 0), (0, 1), (0, 1)]
directions: SSSEEESESEESESSSSSESSESENESEENESEEEEE
cells visited while searching: 540
cached path matches: True
first hex row: 93913913951391155393
```

#### Constructor parameters

`MazeGenerator(height, width, entry, exit, perfect, seed=None)`

| Parameter | Type | Default | Meaning |
|---|---|---|---|
| `height` | `int` | *required* | Number of cell rows. |
| `width` | `int` | *required* | Number of cell columns. |
| `entry` | `tuple[int, int]` | *required* | Start cell as `(x, y)`: `x` in `0..width-1`, `y` in `0..height-1`. |
| `exit` | `tuple[int, int]` | *required* | Goal cell as `(x, y)`, same ranges as `entry`. |
| `perfect` | `bool` | *required* | `True` leaves the maze perfect: no loops, so any two connected cells have exactly one route between them. `False` removes dead ends, adds loops, and forces the four corners and the centre cell open and reachable. |
| `seed` | `int \| None` | `None` | Seeds the generator for reproducible mazes. The same seed with the same other arguments gives the same maze. `None` leaves the random module unseeded, so every run differs. |

Only `seed` has a default; the other five are required. Note that a seed is
applied with `random.seed()`, which seeds the standard library's global random
state, not a private one.

`create_maze()` returns the `Maze` and raises `ValueError` if it cannot produce
a valid maze within 1000 attempts.

#### Reaching the maze structure

`create_maze()` returns the `Maze`, and also stores it on the generator as
`generator.maze` (`None` before the first call).

A `Maze` carries:

| Attribute | Meaning |
|---|---|
| `height`, `width` | Cell dimensions, as passed to the constructor. |
| `entry`, `exit` | Cell coordinates, as passed to the constructor. |
| `grid_height`, `grid_width` | `2 * height + 1` and `2 * width + 1`. |
| `grid` | The maze itself: `list[list[int]]`, indexed `grid[row][column]` — that is, `grid[y][x]`. |

The grid is a wall-and-cell layout: rows and columns alternate between cells
and the walls separating them. Odd coordinates are cells, even coordinates are
walls, and the outermost ring is always solid border. Cell `(x, y)` sits at
`grid[2 * y + 1][2 * x + 1]`, and the wall between two horizontally adjacent
cells sits at the even column between them.

Each grid entry holds one of three values:

| Value | Meaning |
|---|---|
| `0` | Open — a corridor you can walk through. |
| `1` | Wall. |
| `2` | Wall belonging to the "42" logo stamped into the centre. Solid like `1`; the separate value only marks it as permanent so generation never carves through it. |

##### The grid is not the hexadecimal encoding

`encode_maze_to_hex(maze)` returns a *different* representation: one string per
cell row, one hexadecimal digit per cell, `height` strings of `width`
characters. Each digit is a bitmask of that cell's four walls — north `1`,
east `2`, south `4`, west `8` — so `f` is a fully walled cell and `0` a fully
open one.

That encoding is what the output file contains. It is derived from `maze.grid`
but is not the same thing, and neither has the other's dimensions: the grid is
`(2 * height + 1) x (2 * width + 1)` integers with walls as their own entries,
while the hex form is `height x width` digits with walls folded into each
cell's bits. Read `maze.grid` to inspect a maze in memory; read the hex rows to
understand a written file.

#### Reaching a solution

`bfs_solve_maze(maze)` returns `(path, explored)`. `create_maze()` already
calls it, so the same two lists are available as `generator.path` and
`generator.explored` without solving again.

`path` is **the shortest path** from `entry` to `exit`: the solver is a
breadth-first search, which visits cells in order of distance from the entry,
so the first route it reaches the exit by is a minimal one. It is empty if the
exit is unreachable. `explored` is every cell BFS visited on the way, in visit
order — useful for animating or debugging the search, not part of the answer.

Both lists are `(x, y)` cell coordinates. They are converted down from the
grid, which includes the wall positions the search stepped through, so
consecutive entries repeat: a 38-cell route comes back as 75 entries.
`path_to_direction(path)` collapses that into the move string —
`"SSSEEESES..."` using `N`, `E`, `S`, `W` — which is what the repeated entries
are there for.

#### Public API

Everything below is importable directly from `mazegen`:

- `MazeGenerator` — the generator class.
- `Maze` — the maze structure it produces.
- `bfs_solve_maze(maze)` — shortest path plus explored cells.
- `encode_maze_to_hex(maze)` — hexadecimal wall encoding, one string per row.
- `path_to_direction(path)` — path as a string of `N`/`E`/`S`/`W` moves.

## Output analyser

`maze_analyzer.py` is our own verification tool. It reads a maze *output file* —
not the source code — and re-derives everything from scratch, so it checks the
written result rather than trusting the generator.

```bash
venv/bin/python3 maze_analyzer.py maze.txt
```

It checks wall coherence (every shared wall encoded the same way by both cells
that touch it), connectivity from the entry and whether any open corridor is
unreachable, whether the exit is reachable, the number of independent loops
(zero means a perfect maze), dead ends split into real ones and ones merely
enclosed by the "42" pattern, and the four corners plus the centre cell that a
Pac-Man-style board needs open.

It prints a measurement block and a one-line verdict. A malformed file gives a
clear message and exit code `2` instead of a traceback. Two thresholds drive the
playable verdict: `--min-loops N` (independent routes required, default `2`) and
`--max-dead-ends N` (real dead ends tolerated, default `2`; use `0` to check the
no-dead-end bonus).

## Error handling

- **Missing config file** raises `FileNotFoundError` before any generation.
- **Malformed config line** — no `=`, a duplicate key, coordinates that are not
  two integers, a non-integer or out-of-range `WIDTH`/`HEIGHT`/`SEED`, or a
  `PERFECT` that is neither `True` nor `False` — is reported with its line number.
- **Invalid config values** — a missing mandatory key, an `ENTRY`/`EXIT` outside
  the maze, or `ENTRY` identical to `EXIT` — are rejected after parsing, naming
  the offending key. Both kinds print `Configuration Error: ...` to standard
  error and exit `1`.
- **Generation failure** after 1000 retries raises `ValueError`, reported as
  `Maze Generation Error: ...`, exit `1`.
- **Output write failure** is caught and reported; the program keeps running so
  the maze is still displayed.
- **`Ctrl-C`, end-of-input, and unexpected errors in the menu** are caught — the
  first two exit cleanly, the last leaves the session running.

## The team

### Roles

**dganapat** — maze generation algorithm, pathfinding, user interaction,
docstrings.

**si-wong** — maze generation, configuring the maze data, Makefile,
documentation.

### Planning, and how it evolved

We researched the topic before writing anything. We were initially unsure how to
divide the work, and settled on splitting it by component, because the components
turned out to be loosely coupled and could be worked on in parallel. Cleanup and
documentation were done jointly at the end.

### Retrospective

**What worked.** The split by component — once the boundaries were clear, the two
of us could work at the same time without blocking each other. And building the
Makefile early, which turned the compile-and-rerun loop into one command we used
constantly.

**What could be improved.** We exchanged files directly instead of using version
control. That cost us time and left no history of how the project evolved; we
should learn a proper git workflow. We also wrote no unit tests — we verified
output with our own analyser instead, which caught real problems, but a test
suite would have caught regressions earlier.

### Tools used

`flake8` (style), `mypy` (static typing), `make`, Python virtual environments,
`git`, VS Code, our own output analyser `maze_analyzer.py`, and AI.

## Resources

Jet Brains - A-maze-ing - Tutorial 
https://academy.jetbrains.com/course/17519
https://www.codecademy.com/article/depth-first-search-dfs-algorithm
https://www.geeksforgeeks.org/dsa/breadth-first-search-or-bfs-for-a-graph/

### AI usage

AI was used for explaining maze generation algorithms, discussing software
architecture, reviewing Python code, improving documentation, generating README
structure, and suggesting refactoring ideas.

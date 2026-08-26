*This project has been created as part of the 42 curriculum by \<wabin-wa\>, \<luli2\>*

# A-Maze-ing

# Description

A-Maze-ing is a command-line maze generator written in Python. It reads a
configuration file, generates a maze, solves the shortest path from entry to
exit, displays the result in the terminal, and saves the maze in the required
hexadecimal output format.

The project supports two generation modes:

* `PERFECT=True`: generates a perfect maze, meaning there is exactly one path
  between any two reachable cells and no loops.
* `PERFECT=False`: starts from a perfect maze and opens extra walls to create a
  more playable, Pac-Man-style board with loops and without dead ends.

Main features:

* configurable width, height, entry, exit, output file, mode, delay, and seed
* randomized maze generation with reproducible results when a seed is provided
* shortest-path solving with BFS
* terminal rendering with optional path display and colour rotation
* reusable `mazegen` package for future Python projects

# Instructions

### Create virtual environment

```bash
python3 -m venv .venv
source .venv/bin/activate
```

Windows:

```bash
.venv\Scripts\activate
```

### Install dependencies

```bash
make install
```

### Run

```bash
make run
```

### Debug

```bash
make debug
```

### Lint

```bash
make lint
```

### Build reusable package

```bash
make build
```


# Configuration

Configuration file format：

```text
WIDTH=30
HEIGHT=30
ENTRY=0,0
EXIT=19,24
OUTPUT_FILE=maze.txt
PERFECT=True
DELAY=0
SEED=42
```


* `WIDTH`: number of columns in the maze. It must be a positive integer.
* `HEIGHT`: number of rows in the maze. It must be a positive integer.
* `ENTRY`: entry coordinate in `column,row` format.
* `EXIT`: exit coordinate in `column,row` format.
* `OUTPUT_FILE`: file path where the generated maze and solution are saved.
* `PERFECT`: `true` or `false`, case-insensitive.
* `DELAY`: delay in seconds between animation frames when animation is enabled.
* `SEED`: integer used to make maze generation reproducible.

The entry and exit must be inside the maze, must not be the same cell, and must
not overlap the mandatory `42` pattern when the pattern fits inside the maze.

# Maze Generation Algorithm

### Perfect Maze

The perfect maze is generated with a randomized depth-first search backtracking
algorithm.

The generator starts from the entry cell, marks it as visited, then repeatedly
chooses a random unvisited neighbour. It removes the wall between the current
cell and that neighbour, pushes the neighbour onto a stack, and continues from
there. When a cell has no unvisited neighbours, the algorithm backtracks by
popping the stack until it can continue elsewhere.

This algorithm is a good fit for the project because it is simple, iterative,
easy to visualize during generation, and naturally creates a connected maze
without cycles. Since every reachable cell is visited once and each new cell is
connected by exactly one removed wall, the result has one unique path between
cells.

### Imperfect Maze

When `PERFECT=False`, the program first generates a perfect maze, then removes
additional valid walls to make the board less linear.

The imperfect step focuses on:

* opening dead ends where possible
* making the four corners and the centre easier to reach
* adding at least two independent routes
* avoiding very large open areas
* preserving the `42` pattern cells as blocked cells

### Solver

The solver uses breadth-first search (BFS). It starts from the entry cell and
explores all reachable cells layer by layer through open walls. Each visited
cell stores its parent cell and the direction used to reach it.

BFS gives the shortest path because all moves have the same cost. The first
time BFS reaches the exit, it has used the minimum possible number of steps.
The solver then reconstructs the path by walking backward through the parent
map and reversing the result.

## Program Architecture

```text
a_maze_ing.py
    ↓
Config
    ↓
Maze
    ↓
MazeGenerator
    ↓
MazeSolver
    ↓
render / save output
```

File overview:

* `a_maze_ing.py`: main CLI entry point. It loads the config, generates and
  solves the maze, renders the menu, and saves output.
* `config.py`: reads `KEY=VALUE` settings, validates them, converts them to
  typed attributes, and writes the final output file.
* `maze.py`: stores the maze grid, wall states, entry, exit, `42` pattern,
  hex encoding, and terminal rendering.
* `generator.py`: generates perfect mazes with randomized DFS and converts
  them into imperfect mazes when requested.
* `solver.py`: finds the shortest path from entry to exit using BFS.
* `directions.py`: stores movement metadata for north, east, south, and west.

## mazegen — Usage Guide

`mazegen` is a standalone, reusable Python package for generating, solving, and
rendering mazes. It can be installed with `pip` and imported into any future
project independently of the `a_maze_ing.py` CLI tool.

### Installation

``bash
pip install mazegen-1.0.0-py3-none-any.whl
``

or, from source, at the root of the repository:

``bash
pip install .
``

### Import

``python
from mazegen import Maze, MazeGenerator, MazeSolver
import random
``

---

### 1. Basic example

``python
import random
from mazegen import Maze, MazeGenerator, MazeSolver

# Reproducibility: seed the global random module before generating
random.seed(42)

# 1. Create an empty maze grid
maze = Maze(height=10, width=10, start=(0, 0), end=(9, 9))

# 2. Carve the maze (perfect = single unique path, no loops)
generator = MazeGenerator(maze, perfect=True)
generator.generate_maze()

# 3. Solve it (shortest path, breadth-first search)
solver = MazeSolver(maze)
solver.solver()

print("Solved:", solver.found_solution)
``

That's the minimal flow: **create → generate → solve**.

---

### 2. Passing custom parameters

### Maze size and entry/exit points

``python
maze = Maze(
    height=15,       # number of rows
    width=20,        # number of columns
    start=(0, 0),    # entry coordinates (row, col)
    end=(14, 19),    # exit coordinates (row, col)
)
``

### Reproducibility (seed)

`mazegen` uses Python's built-in `random` module internally, so reproducibility
is controlled by seeding it **before** calling `generate_maze()`:

``python
random.seed(1234)   # same seed -> same maze, every time
``

### Perfect vs. non-perfect maze

``python
# Perfect maze: exactly one path between start and end, no loops
generator = MazeGenerator(maze, perfect=True)

# Non-perfect maze: Pac-Man-style board with loops and open corners
generator = MazeGenerator(maze, perfect=False)

generator.generate_maze()
``

### Animation / display while generating (optional)

`generate_maze()` accepts optional parameters to preview the carving process
in the terminal (mainly intended for the CLI, but usable standalone too):

``python
generator.generate_maze(
    R=0, G=150, B=225,       # wall colour (RGB)
    delay=0.05,               # seconds between animation frames
    display_generation=True,  # print each step to the terminal
)
``

---

### 3. Accessing the generated structure

The `Maze` object exposes the maze data directly — this is **not** the same
format as the hexadecimal output file, but a Python-native structure that is
easier to work with programmatically.

``python
maze.height    # int, number of rows
maze.width     # int, number of columns
maze.start     # tuple[int, int], entry coordinates (row, col)
maze.end       # tuple[int, int], exit coordinates (row, col)
maze._42       # set[tuple[int, int]], cells forming the "42" pattern
``

Each cell is a dictionary keyed by cardinal direction, where `True` means the
wall is closed and `False` means it's open:

``python
maze.maze[row][col] # -> {"N": True, "E": False, "S": True, "W": True}
``

Example: check whether you can move east from cell (2, 3):

``python
if not maze.maze[2][3]["E"]:
    print("Open path to the east")
``

Helper methods are also available on the `Maze` object:

``python
maze.cell_to_int(r, c)   # int, hexadecimal-style wall encoding (0-15) for one cell
maze.maze_to_hex()       # str, full maze encoded as a hex grid (one row per line)
``

---

### 4. Accessing the solution

`MazeSolver` computes the shortest path from `maze.start` to `maze.end` using
a breadth-first search.

``python
solver = MazeSolver(maze)
solver.solver()

solver.found_solution   # bool, True if a path exists
solver.solution_path    # list[tuple[tuple[int, int], str | None]]
``

`solution_path` is an ordered list of `(coordinates, direction_taken)` pairs,
from start to end. The very first entry has `direction_taken = None` since no
move was needed to reach the starting cell:

``python
for (r, c), direction in solver.solution_path:
    print(f"At ({r}, {c})", f"-> moved {direction}" if direction else "(start)")
``

To get just the ordered list of cells on the path:

``python
path_cells = [coord for coord, _ in solver.solution_path]
``

To get just the sequence of moves (e.g. `"NEESS"`):

``python
path_moves = "".join(
    direction for _, direction in solver.solution_path if direction is not None
)
``

---

### Summary

| Task | Call |
|---|---|
| Create a maze grid | `Maze(height, width, start, end)` |
| Set the seed for reproducibility | `random.seed(seed_value)` before generating |
| Generate a perfect maze | `MazeGenerator(maze, perfect=True).generate_maze()` |
| Generate a Pac-Man-style board | `MazeGenerator(maze, perfect=False).generate_maze()` |
| Read wall data for a cell | `maze.maze[r][c]["N"/"E"/"S"/"W"]` |
| Get hex-encoded maze | `maze.maze_to_hex()` |
| Solve the maze | `MazeSolver(maze).solver()` |
| Read the solution path | `solver.solution_path` |

## Output Format

* each maze cell is represented by one hexadecimal digit from `0` to `f`
* a set bit means the corresponding wall is closed
* bit mapping: `N = 1`, `E = 2`, `S = 4`, `W = 8`
* after the maze grid, one blank line separates the footer
* the footer contains `ENTRY`, `EXIT`, and the shortest path

Example:

```text
953915553
af86afffa
afc5057fa
afffafffa
813fafd52
c46fefffe

0,0
2,5
SSSSEES
```

In this example, `0,0` is the entry, `2,5` is the exit, and `SSSSEES` is the
shortest path as a sequence of moves.

## Controls

* `1`: regenerate a new maze using the same configuration
* `2`: show or hide the shortest path overlay
* `3`: rotate the wall colour used in the terminal render
* `4`: toggle generation animation on or off
* `5`: quit the program

# Team Work

### Roles

* Member A: luli2 worked on the command-line flow, reusable package structure, and testing/validation, and documentation.
* Member B: wabin-wa, worked on the configuration handling, maze data structure, generation algorithm, solver, output format.

### Planning and evolution

* At the beginning, the project was split into CLI/configuration work and core
  maze logic work.
* During development, the code was reorganized into the reusable `mazegen`
  package so the generator, solver, and renderer could be imported separately.
* The non-perfect mode was adjusted after the perfect maze worked, because it
  needed extra rules for loops, corners, dead ends, and Pac-Man-style play.

### What worked / what did not

The randomized DFS approach worked well for perfect maze generation because it
is easy to reason about and produces connected mazes without loops. BFS also
worked well for solving because it gives the shortest path directly.

The harder part was the imperfect maze mode. Simply removing random walls can
create messy boards, disconnected-looking areas, or large open spaces, so the
wall removal step uses extra validation before opening a wall.

# Resources

* Python documentation
* setuptools and packaging documentation
* algorithm references for randomized DFS/backtracking
* algorithm references for breadth-first search
* 42 project subject and evaluation requirements

### AI Usage

AI was used to help explain the algorithms, improve documentation wording, and
review whether the project structure was clear. The final behaviour is still
verified through the source code, configuration validation, generated output
format, and the maze analyzer script.

## License

This project is licensed under the MIT License.
See `LICENSE.md`.

# Bonus

* `--max-dead-ends 0`: stricter analyzer mode for checking the no-dead-end
  bonus condition
* animation during maze generation: the CLI can display intermediate generation
  frames when animation is enabled
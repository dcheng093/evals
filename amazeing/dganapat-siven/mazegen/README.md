# mazegen

A standalone maze generator: builds a rectangular maze, solves it, and encodes
it for output.

**Requires Python 3.10 or newer. It needs nothing beyond the standard
library** — `mazegen` declares no dependencies, and installing it pulls nothing
else in.

## Install

```sh
pip install mazegen-1.0.0-py3-none-any.whl
```

## Complete example

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

## Constructor parameters

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

## Reaching the maze structure

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

### The grid is not the hexadecimal encoding

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

## Reaching a solution

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

## Public API

Everything below is importable directly from `mazegen`:

- `MazeGenerator` — the generator class.
- `Maze` — the maze structure it produces.
- `bfs_solve_maze(maze)` — shortest path plus explored cells.
- `encode_maze_to_hex(maze)` — hexadecimal wall encoding, one string per row.
- `path_to_direction(path)` — path as a string of `N`/`E`/`S`/`W` moves.

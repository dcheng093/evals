import random
from .maze import Maze
from .solver import bfs_solve_maze
import sys


def add_42_logo(maze: Maze) -> list[tuple[int, int]]:
    """Stamps the '42' wall logo into the center of the maze grid."""
    pattern = [
        [1, 0, 1, 0, 1, 1, 1],
        [1, 0, 1, 0, 0, 0, 1],
        [1, 1, 1, 0, 1, 1, 1],
        [0, 0, 1, 0, 1, 0, 0],
        [0, 0, 1, 0, 1, 1, 1],
    ]
    pat_w = len(pattern[0])
    pat_h = len(pattern)

    grid = maze.grid
    grid_h = maze.grid_height
    grid_w = maze.grid_width

    if grid_w < (pat_w + 4) or grid_h < (pat_h + 4):
        print(
            f"Warning: Maze dimensions ({maze.width}x{maze.height}) "
            "are too small to fit the '42' pattern.",
            file=sys.stderr
        )
        return []

    start_y = (grid_h // 2) - (pat_h // 2)
    start_x = (grid_w // 2) - (pat_w // 2)

    # Cell centers only ever sit on odd (row, col) grid coordinates. The
    # pattern's own middle row/column must land on one of those, or the
    # "42" glyph's built-in gap won't coincide with a real cell -- it'll
    # coincide with a wall instead, and the Pac-Man centre requirement
    # becomes geometrically impossible to satisfy without punching a
    # hole in the logo. Nudge the placement by one row/col when needed.
    if (start_y + pat_h // 2) % 2 == 0:
        start_y += 1
    if (start_x + pat_w // 2) % 2 == 0:
        start_x += 1

    logo_pos = []
    for y in range(pat_h):
        for x in range(pat_w):
            if pattern[y][x] == 1:
                gy = start_y + y
                gx = start_x + x
                grid[gy][gx] = 2  # Mark as permanent logo wall
                logo_pos.append((gy, gx))
    return logo_pos


def dfs_generator(maze: Maze, logo_pos: list[tuple[int, int]]) -> None:
    """Generates maze corridors using DFS, avoiding logo wall positions."""
    grid = maze.grid
    height = maze.grid_height
    width = maze.grid_width
    directions = [(0, -1), (0, 1), (-1, 0), (1, 0)]

    def dfs(x: int, y: int) -> None:
        grid[y][x] = 0
        for dx, dy in random.sample(directions, len(directions)):
            nx, ny = (x + dx * 2), (y + dy * 2)
            wall_x, wall_y = x + dx, y + dy

            if (0 < nx < width - 1) and (0 < ny < height - 1):
                if (
                    grid[ny][nx] == 1
                    and (ny, nx) not in logo_pos
                    and (wall_y, wall_x) not in logo_pos
                ):
                    grid[wall_y][wall_x] = 0
                    dfs(nx, ny)

    dfs(1, 1)


def apply_entry_exit(maze: Maze) -> None:
    """Marks entry and exit interior cells as open corridors without
    breaking outer border walls."""
    grid = maze.grid
    x1, y1 = maze.entry
    x2, y2 = maze.exit

    # Convert cell coordinates to grid pathway coordinates
    entry_x, entry_y = (x1 * 2 + 1), (y1 * 2 + 1)
    exit_x, exit_y = (x2 * 2 + 1), (y2 * 2 + 1)

    # Ensure interior entry/exit cells are open corridors
    grid[entry_y][entry_x] = 0
    grid[exit_y][exit_x] = 0

    # Ensure perimeter border walls around the entire grid remain
    # completely intact (1)
    # North & South outer borders
    for x in range(maze.grid_width):
        grid[0][x] = 1
        grid[maze.grid_height - 1][x] = 1

    # West & East outer borders
    for y in range(maze.grid_height):
        grid[y][0] = 1
        grid[y][maze.grid_width - 1] = 1


def check_open_areas(maze: Maze) -> bool:
    """Ensures no 3x3 open floor area exists anywhere in the grid."""
    grid = maze.grid
    for y in range(0, maze.grid_height - 2):
        for x in range(0, maze.grid_width - 2):
            if all(
                grid[y + dy][x + dx] == 0 for dy in range(3) for dx in range(3)
            ):
                return False
    return True


def apply_pacman_corners_and_center(
    maze: Maze,
    logo_pos: list[tuple[int, int]],
) -> None:
    """Ensures four outer corners and center cell are open AND reachable.

    Just setting the cell to 0 isn't enough -- if every wall around it is
    still closed it becomes an isolated one-cell room, which the analyzer
    (correctly) reports as an unreachable corridor. So we also carve a
    passage to a neighboring cell if one doesn't already exist.
    """
    grid = maze.grid
    h = maze.grid_height
    w = maze.grid_width

    def ensure_open_and_connected(cx: int, cy: int) -> None:
        grid[cy][cx] = 0

        # Already connected to an open neighbor? nothing more to do.
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = cx + dx * 2, cy + dy * 2
            wx, wy = cx + dx, cy + dy
            if 0 < nx < w - 1 and 0 < ny < h - 1 and grid[wy][wx] == 0:
                return

        # Otherwise carve one passage toward the nearest non-logo neighbor.
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = cx + dx * 2, cy + dy * 2
            wx, wy = cx + dx, cy + dy
            if (
                0 < nx < w - 1 and 0 < ny < h - 1
                and (wy, wx) not in logo_pos
                and (ny, nx) not in logo_pos
            ):
                grid[wy][wx] = 0
                grid[ny][nx] = 0
                return

    # Four corner cells on outer perimeter pathways
    corners = [(1, 1), (w - 2, 1), (1, h - 2), (w - 2, h - 2)]
    for cx, cy in corners:
        ensure_open_and_connected(cx, cy)

    # Center cell
    cy, cx = (h // 2) | 1, (w // 2) | 1
    ensure_open_and_connected(cx, cy)


def remove_dead_ends_and_add_loops(
    maze: Maze,
    logo_pos: list[tuple[int, int]],
) -> None:
    """Removes dead-ends and ensures multiple loops exist in non-perfect
    mode."""
    grid = maze.grid
    height = maze.grid_height
    width = maze.grid_width

    # 1. Repeatedly eliminate dead-ends by knocking down adjacent
    #    internal walls
    changed = True
    while changed:
        changed = False
        for y in range(1, height - 1, 2):
            for x in range(1, width - 1, 2):
                # Count open neighbors
                open_neighbors = []
                for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    nx, ny = x + dx * 2, y + dy * 2
                    wx, wy = x + dx, y + dy
                    if 0 < nx < width - 1 and 0 < ny < height - 1:
                        if grid[wy][wx] == 0:
                            open_neighbors.append((wx, wy))

                # If cell is a dead end (only 1 open connection),
                # break an extra wall
                if len(open_neighbors) == 1:
                    candidates = []
                    for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                        wx, wy = x + dx, y + dy
                        if (
                            0 < wx < width - 1 and 0 < wy < height - 1
                            and grid[wy][wx] == 1
                            and (wy, wx) not in logo_pos
                        ):
                            candidates.append((wx, wy))

                    if candidates:
                        wall_to_remove = random.choice(candidates)
                        grid[wall_to_remove[1]][wall_to_remove[0]] = 0
                        if check_open_areas(maze):
                            changed = True
                        else:
                            grid[wall_to_remove[1]][wall_to_remove[0]] = 1


class MazeGenerator:
    def __init__(
        self,
        height: int,
        width: int,
        entry: tuple[int, int],
        exit: tuple[int, int],
        perfect: bool,
        seed: int | None = None,
    ) -> None:
        self.height = height
        self.width = width
        self.entry = entry
        self.exit = exit
        self.perfect = perfect
        self.seed = seed
        self.maze: Maze | None = None
        self.path: list[tuple[int, int]] = []
        self.explored: list[tuple[int, int]] = []

    def create_maze(self) -> Maze:
        if self.seed is not None:
            random.seed(self.seed)

        for _ in range(1000):
            maze = Maze(self.height, self.width, self.entry, self.exit)

            # 1. Place "42" pattern first
            logo_pos = add_42_logo(maze)

            # 2. Build maze corridors around logo
            dfs_generator(maze, logo_pos)
            apply_entry_exit(maze)

            # 3. Apply Pac-Man parameters if PERFECT=False
            if not self.perfect:
                apply_pacman_corners_and_center(maze, logo_pos)
                remove_dead_ends_and_add_loops(maze, logo_pos)

            # 4. Enforce 3x3 open area constraint
            if not check_open_areas(maze):
                continue

            # 5. Solve maze and verify valid path
            path, explored = bfs_solve_maze(maze)
            if path:
                self.maze = maze
                self.path = path
                self.explored = explored
                return maze

        raise ValueError("generate_maze(): Could not generate a valid maze.")


def encode_maze_to_hex(maze: Maze) -> list[str]:
    """Encodes grid wall states into hexadecimal representation.

    Outer perimeter borders always retain closed wall bits (1) for
    entry/exit cells on borders.
    """
    grid = maze.grid
    hex_rows = []

    for y in range(maze.height):
        row_str = ""
        for x in range(maze.width):
            gx = x * 2 + 1
            gy = y * 2 + 1

            # Logo cells (value 2) are just as solid as regular walls (1);
            # only value 0 is an open passage. Checking `== 1` alone left
            # "42"-adjacent walls encoded as open, which is what made
            # logo-boundary cells show up as disconnected-but-not-closed
            # "corridors" instead of proper isolated logo cells.
            wall_bits = 0
            if grid[gy - 1][gx] != 0:
                wall_bits |= 1  # North
            if grid[gy][gx + 1] != 0:
                wall_bits |= 2  # East
            if grid[gy + 1][gx] != 0:
                wall_bits |= 4  # South
            if grid[gy][gx - 1] != 0:
                wall_bits |= 8  # West

            row_str += format(wall_bits, "x")
        hex_rows.append(row_str)

    return hex_rows


def path_to_direction(path: list[tuple[int, int]]) -> str:
    """Converts coordinate path tuples into cardinal direction string (N, E,
      S, W)."""
    if len(path) < 2:
        return ""

    directions = []
    for i in range(len(path) - 1):
        x1, y1 = path[i]
        x2, y2 = path[i + 1]

        dx = x2 - x1
        dy = y2 - y1

        if dx > 0:
            directions.append("E")
        elif dx < 0:
            directions.append("W")
        elif dy > 0:
            directions.append("S")
        elif dy < 0:
            directions.append("N")

    return "".join(directions)

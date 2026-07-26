from collections import deque

from .maze import Maze


def bfs_solve_maze(
    maze: Maze,
) -> tuple[list[tuple[int, int]], list[tuple[int, int]]]:
    grid = maze.grid
    height = maze.grid_height
    width = maze.grid_width
    x1, y1 = maze.entry
    x2, y2 = maze.exit

    # Define paths outside boundaries to map correctly
    entry_x, entry_y = (x1 * 2 + 1), (y1 * 2 + 1)
    exit_x, exit_y = (x2 * 2 + 1), (y2 * 2 + 1)

    queue = deque([(entry_x, entry_y)])
    visited = {(entry_x, entry_y)}
    explored = []
    parent = {}

    while queue:
        curr_x, curr_y = queue.popleft()
        explored.append((curr_x, curr_y))

        if (curr_x, curr_y) == (exit_x, exit_y):
            break

        for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            nx, ny = curr_x + dx, curr_y + dy
            if 0 <= nx < width and 0 <= ny < height:
                if grid[ny][nx] == 0 and (nx, ny) not in visited:
                    visited.add((nx, ny))
                    parent[(nx, ny)] = (curr_x, curr_y)
                    queue.append((nx, ny))

    # Reconstruct shortest path
    path = []
    curr = (exit_x, exit_y)
    if curr in visited:
        while curr != (entry_x, entry_y):
            path.append(curr)
            curr = parent[curr]
        path.append((entry_x, entry_y))
        path.reverse()

    # Convert grid coordinates back to cell coordinates (x, y)
    # so that the rest of your program (e.g. path_to_direction) receives
    # expected cell tuples
    path_cells = [(gx // 2, gy // 2) for gx, gy in path]
    explored_cells = [(gx // 2, gy // 2) for gx, gy in explored]

    return path_cells, explored_cells

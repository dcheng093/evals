from mazegen import Maze

RESET = "\033[0m"

THEMES = [
    {  # Magenta, Yellow, Green
        "WALL": "\033[95m",
        "PATH": "\033[93m",
        "LOGO": "\033[92m"
    },
    {  # Blue, Cyan, Yellow
        "WALL": "\033[94m",
        "PATH": "\033[96m",
        "LOGO": "\033[93m"
    },
    {  # Red, Green, White
        "WALL": "\033[91m",
        "PATH": "\033[92m",
        "LOGO": "\033[97m"
    },
    {  # Cyan, White, Red
        "WALL": "\033[96m",
        "PATH": "\033[97m",
        "LOGO": "\033[91m"
    }
]


def print_maze_with_path(maze: Maze,
                         path: list[tuple[int, int]],
                         theme: dict[str, str] | None = None
                         ) -> None:
    colors = theme if theme is not None else THEMES[0]
    path_grid_set = {(cx * 2 + 1, cy * 2 + 1) for cx, cy in path}

    for y in range(maze.grid_height):
        row_str = ""
        for x in range(maze.grid_width):
            if (x, y) in path_grid_set:
                row_str += colors["PATH"] + "· " + RESET  # Path element
            elif maze.grid[y][x] == 1:
                row_str += colors["WALL"] + "██" + RESET  # Wall
            elif maze.grid[y][x] == 2:
                row_str += colors["LOGO"] + "▒▒" + RESET  # 42 Logo Wall
            else:
                row_str += "  "  # Walkable empty space
        print(row_str)

from dataclasses import dataclass


@dataclass
class Maze:
    def __init__(self,
                 height: int,
                 width: int,
                 entry: tuple[int, int],
                 exit: tuple[int, int]) -> None:
        self.height = height
        self.width = width
        self.entry = entry
        self.exit = exit

        self.grid_height = 2 * height + 1
        self.grid_width = 2 * width + 1

        # Initialize grid with walls (1)
        self.grid: list[list[int]] = [
            [1 for _ in range(self.grid_width)]
            for _ in range(self.grid_height)
        ]

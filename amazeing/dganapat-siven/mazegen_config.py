import os
from typing import Any
from dataclasses import dataclass


@dataclass
class MazeConfig():
    width: int
    height: int
    entry: tuple[int, int]
    exit: tuple[int, int]
    output_file: str
    perfect: bool
    seed: int | None = None


class ConfigReader():
    def __init__(self) -> None:
        self.data: dict[str, Any] = {}

    def read(self, filename: str) -> MazeConfig:
        self.data.clear()

        if not os.path.exists(filename):
            raise FileNotFoundError(f"Configuration file not '{filename}'"
                                    "not found.")

        try:
            with open(filename, "r") as f:
                for line_num, line in enumerate(f, 1):
                    line = line.strip()

                    # Ignore empty lines and comment lines (#)
                    if not line or line.startswith("#"):
                        continue
                    if "=" not in line:
                        raise ValueError(
                            f"Line {line_num}: Invalid line format "
                            f"(missing '='): '{line}'"
                        )

                    key, value = line.split("=", 1)
                    key = key.strip().upper()
                    value = value.strip()

                    if key in self.data:
                        raise ValueError(f"Line {line_num}: Duplicate"
                                         f"key '{key}' found")

                    if key in ("ENTRY", "EXIT"):
                        parts = value.split(",")
                        if len(parts) != 2:
                            raise ValueError(
                                f"Line {line_num}: Invalid coordinate "
                                f"format for {key}: '{value}'"
                            )
                        try:
                            x, y = int(parts[0].strip()), int(parts[1].strip())
                            self.data[key] = (x, y)
                        except ValueError:
                            raise ValueError(
                                f"Line {line_num}: Coordinates for {key} "
                                "must be integers"
                            )

                    elif key == "SEED":
                        try:
                            self.data[key] = int(value)
                        except ValueError:
                            raise ValueError(
                                f"Line {line_num}: SEED must be an "
                                f"integer, got '{value}'"
                            )

                    elif key == "PERFECT":
                        if value.lower() not in ("true", "false"):
                            raise ValueError(
                                f"Line {line_num}: PERFECT must be True "
                                f"or False, got '{value}'"
                            )
                        self.data[key] = value.lower() == "true"

                    elif key in ("WIDTH", "HEIGHT"):
                        try:
                            val = int(value)
                            if val < 2:
                                raise ValueError(
                                    f"Line {line_num}: {key} must be "
                                    "at least 2"
                                )
                            self.data[key] = val
                        except ValueError:
                            raise ValueError(
                                f"Line {line_num}: {key} must be an integer"
                            )

                    else:
                        self.data[key] = value

        except Exception as e:
            raise RuntimeError(f"Failed to parse config file: {e}") from e

        self.validate()

        return MazeConfig(
            width=self.data["WIDTH"],
            height=self.data["HEIGHT"],
            entry=self.data["ENTRY"],
            exit=self.data["EXIT"],
            output_file=self.data["OUTPUT_FILE"],
            perfect=self.data["PERFECT"],
            seed=self.data.get("SEED")
        )

    def in_bounds(self, coord: tuple[int, int]) -> bool:
        x, y = coord
        return bool(
            0 <= x < self.data["WIDTH"] and 0 <= y < self.data["HEIGHT"]
        )

    def validate(self) -> None:
        required_keys = [
            "WIDTH", "HEIGHT", "ENTRY", "EXIT", "OUTPUT_FILE", "PERFECT"
        ]
        for key in required_keys:
            if key not in self.data:
                raise ValueError(f"Missing required configuration key: {key}")

        for coord_key in ("ENTRY", "EXIT"):
            coord = self.data[coord_key]
            if not self.in_bounds(coord):
                raise ValueError(
                    f"{coord_key} {coord} is out of bounds for maze size "
                    f"({self.data['WIDTH']}x{self.data['HEIGHT']})"
                )

        if self.data["ENTRY"] == self.data["EXIT"]:
            raise ValueError("ENTRY and EXIT coordinates cannot be identical")

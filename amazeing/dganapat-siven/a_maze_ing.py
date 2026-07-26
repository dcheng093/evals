import sys
from mazegen_config import ConfigReader
from mazegen import MazeGenerator, encode_maze_to_hex, path_to_direction
from mazegen_display import print_maze_with_path, THEMES


def save_output_file(config_output: str, generator: MazeGenerator) -> None:
    """Writes hexadecimal maze grid, entry/exit coordinates, and path to
    file."""
    if not config_output or not generator.maze:
        return

    try:
        hex_rows = encode_maze_to_hex(generator.maze)
        dir_path = path_to_direction(generator.path)

        with open(config_output, "w") as f:
            for row in hex_rows:
                f.write(row + "\n")
            f.write("\n")
            f.write(f"{generator.maze.entry[0]},{generator.maze.entry[1]}\n")
            f.write(f"{generator.maze.exit[0]},{generator.maze.exit[1]}\n")
            f.write(f"{dir_path}\n")
    except IOError as e:
        print(
            f"Error: Could not write output file '{config_output}': {e}",
            file=sys.stderr,
        )


def main() -> None:
    if len(sys.argv) > 2:
        print("Usage: python3 a_maze_ing.py [config_file]", file=sys.stderr)
        sys.exit(1)

    config_file = sys.argv[1] if len(sys.argv) > 1 else "config.txt"

    try:
        reader = ConfigReader()
        config = reader.read(config_file)
    except Exception as e:
        print(f"Configuration Error: {e}", file=sys.stderr)
        sys.exit(1)

    try:
        generator = MazeGenerator(
            height=config.height,
            width=config.width,
            entry=config.entry,
            exit=config.exit,
            perfect=config.perfect,
            seed=config.seed,
        )

        print("Generating initial maze...")
        generator.create_maze()
        save_output_file(config.output_file, generator)
    except Exception as e:
        print(f"Maze Generation Error: {e}", file=sys.stderr)
        sys.exit(1)

    show_path = True
    color_index = 0

    while True:
        try:
            print("\n" + "=" * 30)
            print("           A-MAZE-ING            ")
            print("=" * 30)

            if generator.maze is None:
                print("Error: no maze available to display.", file=sys.stderr)
                sys.exit(1)

            current_theme = THEMES[color_index % len(THEMES)]
            active_path = generator.path if show_path else []

            print_maze_with_path(
                maze=generator.maze, path=active_path, theme=current_theme
            )

            print("\nInteractive Menu:")
            print("1. Re-generate a new maze")
            state = "ON" if show_path else "OFF"
            print(f"2. Show/Hide shortest path (Currently: {state})")
            print("3. Change wall colors")
            print("4. Quit")

            choice = input("\nChoice (1-4): ").strip()

            if choice == "1":
                print("\nRe-generating maze...")
                generator.seed = None  # Clear seed on interactive regeneration
                generator.create_maze()
                save_output_file(config.output_file, generator)

            elif choice == "2":
                show_path = not show_path

            elif choice == "3":
                color_index += 1

            elif choice == "4":
                print("Exiting A-Maze-ing...")
                break

            else:
                print("Invalid option. Please enter a choice between 1 and 4.")

        except (KeyboardInterrupt, EOFError):
            print("\nExiting A-Maze-ing...")
            sys.exit(0)
        except Exception as e:
            print(
                f"An unexpected error occurred during execution: {e}",
                file=sys.stderr,
            )


if __name__ == "__main__":
    main()

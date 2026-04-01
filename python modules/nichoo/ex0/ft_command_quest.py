# Data Structures
# - Lists : Backpack [Ordered, Expendable]
# - Tuples : Armor (Immutable, Reliable)
# - Sets : Achievements (Unique, No duplicates)
# - Dictionaires : Spellbook (instant lookups by name)

# Generators
# Comprehension


import sys


def get_arguments() -> list[str]:
    return (sys.argv[1:])


def command_quest() -> None:
    print("=== Command Quest ===")

    try:
        arguments = get_arguments()
        no_of_arguments = len(arguments)
        if not (no_of_arguments):
            raise Exception("No arguments given!")
        print(f"Program name: {sys.argv[0]}")

    except Exception as e:
        print(f"{e}")
        print(f"Program name: {sys.argv[0]}")

    else:
        print(f"Arguments received: {no_of_arguments}")

        i = 0
        while i < no_of_arguments:
            print(f"Argument {i + 1}: {arguments[i]}")
            i += 1

    finally:
        print(f"Total arguments: {len(sys.argv)}")


if __name__ == "__main__":
    command_quest()

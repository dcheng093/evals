# sequences (little s) are a duck type.
#   A sequence is any ordered collection of objects that
#   provides random access to its members.
#   Specifically, if it defines __len__ and __getitem__ and uses
#   integer indices between 0 and n-1 then it is a sequence.
#
# A Sequence (big s) is a nominal type.
#   That is, to be a Sequence, a class must be declared as such,
#   either by inheriting from Sequence or being registered as a subclass.
#
# Sequence Types - Lists, Tuples and Range
#
# Tuples
#   Tuples are immutable sequences, typically used to store
#   collections of heterogeneous data
#   (such as the 2-tuples produced by the enumerate() built-in).
#   Tuples are also used for cases where an immutable sequence of
#   homogeneous data is needed (such as allowing storage
#   in a set or dict instance).


import sys
import math


def get_arguments() -> tuple:
    """Parses coordinates from the command-line"""
    coords = []
    no_of_arguments = len(sys.argv)
    if no_of_arguments != 4:
        raise Exception("Incorrect usage.\n"
                        "Try: "
                        "python3 ft_coordinate_system.py "
                        "<x1> <y1> <z1> ")

    for i in range(1, 4):
        coords.append(int(sys.argv[i]))

    return (tuple(coords))


def atoi(arguments: tuple) -> tuple:
    """Converts a string of digits into a tuple"""
    arguments = tuple(int(num) for num in arguments)
    return arguments


def calculate_distance(start: tuple, end: tuple) -> float:
    """Calculates the distance between two 3d points"""
    (x1, y1, z1) = start
    (x2, y2, z2) = end
    distance = math.sqrt((x2-x1)**2 + (y2-y1)**2 + (z2-z1)**2)

    return distance


def ft_coordinate_system() -> None:
    print("=== Game Coordinate System ===")
    print()

    try:
        no_of_arguments = len(sys.argv)

        # Scenario where 3 arguments were given
        if no_of_arguments > 1:
            coord = get_arguments()
            print(f"Position created: {coord}")
            print("Distance between (0, 0, 0) and "
                  f"({coord[0]}, {coord[1]}, {coord[2]}): "
                  "%.2f" % calculate_distance((0, 0, 0), coord))

        # Scenario where 0 arguments were given
        else:
            coord = ('10', '20', '5')

            coord = atoi(coord)
            print("Parsing coordinates: \""
                  f"{coord[0]}, {coord[1]}, {coord[2]}\"")
            print(f"Position created: {coord}")
            print("Distance between (0, 0, 0) and "
                  f"({coord[0]}, {coord[1]}, {coord[2]}): "
                  "%.2f" % calculate_distance((0, 0, 0), coord))
            print()

            bad_coord = ('abc', 'def', 'ghi')

            print("Parsing coordinates: \""
                  f"{bad_coord[0]}, {bad_coord[1]}, "
                  f"{bad_coord[2]}\"")

            try:
                bad_coord = atoi(bad_coord)

            except ValueError as e:
                print("Error parsing coordinates: "
                      f"{e}")
                print("Error details - Type: ValueError, "
                      f"Args: (\"{e}\")")

    except ValueError as e:
        print("Error parsing coordinates: "
              f"{e}")
        print("Error details - Type: ValueError, "
              f"Args: (\"{e}\")")

    except Exception as e:
        print(f"{e}")

    else:
        print()
        print("Unpacking demonstration:")
        (x, y, z) = coord
        print(f"Coordinates: x={x}, y={y}, z={z}")


if __name__ == "__main__":
    ft_coordinate_system()

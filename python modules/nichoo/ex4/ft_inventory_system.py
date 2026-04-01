# Dictionaries
# - A set of key:pair values, with the requirement
#   that the keys are unique (within one dictionary).
#   A pair of braces creates an empty dictionary: {}.
#
#   The main operations on a dictionary are storing a
#   value with some key and extracting the value given the key.
#   If you store using a key that is already in use,
#   the old value associated with that key is forgotten.


import sys


def get_arguments() -> dict:
    no_of_arguments = len(sys.argv)

    if no_of_arguments == 1:
        raise Exception("Invalid input. "
                        "Try python3 ft_inventory_system.py "
                        "<key:value> <key:value> ...")

    arguments = []
    for i in range(1, no_of_arguments):
        if ":" not in sys.argv[i]:
            raise Exception("No value found "
                            f"for key: '{sys.argv[i]}'. "
                            "Try <key:value>.")

        item = sys.argv[i].split(":")
        if not item[1]:
            raise Exception("Invalid key value pair: "
                            f"'{item[0]}':'{item[1]}'")

        try:
            if int(item[1]) < 0:
                raise ValueError

        except ValueError:
            raise ValueError(f"Invalid value '{item[1]}' "
                             "in a key:value pair. "
                             "Please provide value "
                             "that is a positive integer.")

        arguments.append(item)

    return (dict(arguments))


def convert_values(d: dict) -> dict:
    return {key: int(value) for key, value in d.items()}


def calculate_value_total(values: dict) -> int:
    sum = 0
    for value in values:
        sum += int(value)
    return (sum)


def print_unit(unit: int) -> None:
    if unit == 0 or unit > 1:
        print("units", end="")
    else:
        print("unit", end="")


def print_ratio(unit: int, total: int) -> None:
    try:
        print(" (%.2f" % (unit/total * 100),
              "%)")
    except ZeroDivisionError:
        pass


def sort_items_into_categories(d: dict) -> dict:
    item_categories = {
            "Moderate": {},
            "Scarce": {}
        }

    item_categories["Moderate"] = {
        w: d[w] for w in d if int(d[w]) >= 5
    }
    item_categories["Scarce"] = {
        w: d[w] for w in d if int(d[w]) < 5
    }

    return (item_categories)


def ft_inventory_system() -> None:
    try:
        d = get_arguments()
        keys = d.keys()
        values = d.values()
        d = convert_values(d)

    except Exception as e:
        print(f"{e}")

    else:
        print("=== Inventory System Analysis ===")

        total_items = calculate_value_total(values)
        print(f"Total items in inventory: {total_items}")
        print(f"Unique item types: {len(keys)}")
        print()

        print("=== Current Inventory ===")

        d = {w: d[w] for w in sorted(d, key=d.get, reverse=True)}
        for k, v in d.items():
            print(f"{k}: {v} ", end="")
            print_unit(v)
            print_ratio(v, total_items)
        print()

        print("=== Inventory Statistics ===")
        most_abundant = list(d.keys())[0]
        most_abundant_units = int(d[most_abundant])
        least_abundant = list(d.keys())[len(keys) - 1]
        least_abundant_units = int(d[least_abundant])

        # Cool, alternative way for printing units
        #
        # [start:end] or 'slicing' is for assessing
        # a sub-sequence of a sequence.
        #
        # In this case, it makes a copy of 's', and sets
        # the end index at 0 (for slicing, the end
        # indicates the first index that isn't in the splice)
        # where it omits the 's', or at 1, where it copies
        #
        # ^ is the XOR (exclusive OR) operator:
        # same = 0, different = 1
        # 0 XOR 1 = 1
        # 1 XOR 1 = 0
        # >1 XOR 1 = 1

        print(f"Most abundant: {most_abundant} ({most_abundant_units} "
              f"unit{'s'[:most_abundant_units ^ 1]})")
        print(f"Least abundant: {least_abundant} ({least_abundant_units} "
              f"unit{'s'[:least_abundant_units ^ 1]})")
        print()
        print("=== Item Categories ===")
        item_categories = sort_items_into_categories(d)
        print(f"Moderate (>=5): {item_categories['Moderate']}")
        print(f"Scarce (<5): {item_categories['Scarce']}")
        print()

        print("=== Management Suggestions ===")
        print("Restock needed (<1 remaining): "
              f"{[k for k, v in d.items() if int(v) <= 1]}")
        print()

        print("=== Dictionary Properties Demo ===")
        print("Dictionary keys: "
              f"{[k for k in d.keys()]}")
        print("Dictionary values: "
              f"{[v for v in d.values()]}")
        print("Sample lookup - 'sword' in inventory: "
              f"{'sword' in d}")


if __name__ == "__main__":
    ft_inventory_system()

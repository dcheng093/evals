def garden_operations():
    try:
        print("Testing ValueError...")
        int("abc")
    except ValueError:
        print("Caught ValueError: invalid literal for int()\n")

    try:
        print("Testing ZeroDivisionError...")
        return 10 / 0
    except ZeroDivisionError:
        print("Caught ZeroDivisionError: division by zero\n")

    try:
        print("Testing FileNotFoundError...")
        return open("missing.txt")
    except FileNotFoundError:
        print("Caught FileNotFoundError: No such file 'missing.txt'\n")

    try:
        print("Testing KeyError...")
        missing = {"flowers": 5}
        print(missing["plant"])
    except KeyError:
        print("Caught KeyError: 'missing\\_plant'\n")


def test_error_types():
    print("=== Garden Error Types Demo ===\n")
    garden_operations()
    print("Testing multiple errors together...")
    try:
        return int("abc")
    except (ValueError, ZeroDivisionError):
        print("Caught an error, but program continues!\n")
    print("All error types tested successfully!")

def check_plant_health(plant_name, water, hours):
    if len(plant_name) == 0:
        raise ValueError("Error: Plant name cannot be empty!")
    elif hours < 2:
        raise ValueError(f"Error: Sunlight hours {hours} is too low (min 2)")
    elif hours > 12:
        raise ValueError(f"Error: Sunlight hours {water} is too high (max 10)")
    elif water < 1:
        raise ValueError(f"Error: Water level {water} is too low (min 1)")
    elif water > 10:
        raise ValueError(f"Error: Water level {water} is too high (max 10)")
    return f"Plant '{plant_name}' is healthy!"


def test_plant_checks():
    print("=== Garden Plant Health Checker ===\n")

    print("Testing good values...")
    try:
        result = check_plant_health("Tomato", 5, 6)
        print(result)
    except ValueError as e:
        print(e)
    print("")

    print("Testing good values...")
    try:
        check_plant_health("", 5, 6)
    except ValueError as e:
        print(e)
    print("")

    print("Testing good values...")
    try:
        check_plant_health("Carrot", 0, 6)
    except ValueError as e:
        print(e)
    print("")

    print("Testing bad sunlight hours...")
    try:
        check_plant_health("Lettuce", 5, 15)
    except ValueError as e:
        print(e)
    print("\nAll error raising tests completed!")

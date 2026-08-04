class GardenError(Exception):
    def __init__(self, message: str = "Garden Error") -> None:
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message: str = "The tomato plant is wilting!") -> None:
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message: str = "Not enough water in the tank!") -> None:
        super().__init__(message)


def water_plant(plant_name: str) -> None:
    if plant_name == plant_name.capitalize():
        print(f"Watering {plant_name}: [OK]")
    else:
        raise PlantError(f"Invalid plant name to water: '{plant_name}'")


def test_watering_system(x: int) -> None:
    try:
        if x == 1:
            print("Testing valid plants...")
            print("Opening watering system")
            for y in "Tomato", "Lettuce", "Carrots":
                water_plant(y)
        elif x == 2:
            print("Testing invalid plants...")
            print("Opening watering system")
            for y in "Tomato", "lettuce", "carrots":
                water_plant(y)
    except PlantError as e:
        print(f"Caught PlantError: {e}")
        print(".. ending tests and returning to main")
        return
    finally:
        print("Closing watering system")


def main() -> None:
    print("=== Garden Watering System ===")
    print()
    test_watering_system(1)
    print()
    test_watering_system(2)
    print()
    print("Cleanup always happens, even with errors!")


if __name__ == "__main__":
    main()

class GardenError(Exception):
    def __init__(self, message: str = "Garden Error") -> None:
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message: str = "The tomato plant is wilting!") -> None:
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message: str = "Not enough water in the tank!") -> None:
        super().__init__(message)


def main() -> None:
    print("=== Custom Garden Errors Demo ===")
    print()

    print("Testing PlantError...")
    try:
        raise PlantError()
    except PlantError as e:
        print(f"Caught PlantError: {e}")
    print()

    print("Testing WaterError...")
    try:
        raise WaterError()
    except WaterError as e:
        print(f"Caught WaterError: {e}")
    print()

    print("Testing catching all garden errors...")
    try:
        raise PlantError()
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    try:
        raise WaterError()
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    print()

    print("All custom error types work correctly!")


if __name__ == "__main__":
    main()

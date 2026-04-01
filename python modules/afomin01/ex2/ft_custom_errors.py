class GardenError(Exception):
    def __init__(self, message: str):
        super().__init__("Caught a garden error: " + message)


class PlantError(GardenError):
    def __init__(self, plant: str):
        super().__init__(f"The {plant} is wilting!")


class WaterError(GardenError):
    def __init__(self):
        super().__init__("Not enough water in the tank!")


def plantEr(plant: str, show=False):
    if show:
        print("Testing PlantError...")
    try:
        raise PlantError(plant)
    except GardenError as e:
        print(e)
    if show:
        print("")


def waterEr(show=False):
    if show:
        print("Testing WaterError...")
    try:
        raise WaterError()
    except GardenError as e:
        print(e)
    if show:
        print("")


def gardenEr():
    print("Testing catching all garden errors...")
    plantEr("Pluto")
    waterEr()
    print("")


print("=== Custom Garden Errors Demo ===\n")
plantEr("tomato", True)
waterEr(True)
gardenEr()
print("All custom error types work correctly!")

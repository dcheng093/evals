class NotPlantError(Exception):
    pass


class EmptyNameError(Exception):
    pass


class NegativeWater(Exception):
    pass


class HealthError(Exception):
    pass


class EmptyTankError(Exception):
    pass


class Plant:

    def __init__(self, name, water=0, sun=0):
        self.name = name
        self.water = water
        self.sun = sun

    def check_health(self):
        if self.water > 10:
            raise HealthError(f"Error checking {self.name}: " +
                              f"Water level {self.water} is too high (max 10)")
        elif self.water < 1:
            raise HealthError(f"Error checking {self.name}: " +
                              f"Water level {self.water} is too low (min 1)")
        elif self.sun < 2:
            raise HealthError(f"Error checking {self.name}: " +
                              f"Sunlight level {self.sun} is too low (min 2)")
        elif self.sun > 12:
            raise HealthError(f"Error checking {self.name}: Sunlight level " +
                              f"{self.sun} is too high (max 12)")
        else:
            print(f"{self.name}: healthy " +
                  f"(water: {self.water}, sun: {self.sun})")


class Garden:

    def __init__(self):
        self.__plants = []

    def add_plant(self, plant):
        try:
            if type(plant) is not Plant:
                raise NotPlantError("Error adding plant: Not a Plant object")
            if not plant.name:
                raise EmptyNameError("Error adding plant: Name is empty")
            else:
                print(f"Added {plant.name} - success")
                self.__plants.append(plant)
        except Exception as e:
            print(e)

    def water_plants(self, ammount, water_level):
        print("Watering plants...")
        try:
            if ammount < 0:
                raise NegativeWater("Error watering plant: Negative ammount")
            else:
                for plant in self.__plants:
                    if ammount > water_level:
                        raise EmptyTankError("Error: Not enough water in tank")
                    plant.water += ammount
                    water_level -= ammount
        except Exception as e:
            print(e)
        finally:
            print("Closing watering system (cleanup)")

    def check_health(self):
        print("Checking plant health...")
        if len(self.__plants) == 0:
            print("List of plants is empty.")
        else:
            try:
                for plant in self.__plants:
                    plant.check_health()
            except Exception as e:
                print(e)


class GardenManager:
    def __init__(self):
        pass

    @staticmethod
    def report(garden):
        print("=== Garden Managment System ===\n")
        print("Adding plants to garden...")
        garden.add_plant(Plant("Potato"))
        garden.add_plant(Plant("Helsinki"))
        garden.add_plant(Plant("Kandibober"))
        print("")
        garden.water_plants(1, 40)
        garden.check_health()
        print("\nTesting error recovery...")
        garden.water_plants(1, 0)
        print("\nGarden management system test complete!")


garden = Garden()
GardenManager.report(garden)

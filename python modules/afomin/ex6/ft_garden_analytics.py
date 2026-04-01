class GardenStats:

    def __init__(self, points):
        self.__totalGrowth = 0
        self.__added = 0

    def get_growth(self):
        return self.__totalGrowth

    def reset_growth(self):
        self.__totalGrowth = 0

    def add_growth(self, growth: int):
        self.__totalGrowth += growth

    def get_added(self):
        return self.__added

    def reset_added(self):
        self.__added = 0

    def add_added(self, new: int):
        self.__added += new


class Plant:
    __plantType = "regular"

    def __init__(self, name: str, cmPerDay: float, height=0):
        if (height < 0):
            height = 0
        self.__name = name
        self.__cmPerDay = cmPerDay
        self.__height = height

    def get_name(self):
        return self.__name

    def get_height(self):
        return self.__height

    def get_type():
        return Plant.__plantType

    def grow(self, days=1):
        if (days > 0):
            growth = days * self.__cmPerDay
            self.__height += growth
            return growth

    def display(self, endChars="\n"):
        print(f"- {self.__name}: {self.__height}cm", end=endChars)


class FloweringPlant(Plant):
    __plantType = "flowering"

    def __init__(self, name: str, cmPerDay: float, color: str, height=0):
        super().__init__(name, cmPerDay, height)
        self.__color = color

    def get_color(self):
        return self.__color

    def get_type():
        return FloweringPlant.__plantType

    def display(self, endChars="\n"):
        super().display(", ")
        print(f"{self.__color} flowers (blooming)", end=endChars)


class PrizeFlower(FloweringPlant):
    __plantType = "prize flowers"

    def __init__(self, name: str, cm: float, color: str, h=0, p=0):
        super().__init__(name, cm, color, h)
        self.__prize = p

    def get_prize(self):
        return self.__prize

    def get_type():
        return PrizeFlower.__plantType

    def display(self):
        super().display(", ")
        print(f"Prize points: {self.__prize}")


class Garden:

    def __init__(self, owner: str, points=0):
        self.__owner = owner
        self.__stats = GardenStats(points)
        self.__plants = []

    def add_plant(self, plant: Plant):
        self.__plants.append(plant)

    def get_owner(self):
        return self.__owner

    def get_plants(self):
        return self.__plants

    def get_stats(self):
        return self.__stats


class GardenManager:

    def __init__(self):
        self.__gardens = []

    @staticmethod
    def show_plants_types(garden: Garden):
        print("Plant types:", end=" ")
        type_count = {}
        for plant in garden.get_plants():
            if type(plant).get_type() in type_count:
                type_count[type(plant).get_type()] += 1
            else:
                type_count[type(plant).get_type()] = 1
        for i, key in enumerate(type_count):
            print(f"{type_count[key]} {key}", end="")
            if i != len(type_count) - 1:
                print(",", end=" ")
        print("\n")

    @staticmethod
    def report_static(garden: Garden):
        stats = garden.get_stats()
        print(f"=== {garden.get_owner()}'s Garden Report ===")
        print("Plants in garden:")
        for plant in garden.get_plants():
            plant.display()
        print(f"\nPlants added: {stats.get_added()}", end=", ")
        print(f"total growth: {stats.get_growth()}")
        GardenManager.show_plants_types(garden)
        stats.reset_growth()
        stats.reset_added()

    def report(self, index: int):
        GardenManager.report_static(self.__gardens[index])

    def add_garden(self, garden: Garden):
        self.__gardens.append(garden)

    def add_plant(self, index: int, plant: Plant):
        garden = self.__gardens[index]
        garden.add_plant(plant)
        garden.get_stats().add_added(1)
        print(f"Added {plant.get_name()} to {garden.get_owner()}'s garden")

    def grow(self, index: int, days=1):
        garden = self.__gardens[index]
        print(f"{garden.get_owner()} is helping all plants grow...")
        for plant in garden.get_plants():
            growth = plant.grow(days)
            garden.get_stats().add_growth(growth)
            print(f"{plant.get_name()} grew {growth}cm")
        print("")

    def height_validation(self):
        for garden in self.__gardens:
            for plant in garden.get_plants():
                if plant.get_height() < 0:
                    return False
        return True

    @staticmethod
    def count_points(garden: Garden):
        count = 0
        for plant in garden.get_plants():
            count += plant.get_height()
            if type(plant) is PrizeFlower:
                count += plant.get_prize()
        return int(count)

    def info(self):
        print(f"Height validation test: {self.height_validation()}")
        print("Garden scores:", end=" ")
        for garden in self.__gardens:
            print(f"{garden.get_owner()}:", end=" ")
            print(f"{GardenManager.count_points(garden)}", end="")
            if garden != self.__gardens[-1]:
                print(",", end=" ")
        print(f"\nTotal gardens managed {len(self.__gardens)}")

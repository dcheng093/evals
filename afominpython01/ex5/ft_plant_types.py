class Plant:

    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def display(self):
        print(f"{self.name} ({self.__class__.__name__}):", end=" ")
        print(f"{self.height}cm, {self.age} days", end="")


class Tree(Plant):

    def __init__(self, name, height, age, trunk_diameter):
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def produce_shadow(self):
        print(self.name, f"provides {self.trunk_diameter * 3.14 / 2}", end=" ")
        print("square meters of shade")

    def display(self):
        super().display()
        print(f", {self.trunk_diameter}cm diameter")


class Flower(Plant):

    def __init__(self, name, height, age, color):
        super().__init__(name, height, age)
        self.color = color

    def bloom(self):
        print(self.name, "is blooming beautifully!")

    def display(self):
        super().display()
        print(f", {self.color} color")


class Vegetable(Plant):

    def __init__(self, name, height, age, harvest_season, nutritional_value):
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def display(self):
        super().display()
        print(f", {self.harvest_season} harvest")
        print(f"{self.name} is reach in {self.nutritional_value}")


print("=== Garden Plant Types ===")
flower = Flower("Rose", 20, 10, "Red")
flower.display()
flower.bloom()
print("")
tree = Tree("Oak", 500, 4235, 50)
tree.display()
tree.produce_shadow()
print("")
vegetable = Vegetable("Carrot", 20, 14, "summer", "vitamin A")
vegetable.display()

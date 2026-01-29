class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def get_info(self):
        print(f"{self.name}: {self.height}cm, {self.age} days old")

    def grow(self, days: int, cmPerDay: float):
        self.height += days * cmPerDay
        self.age += days


cmPerDay = 0.25
plant = Plant("Kartoshka", 20, 20)
print(f"=== Day {plant.age} ===")
plant.get_info()
plant.grow(6, cmPerDay)
print(f"=== Day {plant.age} ===")
plant.get_info()
print(f"Growth this week +{cmPerDay * 6}")

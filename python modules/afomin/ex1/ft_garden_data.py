class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def Display(self):
        print(f"{self.name}: {self.height}cm, {self.age} days old")


plant_a = Plant("Kartoshka", 20, 20)
plant_b = Plant("Banan", 50, 2023)
plant_c = Plant("Alien", 200, 209000123)
print("=== Garden Plant Registry ===")
plant_a.Display()
plant_b.Display()
plant_c.Display()

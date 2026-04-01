#!/usr/bin/env python3
# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_plant_types.py                                 :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: andmarti <andmarti@student.42kl.edu.my>   +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2025/12/18 18:27:37 by andmarti         #+#    #+#              #
#    Updated: 2025/12/18 18:27:38 by andmarti        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

class Plant:
    def __init__(
        self,
        name: str,
        height: int,
        age: int
    ) -> None:
        self.name = name
        self.height = height
        self.age = age


class Flower(Plant):
    def __init__(
        self,
        name: str,
        height: int,
        age: int,
        color: str
    ) -> None:
        super().__init__(name, height, age)
        self.color = color
        print(
            f"{self.name} (Flower): {self.height}cm, ",
            f"{age} days, {self.color} color")

    def bloom(self) -> None:
        print(f"{self.name} is bloomin beautifully!")


class Tree(Plant):
    def __init__(
        self,
        name: str,
        height: int,
        age: int,
        trunk_diameter: int
    ) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter
        print(
            f"{self.name} (Tree): {self.height}cm, ",
            f"{age} days, {self.trunk_diameter}cm diameter")

    def produce_shade(self) -> None:
        r_sq: float = self.trunk_diameter * self.trunk_diameter
        shade: int = int((3.14 * r_sq) / 100)
        print(f"{self.name} provides {shade} square meters of shade")


class Vegetable(Plant):
    def __init__(
        self,
        name: str,
        height: int,
        age: int,
        harvest_season: str,
        nutritional_value: str
    ) -> None:
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value
        print(
            f"{self.name} (Vegetable): {self.height}cm, ",
            f"{age} days, {self.harvest_season} harvest")

    def print_nutrition(self) -> None:
        print(f"{self.name} is {self.nutritional_value}")


if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    print("")
    rose = Flower("Rose", 25, 30, "red")
    rose.bloom()
    print("")
    oak = Tree("Oak", 500, 1825, 50)
    oak.produce_shade()
    print("")
    tomato = Vegetable("Tomato", 80, 90, "summer", "rich in Vitamin C")
    tomato.print_nutrition()
    print("")
    tulip = Flower("Tulips", 25, 40, "pink")
    tulip.bloom()
    print("")
    mango = Tree("Mango Tree", 500, 800, 70)
    mango.produce_shade()
    print("")
    onion = Vegetable("Onion", 80, 80, "winter", "good for blood flow")
    onion.print_nutrition()

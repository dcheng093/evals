#!/usr/bin/env python3
# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_plant_factory.py                               :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: andmarti <andmarti@student.42kl.edu.my>   +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2025/12/18 18:27:17 by andmarti         #+#    #+#              #
#    Updated: 2025/12/18 18:27:18 by andmarti        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

class Plant:
    num_plants = 0  # static

    def __init__(self, name: str, start_height: int, start_age: int) -> None:
        self.name = name.capitalize()
        self.height = start_height  # in cms
        self.days_old = start_age
        Plant.num_plants = Plant.num_plants + 1
        print(f"Created: {self.name} ({self.height}cm, {self.days_old} days)")

    def print(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.days_old} days old")

    def grow(self) -> None:
        self.height = self.height + 1

    def age(self) -> None:
        self.days_old = self.days_old + 1

    def get_info(self) -> None:
        print(self)

    def day_passes(self) -> None:
        self.grow()
        self.age()

    def print_total(self) -> None:
        print(f"Total plants created: {Plant.num_plants}")


if __name__ == "__main__":
    print("=== Plant Factory Output ===")
    r: Plant = Plant("Rose", 25, 30)
    o: Plant = Plant("Oak", 200, 365)
    c: Plant = Plant("Cactus", 5, 90)
    s: Plant = Plant("Sunflower", 80, 45)
    f: Plant = Plant("Fern", 15, 120)
    print("")
    f.print_total()

#!/usr/bin/env python3
# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_garden_analytics.py                            :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: andmarti <andmarti@student.42kl.edu.my>   +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2025/12/18 18:26:44 by andmarti         #+#    #+#              #
#    Updated: 2025/12/18 19:23:59 by andmarti        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

class Plant:
    def __init__(
        self,
        name: str,
        height: int
    ) -> None:
        self.name = name
        self.height = height  # in cm

    def grow(self) -> None:
        self.height = self.height + 1
        print(f"{self.name} grew 1cm")

    def print(self) -> None:
        print(f"- {self.name}: {self.height}cm")


class FloweringPlant(Plant):
    def __init__(
        self,
        name: str,
        height: int,
        color: str
    ) -> None:
        super().__init__(name, height)
        self.color = color

    def print(self) -> None:
        print(
            f"- {self.name}: {self.height}cm,",
            f"{self.color} flowers (blooming)")


class PrizeFlower(FloweringPlant):
    def __init__(
        self,
        name: str,
        height: int,
        color: str,
        points: int
    ) -> None:
        super().__init__(name, height, color)
        self.points = points

    def print(self) -> None:
        print(
            f"- {self.name}: {self.height}cm,",
            f"{self.color} flowers (blooming),",
            f"Prize points: {self.points}")


class Garden:
    def __init__(
        self,
        owner: str,
        start_cum_height: int = 0,
        plants: list[Plant] | None = None
    ) -> None:
        self.owner = owner
        self.start_cum_height = start_cum_height
        self.plants = [] if plants is None else plants

    def garden_report(self) -> None:
        print(f"=== {self.owner}'s Garden Report ===")
        end_cum_height = 0
        tot_plant = 0
        tot_flowering = 0
        tot_prize = 0
        for plant in self.plants:
            end_cum_height += plant.height
            if type(plant) is Plant:
                tot_plant += 1
            if type(plant) is FloweringPlant:
                tot_flowering += 1
            if type(plant) is PrizeFlower:
                tot_prize += 1
        print("Plants in garden:")
        for plant in self.plants:
            plant.print()
        print("")
        tot_plants = len(self.plants)
        growth = end_cum_height - self.start_cum_height
        print(f"Plants added: {tot_plants}, Total growth: {growth}cm")
        print(
            f"Plant types: {tot_plant} regular,"
            f"{tot_flowering} flowering, {tot_prize} prize flowers")

    def get_score(self) -> int:
        garden_score = 0
        for plant in self.plants:
            if type(plant) is FloweringPlant:
                garden_score += 10
            if type(plant) is PrizeFlower:
                garden_score += 20
                garden_score += plant.points
            garden_score += plant.height
        return garden_score

    def add_plant(self, plant: Plant, silent: bool = False) -> None:
        self.plants.append(plant)
        self.start_cum_height += plant.height
        if silent is False:
            print(f"Added {plant.name} to {self.owner}'s garden")

    def grow_all_plants(self) -> None:
        print(f"{self.owner} is helping all plants grow...")
        for plant in self.plants:
            plant.grow()


class GardenManager:
    def __init__(
        self,
        gardens: list[Garden] | None = None
    ) -> None:
        self.gardens = [] if gardens is None else gardens

    def gardens_stats(self) -> None:
        height_valid = True
        for garden in self.gardens:
            for plant in garden.plants:
                if plant.height < 0:
                    height_valid = False
        print(f"Height validation test: {height_valid}")
        if len(self.gardens) <= 0:
            return
        print("Garden scores - ", end="")
        for i in range(len(self.gardens)):
            print(
                f"{self.gardens[i].owner}:",
                f"{self.gardens[i].get_score()}",
                end="")
            if i < len(self.gardens) - 1:
                print(", ", end="")
            else:
                print("")
        print(f"Total gardens managed: {len(self.gardens)}")

    def add_garden(self, garden: Garden) -> None:
        self.gardens.append(garden)


if __name__ == "__main__":
    bob_g = Garden("Bob")
    bob_g.add_plant(Plant("Tomato bush", 92), True)
    print("=== Garden Management System Demo ===")
    print("")
    alice_g = Garden("Alice")
    alice_g.add_plant(Plant("Oak Tree", 100))
    alice_g.add_plant(FloweringPlant("Rose", 25, "red"))
    alice_g.add_plant(PrizeFlower("Sunflower", 50, "yellow", 10))
    print("")
    alice_g.grow_all_plants()
    print("")
    alice_g.garden_report()
    print(f"score: {alice_g.get_score()}")
    print("")
    gm = GardenManager()
    gm.add_garden(alice_g)
    gm.add_garden(bob_g)
    gm.gardens_stats()

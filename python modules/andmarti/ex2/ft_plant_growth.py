#!/usr/bin/env python3
# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_plant_growth.py                                :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: andmarti <andmarti@student.42kl.edu.my>   +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2025/12/18 18:27:09 by andmarti         #+#    #+#              #
#    Updated: 2025/12/18 18:27:10 by andmarti        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

class Plant:
    def __init__(self, name: str, height: int, days_old: int) -> None:
        self.name = name.capitalize()
        self.height = height  # in cms
        self.days_old = days_old

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


if __name__ == "__main__":
    days_passed: int = 0
    r = Plant("Rose", 25, 30)
    start_h = r.height
    print(f"=== Day {days_passed + 1} ===")
    r.print()
    while days_passed < 6:
        r.day_passes()
        days_passed = days_passed + 1
    print(f"=== Day {days_passed + 1} ===")
    r.print()
    end_h = r.height
    print(f"Growth this week: +{end_h - start_h}cm")

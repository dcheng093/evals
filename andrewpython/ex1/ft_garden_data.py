#!/usr/bin/env python3
# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_garden_data.py                                 :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: andmarti <andmarti@student.42kl.edu.my>   +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2025/12/18 18:26:16 by andmarti         #+#    #+#              #
#    Updated: 2025/12/18 18:26:18 by andmarti        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

class Plant:
    def __init__(self, name: str, height: int, days_old: int) -> None:
        self.name = name.capitalize()
        self.height = height  # in cms
        self.days_old = days_old

    def print(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.days_old} days old")


if __name__ == "__main__":
    print("=== Garden Plant Registry ===")
    r = Plant("Rose", 25, 30)
    r.print()
    s = Plant("Sunflower", 80, 45)
    s.print()
    c = Plant("Cactus", 15, 120)
    c.print()

#!/usr/bin/env python3
# *************************************************************************** #
#                                                                             #
#                                                        :::      ::::::::    #
#    ft_garden_security.py                             :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+      #
#    By: andmarti <andmarti@student.42kl.edu.my>   +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+            #
#    Created: 2025/12/18 18:27:29 by andmarti         #+#    #+#              #
#    Updated: 2025/12/18 18:27:32 by andmarti        ###   ########.fr        #
#                                                                             #
# *************************************************************************** #

class SecurePlant:
    def __init__(
        self,
        name: str,
        height: int,
        age: int
    ) -> None:
        self.name = name
        self._height = height
        self._age = age
        print(f"Plant created: {name}")

    def set_height(self, h: int) -> None:
        if (h < 0):
            print(
                "Invalid operation attempted: ",
                f"height {h}cm [REJECTED]")
            print("Security: Negative height rejected")
        else:
            self._height = h
            print(
                "Height updated: "
                f"{h}cm [OK]")

    def set_age(self, a: int) -> None:
        if (a < 0):
            print(
                "Invalid operation attempted: "
                f"age {a} days [REJECTED]")
            print("Security: Negative age rejected")
        else:
            self._age = a
            print(
                "Age updated: "
                f"{a} days [OK]")

    def get_height(self) -> int:
        return self._height

    def get_age(self) -> int:
        return self._age

    def print_current(self) -> None:
        print(
            "Current plant: "
            f"{self.name} ({self._height}cm, {self._age} days)")


if __name__ == "__main__":
    print("=== Garden Security System ===")
    r = SecurePlant("Rose", 25, 30)
    r.set_height(25)
    r.set_age(30)
    print("")
    r.set_height(-5)
    # r.set_age(-5)
    print("")
    r.print_current()

# ************************************************************************** #
#                                                                            #
#                                                         :::      ::::::::  #
#    ft_seed_inventory.py                               :+:      :+:    :+:  #
#                                                     +:+ +:+         +:+    #
#    By: lchin <lchin@student.42kl.edu.my>          +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+          #
#    Created: 2026/01/13 12:58:43 by lchin             #+#    #+#            #
#    Updated: 2026/01/13 12:58:58 by lchin            ###   ########.fr      #
#                                                                            #
# ************************************************************************** #

# print(f"...") -> prints a formatted string, {} refers to code

def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    seed_name = seed_type.capitalize()
    if unit == "packets":
        print(f"{seed_name} seeds: {quantity} packets available")
    elif unit == "grams":
        print(f"{seed_name} seeds: {quantity} grams total")
    elif unit == "area":
        print(f"{seed_name} seeds: covers {quantity} square meters")
    else:
        print("Unknown unit type")

# ************************************************************************** #
#                                                                            #
#                                                         :::      ::::::::  #
#    ft_plant_age.py                                    :+:      :+:    :+:  #
#                                                     +:+ +:+         +:+    #
#    By: lchin <lchin@student.42kl.edu.my>          +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+          #
#    Created: 2026/01/13 12:55:06 by lchin             #+#    #+#            #
#    Updated: 2026/01/13 12:55:24 by lchin            ###   ########.fr      #
#                                                                            #
# ************************************************************************** #

def ft_plant_age():
    age = int(input("Enter plant age in days: "))
    if age > 60:
        print("Plant is ready to harvest!")
    else:
        print("Plant needs more time to grow.")


ft_plant_age()
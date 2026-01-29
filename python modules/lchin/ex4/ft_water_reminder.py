# ************************************************************************** #
#                                                                            #
#                                                         :::      ::::::::  #
#    ft_water_reminder.py                               :+:      :+:    :+:  #
#                                                     +:+ +:+         +:+    #
#    By: lchin <lchin@student.42kl.edu.my>          +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+          #
#    Created: 2026/01/13 12:55:46 by lchin             #+#    #+#            #
#    Updated: 2026/01/13 12:56:04 by lchin            ###   ########.fr      #
#                                                                            #
# ************************************************************************** #

def ft_water_reminder():
    last_water = int(input("Days since last watering: "))
    if last_water > 2:
        print("Water the plants!")
    else:
        print("Plants are fine")


ft_water_reminder()
# ************************************************************************** #
#                                                                            #
#                                                         :::      ::::::::  #
#    ft_count_harvest_recursive.py                      :+:      :+:    :+:  #
#                                                     +:+ +:+         +:+    #
#    By: lchin <lchin@student.42kl.edu.my>          +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+          #
#    Created: 2026/01/13 12:57:14 by lchin             #+#    #+#            #
#    Updated: 2026/01/13 12:57:34 by lchin            ###   ########.fr      #
#                                                                            #
# ************************************************************************** #

def ft_count_harvest_recursive(harvest_day=None, current_day=1):
    if harvest_day is None:
        harvest_day = int(input("Days until harvest: "))
    if current_day > harvest_day:
        print("Harvest time!")
        return
    print("Day", current_day)
    ft_count_harvest_recursive(harvest_day, current_day + 1)

ft_count_harvest_recursive()
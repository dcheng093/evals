# ************************************************************************** #
#                                                                            #
#                                                         :::      ::::::::  #
#    ft_harvest_total.py                                :+:      :+:    :+:  #
#                                                     +:+ +:+         +:+    #
#    By: lchin <lchin@student.42kl.edu.my>          +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+          #
#    Created: 2026/01/13 12:54:29 by lchin             #+#    #+#            #
#    Updated: 2026/01/13 12:54:49 by lchin            ###   ########.fr      #
#                                                                            #
# ************************************************************************** #

def ft_harvest_total():
    day1 = int(input("Day 1 harvest: "))
    day2 = int(input("Day 2 harvest: "))
    day3 = int(input("Day 3 harvest: "))
    print("Total harvest:", day1 + day2 + day3)


ft_harvest_total()

# ************************************************************************** #
#                                                                            #
#                                                         :::      ::::::::  #
#    ft_count_harvest_iterative.py                      :+:      :+:    :+:  #
#                                                     +:+ +:+         +:+    #
#    By: lchin <lchin@student.42kl.edu.my>          +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+          #
#    Created: 2026/01/13 12:56:42 by lchin             #+#    #+#            #
#    Updated: 2026/01/13 12:56:59 by lchin            ###   ########.fr      #
#                                                                            #
# ************************************************************************** #

"""
for i in range(start, end), print(i) -> print from start to end - 1
for i in range(end), print(i) -> print from 0 to end - 1
range(start, stop, step), e.g. range(1, 10 2) -> 1, 3, 5, 7, 9
"""


def ft_count_harvest_iterative():
    harvest_day = int(input("Days until harvest: "))
    for day in range(1, harvest_day + 1):
        print("Day", day)
    print("Harvest time!")


ft_count_harvest_iterative()
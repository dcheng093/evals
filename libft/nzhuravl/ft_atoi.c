/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuravl <nzhuravl@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:21:21 by nzhuravl          #+#    #+#             */
/*   Updated: 2025/12/20 20:21:22 by nzhuravl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32
		|| (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (sign * result);
}
/*
int	main(int ac, char **av)
{
	int	a;
	if (ac == 2)
		printf("Input:\n");
		printf("  Argument 1     : \"%s\"\n", av[1]);
		a = ft_atoi(av[1]);
		printf("Result:\n");
		printf("  Number: \"%d\"\n\n", a);
		return (0);
}
*/

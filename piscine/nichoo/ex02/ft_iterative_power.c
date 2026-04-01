/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:22:51 by nichoo            #+#    #+#             */
/*   Updated: 2025/08/17 21:16:52 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	result = 1;
	while (power > 0)
	{
		result = result * nb;
		power--;
	}
	return (result);
}

int main(int ac, char **av)
{
	if (ac != 3)
		return 0;
	int nb = atoi(av[1]);
	int power = atoi(av[2]);
	int result;

	printf("%d\n", result = ft_iterative_power(nb, power));
}

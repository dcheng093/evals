/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:43:09 by nichoo            #+#    #+#             */
/*   Updated: 2025/08/17 21:18:37 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power > 0)
		return (nb * ft_recursive_power(nb, power - 1));
	if (power < 0)
		return (0);
	return (1);
}


int main(int ac, char **av)
{
	if (ac != 3)
		return 0;
	int nb = atoi(av[1]);
	int power = atoi(av[2]);
	int result;

	printf("%d\n", result = ft_recursive_power(nb, power));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 16:39:55 by nichoo            #+#    #+#             */
/*   Updated: 2025/08/17 21:35:13 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 5;
	if (nb == 2 || nb == 3 || nb == 2147483647)
		return (1);
	if (nb <= 1)
		return (0);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	while (i * i <= nb)
	{
		if (nb % (i - 1) == 0 || nb % (i + 1) == 0)
			return (0);
		i += 6;
	}
	return (1);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	int nb = atoi(av[1]);
	int result = ft_is_prime(nb);

	printf("%d\n", result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:34:38 by nichoo            #+#    #+#             */
/*   Updated: 2025/08/17 21:38:55 by dcheng           ###   ########.fr       */
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
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	new_prime;

	if (ft_is_prime(nb))
		return (nb);
	new_prime = nb++;
	while (!ft_is_prime(new_prime))
		new_prime++;
	return (new_prime);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 0;
	int nb = atoi(av[1]);
	int result = ft_find_next_prime(nb);
	printf("%d\n", result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:56:54 by nichoo            #+#    #+#             */
/*   Updated: 2025/08/17 21:09:35 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_factorial(int nb)
{
	int	result;
	int	n;

	if (nb < 0)
		return (0);
	n = 1;
	result = 1;
	while (n <= nb)
		result *= n++;
	return (result);
}

int main(int ac, char **av)
{
	if (ac < 2)
		return 0;

	int nb = atoi(av[1]);
	int result;
	printf("%d\n", result = ft_iterative_factorial(nb)); 
}

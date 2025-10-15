/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:12:16 by nichoo            #+#    #+#             */
/*   Updated: 2025/08/17 21:13:14 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_recursive_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
		return (0);
	if (nb > 0)
		result = nb * ft_recursive_factorial(nb - 1);
	return (result);
}

int main(int ac, char **av)
{
	if (ac < 2)
		return 0;

	int nb = atoi(av[1]);
	int result;
	printf("%d\n", result = ft_recursive_factorial(nb)); 
}

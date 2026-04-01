/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:36:28 by kquek             #+#    #+#             */
/*   Updated: 2025/08/14 12:51:06 by kquek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	if (*b != 0)
	{
		div = *a / *b;
		mod = *a % *b;
		*a = div;
		*b = mod;
	}
}
/*
int	main(void)
{
	int	a;
	int	b;

	a = 10;
	b = 3;
	ft_ultimate_div_mod(&a, &b);
	printf("Division: %d\n", a);
	printf("Modulus: %d\n", b);
	return (0);
}
*/

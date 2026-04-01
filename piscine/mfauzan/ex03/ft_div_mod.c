/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfauzan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:06:25 by mfauzan           #+#    #+#             */
/*   Updated: 2025/08/21 11:05:52 by mfauzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 2;
	b = 5;

	ft_swap(a, b, &div, &mod);
	printf("%d\n", div);
	printf("%d\n", mod);
}*/

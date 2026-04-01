/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:22:18 by mfauzan           #+#    #+#             */
/*   Updated: 2025/08/21 15:49:51 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp;

	tmp = *a / *b;
	*b = *a % *b;
	*a = tmp;
}

int	main(void)
{
	int	a;
	int	b;

	a = 10;
	b = 2;

	ft_ultimate_div_mod(&a, &b);

	printf("%d, %d\n", a, b);
}

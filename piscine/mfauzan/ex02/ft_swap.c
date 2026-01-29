/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfauzan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:00:02 by mfauzan           #+#    #+#             */
/*   Updated: 2025/08/21 11:57:22 by mfauzan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*#inlcude <stdio.h>
 * int	main(void)
{
	int	a;
	int	b;

	a = 5;
	b = 7;

	printf("%d\n", a);
	printf("%d\n", b);

	ft_swap(&a, &b);

	printf("%d\n", a);
	printf("%d\n", b);
}*/

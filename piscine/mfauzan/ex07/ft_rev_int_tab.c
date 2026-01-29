/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:06:53 by mfauzan           #+#    #+#             */
/*   Updated: 2025/08/21 15:50:34 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
}

#include <stdio.h>
int	main(void)
{
	int	i;
	int	tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	int	size;

	i = 0;
	size = sizeof(tab) / sizeof(tab[0]);
	while (i < size)
	{	
		printf("%d", tab[i]);
		i++;
	}

	printf("\n");
	ft_rev_int_tab(tab, size);

	i = 0;
	while (i < size)
	{
		printf("%d", tab[i]);
		i++;
	}
	return (0);
}
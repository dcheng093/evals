/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuravl <nzhuravl@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:42:05 by nzhuravl          #+#    #+#             */
/*   Updated: 2025/12/20 20:45:09 by nzhuravl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 97 && c <= 122)
		|| (c >= 65 && c <= 90));
}
/*
int	main(void)
{
	int c = 'a';
	printf("C is alpha or not: %i\n", ft_isalpha(c));
	printf("'A' -> %d\n", ft_isalpha('A'));
	printf("'z' -> %i\n", ft_isalpha('z'));

	int ch;

	printf("Enter a character: ");
	ch = getchar();

	if (ft_isalpha(ch))
		printf("Is Alpha\n");
	else
		printf("Not Alpha\n");

	return(0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 08:24:58 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/14 15:32:21 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION : Compares a specific number of chars from the 
	null-terminated strings.

	RETURN VALUE : Returns an int that indiciates the relationship 
	between the two strings.
*/

#include "libft.h"
//#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*int     main(void)
{
	char    *s1 = "Lactose intolerance"; //19
	char    *s2 = "Lactose intolerance"; //19

	printf("%d\n", ft_strncmp(s1, s2, 8));
	printf("%d", ft_strncmp(s1, s2, 19));
	return (0);
}*/
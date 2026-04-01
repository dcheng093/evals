/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:38:40 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/14 17:17:04 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	while (*src && size - 1)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (srclen);
}
/*#include <bsd/string.h>
#include <stdio.h>
int		main()
{
	size_t		l;
	char	*s1 = "Hello World";
	char	s2[20];

	l = 20;
	printf("     My Function : %zu\n" , ft_strlcpy(s2, s1, l));
	printf("Orginal Function : %zu\n" , strlcpy(s2, s1, l));
	printf("s2 : %s\n" , s2 );

	return (0);
}*/
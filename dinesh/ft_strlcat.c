/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:32:24 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/14 16:21:22 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen > size)
		return (srclen + size);
	dst += dstlen;
	size -= dstlen;
	while (size > 1 && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (srclen + dstlen);
}
/*#include <bsd/string.h>
#include <stdio.h>
int		main()
{
	size_t		l;
	char	s1[] = "Hello ";
	char	s2[] = "World";
	char    s3[] = "Hello " ;

	l = 10;
	printf("     My Function : %zu\n" , ft_strlcat(s1, s2, l));
	printf("Orginal Function : %zu\n" , strlcat(s3, s2, l));
	printf("New s1 : %s\n" , s1 );
	printf("New s3 : %s\n" , s3 );
	

	return (0);
}*/
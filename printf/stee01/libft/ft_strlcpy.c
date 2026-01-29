/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:42:05 by stee              #+#    #+#             */
/*   Updated: 2025/10/21 14:56:35 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		srclen;

	srclen = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}
/*
#include <stdio.h>
int main(void)
{
    const char *s = "Hello, world!"; // 13
	const char *d = "             ";

	printf("%s\n", d);
	printf("%s\n", ft_strlcpy(d, s, 13);
    return 0;
}*/

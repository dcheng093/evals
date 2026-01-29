/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:44:00 by stee              #+#    #+#             */
/*   Updated: 2025/10/21 14:56:07 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	sum;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	sum = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (size > dstlen)
		sum = dstlen + srclen;
	else
		return (srclen + size);
	while (src[i] != '\0' && size > (dstlen + 1))
	{
		dst[dstlen] = src[i];
		dstlen++;
		i++;
	}
	dst[dstlen] = '\0';
	return (sum);
}
/*
#include <stdio.h>
int main(void)
{
    const char *s = "Hello, world!"; // 13
	const char *d = "This is Test"; // 12

	printf("%s\n", d);
	ft_strlcat(d, s, 25)
	printf("%s\n", d);
    return 0;
}*/

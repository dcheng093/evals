/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:29:28 by asyeo             #+#    #+#             */
/*   Updated: 2026/07/14 15:29:28 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;
	size_t	sum;

	i = 0;
	sum = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (n > dest_len)
		sum = dest_len + src_len;
	else
		return (src_len + n);
	while (src[i] && (dest_len + 1) < n)
		dest[dest_len++] = src[i++];
	dest[dest_len] = '\0';
	return (sum);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char 	dest[10] = "Hello";
// 	size_t	len = ft_strlcat(dest, "World", 11);
// 	printf("Result : %s\n", dest);
// 	printf("Returned : %zu\n", len);
// }

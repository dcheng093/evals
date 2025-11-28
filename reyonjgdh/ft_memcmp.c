/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:33:50 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/11 09:36:56 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*var1;
	unsigned char	*var2;

	var1 = (unsigned char *)s1;
	var2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (var1[i] != var2[i])
			return (var1[i] - var2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	const char *ft_memcmp_string1 = "Fleshling youth, 
// teach me to communicate in trash talk.";
// 	const char *ft_memcmp_string2 = "Fleshling youth, 
// what is that golem on your back?";
// 	size_t size1 = 16;
// 	size_t size2 = 20;

// 	printf("========================================\n");
// 	printf("ft_memcmp\n");
// 	printf("========================================\n");
// 	printf("String1: %s\n", ft_memcmp_string1);
// 	printf("String2: %s\n", ft_memcmp_string2);
// 	printf("Size: %zu\n\n", size1);
// 	printf("Original: %d\n", memcmp(ft_memcmp_string1, 
// ft_memcmp_string2, size1));
// 	printf("Recreation: %d\n", ft_memcmp(ft_memcmp_string1, 
// ft_memcmp_string2, size1));
// 	printf("--------------------\n");

// 	printf("String1: %s\n", ft_memcmp_string1);
// 	printf("String2: %s\n", ft_memcmp_string2);
// 	printf("Size: %zu\n\n", size2);
// 	printf("Original: %d\n", memcmp(ft_memcmp_string1, 
// ft_memcmp_string2, size2));
// 	printf("Recreation: %d\n", ft_memcmp(ft_memcmp_string1, 
// ft_memcmp_string2, size2));
// 	printf("--------------------\n");
// }

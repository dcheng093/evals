/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 07:45:40 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/06 10:09:30 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	// const char *ft_strncmp_string1 = "Fleshling youth, 
	// teach me to communicate in trash talk.";
	// const char *ft_strncmp_string2 = "Fleshling youth, 
	// what is that golem on your back?";
	const char *ft_strncmp_string1 = "test\200";
	const char *ft_strncmp_string2 = "test\0";
	size_t size1 = 6;
	size_t size2 = 0;

	printf("========================================\n");
	printf("ft_strncmp\n");
	printf("========================================\n");
	printf("String1: %s\n", ft_strncmp_string1);
	printf("String2: %s\n", ft_strncmp_string2);
	printf("Size: %zu\n\n", size1);
	printf("Original: %d\n", strncmp(ft_strncmp_string1, 
ft_strncmp_string2, size1));
	printf("Recreation: %d\n", ft_strncmp(ft_strncmp_string1, 
ft_strncmp_string2, size1));
	printf("--------------------\n");

	printf("String1: %s\n", ft_strncmp_string1);
	printf("String2: %s\n", ft_strncmp_string2);
	printf("Size: %zu\n\n", size2);
	printf("Original: %d\n", strncmp(ft_strncmp_string1, 
ft_strncmp_string2, size2));
	printf("Recreation: %d\n", ft_strncmp(ft_strncmp_string1, 
ft_strncmp_string2, size2));
	printf("--------------------\n");

	printf("String1: %s\n", ft_strncmp_string1);
	printf("String2: %s\n", "");
	printf("Size: %zu\n\n", size2);
	printf("Original: %d\n", strncmp(ft_strncmp_string1, "", size2));
	printf("Recreation: %d\n", ft_strncmp(ft_strncmp_string1, "", size2));
	printf("--------------------\n");

	printf("String1: %s\n", "");
	printf("String2: %s\n", ft_strncmp_string2);
	printf("Size: %zu\n\n", size2);
	printf("Original: %d\n", strncmp("", ft_strncmp_string2, size2));
	printf("Recreation: %d\n", ft_strncmp("", ft_strncmp_string2, size2));
	printf("--------------------\n");
}
 */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:34:41 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/11 09:44:23 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(little) == 0)
		return ((char *)big);
	if (len == 0)
		return (0);
	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (*big != '\0' && i < len - ft_strlen(little))
	{
		j = 0;
		while (*(big + j) != '\0' && little[j] && *(big + j) == little[j])
		{
			if (j == ft_strlen(little) - 1)
				return ((char *)big);
			j++;
		}
		big++;
		i++;
	}
	return (0);
}

/* #include <bsd/string.h>
int	main(void)
{
	const char *ft_strnstr_string1 = "Fleshling youth, teach me to 
	communicate in trash talk.";
	const char *ft_strnstr_string2 = "trash";
	size_t size1 = 16;
	size_t size2 = 60;

	printf("========================================\n");
	printf("ft_strnstr\n");
	printf("========================================\n");
	printf("String1: %s\n", ft_strnstr_string1);
	printf("String2: %s\n", ft_strnstr_string2);
	printf("Size: %zu\n\n", size1);
	printf("Original: %s\n", strnstr(ft_strnstr_string1, 
		ft_strnstr_string2, size1));
	printf("Recreation: %s\n", ft_strnstr(ft_strnstr_string1, 
		ft_strnstr_string2, size1));
	printf("--------------------\n");

	printf("String1: %s\n", ft_strnstr_string1);
	printf("String2: %s\n", ft_strnstr_string2);
	printf("Size: %zu\n\n", size2);
	printf("Original: %s\n", strnstr(ft_strnstr_string1, 
ft_strnstr_string2, size2));
	printf("Recreation: %s\n", ft_strnstr(ft_strnstr_string1, 
ft_strnstr_string2, size2));
	printf("--------------------\n");

	printf("String1: %s\n", ft_strnstr_string1);
	printf("String2: %s\n", "");
	printf("Size: %zu\n\n", size2);
	printf("Original: %s\n", strnstr(ft_strnstr_string1, "", size2));
	printf("Recreation: %s\n", ft_strnstr(ft_strnstr_string1, "", size2));
	printf("--------------------\n");
} */
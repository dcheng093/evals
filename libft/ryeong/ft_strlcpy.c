/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:26:07 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/05 16:22:49 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

/* #include <bsd/string.h>
int main(void)
{
	char ft_strlcpy_var1[] = "Fleshling youth, teach ";
	char *ft_strlcpy_var2 = "me to communicate in trash talk.";
	char ft_strlcpy_var3[] = "Fleshling youth, teach ";
	size_t ft_strlcpy_size[] = {0, 50, 80};

	printf("========================================\n");
	printf("ft_strlcpy\n");
	printf("========================================\n");
	printf("Var1: %s\n", ft_strlcpy_var1);
	printf("Var2: %s\n", ft_strlcpy_var2);
	printf("Size: %zu\n\n", ft_strlcpy_size[0]);
	printf("Original: %zu\n", strlcpy(ft_strlcpy_var1, ft_strlcpy_var2, 
ft_strlcpy_size[0]));
	printf("New Var: %s\n", ft_strlcpy_var1);
	printf("Recreation: %zu\n", ft_strlcpy(ft_strlcpy_var3, ft_strlcpy_var2, 
ft_strlcpy_size[0]));
	printf("New Var: %s\n", ft_strlcpy_var3);

	printf("--------------------\n");

	// printf("Var1: %s\n", ft_strlcpy_var1);
	// printf("Var2: %s\n", ft_strlcpy_var2);
	// printf("Size: %zu\n\n", ft_strlcpy_size[1]);
	// printf("Original: %zu\n", strlcpy(ft_strlcpy_var1, ft_strlcpy_var2, 
// ft_strlcpy_size[1]));
	// printf("New Var: %s\n", ft_strlcpy_var1);
	// printf("Recreation: %zu\n", ft_strlcpy(ft_strlcpy_var3, ft_strlcpy_var2, 
// ft_strlcpy_size[1]));
	// printf("New Var: %s\n", ft_strlcpy_var3);

	// printf("--------------------\n");
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:26:44 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/06 07:41:38 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	result;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	result = dstlen + srclen;
	dst += dstlen;
	if (size <= dstlen)
		return (result - (dstlen - size));
	while (src[i] && i < size - dstlen - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (result);
}

/* #include <bsd/string.h>
int main(void)
{
	char ft_strlcat_var1[80] = "Fleshling youth, teach ";
	char *ft_strlcat_var2 = "me to communicate in trash talk.";
	char ft_strlcat_var3[80] = "Fleshling youth, teach ";
	size_t ft_strlcat_size[] = {10, 50, 80};

	printf("========================================\n");
	printf("ft_strlcat\n");
	printf("========================================\n");
	printf("Var1: %s\n", ft_strlcat_var1);
	printf("Var2: %s\n", ft_strlcat_var2);
	printf("Size: %zu\n\n", ft_strlcat_size[0]);
	printf("Original: %zu\n", strlcat(ft_strlcat_var1, 
ft_strlcat_var2, ft_strlcat_size[0]));
	printf("New Var: %s\n", ft_strlcat_var1);
	printf("Recreation: %zu\n", ft_strlcat(ft_strlcat_var3, 
ft_strlcat_var2, ft_strlcat_size[0]));
	printf("New Var: %s\n", ft_strlcat_var3);

	printf("--------------------\n");

	// printf("Var1: %s\n", ft_strlcat_var1);
	// printf("Var2: %s\n", ft_strlcat_var2);
	// printf("Size: %zu\n\n", ft_strlcat_size[1]);
	// printf("Original: %zu\n", strlcat(ft_strlcat_var1, 
// ft_strlcat_var2, ft_strlcat_size[1]));
	// printf("New Var: %s\n", ft_strlcat_var1);
	// printf("Recreation: %zu\n", ft_strlcat(ft_strlcat_var3, 
// ft_strlcat_var2, ft_strlcat_size[1]));
	// printf("New Var: %s\n", ft_strlcat_var3);

	// printf("--------------------\n");
} */
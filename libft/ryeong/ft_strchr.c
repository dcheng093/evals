/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:29:45 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/04 10:01:27 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

// int main(void)
// {
// 	const char *ft_strchr_string = "Fleshling youth, teach me to 
// communicate in trash talk.";
// 	int ft_strchr_char[] = {(int)'\0', (int)'@', (int)'t'};

// 	printf("========================================\n");
// 	printf("ft_strchr\n");
// 	printf("========================================\n");
// 	printf("String: %s\n", ft_strchr_string);
// 	printf("Char: '%c'\n\n", ft_strchr_char[0]);
// 	printf("Original: %s\n", strchr(ft_strchr_string, ft_strchr_char[0]));
// 	printf("Recreation: %s\n", ft_strchr(ft_strchr_string, ft_strchr_char[0]));
// 	printf("--------------------\n");

// 	printf("String: %s\n", ft_strchr_string);
// 	printf("Char: '%c'\n\n", ft_strchr_char[1]);
// 	printf("Original: %s\n", strchr(ft_strchr_string, ft_strchr_char[1]));
// 	printf("Recreation: %s\n", ft_strchr(ft_strchr_string, ft_strchr_char[1]));
// 	printf("--------------------\n");

// 	printf("String: %s\n", ft_strchr_string);
// 	printf("Char: '%c'\n\n", ft_strchr_char[2]);
// 	printf("Original: %s\n", strchr(ft_strchr_string, ft_strchr_char[2]));
// 	printf("Recreation: %s\n", ft_strchr(ft_strchr_string, ft_strchr_char[2]));
// 	printf("--------------------\n");

// 	printf("String: %s\n", "");
// 	printf("Char: '%c'\n\n", ft_strchr_char[2]);
// 	printf("Original: %s\n", strchr("", ft_strchr_char[2]));
// 	printf("Recreation: %s\n", ft_strchr("", ft_strchr_char[2]));
// 	printf("--------------------\n");

// 	printf("String: %s\n", "");
// 	printf("Char: '%c'\n\n", ft_strchr_char[0]);
// 	printf("Original: %s\n", strchr("", ft_strchr_char[0]));
// 	printf("Recreation: %s\n", ft_strchr("", ft_strchr_char[0]));
// 	printf("--------------------\n");
// }
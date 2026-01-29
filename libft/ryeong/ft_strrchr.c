/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:30:19 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/06 09:53:28 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

// int main(void)
// {
// 	const char *ft_strrchr_string = "Fleshling youth, teach me to 
// communicate in trash talk.";
// 	int ft_strrchr_char[] = {(int)'\0', (int)'@', (int)'t'};

// 	printf("========================================\n");
// 	printf("ft_strrchr\n");
// 	printf("========================================\n");
// 	printf("String: %s\n", ft_strrchr_string);
// 	printf("Char: '%c'\n\n", ft_strrchr_char[0]);
// 	printf("Original: %s\n", strrchr(ft_strrchr_string, ft_strrchr_char[0]));
//printf("Recreation: %s\n", ft_strrchr(ft_strrchr_string,ft_strrchr_char[0]));
// 	printf("--------------------\n");

// 	printf("String: %s\n", ft_strrchr_string);
// 	printf("Char: '%c'\n\n", ft_strrchr_char[1]);
// 	printf("Original: %s\n", strrchr(ft_strrchr_string, ft_strrchr_char[1]));
//printf("Recreation: %s\n", ft_strrchr(ft_strrchr_string,ft_strrchr_char[1]));
// 	printf("--------------------\n");

// 	printf("String: %s\n", ft_strrchr_string);
// 	printf("Char: '%c'\n\n", ft_strrchr_char[2]);
// 	printf("Original: %s\n", strrchr(ft_strrchr_string, ft_strrchr_char[2]));
//printf("Recreation: %s\n", ft_strrchr(ft_strrchr_string,ft_strrchr_char[2]));
// 	printf("--------------------\n");

// 	printf("String: %s\n", "");
// 	printf("Char: '%c'\n\n", ft_strrchr_char[2]);
// 	printf("Original: %s\n", strrchr("", ft_strrchr_char[2]));
// 	printf("Recreation: %s\n", ft_strrchr("", ft_strrchr_char[2]));
// 	printf("--------------------\n");

// 	printf("String: %s\n", "");
// 	printf("Char: '%c'\n\n", ft_strrchr_char[0]);
// 	printf("Original: %s\n", strrchr("", ft_strrchr_char[0]));
// 	printf("Recreation: %s\n", ft_strrchr("", ft_strrchr_char[0]));
// 	printf("--------------------\n");
// }
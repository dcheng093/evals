/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 08:35:33 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/03 08:35:37 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	unsigned char	v;

	v = (unsigned char)c;
	if ((v >= 0 && v <= 127))
		return (1);
	else
		return (0);
}

// int main(void)
// {
// 	int ft_isascii_char[] = {(int)'A', (int)'9', (int)'\0', (int)'@', 128};

// 	printf("========================================\n");
// 	printf("ft_isascii\n");
// 	printf("========================================\n");
// 	printf("Char: '%c'\n\n", ft_isascii_char[0]);
// 	printf("Original: %d\n", isascii(ft_isascii_char[0]));
// 	printf("Recreation: %d\n", ft_isascii(ft_isascii_char[0]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_isascii_char[1]);
// 	printf("Original: %d\n", isascii(ft_isascii_char[1]));
// 	printf("Recreation: %d\n", ft_isascii(ft_isascii_char[1]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_isascii_char[2]);
// 	printf("Original: %d\n", isascii(ft_isascii_char[2]));
// 	printf("Recreation: %d\n", ft_isascii(ft_isascii_char[2]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_isascii_char[3]);
// 	printf("Original: %d\n", isascii(ft_isascii_char[3]));
// 	printf("Recreation: %d\n", ft_isascii(ft_isascii_char[3]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_isascii_char[4]);
// 	printf("Original: %d\n", isascii(ft_isascii_char[4]));
// 	printf("Recreation: %d\n", ft_isascii(ft_isascii_char[4]));
// 	printf("--------------------\n");
// }
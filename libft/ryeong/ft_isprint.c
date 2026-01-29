/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 08:36:00 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/05 14:46:15 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	unsigned char	v;

	v = (unsigned char)c;
	if ((v >= 32 && v <= 126))
		return (16384);
	else
		return (0);
}

// int main(void)
// {
// 	int ft_isprint_char[] = {(int)'A', (int)'9', (int)' ', 127, '\n'};

// 	printf("========================================\n");
// 	printf("ft_isprint\n");
// 	printf("========================================\n");
// 	printf("Char: '%c'\n\n", ft_isprint_char[0]);
// 	printf("Original: %d\n", isprint(ft_isprint_char[0]));
// 	printf("Recreation: %d\n", ft_isprint(ft_isprint_char[0]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_isprint_char[1]);
// 	printf("Original: %d\n", isprint(ft_isprint_char[1]));
// 	printf("Recreation: %d\n", ft_isprint(ft_isprint_char[1]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_isprint_char[2]);
// 	printf("Original: %d\n", isprint(ft_isprint_char[2]));
// 	printf("Recreation: %d\n", ft_isprint(ft_isprint_char[2]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_isprint_char[3]);
// 	printf("Original: %d\n", isprint(ft_isprint_char[3]));
// 	printf("Recreation: %d\n", ft_isprint(ft_isprint_char[3]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_isprint_char[4]);
// 	printf("Original: %d\n", isprint(ft_isprint_char[4]));
// 	printf("Recreation: %d\n", ft_isprint(ft_isprint_char[4]));
// 	printf("--------------------\n");
// }
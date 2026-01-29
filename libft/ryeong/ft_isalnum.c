/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 08:34:20 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/03 08:34:50 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	char	v;

	v = (char)c;
	if ((v >= 'A' && v <= 'Z') || (v >= 'a' && v <= 'z')
		|| (v >= '0' && v <= '9'))
		return (8);
	else
		return (0);
}

// int main(void)
// {
// 	int ft_isalnum_char[] = {(int)'A', (int)'Z', (int)'0', (int)'9', (int)'@'};

// 	printf("========================================\n");
// 	printf("ft_isalnum\n");
// 	printf("========================================\n");
// 	printf("Char: '%c'\n\n", ft_isalnum_char[0]);
// 	printf("Original: %d\n", isalnum(ft_isalnum_char[0]));
// 	printf("Recreation: %d\n", ft_isalnum(ft_isalnum_char[0]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_isalnum_char[1]);
// 	printf("Original: %d\n", isalnum(ft_isalnum_char[1]));
// 	printf("Recreation: %d\n", ft_isalnum(ft_isalnum_char[1]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_isalnum_char[2]);
// 	printf("Original: %d\n", isalnum(ft_isalnum_char[2]));
// 	printf("Recreation: %d\n", ft_isalnum(ft_isalnum_char[2]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_isalnum_char[3]);
// 	printf("Original: %d\n", isalnum(ft_isalnum_char[3]));
// 	printf("Recreation: %d\n", ft_isalnum(ft_isalnum_char[3]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_isalnum_char[4]);
// 	printf("Original: %d\n", isalnum(ft_isalnum_char[4]));
// 	printf("Recreation: %d\n", ft_isalnum(ft_isalnum_char[4]));
// 	printf("--------------------\n");
// }
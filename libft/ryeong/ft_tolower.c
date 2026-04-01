/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:28:56 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/04 08:18:54 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	v;

	v = (unsigned char)c;
	if ((v >= 'A' && v <= 'Z'))
		return (c + ('a' - 'A'));
	else
		return (c);
}

// int main(void)
// {
// 	int ft_tolower_char[] = {(int)'c', (int)'@', (int)'T', 128};

// 	printf("========================================\n");
// 	printf("ft_tolower\n");
// 	printf("========================================\n");
// 	printf("Char: '%c'\n\n", ft_tolower_char[0]);
// 	printf("Original: %c\n", (char)tolower(ft_tolower_char[0]));
// 	printf("Recreation: %c\n", (char)ft_tolower(ft_tolower_char[0]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_tolower_char[1]);
// 	printf("Original: %c\n", (char)tolower(ft_tolower_char[1]));
// 	printf("Recreation: %c\n", (char)ft_tolower(ft_tolower_char[1]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_tolower_char[2]);
// 	printf("Original: %c\n", (char)tolower(ft_tolower_char[2]));
// 	printf("Recreation: %c\n", (char)ft_tolower(ft_tolower_char[2]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_tolower_char[3]);
// 	printf("Original: %c\n", (char)tolower(ft_tolower_char[3]));
// 	printf("Recreation: %c\n", (char)ft_tolower(ft_tolower_char[3]));
// 	printf("--------------------\n");
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:27:56 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/04 09:36:54 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	v;

	v = (unsigned char)c;
	if ((v >= 'a' && v <= 'z'))
		return (c - ('a' - 'A'));
	else
		return (c);
}

// int main(void)
// {
// 	int ft_toupper_char[] = {(int)'c', (int)'@', (int)'T', 128};

// 	printf("========================================\n");
// 	printf("ft_toupper\n");
// 	printf("========================================\n");
// 	printf("Char: '%c'\n\n", ft_toupper_char[0]);
// 	printf("Original: %c\n", (char)toupper(ft_toupper_char[0]));
// 	printf("Recreation: %c\n", (char)ft_toupper(ft_toupper_char[0]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_toupper_char[1]);
// 	printf("Original: %c\n", (char)toupper(ft_toupper_char[1]));
// 	printf("Recreation: %c\n", (char)ft_toupper(ft_toupper_char[1]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_toupper_char[2]);
// 	printf("Original: %c\n", (char)toupper(ft_toupper_char[2]));
// 	printf("Recreation: %c\n", (char)ft_toupper(ft_toupper_char[2]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_toupper_char[3]);
// 	printf("Original: %c\n", (char)toupper(ft_toupper_char[3]));
// 	printf("Recreation: %c\n", (char)ft_toupper(ft_toupper_char[3]));
// 	printf("--------------------\n");
// }
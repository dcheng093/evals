/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 08:33:40 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/03 08:33:56 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	char	v;

	v = (char)c;
	if ((v >= '0' && v <= '9'))
		return (2048);
	else
		return (0);
}

// int main(void)
// {
// 	int ft_isdigit_char[] = {(int)'0', (int)'9', (int)'Z'};

// 	printf("========================================\n");
// 	printf("ft_isdigit\n");
// 	printf("========================================\n");
// 	printf("Char: '%c'\n\n", ft_isdigit_char[0]);
// 	printf("Original: %d\n", isdigit(ft_isdigit_char[0]));
// 	printf("Recreation: %d\n", ft_isdigit(ft_isdigit_char[0]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_isdigit_char[1]);
// 	printf("Original: %d\n", isdigit(ft_isdigit_char[1]));
// 	printf("Recreation: %d\n", ft_isdigit(ft_isdigit_char[1]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_isdigit_char[2]);
// 	printf("Original: %d\n", isdigit(ft_isdigit_char[2]));
// 	printf("Recreation: %d\n", ft_isdigit(ft_isdigit_char[2]));
// 	printf("--------------------\n");
// }
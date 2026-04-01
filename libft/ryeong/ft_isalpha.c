/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 08:32:56 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/03 08:33:07 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	char	v;

	v = (char)c;
	if ((v >= 'A' && v <= 'Z') || (v >= 'a' && v <= 'z'))
		return (1024);
	else
		return (0);
}

// int main(void)
// {
// 	int ft_isalpha_char[] = {(int)'A', (int)'\0', (int)'Z'};

// 	printf("========================================\n");
// 	printf("ft_isalpha\n");
// 	printf("========================================\n");
// 	printf("Char: '%c'\n\n", ft_isalpha_char[0]);
// 	printf("Original: %d\n", isalpha(ft_isalpha_char[0]));
// 	printf("Recreation: %d\n", ft_isalpha(ft_isalpha_char[0]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_isalpha_char[1]);
// 	printf("Original: %d\n", isalpha(ft_isalpha_char[1]));
// 	printf("Recreation: %d\n", ft_isalpha(ft_isalpha_char[1]));
// 	printf("--------------------\n");

// 	printf("Char: '%c'\n\n", ft_isalpha_char[2]);
// 	printf("Original: %d\n", isalpha(ft_isalpha_char[2]));
// 	printf("Recreation: %d\n", ft_isalpha(ft_isalpha_char[2]));
// 	printf("--------------------\n");
// }
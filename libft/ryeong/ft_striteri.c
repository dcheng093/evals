/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:27:11 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/04 09:57:19 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (*s)
	{
		f(i, s);
		i++;
		s++;
	}
}

// void    test(unsigned int i, char *c)
// {
//     *c += i;
// }

// int main(void)
// {
// 	char *ft_striteri_string = ft_strdup("Fleshling youth, teach me to 
// communicate in trash talk.");

// 	printf("========================================\n");
// 	printf("ft_striteri\n");
// 	printf("========================================\n");
// 	printf("String: %s\n", ft_striteri_string);
// 	ft_striteri(ft_striteri_string, test);
// 	printf("New String: %s\n", ft_striteri_string);
// 	printf("--------------------\n");

// 	free(ft_striteri_string);
// 	ft_striteri_string = (char *)0;
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:03:24 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/10 07:11:19 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ph;
	int		i;

	ph = NULL;
	i = 0;
	if (s1 != 0 && s2 != 0)
	{
		ph = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
		while (*s1)
		{
			ph[i] = *s1;
			i++;
			s1++;
		}
		while (*s2)
		{
			ph[i] = *s2;
			i++;
			s2++;
		}
		ph[i] = '\0';
		return (ph);
	}
	else
		return (0);
}

// int	main(void)
// {
// 	const char *ft_strjoin_string1 = "Fleshling youth, 
// teach me to communicate in trash talk.";
// 	const char *ft_strjoin_string2 = "Fleshling youth, 
// what is that golem on your back?";
// 	const char *ft_strjoin_string3 = 0;

// 	printf("========================================\n");
// 	printf("ft_strjoin\n");
// 	printf("========================================\n");
// 	printf("String1: %s\n", ft_strjoin_string1);
// 	printf("String2: %s\n", ft_strjoin_string2);
//printf("New String: %s\n",ft_strjoin(ft_strjoin_string1,ft_strjoin_string2));
// 	printf("--------------------\n");

// 	printf("String1: %s\n", ft_strjoin_string3);
// 	printf("String2: %s\n", ft_strjoin_string2);
//printf("New String: %s\n",ft_strjoin(ft_strjoin_string3,ft_strjoin_string2));
// 	printf("--------------------\n");

// 	printf("String1: %s\n", ft_strjoin_string1);
// 	printf("String2: %s\n", ft_strjoin_string3);
//printf("New String: %s\n",ft_strjoin(ft_strjoin_string1,ft_strjoin_string3));
// 	printf("--------------------\n");
// }
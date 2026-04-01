/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 08:51:14 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/10 07:09:48 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*ph;

	ph = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!ph)
		return (NULL);
	i = 0;
	while (src[i])
	{
		ph[i] = src[i];
		i++;
	}
	ph[i] = '\0';
	return (ph);
}

// int	main(void)
// {
// 	const char *ft_strdup_string1 = "Fleshling youth, teach me to 
// communicate in trash talk.";
// 	char *ft_strdup_string2 = strdup(ft_strdup_string1);
// 	char *ft_strdup_string3 = ft_strdup(ft_strdup_string1);

// 	printf("========================================\n");
// 	printf("ft_strdup\n");
// 	printf("========================================\n");
// 	printf("String: %s\n\n", ft_strdup_string1);

// 	printf("Original: %s\n", ft_strdup_string2);
// 	printf("Recreation: %s\n", ft_strdup_string3);

// 	free(ft_strdup_string2);
// 	free(ft_strdup_string3);
// 	printf("--------------------\n");
// }

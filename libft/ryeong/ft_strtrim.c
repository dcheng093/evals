/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:07:00 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/07 17:27:58 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkchars(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

// static void	buildph(char *ph, size_t *i, size_t *j, char const *s1)
// {
// 	ph[*i] = s1[*j];
// 	(*i)++;
// 	(*j)++;
// }

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	saveindex[2];
	char	*ph;

	i = 0;
	ph = NULL;
	saveindex[0] = 0;
	saveindex[1] = ft_strlen(s1);
	while (i < ft_strlen(s1) && checkchars(s1[i], set) == 1)
	{
		saveindex[0]++;
		i++;
	}
	i = ft_strlen(s1) - 1;
	if (s1[saveindex[0]] != '\0')
	{
		while (i > 0 && checkchars(s1[i], set) == 1)
		{
			saveindex[1]--;
			i--;
		}
	}
	ph = ft_substr(s1, saveindex[0], (saveindex[1]) - (saveindex[0] + 1) + 1);
	return (ph);
}

// int main(void)
// {
// 	char ft_strtrim_string1[] = "\"    racing\"";
// 	char *ft_strtrim_string2 = "\"racing \"";

// 	printf("========================================\n");
// 	printf("ft_strtrim\n");
// 	printf("========================================\n");
// 	printf("String: %s\n", ft_strtrim_string1);
// 	printf("Set: %s\n\n", ft_strtrim_string2);
// 	printf("New String: %s\n", ft_strtrim(ft_strtrim_string1, 
// ft_strtrim_string2));
// 	printf("--------------------\n");
// }
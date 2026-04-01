/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crowlord <crowlord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 22:13:50 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/19 19:34:46 by crowlord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_tokencount(char const *str, char delimiter)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == delimiter)
			str++;
		if (*str && *str != delimiter)
		{
			count++;
			while (*str && *str != delimiter)
				str++;
		}
	}
	return (count);
}

static char	**fill_tokens(char const *s, char c, char **strings)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			strings[j] = ft_substr(s, start, i - start);
			j++;
		}
		else
			i++;
	}
	strings[j] = NULL;
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;

	if (!s)
		return (NULL);
	strings = malloc(sizeof(char *) * (ft_tokencount(s, c) + 1));
	if (!strings)
		return (NULL);
	fill_tokens(s, c, strings);
	return (strings);
}

// #include <stdio.h>
// #include "libft.h"

// int main(int argc, char **argv)
// {
// 	char    **result;
// 	int     i = 0;

// 	if (argc != 3)
// 	{
// 		printf("Usage: %s \"string\" \"delimiter\"\n", argv[0]);
// 		return (1);
// 	}
// 	result = ft_split(argv[1], argv[2][0]);
// 	if (!result)
// 	{
// 		printf("ft_split returned NULL\n");
// 		return (1);
// 	}
// 	while (result[i])
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (result[i])
// 	{
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return (0);
// }

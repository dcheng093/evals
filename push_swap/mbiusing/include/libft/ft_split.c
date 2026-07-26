/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:54:59 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/21 13:55:02 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	DESC:	Allocates (with malloc(3)) and returns an array
			of strings obtained by splitting ’s’ using the
			character ’c’ as a delimiter. The array must end
			with a NULL pointer.
	RETURN:	The array of new strings resulting from the split.
			NULL if the allocation fails.
	PARAMS:	s: The string to be split.
			c: The delimiter character.
*/

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

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	char	**st_arr;
	int	i;

	i = 0;
	if (argc != 2)
		return (0);
	st_arr = ft_split(argv[1], ' ');
	while (st_arr[i])
		printf("%s \n", st_arr[i++]);
	i = 0;
	while (st_arr[i])
		free(st_arr[i++]);
}
*/

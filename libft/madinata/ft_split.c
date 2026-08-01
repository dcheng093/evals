/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madinata <madinata@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 17:24:52 by madinata          #+#    #+#             */
/*   Updated: 2026/07/28 17:33:10 by madinata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(char const *str, char c)
{
	int	is_word;
	int	word_count;

	word_count = 0;
	is_word = 0;
	while (*str != '\0')
	{
		if (*str == c)
		{
			if (is_word)
				word_count++;
			is_word = 0;
		}
		else
			is_word = 1;
		str++;
	}
	if (is_word)
		word_count++;
	return (word_count);
}

static int	word_len(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		total_words;
	int		i;
	int		j;

	total_words = count_words(s, c);
	result = malloc((total_words + 1) * sizeof(char *));
	i = 0;
	while (i < total_words)
	{
		if (*s == c)
			s++;
		else
		{
			result[i] = malloc(word_len(s, c) * sizeof(char));
			j = 0;
			while (*s != '\0' && *s != c)
				result[i][j++] = *s++;
			result[i][j] = '\0';
			i++;
		}
	}
	result[i] = 0;
	return (result);
}

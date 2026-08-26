/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 17:36:05 by jia-liew          #+#    #+#             */
/*   Updated: 2026/07/30 17:36:06 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char c);
static char		*insert_words(char const *word, char c);
static void		*free_all(char **array, size_t count);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	in_word;
	char	**words;

	i = 0;
	in_word = 0;
	words = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!words || !s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			words[i] = insert_words(s, c);
			if (!words[i])
				return (free_all(words, i));
			i++;
		}
		s++;
	}
	words[i] = NULL;
	return (words);
}

static size_t	count_words(const char *str, char c)
{
	size_t	count;
	size_t	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static char	*insert_words(const char *word_start, char c)
{
	size_t	i;
	size_t	letters;
	char	*word;

	letters = 0;
	i = 0;
	while (word_start[letters] != c && word_start[letters])
		letters++;
	word = (char *)malloc(((letters) + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (word_start[i] != c && word_start[i])
	{
		word[i] = word_start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*free_all(char **array, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free (array[i]);
		i++;
	}
	free (array);
	return (NULL);
}

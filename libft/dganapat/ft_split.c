/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:04:54 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/14 15:24:02 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	word_counter(char const *s, char c)
{
	size_t	is_searching;
	size_t	word_counter;

	is_searching = 1;
	word_counter = 0;
	while (*s)
	{
		if (*s != c && is_searching)
		{
			word_counter++;
			is_searching = 0;
		}
		else if (*s == c)
			is_searching = 1;
		s++;
	}
	return (word_counter);
}

static	char	*new_word(const char **s, char c)
{
	const char	*end;
	char		*new_string;
	size_t		str_len;

	while (**s && **s == c)
		(*s)++;
	end = *s;
	while (*end && *end != c)
		end++;
	str_len = end - *s;
	new_string = malloc(sizeof(char) * (str_len + 1));
	if (!new_string)
		return (NULL);
	ft_strlcpy(new_string, *s, str_len + 1);
	*s = end;
	return (new_string);
}

static char	*free_split(char **string_split, int i)
{
	while (i > 1)
		free(string_split[i-- - 1]);
	free(string_split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	words;
	char	**string_split;

	i = 0;
	words = 0;
	if (!s)
		return (NULL);
	words = word_counter(s, c);
	string_split = malloc((words + 1) * sizeof(char *));
	if (!string_split)
		return (NULL);
	while (words > i)
	{
		string_split[i] = new_word(&s, c);
		if (!string_split)
			free_split(string_split, i);
		i++;
	}
	string_split[i] = NULL;
	return (string_split);
}
/*int		main()
{
	char s1[] = "--1-2--3---4----5-----42";
	char c = '-';
	int i;

	char **new = ft_split(s1,c);

	i = 0;
	while (new[i])
	{
		printf("%s\n" , new[i]);
		i++;
	}
	free_split(new, word_counter(s1,c));

	return (0);
}*/
/*static	int	word_counter(char const *s, char c)
{
	int	is_searching;
	int	word_counter;

	is_searching = 1;
	word_counter = 0;
	while (*s)
	{
		if (*s != c && is_searching)
		{
			word_counter++;
			is_searching = 0;
		}
		else if (*s == c)
			is_searching = 1;
		s++;
	}
	return (word_counter);
}

static char *word_malloc_allocation(const char *s, int start, int end, char dil)
{
	char	*new_string;
	int		str_len;
	int		i;

	i = 0;
	str_len = end - start;
	new_string = malloc(sizeof(char) * (str_len + 1));
	if (!new_string)
		return (NULL);
	while (end >= start)
	{
		if (s[start] != dil)
			new_string[i] = s[start];
		i++;
		start++;
	}
	new_string[i] = '\0';
	return (new_string);
}

static	void	*free_split(char **string_split, int i)
{
	while (i > 1)
		free(string_split[i-- - 1]);
	free(string_split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**string_split;
	size_t	i;
	int		j;
	int		start;

	if (!s)
		return (NULL);
	string_split = malloc((word_counter(s, c) + 1) * sizeof(char *));
	if (!string_split)
		return (NULL);
	i = 0;
	j = 0;
	start = -1;
	while (s[i])
	{
		if (s[i] != c && start < 0)
			start = i;
		if ((s[i] == c || i == ft_strlen(s) - 1) && start >= 0)
		{
			string_split[j] = word_malloc_allocation(s, start, i, c);
			if (!string_split[j])
				return (free_split(string_split, i));
			start = -1;
			j++;
		}
		i++;
	}
	string_split[j] = NULL;
	return (string_split);
}*/
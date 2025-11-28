/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:09:53 by stee              #+#    #+#             */
/*   Updated: 2025/10/21 15:19:27 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	ct;

	if (!s)
		return (0);
	i = 0;
	ct = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			ct++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (ct);
}

static char	*ft_mallocword(char const *s, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	word = (char *) malloc(sizeof(char) * (i + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

/*
static void	ft_free_words(char **arr, size_t j)
{
	while (j > 0)
	{
		free(arr[j - 1]);
		j--;
	}
}
*/

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	arr = (char **) malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			arr[j] = ft_mallocword(&s[i], c);
			while (s[i] != '\0' && s[i] != c)
				i++;
			j++;
		}
		else if (s[i] == c)
			i++;
	}
	arr[j] = NULL;
	return (arr);
}
/*
#include <stdio.h>
void print_split(char **result)
{
	int i = 0;
	while (result[i])
	{
		printf("res[%d]: \"%s\"\n", i, result[i]);
		i++;
	}
	printf("res[%d]: NULL\n\n", i);
}

void free_split(char **res)
{
	int i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
}

// -------- Main Test Function --------
int main(void)
{
	char **res;

	res = ft_split("this-test-1", '-');
	printf("Test 1:\n");
	print_split(res);
	free_split(res);

	res = ft_split("--this--is--test2--", '-');
	printf("Test 2:\n");
	print_split(res);
	free_split(res);

	res = ft_split("test3", '-');
	printf("Test 3:\n");
	print_split(res);
	free_split(res);

	res = ft_split("------", '-');
	printf("Test 4:\n");
	print_split(res);
	free_split(res);

	res = ft_split("", '-');
	printf("Test 5:\n");
	print_split(res);
	free_split(res);

	return (0);
}
*/

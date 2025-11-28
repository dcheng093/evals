/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:07:03 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/18 13:50:10 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION : Mallocs and returns an array of strings obtained from 
	splitting s with char c (used as delimiter).
    
	RETURN VALUE : Array of strings from splitting s; NULL if malloc fails.
*/

#include "libft.h"
#include <stdio.h>

static int	ft_isdelimiter(char c, char delimiter)
{
	if (c == delimiter)
		return (1);
	return (0);
}

static int	ft_countwords(const char *s, char delimiter)
{
	size_t	ct;
	size_t	i;

	ct = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (ft_isdelimiter(s[i], delimiter))
			i++;
		if (s[i])
		{
			ct++;
			while (s[i] && !ft_isdelimiter(s[i], delimiter))
				i++;
		}
	}
	return (ct);
}

// static void	ft_free_split(char **arr, size_t i)
// {
// 	size_t	i;

// 	i = 0;
// 	while (arr[i])
// 		free(arr[i++]);
// 	free (arr);
// }

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	arr = ft_calloc((ft_countwords(s, c) + 1), sizeof(char *));
	if (!arr)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
			arr[j++] = ft_substr(s, start, i - start);
	}
	return (arr);
}

// void print_split(char **result)
// {
// 	int i = 0;
// 	while (result[i])
// 	{
// 		printf("res[%d]: \"%s\"\n", i, result[i]);
// 		i++;
// 	}
// 	printf("res[%d]: NULL\n\n", i);
// }

// void free_split(char **res)
// {
// 	int i = 0;
// 	while (res[i])
// 		free(res[i++]);
// 	free(res);
// }

// int main(void)
// {
// 	char **res;

// 	res = ft_split("this-test-1", '-');
// 	printf("Test 1:\n");
// 	print_split(res);
// 	free_split(res);

// 	res = ft_split("--this--is--test2--", '-');
// 	printf("Test 2:\n");
// 	print_split(res);
// 	free_split(res);

// 	res = ft_split("test3", '-');
// 	printf("Test 3:\n");
// 	print_split(res);
// 	free_split(res);

// 	res = ft_split("------", '-');
// 	printf("Test 4:\n");
// 	print_split(res);
// 	free_split(res);

// 	res = ft_split("", '-');
// 	printf("Test 5:\n");
// 	print_split(res);
// 	free_split(res);

// 	return (0);
// }

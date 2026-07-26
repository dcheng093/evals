/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:42:33 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/21 13:42:37 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	DESC:	Allocates (with malloc(3)) and returns a new
			string, which is the result of the concatenation
			of ’s1’ and ’s2’.
	RETURN:	The new string.
			NULL if the allocation fails.
	PARAMS:	s1: The prefix string.
			s2: The suffix string.
*/

#include "libft.h"
#include <stdlib.h>

static char	*fill_joined_string(char *newstring, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = 0;
	while (i < s1len)
	{
		newstring[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2len)
	{
		newstring[i + j] = s2[j];
		j++;
	}
	newstring[i + s2len] = '\0';
	return (newstring);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	newstring = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!newstring)
		return (NULL);
	fill_joined_string(newstring, s1, s2);
	return (newstring);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s1[]= "hi";
	char	s2[]= "there!";
	char	*string;
	int	i;
	string = ft_strjoin(s1, s2);
	if (!string)
		return (1);
	i = 0;
	while (string[i])
	{
		printf("%c", *string);
		string++;
		i++;
	}
	free(string);
	string = NULL;
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuravl <nzhuravl@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:13:25 by nzhuravl          #+#    #+#             */
/*   Updated: 2025/12/21 18:19:24 by nzhuravl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	safe_malloc(char **token_v, size_t position, size_t buffer)
{
	size_t	i;

	i = 0;
	token_v[position] = malloc(buffer);
	if (NULL == token_v[position])
	{
		while (i < position)
		{
			free(token_v[i]);
			i++;
		}
		free(token_v);
		return (1);
	}
	return (0);
}

void	copy_token(char *dst, const char *src, size_t len)
{
	size_t	j;

	j = 0;
	while (j < len)
	{
		dst[j] = src[j];
		j++;
	}
	dst[len] = '\0';
}

int	fill(char **token_v, char const *s, char delimeter)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == delimeter && *s)
			s++;
		while (*s != delimeter && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (safe_malloc(token_v, i, len + 1))
				return (1);
			s -= len;
			copy_token(token_v[i], s, len);
			s += len;
			i++;
		}
	}
	return (0);
}

size_t	count_tokens(char const *s, char delimeter)
{
	size_t	tokens;
	bool	inside_token;

	tokens = 0;
	while (*s)
	{
		inside_token = false;
		while (*s == delimeter && *s)
			s++;
		while (*s != delimeter && *s)
		{
			if (!inside_token)
			{
				tokens++;
				inside_token = true;
			}
			s++;
		}
	}
	return (tokens);
}

char	**ft_split(char const *s, char c)
{
	size_t	tokens;
	char	**token_v;

	if (!s)
		return (NULL);
	tokens = count_tokens(s, c);
	token_v = malloc((tokens + 1) * sizeof(char *));
	if (!token_v)
		return (NULL);
	token_v[tokens] = NULL;
	if (fill(token_v, s, c))
		return (NULL);
	return (token_v);
}
/*
int	main(void)
{
	char	*s = "Word1 Word2 Word 3";
	char	**v = ft_split(s, ' ');
	char **start = v;

	if (!v)
		return (1);

	while (*v)
	{
		printf("%s\n", *v);
		free(*v);
		v++;
	}
	free(start);
	return(0);
}*/

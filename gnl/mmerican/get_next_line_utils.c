/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerican <mmerican@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:13:50 by mmerican          #+#    #+#             */
/*   Updated: 2025/12/10 14:13:18 by mmerican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char *str, int start, int end)
{
	char	*result;
	int		i;

	if (start >= end)
		return (NULL);
	result = malloc(end - start + 1);
	if (result == NULL)
		return (NULL);
	i = start;
	while (i < end)
	{
		result[i - start] = str[i];
		i++;
	}
	result[i - start] = '\0';
	return (result);
}

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	int		i;
	int		j;

	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

int	str_has_newline(const char *str)
{
	while (*str)
	{
		if (*(str++) == '\n')
			return (1);
	}
	return (0);
}

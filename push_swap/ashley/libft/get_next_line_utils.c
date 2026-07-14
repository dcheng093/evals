/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:30:41 by asyeo             #+#    #+#             */
/*   Updated: 2026/07/14 15:30:41 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_gnl(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, ssize_t c)
{
	ssize_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*dup;
	ssize_t	i;

	i = 0;
	if (!s)
		return (NULL);
	dup = malloc (ft_strlen_gnl(s) + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = (0);
	return (dup);
}

char	*ft_substr_gnl(char *s, ssize_t start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = (0);
	return (sub);
}

char	*ft_strjoin_gnl(char *save, char *buff, size_t r)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!buff)
		return (NULL);
	str = malloc(ft_strlen_gnl(save) + r + 1);
	if (!str)
		return (NULL);
	if (save)
	{
		while (save[i])
		{
			str[i] = save[i];
			i++;
		}
		free (save);
	}
	while (j < r)
		str[i++] = buff[j++];
	str[i] = (0);
	return (str);
}

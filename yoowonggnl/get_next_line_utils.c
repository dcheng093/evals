/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoowong <yoowong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:28:12 by yoowong           #+#    #+#             */
/*   Updated: 2025/11/28 16:28:13 by yoowong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdint.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	size_t			i;
	unsigned char	*p;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	p = (unsigned char *)ptr;
	i = 0;
	while (i < nmemb * size)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	str_len;
	size_t	sub_len;
	size_t	idx;

	idx = 0;
	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_calloc(1, sizeof (char)));
	sub_len = str_len - start;
	if (sub_len > len)
		sub_len = len;
	s1 = ft_calloc(sub_len + 1, sizeof (char));
	if (!s1)
		return (NULL);
	while (idx < sub_len)
	{
		s1[idx] = s[start + idx];
		idx++;
	}
	s1[idx] = '\0';
	return (s1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	idx;
	char	*s3;

	idx = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = ft_calloc((len1 + len2 + 1), sizeof (char));
	if (!s3)
		return (NULL);
	while (s1 && s1[idx])
	{
		s3[idx] = s1[idx];
		idx++;
	}
	idx = 0;
	while (s2[idx])
	{
		s3[len1 + idx] = s2[idx];
		idx++;
	}
	s3[len1 + idx] = '\0';
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

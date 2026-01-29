/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoowong <yoowong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 08:50:33 by yoowong           #+#    #+#             */
/*   Updated: 2025/12/07 08:50:35 by yoowong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	if (!s)
		return (0);
	while (s[length])
		length++;
	return (length);
}

char	*ft_strchr(char const *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len1;
	size_t	len2;
	size_t	i;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = malloc((len1 + len2 + 1) * sizeof (char));
	if (!s3)
		return (NULL);
	while (i < len1)
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		s3[i + len1] = s2[i];
		i++;
	}
	s3[i + len1] = '\0';
	return (s3);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*s1;
	size_t	slen;
	size_t	sub_len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (NULL);
	sub_len = slen - start;
	if (len > sub_len)
		len = sub_len;
	s1 = malloc(len + 1);
	if (!s1)
		return (NULL);
	while (i < len)
	{
		s1[i] = s[start + i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

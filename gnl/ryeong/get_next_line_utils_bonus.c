/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:47:44 by ryeong            #+#    #+#             */
/*   Updated: 2026/01/13 13:07:30 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*ph;

	ph = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!ph)
		return (NULL);
	i = 0;
	while (src[i])
	{
		ph[i] = src[i];
		i++;
	}
	ph[i] = '\0';
	return (ph);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ph;

	ph = NULL;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	else
	{
		i = start;
		while ((start + len) > ft_strlen(s))
			len--;
		ph = (char *)malloc((len + 1) * sizeof(char));
		if (!ph)
			return (NULL);
		while (s[i] && i - start < len)
		{
			ph[i - start] = s[i];
			i++;
		}
		ph[i - start] = '\0';
		return (ph);
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ph;
	int		i;

	ph = NULL;
	i = 0;
	if (s1 != 0 && s2 != 0)
	{
		ph = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
		while (*s1)
		{
			ph[i] = *s1;
			i++;
			s1++;
		}
		while (*s2)
		{
			ph[i] = *s2;
			i++;
			s2++;
		}
		ph[i] = '\0';
		return (ph);
	}
	else
		return (0);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

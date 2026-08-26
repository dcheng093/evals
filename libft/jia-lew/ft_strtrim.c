/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:51:33 by jia-liew          #+#    #+#             */
/*   Updated: 2026/07/30 16:51:34 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	found(char c, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = (strlen(s1) - 1);
	while (s1[start])
	{
		if (found(s1[start], set))
			start++;
		else
			break ;
	}
	while (s1[end])
	{
		if (found(s1[end], set))
			end--;
		else
			break ;
	}
	return (ft_substr(s1, start, (end - start + 1)));
}

static int	found(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichong <jichong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:22:06 by jichong           #+#    #+#             */
/*   Updated: 2025/11/02 17:53:32 by jichong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && in_set(s1[start], set) == 1)
		start++;
	while (end > start && in_set(s1[end - 1], set) == 1)
		end--;
	return (ft_substr (s1, start, end - start));
}
/*
int	main(void)
{
	char	*test;

	test = "test";
	printf("%s\n", ft_strtrim(test, "t"));
	return (0);
}*/

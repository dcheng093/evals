/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichong <jichong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:31:56 by jichong           #+#    #+#             */
/*   Updated: 2025/10/22 19:08:34 by jichong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last = NULL;

	while (*s != '\0')
	{
		if (*s == c)
			last = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)last);
}
/*
int	main(void)
{
	char	*string = "lol,lmao,lmfao,rofl,omegalul,yikers";
	char	*last_comma = ft_strrchr(string, ',');
	printf("%s\n", last_comma);
}*/

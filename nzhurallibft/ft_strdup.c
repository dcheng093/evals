/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuravl <nzhuravl@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:36:08 by nzhuravl          #+#    #+#             */
/*   Updated: 2025/12/20 20:38:34 by nzhuravl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dupped;
	int		len;
	int		i;

	len = ft_strlen(s);
	dupped = (char *)malloc(sizeof(char) * (len + 1));
	if (!dupped)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dupped[i] = s[i];
		i++;
	}
	dupped[i] = '\0';
	return (dupped);
}
/*
int	main() 
{
	char *s = ft_strdup("hello");
	if (s)
	{
		printf("Duplicated string: %s\n", s);
		free(s);
	}
	else
		printf("Memory allocation failed.\n");
	return (0);
}*/

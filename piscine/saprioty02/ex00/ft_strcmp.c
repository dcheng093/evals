/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saprioty <saprioty@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:48:00 by saprioty          #+#    #+#             */
/*   Updated: 2025/08/20 17:06:19 by saprioty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
int	main(void)
{
	char	s1[] = "Hello";
	char	s2[] = "Hell";

	printf("%d\n", ft_strcmp(s1, s2));

	return 0;
}*/

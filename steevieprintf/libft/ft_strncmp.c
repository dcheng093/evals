/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:55:47 by stee              #+#    #+#             */
/*   Updated: 2025/10/21 16:42:51 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && (s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	if (i == n)
		return (0);
	else
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
/*
#include <stdio.h>
int main(void)
{
    const char *s1 = "Hello, world!"; // 13
	const char *s2 = "Hello, World!"; // 13
	
	printf("%d\n", ft_strncmp(s1, s2, 7);
	printf("%d", ft_strncmp(s1, s2, 13);
    return 0;
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:39:59 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/17 21:45:22 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
char	ft_plus1ascii(unsigned int i, char c)
{
	(void)i;
	if (c >= 0 && c <= 126)
		return c + 1;
	return c;
}

#include <stdio.h>
int main(int argc, char *argv[])
{
	char    *test1;

	if (argc != 2)
	{
		printf("Blud can u like.. just put 2 arguments only");
		return (1);
	}
	test1 = ft_striteri(argv[1] ,ft_plus1ascii); 
	printf("%s", test1);
	free(test1);
	return (0);
}
*/
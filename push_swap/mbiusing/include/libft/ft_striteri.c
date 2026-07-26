/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:42:53 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/21 13:42:55 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	DESC:	Applies the function ’f’ on each character of
			the string passed as argument, passing its index
			as first argument. Each character is passed by
			address to ’f’ to be modified if necessary.
	PARAMS;	s: The string on which to iterate.
			f: The function to apply to each character.
*/

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

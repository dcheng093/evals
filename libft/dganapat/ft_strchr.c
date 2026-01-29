/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:22:54 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/14 16:27:04 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' )
	{
		if (s[i] == (unsigned char)(c))
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (unsigned char)(c))
		return ((char *)(s + i));
	return (NULL);
}
/*
int     main()
{
	int		c;
	int		n;
	char *s1 = "ttti\ti\0h";

	c = 'h';
	//n = ;

	printf("     My function : %p\n" , ft_strchr(s1, c));
	printf("Orginal function : %p\n" , strchr(s1, c));

	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:59:21 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/09 15:50:53 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)(c))
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*int     main()
{
	int		c;
	//int		n;
	char *s1 = "httti\ti\0h";

	c = 'h';
	//n = ;

	printf("     My function : %p\n" , ft_strrchr(s1, c));
	printf("Orginal function : %p\n" , strrchr(s1, c));

	return (0);
}*/

// "hello wolrd I am a     string"
//ft_split(str, '')
//char **ptr_array = malloc(sizeof(char *) * (how many char*'s you want))
// If at any point malloc() fails, you need to free everything you've malloc'ed
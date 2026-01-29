/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:02:38 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/14 16:33:06 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*new_position;

	i = 0;
	new_position = (const unsigned char *)s;
	while (i != n)
	{
		if (new_position[i] == (unsigned char)c)
			return ((void *)(new_position + i));
		i++;
	}
	return (NULL);
}
/*int     main()
{
	int		c;
	int		n;
	char *s1 = "ii\ti\0h";

	c = '\t';
	n = 5;

	ft_memchr(s1, c, n);
	memchr(s1, c, n);

	printf("     My function : %p\n" , ft_memchr(s1, c, n));
	printf("Orginal function : %p\n" , memchr(s1, c, n));

	return (0);
}*/
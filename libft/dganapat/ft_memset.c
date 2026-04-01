/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:02:20 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/14 16:10:19 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	i = 0;
	s2 = (unsigned char *)s;
	while (i != n)
	{
		s2[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*#include <string.h>
int	main()
{
	char	s1[11];
	char	s2[11];
	//int	n;
	int	c;

	
	//n = 10;
	c = 'a';

	ft_memset(s1, c, 10);
	memset(s2, c, 10);

	printf("My Function %s\n" , s1);
	printf("Original Function %s\n" , s2);

	return (0);
}*/
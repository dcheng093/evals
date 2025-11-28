/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:42:29 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/14 16:11:43 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	i = 0;
	s2 = (unsigned char *)s;
	while (i != n)
	{
		s2[i] = '\0';
		i++;
	}
}
/*int	main()
{
	char	s1[11];
	char	s2[11];
	//int	n;
	//int	c;

	
	//n = 10;
	//c = 'a';

	ft_bzero(s1,10);
	bzero(s2, 10);

	printf("My Function %s\n" , s1);
	printf("Original Function %s\n" , s2);

	return (0);
}*/
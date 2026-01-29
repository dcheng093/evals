/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:58:10 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/14 16:35:25 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s3;
	const unsigned char	*s4;

	i = 0;
	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	while (i != n)
	{
		if (s3[i] != s4[i])
			return (s3[i] - s4[i]);
		i++;
	}
	return (0);
}
/*int		main()
{
	size_t		n;
	char	*s1 = "Hello World";
	char	*s2 = "Hello WorlD";

	n = 11;
	printf("     My Function : %d\n" , ft_memcmp(s1, s2, n));
	printf("Orginal Function : %d\n" , memcmp(s1, s2, n));

	return (0);
}*/

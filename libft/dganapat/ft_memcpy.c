/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:59:40 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/14 16:13:07 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*s1;
	const unsigned char	*s2;

	s2 = (const unsigned char *)src;
	s1 = (unsigned char *)dest;
	i = 0;
	while (i != n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dest);
}
/*int	main()
{
	char	s1[]= "Hello World";
	char	s2[12];
	int n;

	n = 12;

	ft_memcpy(s2, s1, n);
	memcpy(s2, s1, n);

	printf("My Function : %s\n" , s2);
	printf("Original Function : %s\n" , s2);

	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:03:19 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/14 16:14:46 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*temp_d;
	const unsigned char	*temp_s;

	i = 0;
	temp_d = (unsigned char *)dest;
	temp_s = (const unsigned char *)src;
	if (dest <= src || dest > src + n)
	{
		while (i != n)
		{
			temp_d[i] = temp_s[i];
			i++;
		}
		return (dest);
	}
	i = n;
	while (i != 0)
	{
		temp_d[i - 1] = temp_s[i - 1];
		i--;
	}
	return (dest);
}
/*#include <string.h>
#include <stdio.h>
int	main()
{
	char	s1[11] = "Hello World";
	char	s2[20];
	char	s3[20];

	ft_memmove(s2, s1 +2, 12);
	memmove(s3, s1 +2, 12);

	printf("My Function %s\n" , s2);
	printf("Original Function %s\n" , s3);

	return (0);
}*/

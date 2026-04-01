/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:01:36 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/19 15:01:01 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	DESC :	scans the initial n bytes of the memory area
			pointed to by s for the first instance of c.  
			Both c and the bytes of the memory area pointed to by s 
			are interpreted as unsigned char.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	chr;

	str = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == chr)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

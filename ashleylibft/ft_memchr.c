/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:16:25 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/14 15:30:54 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION :
	Function locates the FIRST occurance of chr in string s. 
	(converted to an unsigned char)

	RETURN VALUE:
	A pointer to the matching byte. NULL if the character does not occur
	in the given memory area.
*/

#include "libft.h"
//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		ch;
	const unsigned char	*str;

	ch = c;
	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)s + i);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	
}
*/
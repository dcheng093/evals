/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 08:24:41 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/15 11:37:17 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION : Function fills a block of memory with a particular value.
	
	RETURN VALUE : Returns a pointer to memory area s.
*/

#include "libft.h"
//#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	while (n > 0)
	{
		*(ptr++) = (unsigned char) c;
		n--;
	}
	return (s);
}

/*
int	main(void)
{
	
}
*/
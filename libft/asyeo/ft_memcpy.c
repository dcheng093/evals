/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 08:24:36 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/15 11:33:41 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION: Function copies n bytes from src (source) to dest (destination).
	
	VISUALS: Pouring water from Cup A into empty Cup C.
	
	RETURN VALUE: DEST VALUE.
*/

#include "libft.h"
//#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*t_dst;
	const unsigned char		*t_src;

	if (!dest && !src)
		return (NULL);
	t_dst = (unsigned char *) dest;
	t_src = (const unsigned char *) src;
	i = 0;
	while (i < n)
	{
		t_dst[i] = t_src[i];
		i++;
	}
	return (dest);
}

/*
int	main(void)
{
	
}
*/

/*NOTES:
1) t_dst is temporary destination. t_src is temporary source.
2) n is the full string length.
*/
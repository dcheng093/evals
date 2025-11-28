/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 08:24:39 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/14 16:21:02 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION : Function copies n bytes from src to a temporary array 
	(that does not overlap with src and dest) which are then copied to dest.
	
	RETURN VALUE : ORIGINAL DEST VALUE.
*/

#include "libft.h"
//#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	d = dest;
	s = src;
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
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
*/
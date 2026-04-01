/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:39:22 by stee              #+#    #+#             */
/*   Updated: 2025/10/17 10:41:35 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dptr;
	const unsigned char	*sptr;

	if (dest == NULL && src == NULL)
		return (NULL);
	dptr = (unsigned char *) dest;
	sptr = (const unsigned char *) src;
	if (dptr < sptr)
	{
		while (n--)
			*dptr++ = *sptr++;
	}
	else
	{
		dptr += n;
		sptr += n;
		while (n--)
			*--dptr = *--sptr;
	}
	return (dest);
}

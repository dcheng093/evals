/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:39:49 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/19 14:30:50 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*dst;
	const unsigned char	*src_c;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	dst = (unsigned char *)dest;
	src_c = (const unsigned char *)src;
	if (dst > src_c && dst < src_c + len)
	{
		while (len-- > 0)
			dst[len] = src_c[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dst[i] = src_c[i];
			i++;
		}
	}
	return (dest);
}

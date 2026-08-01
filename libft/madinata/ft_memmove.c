/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madinata <madinata@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:55:09 by madinata          #+#    #+#             */
/*   Updated: 2026/07/31 17:19:23 by madinata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*target;
	const unsigned char	*source;

	target = dest;
	source = src;
	if (target < source && target + n >= source)
	{
		while (n-- > 0)
			*target++ = *source++;
	}
	else
	{
		while (n > 0)
		{
			target[n - 1] = source[n - 1];
			n--;
		}
	}
	return (dest);
}

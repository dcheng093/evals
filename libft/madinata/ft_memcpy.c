/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madinata <madinata@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:03:47 by madinata          #+#    #+#             */
/*   Updated: 2026/07/31 17:21:36 by madinata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*target;
	const unsigned char	*source;

	target = dest;
	source = src;
	while (n > 0)
	{
		target[n - 1] = source[n - 1];
		n--;
	}
	return (dest);
}

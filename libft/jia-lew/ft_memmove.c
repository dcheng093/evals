/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:24:37 by jia-liew          #+#    #+#             */
/*   Updated: 2026/07/28 14:51:11 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	if (!dest || !src)
		return (NULL);
	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	while (src < dest && n > 0 && n != 0)
	{
		n--;
		d[n] = s[n];
	}
	while (src >= dest && i <= (n - 1) && n != 0)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

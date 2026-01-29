/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:35:01 by stee              #+#    #+#             */
/*   Updated: 2025/10/21 14:50:35 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptrdest;
	const unsigned char	*ptrsrc;

	if (dest == NULL && src == NULL)
		return (NULL);
	ptrdest = (unsigned char *) dest;
	ptrsrc = (const unsigned char *) src;
	while (n--)
		*ptrdest++ = *ptrsrc++;
	return (dest);
}

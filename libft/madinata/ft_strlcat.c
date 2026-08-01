/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madinata <madinata@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:54:17 by madinata          #+#    #+#             */
/*   Updated: 2026/07/31 17:15:17 by madinata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	while (*src != '\0')
	{
		if (i < size - 1 && size != 0)
			dst[i] = *src;
		else if (i == size - 1)
			dst[i] = '\0';
		i++;
		src++;
	}
	if (*src == '\0' && i < size)
		dst[i] = '\0';
	return (i);
}

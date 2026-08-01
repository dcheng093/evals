/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madinata <madinata@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:42:12 by madinata          #+#    #+#             */
/*   Updated: 2026/07/31 20:42:40 by madinata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (size > 0 && i < size - 1 && *src != '\0')
		dst[i++] = *src++;
	if (i == size - 1 || *src == '\0')
		dst[i] = '\0';
	while (*src++ != '\0')
		i++;
	return (i);
}

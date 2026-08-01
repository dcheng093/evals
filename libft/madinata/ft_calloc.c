/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madinata <madinata@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 22:20:25 by madinata          #+#    #+#             */
/*   Updated: 2026/07/31 16:18:34 by madinata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*result;
	size_t			i;

	if (nmemb == 0 || size == 0)
		return (ft_calloc(1, 1));
	if (size != 0 && (((size_t)0 - 1) / size) < nmemb)
		return (0);
	result = malloc(nmemb * size);
	if (!result)
		return (0);
	i = 0;
	while (i < nmemb * size)
		result[i++] = 0;
	return (result);
}

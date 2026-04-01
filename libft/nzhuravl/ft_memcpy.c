/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuravl <nzhuravl@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:53:12 by nzhuravl          #+#    #+#             */
/*   Updated: 2025/12/20 20:53:35 by nzhuravl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*src_b;
	unsigned char		*dest_b;

	src_b = (const unsigned char *)src;
	dest_b = (unsigned char *)dest;
	if (!dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest_b[i] = src_b[i];
		i++;
	}
	return (dest);
}

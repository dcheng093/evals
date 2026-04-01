/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuravl <nzhuravl@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:52:45 by nzhuravl          #+#    #+#             */
/*   Updated: 2025/12/20 20:52:46 by nzhuravl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1_bytes;
	const unsigned char	*s2_bytes;

	s1_bytes = (const unsigned char *)s1;
	s2_bytes = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_bytes[i] != s2_bytes[i])
			return (s1_bytes[i] - s2_bytes[i]);
		i++;
	}
	return (0);
}

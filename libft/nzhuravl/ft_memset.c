/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuravl <nzhuravl@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:47:43 by nzhuravl          #+#    #+#             */
/*   Updated: 2025/12/20 20:48:14 by nzhuravl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t			i;
	unsigned char	*b1;

	if (!b)
		return (NULL);
	b1 = (unsigned char *)b;
	i = 0;
	while (i < n)
	{
		b1[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

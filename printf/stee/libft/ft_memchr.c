/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:57:30 by stee              #+#    #+#             */
/*   Updated: 2025/10/17 10:58:28 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*p;
	unsigned char		ch;

	p = (unsigned const char *) s;
	ch = (unsigned char) c;
	while (n--)
	{
		if (*p == ch)
			return ((void *) p);
		p++;
	}
	return (NULL);
}

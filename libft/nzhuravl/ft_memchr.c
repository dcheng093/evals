/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuravl <nzhuravl@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:51:44 by nzhuravl          #+#    #+#             */
/*   Updated: 2025/12/20 20:51:45 by nzhuravl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*p;

	p = (unsigned char *)s;
	if (!s)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char lumos[] = "Lumos Maxima";
	printf("Part of the spell is: %s\n", 
		(char *)ft_memchr(lumos, 'M', strlen(lumos)));
}
*/		

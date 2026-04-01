/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichong <jichong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:12:41 by jichong           #+#    #+#             */
/*   Updated: 2025/10/25 12:48:05 by jichong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	char	*pdest;
	char	*psrc;

	pdest = (char *)dest;
	psrc = (char *)src;
	while (n--)
		*pdest++ = *psrc++;
	return (dest);
}
/*
int	main(void)
{
	char src[] = "Hello";
	char dest[10];

	ft_memcpy(dest, src, 6);
	printf("Copied string: %s\n", dest);
	return (0);
}*/

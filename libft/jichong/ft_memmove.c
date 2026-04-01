/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichong <jichong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:08:48 by jichong           #+#    #+#             */
/*   Updated: 2025/10/25 14:58:48 by jichong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	return (dest);
}
/*
int	main(void)
{
	char	string[] = "Dark Souls";
	ft_memmove(string + 2, string, 5);
	printf("%s\n", string);
	return (0);
}*/

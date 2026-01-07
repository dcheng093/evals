/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuravl <nzhuravl@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:38:40 by nzhuravl          #+#    #+#             */
/*   Updated: 2025/12/20 20:40:21 by nzhuravl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s || n == 0)
		return (dest);
	i = 0;
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
/*
int	main(void)
{
	//char spell[256];
	//char magic[256];

	char avada[] = "Avada Kedavra";
	//char lumos[] = "Lumos Maxima";
	
	memcpy(avada + 2, avada, sizeof(char) * strlen(avada) + 1);
	memmove(avada + 2, avada, sizeof(char) * strlen(avada) + 1);
	printf("Spell: %s\n", avada);
} */

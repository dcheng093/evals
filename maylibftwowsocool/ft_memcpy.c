/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:08:07 by mbiusing          #+#    #+#             */
/*   Updated: 2025/10/28 12:12:53 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cpydest;
	char	*cpysrc;
	int		i;

	cpydest = (char *) dest;
	cpysrc = (char *) src;
	i = 0;
	while (n > 0)
	{
		cpydest[i] = cpysrc[i];
		i++;
		n--;
	}
	return (cpydest);
}

/*int	main(void)
{
	char	src[] = "Yoooo Wassup";
	char	dest[100];
	ft_memcpy(dest, src, ft_strlen(src)+1);
	printf("%s", dest);
	return (0);
}*/

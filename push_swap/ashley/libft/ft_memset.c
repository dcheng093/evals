/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:27:21 by asyeo             #+#    #+#             */
/*   Updated: 2026/07/14 15:27:21 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = (unsigned char) c;
	return (s);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char buffer[10];

// 	ft_memset(buffer, 0, sizeof(buffer));
// 	for (int i = 0; i < 10; i++)
// 		printf("%d ", buffer[i]); // should print 0 0 0 0 0 0 0 0 0 0
// 	printf("\n");
// }

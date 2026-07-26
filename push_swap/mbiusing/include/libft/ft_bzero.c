/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:36:54 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/21 13:37:18 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	DESC:	erases the data in the n bytes of the memory
		starting at the location pointed to by s, by writing zeros (bytes
		containing '\0') to that area.
*/
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// #include <stdio.h>
// #include <string.h>

// void	ft_ptnb(int *arr, size_t len)
// {
// 	size_t i = 0;
// 	while (i < len)
// 	{
// 		printf("%d, ", arr[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

// int	main(void)
// {
// 	char	s1[] = "yooooo!!!";
// 	int		s2[] = {1, 3, 5, 7, 9};
// 	// Zero 4 chars starting from index 3
// 	ft_bzero(s1 + 3, 4);
// 	printf("%s\n", s1);
// 	// Zero last two integers
// 	ft_bzero(s2 + 3, 2 * sizeof(int));
// 	ft_ptnb(s2, 5);
// 	return 0;
// }

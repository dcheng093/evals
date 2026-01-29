/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:16:20 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/18 14:40:33 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION :
	Compares the first n bytes of the memory areas s1 and s2. The bytes 
	are interpreted as unsigned char. 

	RETURN VALUE :
	An integer less than, equal to, or greater than zero if the first
	n bytes of s1 is found to be less than, equal to, or greater than the 
	first n bytes of s2. Zero if n is equal to zero.
*/

#include "libft.h"
//#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	if (n == 0)
		return (0);
	str1 = s1;
	str2 = s2;
	i = 0;
	while ((i < n - 1) && (str1[i] == str2[i]))
		i++;
	return (str1[i] - str2[i]);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char s1[] = "hello";
// 	char s2[] = "hellO";
// 	char	result;

// 	result = ft_memcmp(s1, s2, 5);
// 	printf("%d\n", result);
// }

/*NOTES:
1) Works similarly to ft_strncmp.

2) Return Value depends entirely on difference found. No difference = 0.

3) If 1st chr in s2 is greater, res is negative. If 1st chr in s2 is 
lesser, res is positive.
*/
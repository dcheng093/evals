/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 08:24:49 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/18 14:52:38 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION :
	Function will 'chain together' two strings.
	Note : space for the terminating '\0' character must be included in dstsize.

	RETURN VALUE :
	The total length of the string that it tried to create : the initial
	length of dst + the length of src, with the goal to facilitate
	truncaction detection.
*/

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	i = 0;
	if (size <= dstlen)
		return (size + srclen);
	while (src[i] && (dstlen + i) < (size - 1))
	{
		dest[dstlen + i] = src[i];
		i++;
	}
	dest[dstlen + i] = '\0';
	return (dstlen + srclen);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char s[3210] = " Jeff the Shark"; //14
// 	char d[] = "Gotham kinda stinks"; //19

// 	printf("%s\n", d);
// 	ft_strlcat(d, s, 35);
// 	printf("%s\n", d);
// 	return (0);
// }

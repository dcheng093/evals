/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:03:11 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/14 15:32:29 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION : Locates the first occurance of a null-terminated 
	substring (needle) in a string (haystack). Chars that appear after 
	NULL are not searched.

	RETURN VALUE : Haystack is returned if needle is empty. If needle occurs
	nowhere in haystack, NULL is returned; otherwise pointer to the first char
	of the first occurance of needle is returned.
*/

#include "libft.h"
//#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	
}
*/
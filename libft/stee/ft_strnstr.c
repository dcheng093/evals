/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:53:56 by stee              #+#    #+#             */
/*   Updated: 2025/10/17 11:00:52 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *) big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *) &big[i]);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int main(void) {
    const char *h1 = "Foo Bar Baz";
    const char *n1 = "Bar";
	char	*result;

    result = ft_strnstr(h1, n1, 11); // len covers the whole string

    result = ft_strnstr(h1, "Quux", 11);

    result = ft_strnstr(h1, n1, 5); // false.

    result = ft_strnstr(h1, n1, 7); // "Foo Bar" - 4+2 = 6. 6 < 7.

    result = ft_strnstr(h1, "", 11);
	
    result = ft_strnstr(h1, "", 0); // Empty needle, len 0

    result = ft_strnstr(h1, "Foo", 11);
	
    result = ft_strnstr(h1, "Foo", 2); // len too short for "Foo"
	
	printf ("%s", result);
    return 0;
}*/

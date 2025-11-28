/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:23:01 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/14 15:29:01 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_little;

	len_little = ft_strlen(little);
	if (*little == '\0')
		return ((char *)(big));
	while (len_little <= len && *big)
	{
		if (ft_strncmp(big, little, len_little) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
/*#include <bsd/string.h>
#include <stdio.h>
int		main()
{
	size_t		n;
	char	haystack[] = "lorem ipsum dolor sit amet";
	char	needle[] = "dolor";

	n = 15;
	//printf("     My Function : %zu\n" , ft_strlcat(s1, s2, l));
	//printf("Orginal Function : %zu\n" , strlcat(s3, s2, l));
	//printf("New s1 : %s\n" , s1 );
	printf("New My Function : %s\n" , ft_strnstr(haystack,needle, n) );
	printf("New Orginal     : %s\n" , strnstr(haystack,needle, n) );

	return (0);
}*/
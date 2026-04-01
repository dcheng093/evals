/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:06:08 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/18 11:16:46 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

/*
	DESCRIPTION : Allocates with malloc and returns a substring from string 's'.
	
	RETURN VALUE : Returns the new string; NULL if malloc fails.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (s == NULL)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

/*
int	main(void)
{
	
}
*/

/* NOTES:
1) unsigned int start will always be equal/more than 0.

2) ft_calloc initializes string values to 0 (including NULL). 
	malloc does not initialize but is used more often.

3) sizeof(char) is an operator that prints/returns the size of a data type.
	each data type has a different number of bytes. 
	(char; 1, int; 2/4, float; 4, double; 8)

4) if a string is empty/NULL, a substring cannot be created, hence return (0);.
*/
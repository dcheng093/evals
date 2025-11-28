/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 08:24:46 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/14 15:33:39 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION : Function checks if 'C' is 7-bit unsigned char that fits 
    within the ASCII character set.
    
	RETURN VALUE : Non-zero if c is a 7-bit ASCII character, otherwise 0.
*/

#include "libft.h"
//#include <stdio.h>

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = ft_strlen(s);
	dup = (char *)malloc((len + 1) * (1 + 1));
	if (!dup)
		return (0);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
int	main(void)
{
	
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:07:43 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/15 13:11:58 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION : Applies function to characters of str to create a new string 
	(with malloc), resulting in succesive function application.
    
	RETURN VALUE : A new string resulting of the successive applications of 
	'f'; NULL if the memory allocations failed.
*/

#include "libft.h"
//#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s || !f)
		return (0);
	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}

/*
int	main(void)
{
	
}
*/
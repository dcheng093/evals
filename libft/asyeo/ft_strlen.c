/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 08:24:56 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/14 15:32:14 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION : Function calculates the string's length pointed to by s, 
	excluding NULL or '\0'.
	
	RETURN VALUE : The number of bytes in the string str.
*/

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*int    main(void)
{
	char    str[] = "Jeff the Lands/0hark!";
	printf("Length of '%s' is: %zu\n", str, ft_strlen(str));
	return (0);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 08:24:06 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/14 15:59:28 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION : Function erases the data in the n bytes of the location 
	memory pointed to by *s by writing '0's to the area.
	
	RETURN VALUE : None.
*/

#include "libft.h"
//#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
int	main(void)
{
	
}
*/

/*NOTES:
1) Alternatively can be written as ft_memset(s, 0, n);
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 08:24:33 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/14 15:30:41 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION : Function checks for any printable characters (including space).
    
	RETURN VALUE : Non-zero if c is a printable character, otherwise 0.
*/

#include "libft.h"
//#include <stdio.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*
int	main(void)
{
	
}
*/
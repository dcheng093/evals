/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 06:17:43 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/19 07:19:49 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION :  Function checks for an alpahabetical characters, both upper 
	and lowercase.
	
	RETURN VALUE : The alphabetical ASCII value.
*/

#include "libft.h"
//#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (c);
	return (0);
}

/*
int	main(void)
{
	
}
*/

/*NOTES:
1) return (1)/return (c) is true, return (0) is false. 
As long as the return (?) is above 0, it is true.
*/
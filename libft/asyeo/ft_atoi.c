/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 08:11:31 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/19 07:17:28 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION : Function checks the string and converts alphabetical 
	characters into int representation.
	
	RETURN VALUE : Converted intial portion of string into interger.
*/

#include "libft.h"
//#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int				sign;
	long			result;
	size_t			i;

	sign = 1;
	result = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		if (result * sign > INT_MAX)
			return (-1);
		if (result * sign < INT_MIN)
			return (0);
		i++;
	}
	return ((int)(result * sign));
}

/*NOTES:

*/

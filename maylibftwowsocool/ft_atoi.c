/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:27:07 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/19 21:40:00 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 	NAME
// 		atoi -- convert ASCII string to integer
//	SYNOPSIS
// 		int atoi(const char *str);
//	DESCRIPTION
// 		The atoi() function converts the initial portion of the string pointed 
// 		to by str to int representation.

#include "libft.h"

int	ft_atoi(const char *num)
{
	int	i;
	int	res;
	int	posneg;

	i = 0;
	res = 0;
	posneg = 1;
	while ((num[i] >= 9 && num[i] <= 13) || (num[i] == ' '))
		i++;
	if (num[i] == '+' || num[i] == '-')
	{
		if (num[i] == '-')
			posneg *= -1;
		i++;
	}
	while (num[i] >= '0' && num[i] <= '9')
	{
		res = res * 10 + (num[i] - '0');
		i++;
	}
	return (posneg * res);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		printf("actual: %d \n", ft_atoi(argv[i]));
		printf("expected: %d \n", atoi(argv[i]));
		i++;
	}
}
*/

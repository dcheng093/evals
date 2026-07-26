/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:36:36 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/21 14:45:16 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC :	The atoi() function converts the initial portion of 
			the string pointed to by str to int representation.
*/
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

// #include <stdio.h>
// #include <stdlib.h>
// int	main(int argc, char **argv)
// {
// 	int	i;

// 	i = 1;
// 	if (argc < 2)
// 		return (0);
// 	while (i < argc)
// 	{
// 		printf("actual: %d \n", ft_atoi(argv[i]));
// 		printf("expected: %d \n", atoi(argv[i]));
// 		i++;
// 	}
// }

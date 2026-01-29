/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:01:50 by stee              #+#    #+#             */
/*   Updated: 2025/10/25 17:25:39 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sum;
	int	sign;
	int	i;

	sum = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		sum = (sum * 10) + (nptr[i] - '0');
		i++;
	}
	return (sum * sign);
}
/*
#include <stdio.h>
int main()
{
    int result;

    result = ft_atoi("123abc456");
    printf("Input: \"123abc456\" -> Output: %d\n", result); // output: 123

    result = ft_atoi("abc123");
    printf("Input: \"abc123\" -> Output: %d\n", result); // output: 0

    result = ft_atoi("--+++1234abc56");
    printf("Input: \"--+++1234abc56\" -> Output: %d\n", result); // output: 0

    result = ft_atoi("");
    printf("Input: \"\" -> Output: %d\n", result); // output: 0

    result = ft_atoi("   -0012a42");
    printf("Input: \"   -0012a42\" -> Output: %d\n", result); // output: -12

    result = ft_atoi("0");
    printf("Input: \"0\" -> Output: %d\n", result); // output: 0

    return 0;
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 18:23:25 by madinata          #+#    #+#             */
/*   Updated: 2026/08/01 18:12:43 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	num_len(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	num;
	int		size;
	int		is_negative;
	char	*result;

	num = n;
	is_negative = 0;
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	size = num_len(num);
	result = malloc(size + is_negative + 1);
	if (!result)
		return (0);
	if (is_negative)
		result[0] = '-';
	result[size + is_negative] = '\0';
	while (size > 0)
	{
		result[--size + is_negative] = num % 10 + '0';
		num /= 10;
	}
	return (result);
}

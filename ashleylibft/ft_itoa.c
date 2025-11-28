/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:07:12 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/19 07:42:47 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	numlen(long n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = n;
	if (n < 0)
		num = -num;
	len = numlen(num) + (n < 0);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = num % 10 + 48;
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

/*
int	main(void)
{
	
}
*/
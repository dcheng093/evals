/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:55:16 by stee              #+#    #+#             */
/*   Updated: 2025/10/21 15:04:45 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countlen(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_inttostr(long n, size_t len, char *str)
{
	int	flag;

	flag = 0;
	str[len] = '\0';
	if (n < 0)
	{
		flag = 1;
		n *= -1;
	}
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--len] = ((n % 10) + '0');
		n /= 10;
	}
	if (flag == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	nb;
	char	*str;

	nb = (long) n;
	len = ft_countlen(nb);
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	return (ft_inttostr(nb, len, str));
}
/*
#include <stdio.h>
int main(void)
{
    int n = -42;
    char *result;

    result = ft_itoa(n);
    printf("Input: %d || Output: %s\n", n, result); // output: "-42"
    free(result);
    return 0;
}*/

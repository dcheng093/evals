/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 20:08:00 by jia-liew          #+#    #+#             */
/*   Updated: 2026/07/30 20:08:01 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n);

char	*ft_itoa(int n)
{
	unsigned int	num;
	char			*numstr;
	int				numlen;

	if (n < 0)
		num = -n;
	else
		num = n;
	numlen = get_len(n);
	numstr = (char *)malloc((numlen + 1) * sizeof(char));
	numstr[numlen--] = '\0';
	if (num == 0)
		numstr[numlen--] = '0';
	while (num)
	{
		numstr[numlen--] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		numstr[numlen] = '-';
	return (numstr);
}

static int	get_len(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	if (n > 0)
		len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

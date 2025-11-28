/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichong <jichong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:37:27 by jichong           #+#    #+#             */
/*   Updated: 2025/11/04 16:08:47 by jichong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	total_len(int n)
{
	int	total;

	total = 0;
	if (n <= 0)
		total = 1;
	while (n)
	{
		n = n / 10;
		total++;
	}
	return (total);
}

char	*ft_itoa(int nbr)
{
	int		i;
	int		len;
	long	num;
	char	*str;

	num = nbr;
	len = total_len(nbr);
	str = (char *)malloc((sizeof(char) * (len + 1)));
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = len - 1;
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 9)
	{
		str[i] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	str[i] = num + '0';
	return (str);
}
/*
int	main(void)
{
	int		number;
	char	*string;

	number = 0;
	string = ft_itoa(number);
	printf("%s\n", string);
	free(string);
}*/

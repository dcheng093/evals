/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 22:31:48 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/18 11:39:38 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_countchar(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*convert_int(long nb, size_t len, char *str)
{
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*str;

	nb = n;
	len = ft_countchar(nb);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	convert_int(nb, len, str);
	return (str);
}

// #include <stdio.h>

// int main(int argc, char *argv[])
// {
//     int     n;
//     char    *str;

//     if (argc != 2)
//     {
//         printf("enter smthn liddis: ./a.out -12345\n");
//         return (1);
//     }
//     n = ft_atoi(argv[1]);
//     str = ft_itoa(n);
//     if (!str)
//         return (1);
//     printf("%s\n", str);
//     free(str);
//     return (0);
// }

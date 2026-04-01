/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:20:01 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/10 07:08:10 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digitcount(long num)
{
	int	i;

	i = 0;
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static char	*reversestring(char *str)
{
	char	ph;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		ph = str[i];
		str[i] = str[j];
		str[j] = ph;
		i++;
		j--;
	}
	return (str);
}

static void	checknegative(int n, long *num, int *isnegative)
{
	if (n < 0)
	{
		*num *= -1;
		*isnegative = 1;
	}
}

char	*ft_itoa(int n)
{
	char	*ph;
	long	num;
	int		isnegative;
	int		i;

	i = 0;
	isnegative = 0;
	num = n;
	if (n == 0)
		return (ft_strdup("0"));
	checknegative(n, &num, &isnegative);
	ph = (char *)malloc(digitcount(n) + isnegative + 1);
	if (!ph)
		return (NULL);
	while (i < digitcount(n))
	{
		ph[i] = (char)(num % 10) + '0';
		num /= 10;
		i++;
	}
	if (n < 0)
		ph[i++] = '-';
	ph[i] = '\0';
	ph = reversestring(ph);
	return (ph);
}

/* int	main(void)
{
	int ft_itoa_number1 = 0;
	int ft_itoa_number2 = 9;
	int ft_itoa_number3 = -9;
	int ft_itoa_number4 = 10;
	int ft_itoa_number5 = -10;
	int ft_itoa_number6 = 8124;
	int ft_itoa_number7 = -9874;
	int ft_itoa_number8 = 543000;
	int ft_itoa_number9 = -2147483648LL;
	int ft_itoa_number10 = INT_MAX;

	printf("========================================\n");
	printf("ft_itoa\n");
	printf("========================================\n");
	printf("Number: %d\n\n", ft_itoa_number1);
	printf("String: %s\n", ft_itoa(ft_itoa_number1));
	printf("--------------------\n");

	printf("Number: %d\n\n", ft_itoa_number2);
	printf("String: %s\n", ft_itoa(ft_itoa_number2));
	printf("--------------------\n");

	printf("Number: %d\n\n", ft_itoa_number3);
	printf("String: %s\n", ft_itoa(ft_itoa_number3));
	printf("--------------------\n");

	printf("Number: %d\n\n", ft_itoa_number4);
	printf("String: %s\n", ft_itoa(ft_itoa_number4));
	printf("--------------------\n");

	printf("Number: %d\n\n", ft_itoa_number5);
	printf("String: %s\n", ft_itoa(ft_itoa_number5));
	printf("--------------------\n");

	printf("Number: %d\n\n", ft_itoa_number6);
	printf("String: %s\n", ft_itoa(ft_itoa_number6));
	printf("--------------------\n");

	printf("Number: %d\n\n", ft_itoa_number7);
	printf("String: %s\n", ft_itoa(ft_itoa_number7));
	printf("--------------------\n");

	printf("Number: %d\n\n", ft_itoa_number8);
	printf("String: %s\n", ft_itoa(ft_itoa_number8));
	printf("--------------------\n");

	printf("Number: %d\n\n", ft_itoa_number9);
	printf("String: %s\n", ft_itoa(ft_itoa_number9));
	printf("--------------------\n");

	printf("Number: %d\n\n", ft_itoa_number10);
	printf("String: %s\n", ft_itoa(ft_itoa_number10));
	printf("--------------------\n");
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:30:17 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/07 14:17:11 by ryeong           ###   ########.fr       */
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

static void	checknegative(int n, long *num, int *isnegative)
{
	if (n < 0)
	{
		*num *= -1;
		*isnegative = 1;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	ph[50];
	long	num;
	int		isnegative;
	int		i;

	i = 0;
	isnegative = 0;
	num = n;
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		checknegative(n, &num, &isnegative);
		while (i < digitcount(n))
		{
			ph[i] = (char)(num % 10) + '0';
			num /= 10;
			i++;
		}
		if (n < 0)
			ph[i++] = '-';
		while (--i >= 0)
			ft_putchar_fd(ph[i], fd);
	}
}

/* int main(void)
{
	int ft_putnbr_fd_number = -5;

	printf("========================================\n");
	printf("ft_putnbr_fd\n");
	printf("========================================\n");
	ft_putnbr_fd(ft_putnbr_fd_number, 0);
	printf("\n--------------------\n");

	ft_putnbr_fd(ft_putnbr_fd_number, 1);
	printf("\n--------------------\n");

	ft_putnbr_fd(ft_putnbr_fd_number, 2);
	printf("\n--------------------\n");
} */
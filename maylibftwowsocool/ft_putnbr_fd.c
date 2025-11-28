/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:04:12 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/19 21:50:38 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}

/*
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc!= 3)
	{
		printf("put 3 arguments smthn liddis : a.out 12345 1");
		return (1);
	}
	int nb = ft_atoi(argv[1]);
	int fd = ft_atoi(argv[2]);
	ft_putnbr_fd(nb, fd);
	return (0);
}
*/
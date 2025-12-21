/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:34:11 by stee              #+#    #+#             */
/*   Updated: 2025/10/21 16:43:47 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	l;

	l = n;
	if (l < 0)
	{
		ft_putchar_fd('-', fd);
		l *= -1;
	}
	if (l >= 10)
	{
		ft_putnbr_fd((l / 10), fd);
		ft_putchar_fd(((l % 10) + '0'), fd);
	}
	else
		ft_putchar_fd((l + '0'), fd);
}
/*
#include <stdio.h>
int main(void)
{
    ft_putnbr_fd(42, 1);
    return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:29:08 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/28 15:37:50 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	long	n;
	int		len;

	len = 0;
	n = nb;
	if (n < 0)
	{
		ft_putchar_fd('-');
		n = -n;
		len++;
	}
	if (n >= 10)
	{
		len += ft_putnbr(n / 10);
	}
	ft_putchar_fd((n % 10) + '0');
	len++;
	return (len);
}

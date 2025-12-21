/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:47:19 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/22 17:31:39 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_i_d(int nb)
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

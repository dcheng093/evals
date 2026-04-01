/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:37:48 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/22 17:37:31 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf_p(void	*pointer)
{
	unsigned long	address;
	int				len;

	if (!pointer)
	{
		ft_putstr("(nil)");
		return (5);
	}
	address = (unsigned long)pointer;
	ft_putchar_fd('0');
	ft_putchar_fd('x');
	len = 2;
	len += ft_putnbr_base(address, 16, HEX_LOWER);
	return (len);
}

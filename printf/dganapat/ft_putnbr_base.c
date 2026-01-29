/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:31:17 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/22 17:38:22 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, unsigned int base, char *set)
{
	int		len;

	len = 0;
	if (n >= base)
	{
		len += ft_putnbr_base(n / base, base, set);
	}
	ft_putchar_fd(set[n % base]);
	len++;
	return (len);
}
/*int     main()
{
	int nb;

	nb = -2147483648;
	//ft_putnbr_base (nb, 10, "0123456789");

	printf("%d\n" , ft_putnbr_base(nb, 10, "0123456789"));

	return (0);
}*/
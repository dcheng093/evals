/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 07:21:06 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/11 19:46:51 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd((nb / 10), fd);
	ft_putchar_fd(((nb % 10) + '0'), fd);
}
/*int	main(void)
{
	int	n;
	int	fd;

	n = -2147483648;
	fd = 1;

	ft_putnbr_fd(n, fd);
	return (0);
}*/

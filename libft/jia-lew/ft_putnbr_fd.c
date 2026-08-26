/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:33:52 by jia-liew          #+#    #+#             */
/*   Updated: 2026/07/31 15:33:53 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;

	if (n < 0)
	{
		number = -n;
		ft_putchar_fd('-', fd);
	}
	else
		number = n;
	if (number >= 10)
		ft_putnbr_fd((number / 10), fd);
	ft_putchar_fd((number % 10) + '0', fd);
}

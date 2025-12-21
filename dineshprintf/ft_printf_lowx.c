/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lowx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:11:37 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/22 16:39:18 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_lowx(unsigned int nb)
{
	return (ft_putnbr_base(nb, 16, HEX_LOWER));
}

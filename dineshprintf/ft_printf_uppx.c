/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uppx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:14:06 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/22 16:51:41 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_uppx(unsigned int nb)
{
	return (ft_putnbr_base(nb, 16, HEX_UPPER));
}

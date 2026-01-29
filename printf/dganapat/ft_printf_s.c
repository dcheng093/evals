/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:41:20 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/28 20:19:10 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(char	*s1)
{
	int	len;

	if (!s1)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = 0;
	while (s1[len])
	{
		ft_putchar_fd(s1[len]);
		len++;
	}
	return (len);
}

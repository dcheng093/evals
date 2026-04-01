/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:34:37 by stee              #+#    #+#             */
/*   Updated: 2025/12/15 19:50:57 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle(const char flag, va_list args)
{
	if (flag == 'c')
		return (ft_putchar_pf((char)va_arg(args, int)));
	if (flag == 's')
		return (ft_putstr_pf(va_arg(args, char *)));
	if (flag == 'i' || flag == 'd')
		return (ft_putnbr_pf(va_arg(args, int)));
	if (flag == 'u')
		return (ft_putunbr_pf(va_arg(args, unsigned int)));
	if (flag == '%')
		return (ft_putchar_pf('%'));
	if (flag == 'p')
		return (ft_putptr_pf(va_arg(args, void *)));
	if (flag == 'x' || flag == 'X')
		return (ft_puthexa_pf(va_arg(args, unsigned int), flag));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		bytes;
	va_list	args;

	va_start(args, s);
	i = 0;
	bytes = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			bytes += ft_handle(s[i + 1], args);
			i++;
		}
		else
			bytes += ft_putchar_pf(s[i]);
		i++;
	}
	va_end(args);
	return (bytes);
}

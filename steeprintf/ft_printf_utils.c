/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <stee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:12:28 by stee              #+#    #+#             */
/*   Updated: 2025/11/14 17:44:52 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(char c)
{
	ft_putchar(c);
	return (1);
}

int	ft_putstr_pf(char *s)
{
	if (!s)
		return (ft_putstr_pf("(null)"));
	ft_putstr(s);
	return (ft_strlen(s));
}

int	ft_puthexa_pf(unsigned long arg, const char flag)
{
	char	*base;
	int		bytes;
	char	buffer[32];
	int		i;

	if (flag == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	bytes = 0;
	if (arg == 0)
		return (ft_putchar_pf('0'));
	i = 0;
	while (arg > 0)
	{
		buffer[i++] = base[arg % 16];
		arg /= 16;
	}
	while (i-- > 0)
		bytes += ft_putchar_pf(buffer[i]);
	return (bytes);
}

int	ft_putnbr_pf(int c)
{
	int		i;
	char	*str;

	str = ft_itoa(c);
	i = ft_putstr_pf(str);
	free (str);
	return (i);
}

int	ft_putptr_pf(void *ptr)
{
	int				bytes;

	if (!ptr)
		return (ft_putstr_pf("(nil)"));
	bytes = 0;
	bytes += ft_putstr_pf("0x");
	bytes += ft_puthexa_pf((unsigned long) ptr, 'x');
	return (bytes);
}

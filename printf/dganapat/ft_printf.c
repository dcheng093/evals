/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:23:36 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/28 20:22:11 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 
//#include <stdarg.h>

int	check_format(va_list args, char format)
{
	if (format == 'i' || format == 'd')
		return (ft_printf_i_d(va_arg(args, int)));
	if (format == 'u')
		return (ft_printf_u(va_arg(args, unsigned int)));
	if (format == 'x')
		return (ft_printf_lowx(va_arg(args, unsigned int)));
	if (format == 'X')
		return (ft_printf_uppx(va_arg(args, unsigned int)));
	if (format == 's')
		return (ft_printf_s(va_arg(args, char *)));
	if (format == 'p')
		return (ft_printf_p(va_arg(args, void *)));
	if (format == 'c')
		return (ft_printf_c(va_arg(args, int)));
	if (format == '%')
		return (ft_putchar_fd('%'), 1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			len += check_format(args, format[i]);
		}
		else
		{
			ft_putchar_fd(format[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
/*#include <stdio.h>
int	main(void)

{
	int	p;
	char c;
	char *s1;
	
	c = 'a';
	s1 = "Hello World";
	p = 5;
	//unsigned int b = 0123456789123456;
	//ft_printf ("  My function pointer : %p\n %d\n %u\n %x\n %X\n", &p,p,p,p,p);
	//printf ("Orginal function pointer : %p\n %d\n %u\n %x\n %X\n", &p,p,p,p,p);
	//printf("%d\n" , ft_printf ("My function pointer : %s\n %c\n %%", s1, c));
	//printf ("%d\n" , printf ("My function pointer : %s\n %c\n %%", s1, c));

	//ft_printf ("My function pointer : %d\n, ft_print);
	//printf ("Orginal function pointer : %d\n,  c);

	printf("%d\n" , ft_printf ("My function pointer : %s\n", s1));
	printf ("%d\n" , printf ("My function pointer : %s\n" , s1));


	
	
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:37:16 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/28 20:23:06 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putchar_fd(char c);
void	ft_putstr(char *s1);

int		ft_putnbr_base(unsigned long n, unsigned int base, char *set);
int		ft_putnbr(int nb);

int		ft_printf_c(int c);
int		ft_printf_i_d(int nb);
int		ft_printf_u(unsigned int nb);

int		ft_printf_lowx(unsigned int nb);
int		ft_printf_uppx(unsigned int nb);

int		ft_printf_s(char *s1);
int		ft_printf_p(void *pointer);
int		ft_printf(const char *format, ...);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <stee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:09:53 by stee              #+#    #+#             */
/*   Updated: 2025/11/07 17:34:16 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int		ft_printf(const char *s, ...);
int		ft_handle(const char flag, va_list args);
void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_putchar_pf(char c);
int		ft_putstr_pf(char *s);
int		ft_puthexa_pf(unsigned long arg, const char flag);
int		ft_putnbr_pf(int c);
int		ft_putunbr_pf(unsigned int c);
int		ft_putptr_pf(void *ptr);

#endif
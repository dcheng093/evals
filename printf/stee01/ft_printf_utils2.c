/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <stee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:12:28 by stee              #+#    #+#             */
/*   Updated: 2025/11/14 17:46:08 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

static char	*ft_uitoa(unsigned int n)
{
	char			*str;
	unsigned int	tmp;
	int				len;

	len = 0;
	tmp = n;
	if (n == 0)
		return (ft_strdup("0"));
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (len > 0)
	{
		str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}

int	ft_putunbr_pf(unsigned int n)
{
	char	*str;
	int		bytes;

	str = ft_uitoa(n);
	bytes = ft_putstr_pf(str);
	free (str);
	return (bytes);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguraiah <vguraiah@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 07:24:11 by vguraiah          #+#    #+#             */
/*   Updated: 2025/08/09 09:22:18 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{	
	write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	if (n >= 0)
	{
		n = 'P';
		ft_putchar(n);
	}
	else
	{
		n = 'N';
		ft_putchar(n);
	}
}

int	main()
{
	ft_is_negative(6);
	ft_is_negative(-6);
	ft_is_negative(0);
	ft_is_negative(123);
	ft_is_negative(-123);

	return (0);
}

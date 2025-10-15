/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguraiah <vguraiah@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 04:39:36 by vguraiah          #+#    #+#             */
/*   Updated: 2025/08/09 09:21:45 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(void)
{
	char num;

	num = '0';
	while (num <= '9')
	{
		ft_putchar(num);
		num++;
	}
}

int	main(void)
{
	ft_print_numbers();
	return (0);
}

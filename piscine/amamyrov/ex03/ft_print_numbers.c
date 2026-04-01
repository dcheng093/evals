/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:43:16 by amamyrov          #+#    #+#             */
/*   Updated: 2025/08/07 20:22:06 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_numbers(void);

void	ft_print_numbers(void)
{
	char	num;

	num = '1';
	while (num <= '9')
	{
		write(1, &num, 1);
		num++;
	}
}

int	 main()
{
	ft_print_numbers();
	return 0;
}

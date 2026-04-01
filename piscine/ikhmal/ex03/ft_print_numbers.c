/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-ab2 <mbin-ab2@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:34:29 by mbin-ab2          #+#    #+#             */
/*   Updated: 2025/08/07 19:37:32 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void);

void	ft_print_numbers(void)
{
	int	num;	

	num = '0';
	while (num <= '9' )
	{
		write(1, &num, 1);
		num++;
	}
}


int	main(void)
{
	ft_print_numbers();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-ab2 <mbin-ab2@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:43:59 by mbin-ab2          #+#    #+#             */
/*   Updated: 2025/08/07 19:38:53 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n);

void	ft_is_negative(int n)
{
	char	negative;
	char	positive;

	negative = 'N';
	positive = 'P';
	if (n < 0)
	{
		write(1, &negative, 1);
	}
	else if (n > 0)
	{
		write(1, &positive, 1);
	}
}

int	main(void)
{
	ft_is_negative(-22);
	return (0);
}

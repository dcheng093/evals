/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: si-wong <si-wong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:37:25 by si-wong           #+#    #+#             */
/*   Updated: 2025/08/08 12:45:48 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	ans;

	ans = nb;
	if (nb <= 9)
	{
		ans += '0';
		write(1, &ans, 1);
	}
	if (nb > 9)
	{
		ft_putnbr(ans / 10);
		ft_putnbr(ans % 10);
	}
}

int	main(void)
{
	ft_putnbr(42);
}

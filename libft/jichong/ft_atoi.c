/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichong <jichong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:11:09 by jichong           #+#    #+#             */
/*   Updated: 2025/11/01 16:18:11 by jichong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(char *str)
{
	int	negative;
	int	final_number;

	negative = 0;
	final_number = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		final_number = final_number * 10 + (*str - 48);
		str++;
	}
	if (negative == 1)
		final_number *= -1;
	return (final_number);
}
/*
int	main(void)
{
	char	string[] = "   -----++356733e683";

	printf("%d\n", ft_atoi(string));
}*/

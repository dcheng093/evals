/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:35:30 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/06 13:35:28 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	conditions(int *state, char *ph, int *isnegative, int *result)
{
	if (*state == 0 && *ph != '-' && *ph != '+'
		&& !(*ph >= '0' && *ph <= '9'))
		*state = 2;
	else if (*state == 0 && *ph == '-')
	{
		*isnegative = 1;
		*state = 1;
	}
	else if (*state == 0 && *ph == '+')
		*state = 1;
	else if ((*ph >= '0' && *ph <= '9'))
	{
		*result = (*result * 10) + (*ph - '0');
	}
	else if (*state == 1 && !(*ph >= '0' && *ph <= '9'))
		*state = 2;
}

int	ft_atoi(const char *nptr)
{
	int		isnegative;
	int		result;
	int		state;
	char	*ph;

	ph = (char *)nptr;
	result = 0;
	state = 0;
	isnegative = 0;
	while (*ph == ' ' || *ph == '\t' || *ph == '\n' || *ph == '\r'
		|| *ph == '\v' || *ph == '\f')
		ph++;
	while (*ph && state != 2)
	{
		conditions(&state, ph, &isnegative, &result);
		ph++;
	}
	if (isnegative == 1)
		result *= -1;
	return (result);
}
/* 
int	main(void)
{
	const char *ft_atoi_num1 = "\n\n\n  -46\b9 \n5d6";
	const char *ft_atoi_num2 = "\t\n\r\v\f  469 \n";
	const char *ft_atoi_num3 = " 0";
	const char *ft_atoi_num4 = " --42";
	const char *ft_atoi_num5 = " asdfsda42";
	const char *ft_atoi_num6 = " +42asdfasdf";
	const char *ft_atoi_num7 = " -1234  -42asdfa23sdf";
	const char *ft_atoi_num8 = " 12ab3";
	const char *ft_atoi_num9 = " 2147483648";
	const char *ft_atoi_num10 = " 2147483647";

	printf("========================================\n");
	printf("ft_atoi\n");
	printf("========================================\n");
	printf("Num: %s\n\n", ft_atoi_num1);
	printf("Original: %d\n", atoi(ft_atoi_num1));
	printf("Recreation: %d\n", ft_atoi(ft_atoi_num1));
	printf("--------------------\n");

	printf("Num: %s\n\n", ft_atoi_num2);
	printf("Original: %d\n", atoi(ft_atoi_num2));
	printf("Recreation: %d\n", ft_atoi(ft_atoi_num2));
	printf("--------------------\n");

	printf("Num: %s\n\n", ft_atoi_num3);
	printf("Original: %d\n", atoi(ft_atoi_num3));
	printf("Recreation: %d\n", ft_atoi(ft_atoi_num3));
	printf("--------------------\n");

	printf("Num: %s\n\n", ft_atoi_num4);
	printf("Original: %d\n", atoi(ft_atoi_num4));
	printf("Recreation: %d\n", ft_atoi(ft_atoi_num4));
	printf("--------------------\n");

	printf("Num: %s\n\n", ft_atoi_num5);
	printf("Original: %d\n", atoi(ft_atoi_num5));
	printf("Recreation: %d\n", ft_atoi(ft_atoi_num5));
	printf("--------------------\n");

	printf("Num: %s\n\n", ft_atoi_num6);
	printf("Original: %d\n", atoi(ft_atoi_num6));
	printf("Recreation: %d\n", ft_atoi(ft_atoi_num6));
	printf("--------------------\n");

	printf("Num: %s\n\n", ft_atoi_num7);
	printf("Original: %d\n", atoi(ft_atoi_num7));
	printf("Recreation: %d\n", ft_atoi(ft_atoi_num7));
	printf("--------------------\n");

	printf("Num: %s\n\n", ft_atoi_num8);
	printf("Original: %d\n", atoi(ft_atoi_num8));
	printf("Recreation: %d\n", ft_atoi(ft_atoi_num8));
	printf("--------------------\n");

	printf("Num: %s\n\n", ft_atoi_num9);
	printf("Original: %d\n", atoi(ft_atoi_num9));
	printf("Recreation: %d\n", ft_atoi(ft_atoi_num9));
	printf("--------------------\n");

	printf("Num: %s\n\n", ft_atoi_num10);
	printf("Original: %d\n", atoi(ft_atoi_num10));
	printf("Recreation: %d\n", ft_atoi(ft_atoi_num10));
	printf("--------------------\n");
} */
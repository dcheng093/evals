/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:44:52 by afomin            #+#    #+#             */
/*   Updated: 2025/08/11 16:00:57 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (1)
	{
		if (str[i] == '\0')
		{
			break ;
		}
		else if (!(str[i] >= 'A' && str[i] <= 'Z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(void)
{
	char	s1[3];
	char	s2[1];

	s1[0] = 'A';
	s1[1] = 'D';
	s1[2] = '\0';
	printf("%s - %d\n", s1, ft_str_is_uppercase(s1));
	printf("%s - %d", s2, ft_str_is_uppercase(s2));
}

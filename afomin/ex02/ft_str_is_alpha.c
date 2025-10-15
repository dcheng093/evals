/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 17:44:52 by afomin            #+#    #+#             */
/*   Updated: 2025/08/11 15:54:30 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (1)
	{
		if (str[i] == '\0')
		{
			return (1);
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
		}
		else
		{
			return (0);
		}
		i++;
	}
}

int	main(void)
{
	char	s1[3];
	char	s2[1];

	s1[0] = 'A';
	s1[1] = '+';
	s1[2] = '\0';
	printf("%s - %d\n", s1, ft_str_is_alpha(s1));
	printf("%s - %d", s2, ft_str_is_alpha(s2));
}

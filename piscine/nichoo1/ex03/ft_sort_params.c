/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nichoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:47:42 by nichoo            #+#    #+#             */
/*   Updated: 2025/08/19 14:26:11 by nichoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_sort_params(char **av)
{
	int	i;
	int	is_sorted;

	while (1)
	{
		i = 1;
		is_sorted = 1;
		while (av[i + 1])
		{
			if (ft_strcmp(av[i], av[i + 1]) > 0)
			{
				ft_swap(&av[i], &av[i + 1]);
				is_sorted = 0;
			}
			i++;
		}
		if (is_sorted == 1)
			break ;
	}
}

int	main(int ac, char **av)
{
	int	i;

	if (ac == 1)
		return (0);
	ft_sort_params(av);
	i = 1;
	while (i < ac)
		ft_putstr(av[i++]);
	return (0);
}

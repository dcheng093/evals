/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nichoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:30:45 by nichoo            #+#    #+#             */
/*   Updated: 2025/08/19 14:31:02 by nichoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac == 1)
		return (0);
	i = 1;
	while (av[i])
	{
		ft_putstr(av[i++]);
		ft_putchar('\n');
	}
}

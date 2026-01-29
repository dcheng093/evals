/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:59:20 by nichoo            #+#    #+#             */
/*   Updated: 2025/08/17 21:30:59 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int nb)
{
	int	n;

	n = 1;
	while (n * n < nb)
		n++;
	if (n * n == nb)
		return (n);
	else
		return (0);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 0;
	int nb = atoi(av[1]);
	int result = ft_sqrt(nb);

	printf("The sqrt of %d is %d\n", nb, result);
}

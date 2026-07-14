/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:20:56 by asyeo             #+#    #+#             */
/*   Updated: 2026/07/14 15:43:02 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_pushswap *ps)
{
	int	tmp;

	if (ps->size_a < 2)
		return (0);
	tmp = ps->a[1];
	ps->a[1] = ps->a[0];
	ps->a[0] = tmp;
	return (1);
}

int	pa(t_pushswap *ps)
{
	size_t	i;

	if (ps->size_b == 0)
		return (0);
	i = ps->size_a;
	while (i > 0)
	{
		ps->a[i] = ps->a[i - 1];
		i--;
	}
	ps->a[0] = ps->b[0];
	i = 0;
	while (i < ps->size_b - 1)
	{
		ps->b[i] = ps->b[i + 1];
		i++;
	}
	ps->size_a++;
	ps->size_b--;
	return (1);
}

int	ra(t_pushswap *ps)
{
	int		tmp;
	size_t	i;

	if (ps->size_a < 2)
		return (0);
	i = 0;
	tmp = ps->a[0];
	while (i < ps->size_a - 1)
	{
		ps->a[i] = ps->a[i + 1];
		i++;
	}
	ps->a[ps->size_a - 1] = tmp;
	return (1);
}

int	rra(t_pushswap *ps)
{
	int		tmp;
	size_t	i;

	if (ps->size_a < 2)
		return (0);
	i = ps->size_a - 1;
	tmp = ps->a[ps->size_a - 1];
	while (i > 0)
	{
		ps->a[i] = ps->a[i - 1];
		i--;
	}
	ps->a[0] = tmp;
	return (1);
}

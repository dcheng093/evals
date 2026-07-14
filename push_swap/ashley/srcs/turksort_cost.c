/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turksort_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:25:58 by asyeo             #+#    #+#             */
/*   Updated: 2026/07/14 15:19:53 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calc_costs_r(t_pushswap *ps)
{
	size_t	i;
	size_t	median_a;
	size_t	median_b;

	i = 0;
	median_a = (ps->size_a + 1) / 2;
	median_b = (ps->size_b + 1) / 2;
	while (i < ps->size_a)
	{
		if (i < median_a)
			ps->cost[i] = i;
		else
			ps->cost[i] = ps->size_a - i;
		if (ps->target_a[i] < median_b)
			ps->cost[i] += ps->target_a[i];
		else
			ps->cost[i] += ps->size_b - ps->target_a[i];
		i++;
	}
}

static void	calc_costs_rr(t_pushswap *ps)
{
	size_t		i;
	size_t		total_cost;

	i = 0;
	while (i < ps->size_a)
	{
		total_cost = ft_max(i, ps->target_a[i]);
		if (total_cost < (size_t) ps->cost[i])
		{
			ps->cost[i] = total_cost;
			ps->rr[i] = 1;
		}
		i++;
	}
}

static void	calc_costs_rrr(t_pushswap *ps)
{
	size_t		i;
	size_t		total_cost;

	i = 0;
	while (i < ps->size_a)
	{
		total_cost = ft_max(ps->size_a - i, ps->size_b - ps->target_a[i]);
		if (total_cost < (size_t) ps->cost[i])
		{
			ps->cost[i] = total_cost;
			ps->rr[i] = 0;
			ps->rrr[i] = 1;
		}
		i++;
	}
}

void	calc_cost(t_pushswap *ps)
{
	size_t	i;

	i = 0;
	while (i < ps->size_a)
	{
		ps->rr[i] = 0;
		ps->rrr[i] = 0;
		i++;
	}
	calc_costs_r(ps);
	calc_costs_rr(ps);
	calc_costs_rrr(ps);
}

size_t	find_cheapest(const t_pushswap *ps)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (i < ps->size_a)
	{
		if (ps->cost[i] < ps->cost[res])
			res = i;
		i++;
	}
	return (res);
}

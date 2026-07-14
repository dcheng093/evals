/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turksort_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 00:34:48 by asyeo             #+#    #+#             */
/*   Updated: 2026/07/14 15:19:47 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_to_top(t_pushswap *ps, size_t i)
{
	size_t	median_a;
	size_t	median_b;
	int		target_val;
	int		target_b_val;

	if (i >= ps->size_a)
		return ;
	target_val = ps->a[i];
	median_a = (ps->size_a + 1) / 2;
	if (i < median_a)
		while (ps->a[0] != target_val)
			op(ps, ROTATE_A);
	else
		while (ps->a[0] != target_val)
			op(ps, REVERSE_ROTATE_A);
	if (ps->size_b == 0 || ps->target_a[i] >= ps->size_b)
		return ;
	target_b_val = ps->b[ps->target_a[i]];
	median_b = (ps->size_b + 1) / 2;
	if (ps->target_a[i] < median_b)
		while (ps->b[0] != target_b_val)
			op(ps, ROTATE_B);
	else
		while (ps->b[0] != target_b_val)
			op(ps, REVERSE_ROTATE_B);
}

static void	rr_to_top(t_pushswap *ps, const size_t i)
{
	int	a_val;
	int	b_val;

	if (ps->size_b == 0 || ps->target_a[i] >= ps->size_b)
	{
		r_to_top(ps, i);
		return ;
	}
	a_val = ps->a[i];
	b_val = ps->b[ps->target_a[i]];
	while (ps->a[0] != a_val && ps->b[0] != b_val)
		op(ps, ROTATE_ROTATE);
	while (ps->a[0] != a_val)
		op(ps, ROTATE_A);
	while (ps->b[0] != b_val)
		op(ps, ROTATE_B);
}

static void	rrr_to_top(t_pushswap *ps, const size_t i)
{
	int	a_val;
	int	b_val;

	if (ps->size_b == 0 || ps->target_a[i] >= ps->size_b)
	{
		r_to_top(ps, i);
		return ;
	}
	a_val = ps->a[i];
	b_val = ps->b[ps->target_a[i]];
	while (ps->a[0] != a_val && ps->b[0] != b_val)
		op(ps, REVERSE_ROTATE_ROTATE);
	while (ps->a[0] != a_val)
		op(ps, REVERSE_ROTATE_A);
	while (ps->b[0] != b_val)
		op(ps, REVERSE_ROTATE_B);
}

void	move_cheapest_to_top(t_pushswap *ps)
{
	size_t	i;

	set_target_a(ps);
	calc_cost(ps);
	i = find_cheapest(ps);
	if (ps->rr[i])
		rr_to_top(ps, i);
	else if (ps->rrr[i])
		rrr_to_top(ps, i);
	else
		r_to_top(ps, i);
}

void	move_b_target_to_top(t_pushswap *ps)
{
	int		a;
	size_t	median_a;
	size_t	i;

	set_target_b(ps);
	i = ps->target_b;
	a = ps->a[i];
	median_a = (ps->size_a + 1) / 2;
	if (i < median_a)
		while (ps->a[0] != a)
			op(ps, ROTATE_A);
	else
		while (ps->a[0] != a)
			op(ps, REVERSE_ROTATE_A);
}

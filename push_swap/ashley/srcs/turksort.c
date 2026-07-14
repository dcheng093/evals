/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turksort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:49:04 by asyeo             #+#    #+#             */
/*   Updated: 2026/07/14 15:19:38 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_a(t_pushswap *ps)
{
	size_t	i;
	size_t	j;
	int		best_val;
	size_t	target_idx;

	i = 0;
	while (i < ps->size_a)
	{
		j = 0;
		best_val = INT_MIN;
		target_idx = SIZE_MAX;
		while (j < ps->size_b)
		{
			if (ps->b[j] < ps->a[i] && (target_idx
					== SIZE_MAX || ps->b[j] > best_val))
			{
				best_val = ps->b[j];
				target_idx = j;
			}
			j++;
		}
		if (target_idx == SIZE_MAX && ps->size_b > 0)
			target_idx = find_max_index(ps->b, ps->size_b);
		ps->target_a[i++] = target_idx;
	}
}

void	set_target_b(t_pushswap *ps)
{
	size_t	target_idx;
	size_t	i;
	int		best_val;

	i = 0;
	best_val = INT_MAX;
	target_idx = SIZE_MAX;
	while (i < ps->size_a)
	{
		if (ps->a[i] > ps->b[0])
		{
			if (target_idx == SIZE_MAX || ps->a[i] < best_val)
			{
				best_val = ps->a[i];
				target_idx = i;
			}
		}
		i++;
	}
	if (target_idx == SIZE_MAX)
		target_idx = find_min_index(ps->a, ps->size_a);
	ps->target_b = target_idx;
}

void	sort_three(t_pushswap *ps)
{
	int	max;

	if (ps->size_a != 3)
		return ;
	max = ps->a[find_max_index(ps->a, ps->size_a)];
	if (ps->a[0] == max)
		op(ps, ROTATE_A);
	else if (ps->a[1] == max)
		op(ps, REVERSE_ROTATE_A);
	if (ps->a[0] > ps->a[1])
		op(ps, SWAP_A);
}

void	sort_stack(t_pushswap *ps)
{
	int		min_val;
	size_t	min_idx;
	size_t	median_a;

	min_idx = find_min_index(ps->a, ps->size_a);
	min_val = ps->a[min_idx];
	median_a = (ps->size_a + 1) / 2;
	if (min_idx < median_a)
		while (ps->a[0] != min_val)
			op(ps, ROTATE_A);
	else
		while (ps->a[0] != min_val)
			op(ps, REVERSE_ROTATE_A);
}

void	turksort(t_pushswap *ps)
{
	if (ps->size_a > 3 && !is_sorted(ps->a, ps->size_a))
		op(ps, PUSH_B);
	if (ps->size_a > 3 && !is_sorted(ps->a, ps->size_a))
		op(ps, PUSH_B);
	while (ps->size_a > 3 && !is_sorted(ps->a, ps->size_a))
	{
		move_cheapest_to_top(ps);
		op(ps, PUSH_B);
	}
	sort_three(ps);
	while (ps->size_b > 0)
	{
		move_b_target_to_top(ps);
		op(ps, PUSH_A);
	}
	sort_stack(ps);
}

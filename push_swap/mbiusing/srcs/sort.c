/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:21:14 by mbiusing          #+#    #+#             */
/*   Updated: 2026/04/28 16:02:59 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size == 2)
		sort_two(a);
	else if (a->size <= 5)
		sort_small(a, b);
	else
		radix_sort(a, b);
}

void	sort_two(t_stack *a)
{
	if (a->head->num > a->head->next->num)
		sa(a);
}

void	sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->head->num;
	y = a->head->next->num;
	z = a->tail->num;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

void	sort_small(t_stack *a, t_stack *b)
{
	int	pos;

	while (a->size > 3)
	{
		pos = find_min_pos(a);
		if (pos <= a->size / 2)
			while (pos-- > 0)
				ra(a);
		else
			while (pos++ < a->size)
				rra(a);
		pb(a, b);
	}
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	while (b->size > 0)
		pa(a, b);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	bit;
	int	i;
	int	size;
	int	max_bits;

	bit = 0;
	size = a->size;
	max_bits = get_max_bits(size);
	while (bit < max_bits && !is_sorted(a))
	{
		i = 0;
		while (i++ < size)
		{
			if (((a->head->num >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}

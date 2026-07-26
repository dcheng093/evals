/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:01:48 by mbiusing          #+#    #+#             */
/*   Updated: 2026/04/28 16:02:40 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_max_bits(int size)
{
	int	max;
	int	bits;

	max = size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

int	find_min_pos(t_stack *a)
{
	t_node	*cur;
	int		min;
	int		pos;
	int		i;

	cur = a->head;
	min = cur->num;
	pos = 0;
	i = 0;
	while (i < a->size)
	{
		if (cur->num < min)
		{
			min = cur->num;
			pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (pos);
}

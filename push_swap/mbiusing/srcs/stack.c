/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:59:18 by mbiusing          #+#    #+#             */
/*   Updated: 2026/04/30 20:23:42 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->size = 0;
	stack->head = NULL;
	stack->tail = NULL;
}

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->num = value;
	node->next = node;
	node->prev = node;
	return (node);
}

int	add_back(t_stack *stack, int value)
{
	t_node	*node;

	node = new_node(value);
	if (!node)
		return (0);
	if (stack->size == 0)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		node->prev = stack->tail;
		node->next = stack->head;
		stack->tail->next = node;
		stack->head->prev = node;
		stack->tail = node;
	}
	stack->size++;
	return (1);
}

int	build_stack(t_stack *a, int *values, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!add_back(a, values[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	t_node	*cur;
	int		i;

	if (!stack || stack->size < 2)
		return (1);
	cur = stack->head;
	i = 0;
	while (i < stack->size - 1)
	{
		if (cur->num > cur->next->num)
			return (0);
		cur = cur->next;
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:08:38 by mbiusing          #+#    #+#             */
/*   Updated: 2026/07/21 15:26:22 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	remove_head(t_stack *stack)
{
	t_node	*dead;

	dead = stack->head;
	if (stack->size == 1)
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	else
	{
		stack->head = dead->next;
		stack->tail->next = stack->head;
		stack->head->prev = stack->tail;
	}
	stack->size--;
}

void	add_front_node(t_stack *stack, t_node *node)
{
	if (stack->size == 0)
	{
		node->next = node;
		node->prev = node;
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		node->next = stack->head;
		node->prev = stack->tail;
		stack->tail->next = node;
		stack->head->prev = node;
		stack->head = node;
	}
	stack->size++;
}

void	push(t_stack *dst, t_stack *src)
{
	t_node	*node;

	if (!dst || !src || src->size == 0)
		return ;
	node = src->head;
	remove_head(src);
	add_front_node(dst, node);
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pb\n", 3);
}

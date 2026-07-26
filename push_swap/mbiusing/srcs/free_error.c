/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:03:26 by mbiusing          #+#    #+#             */
/*   Updated: 2026/04/28 16:03:42 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*cur;
	t_node	*next;
	int		i;
	int		size;

	if (!stack || stack->size == 0)
		return ;
	cur = stack->head;
	size = stack->size;
	i = 0;
	while (i < size)
	{
		next = cur->next;
		free(cur);
		cur = next;
		i++;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

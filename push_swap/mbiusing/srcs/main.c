/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:59:15 by mbiusing          #+#    #+#             */
/*   Updated: 2026/07/21 16:41:43 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		*values;
	int		size;

	if (ac < 2)
		return (0);
	init_stack(&a);
	init_stack(&b);
	values = NULL;
	if (!parse_input(av, &values, &size))
		error_exit();
	get_sorted_index(values, size);
	if (!build_stack(&a, values, size))
	{
		free(values);
		free_stack(&a);
		error_exit();
	}
	free(values);
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 17:05:24 by mbiusing          #+#    #+#             */
/*   Updated: 2026/07/21 16:42:53 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				num;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*head;
	struct s_node	*tail;
}				t_stack;

/* PARSE */
int		parse_input(char **av, int **values, int *size);
int		count_numbers(char **av);

/* VALIDATE */
int		is_valid_num(char *str);
long	ft_atol(char *str);
int		check_dup(int *values, int size);

/* STACK */
void	init_stack(t_stack *stack);
t_node	*new_node(int value);
int		add_back(t_stack *stack, int value);
int		build_stack(t_stack *a, int *values, int size);
int		is_sorted(t_stack *stack);

/* INDEX */
int		get_rank(int *values, int index, int size);
void	get_sorted_index(int *values, int size);

/* SORT */
void	sort_stack(t_stack *a, t_stack *b);
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_small(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);

/* SORT UTILS */
int		get_max_bits(int size);
int		find_min_pos(t_stack *a);

/* OPERATIONS */

	/* SWAP */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

	/* PUSH */
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

	/* ROTATE */
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

	/* RROTATE */
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* FREE & ERROR */
void	free_stack(t_stack *stack);
void	free_split(char **split);
void	error_exit(void);

#endif
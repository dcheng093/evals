/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:36:14 by mbiusing          #+#    #+#             */
/*   Updated: 2026/07/21 16:34:45 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_numbers(char **av)
{
	int		i;
	int		j;
	int		count;
	char	**split;

	i = 1;
	count = 0;
	while (av[i])
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return (-1);
		j = 0;
		while (split[j++])
			count++;
		free_split(split);
		i++;
	}
	return (count);
}

int	parse_split_tokens(char **tokens, int *numbers, int *index)
{
	int		i;
	long	number;

	i = 0;
	while (tokens[i])
	{
		if (!is_valid_num(tokens[i]))
			return (0);
		number = ft_atol(tokens[i]);
		if (number < INT_MIN || number > INT_MAX)
			return (0);
		numbers[(*index)++] = (int)number;
		i++;
	}
	return (1);
}

int	parse_arg(char **av, int *numbers)
{
	int		arg_i;
	int		num_i;
	char	**tokens;

	arg_i = 1;
	num_i = 0;
	while (av[arg_i])
	{
		tokens = ft_split(av[arg_i], ' ');
		if (!tokens || !tokens[0])
		{
			free_split(tokens);
			return (0);
		}
		if (!parse_split_tokens(tokens, numbers, &num_i))
		{
			free_split(tokens);
			return (0);
		}
		free_split(tokens);
		arg_i++;
	}
	return (1);
}

int	parse_input(char **av, int **numbers, int *size)
{
	*size = count_numbers(av);
	if (*size <= 0)
		return (0);
	*numbers = malloc(sizeof(int) * (*size));
	if (!*numbers)
		return (0);
	if (!parse_arg(av, *numbers))
	{
		free(*numbers);
		return (0);
	}
	if (check_dup(*numbers, *size))
	{
		free(*numbers);
		return (0);
	}
	return (1);
}

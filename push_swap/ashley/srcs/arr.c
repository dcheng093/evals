/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:20:49 by asyeo             #+#    #+#             */
/*   Updated: 2026/07/14 15:20:51 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(int *arr, size_t n)
{
	size_t	max_idx;
	size_t	i;

	max_idx = 0;
	i = 1;
	while (i < n)
	{
		if (arr[i] > arr[max_idx])
			max_idx = i;
		i++;
	}
	return (max_idx);
}

int	find_min_index(int *arr, size_t n)
{
	size_t	min_idx;
	size_t	i;

	min_idx = 0;
	i = 1;
	while (i < n)
	{
		if (arr[i] < arr[min_idx])
			min_idx = i;
		i++;
	}
	return (min_idx);
}

int	is_sorted(int *arr, size_t n)
{
	size_t	i;

	if (n < 2)
		return (1);
	i = 0;
	while (i < n - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

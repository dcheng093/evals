/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:04:30 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/19 14:47:02 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
#include <stdio.h>

int	main(void)
{
	char  test1[20] = "987654321";
	ft_bzero(test1, 2);
	printf("%s", test1);
	return (0);
}*/

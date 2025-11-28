/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:43:34 by mbiusing          #+#    #+#             */
/*   Updated: 2025/10/23 11:00:11 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("put in smthn like this : a.out M   OR  a.out 2");
		return (1);
	}
	char c = *argv[1];
	if (ft_isalnum(c))
		printf("yarz it is alphanumerical");
	else
		printf("naur its not alphanumerical");
	return (0);
}
*/
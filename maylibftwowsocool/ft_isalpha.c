/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:51:38 by mbiusing          #+#    #+#             */
/*   Updated: 2025/10/23 10:02:49 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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
	if (ft_isalpha(c))
		printf("yarz it is an alphabet");
	else
		printf("naur its not an alphabet");
	return (0);
}
*/
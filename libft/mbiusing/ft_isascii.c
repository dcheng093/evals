/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:11:59 by mbiusing          #+#    #+#             */
/*   Updated: 2025/10/23 11:42:41 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("put in smthn like this : a.out M   OR  a.out â");
		return (1);
	}
	char c = *argv[1];
	if (ft_isascii(c))
		printf("yarz it is ascii (0 - 127)");
	else
		printf("naur its not ascii (beyond the range of 0 - 127)");
	return (0);
}
*/
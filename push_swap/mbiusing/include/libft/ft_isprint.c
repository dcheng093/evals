/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:50:06 by mbiusing          #+#    #+#             */
/*   Updated: 2025/10/23 12:03:12 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	test1 = '\n';
	if (ft_isprint(test1))
		printf("%c is a printable character", test1);
	else
		printf("%c is a non-printable character", test1);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:03:52 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/18 11:37:52 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("enter it liddis : a.out 2  OR a.out M");
		return (1);
	}
	int c = *argv[1];
	if (ft_isdigit(c))
		printf("yup this is a digit");
	else
		printf("nah this aint a digit");
	return (0);
}
*/
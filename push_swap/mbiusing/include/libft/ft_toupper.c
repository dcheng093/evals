/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:01:50 by mbiusing          #+#    #+#             */
/*   Updated: 2025/10/25 17:06:14 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("use it liddis : a.out c");
		return (1);
	}

	char c = ft_toupper(*argv[1]);
	printf("%c", c);
	return (0);
}
*/
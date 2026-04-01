/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:00:31 by kquek             #+#    #+#             */
/*   Updated: 2025/08/14 15:18:48 by kquek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}
/*
int	main(void)
{
	char	*message;
	int		length;

	message = "four";
	length = ft_strlen(message);
	printf("Message: %s\n", message);
	printf("Length: %d\n", length);
	return (0);
}
*/

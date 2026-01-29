/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:04:23 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/19 21:52:07 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/*
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("put in 3 arguments, smthn liddis : a.out yoooooo 1");
		return (1);
	}
	char *s = argv[1];
	int fd = ft_atoi(argv[2]);
	ft_putstr_fd(s, fd);
	return (0);
}
*/
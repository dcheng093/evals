/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:48:52 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/18 11:43:47 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <stdio.h>

// int main(int argc, char *argv[])
// {
// 	if (argc != 3)
// 	{
// 		printf("How to test different types of file descriptors\n");
// 		printf("Redirect STDOUT (fd = 1)");
// 		printf("./test.out A 1 > out.txt\n");
// 		printf("Redirect STDERR (fd = 2)");
// 		printf("./test.out B 2 2> err.txt\n");
// 		printf("Redirect STDIN (fd = 0)");
// 		printf("./test.out C 0 0> in.txt\n");
// 		printf("actually i might be wrong im tired\n");
// 		return (1);
// 	}
// 	char c = *argv[1];
// 	int fd = ft_atoi(argv[2]);
// 	ft_putchar_fd(c, fd);
// 	return (0);
// }

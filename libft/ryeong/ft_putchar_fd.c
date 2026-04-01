/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:27:58 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/04 09:58:11 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
// 0	STDIN_FILENO	Standard Input (usually the keyboard)
// 1	STDOUT_FILENO	Standard Output (usually the terminal screen)
// 2	STDERR_FILENO	Standard Error (used for error messages)

// int	main(void)
// {
// 	char ft_putchar_fd_char = 'A';

// 	printf("========================================\n");
// 	printf("ft_putchar_fd\n");
// 	printf("========================================\n");
// 	ft_putchar_fd(ft_putchar_fd_char, 0);
// 	printf("\n--------------------\n");

// 	ft_putchar_fd(ft_putchar_fd_char, 1);
// 	printf("\n--------------------\n");

// 	ft_putchar_fd(ft_putchar_fd_char, 2);
// 	printf("\n--------------------\n");

// 	ft_putchar_fd(ft_putchar_fd_char, 3);
// 	printf("\n--------------------\n");
// }
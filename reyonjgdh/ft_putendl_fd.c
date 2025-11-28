/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:29:27 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/04 09:58:39 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	ft_putchar_fd('\n', fd);
}

// 0	STDIN_FILENO	Standard Input (usually the keyboard)
// 1	STDOUT_FILENO	Standard Output (usually the terminal screen)
// 2	STDERR_FILENO	Standard Error (used for error messages)

// int main(void)
// {
// 	char *ft_putendl_fd_string = "Fleshling youth, teach me to 
// communicate in trash talk.";

// 	printf("========================================\n");
// 	printf("ft_putendl_fd\n");
// 	printf("========================================\n");
// 	ft_putendl_fd(ft_putendl_fd_string, 0);
// 	printf("\n--------------------\n");

// 	ft_putendl_fd(ft_putendl_fd_string, 1);
// 	printf("\n--------------------\n");

// 	ft_putendl_fd(ft_putendl_fd_string, 2);
// 	printf("\n--------------------\n");
// }
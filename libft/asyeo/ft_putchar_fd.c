/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:25:02 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/15 13:12:44 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION : Writes the character c on file descriptor.
    
	RETURN VALUE : None.
*/

#include "libft.h"
//#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

/*
int	main(void)
{
	
}
*/

/* NOTES:
1) 1st para is the file descriptor (int fd) which specifies the fd to write on.

2) 2nd para is the char to be written. (char c)

3) write() is a sys call that writes data to a file descriptor.
*/
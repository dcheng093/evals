/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:08:05 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/18 14:25:26 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION : Writes string on specified file descriptor.
	
	RETURN VALUE : None.
*/

#include "libft.h"
//#include <stdio.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

// int	main(void)
// {
// 	char	*str = "Jeffy Jefferson";
// 	ft_putstr_fd(str, 1);
// 	return (0);
// }

/*
NOTES:
1) (!s) is the shortened form of (s == NULL) or (s = '\0').

2) if your code only needs one line, 
you can exclude the second {} and return (0)
*/

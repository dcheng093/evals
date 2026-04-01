/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:56:42 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/13 08:08:38 by dganapat         ###   ########.fr       */
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
	write(fd, "\n", 1);
}
/*int	main()
{
	int	fd;
	char 	*s1 = "Hello World";

	fd = 1;
	ft_putstr_fd(s1, fd);

	return (0);
}*/

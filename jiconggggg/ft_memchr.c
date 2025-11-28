/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichong <jichong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:49:57 by jichong           #+#    #+#             */
/*   Updated: 2025/10/27 18:49:57 by jichong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ps;
	size_t				i;

	ps = s;
	i = 0;
	while (i < n)
	{
		if (ps[i] == ((unsigned char)c))
			return ((void *)&ps[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	string[] = "Hello world!";
	char	*ptr = ft_memchr(string, 'o', sizeof(string));

	if (ptr != NULL)
		printf("Found 'o' at position: %ld\n", ptr - string);
	else
		printf("'o' not found\n");
	return (0);
}*/

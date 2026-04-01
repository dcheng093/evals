/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:05:44 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/13 17:30:22 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char		*new_string;
	size_t				total_size;

	total_size = count * size;
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	new_string = malloc(total_size);
	if (!new_string)
		return (NULL);
	ft_bzero(new_string, total_size);
	return (new_string);
}
/*int       main()
{
	char	*s1 = "Hello ";
	printf("Orginal function : %s\n" , strdup(s1));
	printf("My Function : %s\n" , ft_strdup(s1));
	free(new_string);

	return (0);
}*/
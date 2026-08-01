/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madinata <madinata@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:27:01 by madinata          #+#    #+#             */
/*   Updated: 2026/07/31 21:14:33 by madinata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*result;

	size = ft_strlen(s);
	if (size <= start)
		return (ft_calloc(1, 1));
	if (len < size - start)
		size = len;
	else
		size = size - start;
	result = malloc(size + 1);
	if (!result)
		return (0);
	result = ft_memmove(result, s + start, size);
	result[size] = '\0';
	return (result);
}

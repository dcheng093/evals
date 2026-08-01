/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madinata <madinata@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 16:58:36 by madinata          #+#    #+#             */
/*   Updated: 2026/07/31 20:28:30 by madinata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_member_of(char const c, char const *set)
{
	while (*set != '\0')
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	size_t	start_index;
	size_t	end_index;

	size = ft_strlen(s1);
	start_index = 0;
	end_index = 0;
	while (s1[start_index] != '\0' && is_member_of(s1[start_index], set))
		start_index++;
	while (size - end_index - 1 > 0
		&& is_member_of(s1[size - end_index - 1], set))
		end_index++;
	if (end_index == size || start_index == size)
		return (ft_calloc(1, 1));
	return (ft_substr(s1, start_index, size - start_index - end_index));
}

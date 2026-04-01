/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 23:47:02 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/18 11:51:50 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*array;
	int		size;
	int		i;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	array = (char *) malloc(sizeof(char) * (size + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		array[i] = s[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

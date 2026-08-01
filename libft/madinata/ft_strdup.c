/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madinata <madinata@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 22:21:37 by madinata          #+#    #+#             */
/*   Updated: 2026/07/31 17:23:18 by madinata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	result = malloc(i + 1);
	if (!result)
		return (0);
	i = 0;
	while (*s != '\0')
		result[i++] = *s++;
	result[i] = '\0';
	return (result);
}

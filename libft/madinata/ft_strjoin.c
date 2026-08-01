/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madinata <madinata@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 17:05:45 by madinata          #+#    #+#             */
/*   Updated: 2026/07/31 16:50:54 by madinata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	char	*result;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	result = malloc(size1 + size2 + 1);
	if (!result)
		return (0);
	ft_strlcpy(result, s1, size1 + 1);
	ft_strlcat(result, s2, size1 + size2 + 1);
	return (result);
}

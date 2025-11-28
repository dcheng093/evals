/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:46:17 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/18 11:46:55 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (char) c;
	i = ft_strlen(s);
	if (ch == '\0')
		return ((char *) &s[i]);
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}

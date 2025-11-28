/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:08:26 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/18 12:49:28 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESC :	The strchr() function returns a pointer to the first occurrence of
//			the character c in the string s.
// RETURN :	The strchr() and strrchr() functions return a pointer to the
//  		matched character or NULL if the character is not found.  The
//			terminating null byte is considered part of the string, so that if
//			c is specified as '\0', these functions return a pointer to the
//			terminator.

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	ch;

	ch = (char) c;
	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *) &str[i]);
		i++;
	}
	if (ch == '\0')
		return ((char *) &str[i]);
	return (NULL);
}

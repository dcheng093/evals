/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:46:22 by stee              #+#    #+#             */
/*   Updated: 2025/10/17 10:53:25 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	i = ft_strlen(s);
	ch = (unsigned char) c;
	if (ch == '\0')
		return ((char *) &s[i]);
	i--;
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}

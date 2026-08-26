/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jia-liew <jia-liew@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:50:45 by jia-liew          #+#    #+#             */
/*   Updated: 2026/07/29 15:50:46 by jia-liew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*sf;
	unsigned char	*ss;
	size_t			i;

	sf = (unsigned char *)s1;
	ss = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (sf[i] == ss[i]) && sf[i] && ss[i])
		i++;
	if (i == n)
		return (0);
	return (sf[i] - ss[i]);
}

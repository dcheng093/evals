/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madinata <madinata@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 18:07:30 by madinata          #+#    #+#             */
/*   Updated: 2026/07/27 18:10:27 by madinata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = 0;
	while (*s != '\0')
	{
		if (*s == c)
			result = (char *)s;
		s++;
	}
	if (*s == c)
		result = (char *)s;
	return (result);
}

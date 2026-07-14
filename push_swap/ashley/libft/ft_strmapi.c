/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:29:44 by asyeo             #+#    #+#             */
/*   Updated: 2026/07/14 15:29:44 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// #include <stdio.h>

// char	ft_upper_wrapper(unsigned int i, char c)
// {
// 	(void)i;
// 	return (ft_toupper(c));
// }

// int	main(void)
// {
// 	char	*str = "hello";
// 	char	*result = ft_strmapi(str, ft_upper_wrapper);
// 	printf("%s -> %s\n", str, result);
// 	free (result);
// }

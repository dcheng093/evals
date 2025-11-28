/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:13:53 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/09 15:38:13 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_string;

	new_string = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (i != ft_strlen(s))
	{
		new_string[i] = (f)(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
/*char *f(unsigned int i, char c)
{
	cha
	while (
	char = -32

int	main()
{
	int	i;
	char	c;
	char	*s1 = "Hello World";
	i = 0;
	c = -32;
}*/

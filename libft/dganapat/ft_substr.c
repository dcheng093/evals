/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:04:55 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/13 17:19:00 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s + start);
	s1 = malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (NULL);
	i = 0;
	while (s[start] && len > i)
	{
		s1[i] = s[start];
		i++;
		start++;
	}
	s1[i] = '\0';
	return (s1);
}
/*int			main()
{
int			start;
size_t		len;

start = 6;
len  = 5;
char	*s = "Hello World";

printf("%s\n" , ft_substr(s, start, len));

return (0);

}*/
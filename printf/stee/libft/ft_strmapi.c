/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:13:59 by stee              #+#    #+#             */
/*   Updated: 2025/10/21 16:15:58 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	str = ft_strdup(s);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
/*
char to_upper(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

#include <stdio.h>
int main()
{
    char *input = "this is a Test";
    char *result = ft_strmapi(input, to_upper);
    printf("Input:  %s\n", input);
    printf("Output: %s\n", result);
    free(result);
    return 0;
}*/

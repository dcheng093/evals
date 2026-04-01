/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:44:39 by stee              #+#    #+#             */
/*   Updated: 2025/10/17 13:46:01 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*dup;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	dup = (char *) malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
#include <stdio.h>
int main(void)
{
    const char *original = "This is Test";
    char *copy;

    copy = ft_strdup(original);
    if (copy)
    {
        printf("Duplicated string: \"%s\"\n", copy);
        free(copy);
    }
    else
        printf("Memory allocation failed.\n");
    return 0;
}*/

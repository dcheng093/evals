/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:52:44 by stee              #+#    #+#             */
/*   Updated: 2025/10/21 16:43:29 by stee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	size_t		sub;
	size_t		i;
	size_t		j;
	char		*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	i = 0;
	j = len - 1;
	while (s1[i] != '\0' && ft_in_set(s1[i], set))
		i++;
	while (j > i && ft_in_set(s1[j], set))
		j--;
	sub = (j - i) + 1;
	str = (char *) malloc(sizeof(char) * (sub + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1 + i, sub + 1);
	return (str);
}
/*
#include <stdio.h>
int main(void)
{
    char *result;

    result = ft_strtrim("   Hello, World!   ", " ");
    printf("Trimmed: '%s'\n", result);
    free(result);

    result = ft_strtrim("xxhixxtestKL tssxxx dkthkc xxxx", "x");
    printf("Trimmed: '%s'\n", result);
    free(result);

    result = ft_strtrim("ababaaathis is a testbbaaabbad", "ab");
    printf("Trimmed: '%s'\n", result);
    free(result);

    result = ft_strtrim("Test", "xyz");
    printf("Trimmed: '%s'\n", result);
    free(result);

    result = ft_strtrim("aaaa", "a");
    printf("Trimmed: '%s'\n", result);
    free(result);

    return 0;
}*/

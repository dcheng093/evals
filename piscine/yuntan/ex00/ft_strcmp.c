/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:28:57 by yuntan            #+#    #+#             */
/*   Updated: 2025/08/21 13:03:38 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	diff;

	i = 0;
	diff = s1[i] - s2[i];
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		diff = s1[i] - s2[i];
		if (diff == 0)
			i++;
		else
			return (diff);
	}
	return (s1[i] - s2[i]);
}

/*#include <stdio.h>

int main(void)
{
    printf("Compare(\"cat\", \"cat\")   = %d\n", ft_strcmp("cat", "cat"));
    printf("Compare(\"cat\", \"cater\") = %d\n", ft_strcmp("cat", "cater"));
    printf("Compare(\"cater\", \"cat\") = %d\n", ft_strcmp("cater", "cat"));
    printf("Compare(\"dog\", \"cat\")   = %d\n", ft_strcmp("dog", "cat"));
    printf("Compare(\"abc\", \"abd\")   = %d\n", ft_strcmp("abc", "abd"));
    printf("Compare(\"\", \"\")         = %d\n", ft_strcmp("", ""));
    printf("Compare(\"\", \"hello\")    = %d\n", ft_strcmp("", "hello"));
    printf("Compare(\"hello\", \"\")    = %d\n", ft_strcmp("hello", ""));
    return (0);
}*/

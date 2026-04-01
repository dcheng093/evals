/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:00:59 by yuntan            #+#    #+#             */
/*   Updated: 2025/08/21 13:03:30 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != 0 && s2[i] != 0 && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
    char *str1 = "abcdef";
    char *str2 = "abcdef";
    char *str3 = "abcdeg";
    char *str4 = "abcd";
    char *str5 = "";
    unsigned int n;

    // 1. Exact match
    n = 6;
    printf("ft_strncmp: %d, strncmp: %d\n", ft_strncmp(str1, str2, n), 
		    strncmp(str1, str2, n));

    // 2. First difference at last character
    n = 6;
    printf("ft_strncmp: %d, strncmp: %d\n", ft_strncmp(str1, str3, n), 
		    strncmp(str1, str3, n));

    // 3. n smaller than first difference
    n = 3;
    printf("ft_strncmp: %d, strncmp: %d\n", ft_strncmp(str1, str3, n), 
		    strncmp(str1, str3, n));

    // 4. One string shorter
    n = 6;
    printf("ft_strncmp: %d, strncmp: %d\n", ft_strncmp(str1, str4, n), 
		    strncmp(str1, str4, n));

    // 5. Empty strings
    n = 3;
    printf("ft_strncmp: %d, strncmp: %d\n", ft_strncmp(str5, str4, n), 
		    strncmp(str5, str4, n));
    printf("ft_strncmp: %d, strncmp: %d\n", ft_strncmp(str5, str5, n), 
		    strncmp(str5, str5, n));

    // 6. n = 0
    n = 0;
    printf("ft_strncmp: %d, strncmp: %d\n", ft_strncmp(str1, str3, n), 
		    strncmp(str1, str3, n));

    return 0;
}*/

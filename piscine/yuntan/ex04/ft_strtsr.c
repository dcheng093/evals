/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtsr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:46:14 by yuntan            #+#    #+#             */
/*   Updated: 2025/08/21 13:04:04 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (*to_find == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (str[i + j] != '\0' && str[i + j] == to_find[j])
			{
				j++;
				if (to_find[j] == '\0')
					return (&str[i]);
			}
		}
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int main(void)
{
    char str[] = "i yoa you them";
    char to_find1[] = "you";
    char to_find2[] = "yoa";
    char to_find3[] = "them";
    char to_find4[] = "cat";
    char to_find5[] = "";

    printf("Search '%s' in '%s' -> %s\n", to_find1, str, ft_strstr(str, 
    to_find1));
    printf("Search '%s' in '%s' -> %s\n", to_find2, str, ft_strstr(str, 
    to_find2));
    printf("Search '%s' in '%s' -> %s\n", to_find3, str, ft_strstr(str, 
    to_find3));
    printf("Search '%s' in '%s' -> %s\n", to_find4, str, ft_strstr(str, 
    to_find4));
    printf("Search '%s' in '%s' -> %s\n", to_find5, str, ft_strstr(str, 
    to_find5));

    return (0);
}*/

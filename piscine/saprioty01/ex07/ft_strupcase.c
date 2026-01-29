/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:05:33 by dcheng            #+#    #+#             */
/*   Updated: 2025/08/19 17:22:38 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}

int	main(void)
{
	char	str1[] = "hello";
	char	str2[] = "Hello";
	char	str3[] = "abc123";
	char	str4[] = "UPPER";

	printf("BEFORE : %s\n", str1);
	printf("BEFORE : %s\n", str2);
	printf("BEFORE : %s\n", str3);
	printf("BEFORE : %s\n", str4);
	printf("\n");
	printf("AFTER : %s\n", ft_strupcase(str1));
	printf("AFTER : %s\n", ft_strupcase(str2));
	printf("AFTER : %s\n", ft_strupcase(str3));
	printf("AFTER : %s\n", ft_strupcase(str4));
}

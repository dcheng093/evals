/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:47:04 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/14 16:30:57 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n)
	{
		if (*s1 != *s2)
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
		s1++;
		s2++;
		n--;
	}
	return ((0));
}
/*int		main()
{
	size_t		n;
	//char	*s1 = "Hello";
	//char	*s2 = "HellO/0 WorlD";

	n = 9223372036854775807;
	//printf("     My Function : %d\n" , ft_strncmp(s1, s2, n));
    printf("     My Function : %d\n" ,   ft_strncmp("test\200", "test\0", n));
	printf("Orginal Function : %d\n" , strncmp("test\200", "test\0", n));
	//printf("Orginal Function : %zu\n" ,  n);
	//printf("%u\n", ((unsigned int)-1));

	return (0);
}*/
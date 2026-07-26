/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:41:10 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/21 13:41:12 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (char) c;
	i = ft_strlen(s);
	if (ch == '\0')
		return ((char *) &s[i]);
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}

// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	if (argc != 3)
// 	{
// 		printf("Do it like: %s <string> <char>\n", argv[0]);
// 		return (1);
// 	}
// 	char c = argv[2][0];
// 	char *res = ft_strrchr(argv[1], c);
// 	if (res)
// 	{
// 		printf("Searching for '%c' in \"%s\"\n", c, argv[1]);
// 		printf("Result pointer: %p\n", (void *)res);
// 		printf("Found at index: %ld\n", res - argv[1]);
// 		printf("Substring from there: \"%s\"\n", res);
// 	}
// 	else
// 		printf("'%c' not found in \"%s\"\n", c, argv[1]);
// 	return (0);
// }

/*	%p is used to display the memory address stored in a pointer variable.
	The output is usually presented in hexadecimal format, prefixed w/ 0x.
	The corresponding argument to printf() must be a void * pointer. 
	If you are printing the address of a variable of a different type, 
	it is good practice to explicitly cast it to (void *) 
	to avoid potential warnings or undefined behavior, 
	esp in older C standards / when dealing w/ functions like printf().
*/

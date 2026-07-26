/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:40:45 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/21 13:40:51 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	DESC:	Allocates (with malloc(3)) and returns a copy of
			’s1’ with the characters specified in ’set’ removed
			from the beginning and the end of the string.
	RETURN:	The trimmed string.
			NULL if the allocation fails.
	PARAMS;	s1: The string to be trimmed.
			set: The reference set of characters to trim.
*/

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - start;
	return (ft_substr(s1, start, len));
}

// #include <stdio.h>

// int main(int argc, char **argv)
// {
// 	if (argc != 3)
// 	{
// 		printf("Usage: %s <string> <set>\n", argv[0]);
// 		return (1);
// 	}
// 	char *result = ft_strtrim(argv[1], argv[2]);
// 	if (!result)
// 	{
// 		printf("ft_strtrim returned NULL\n");
// 		return (1);
// 	}
// 	printf("Original: \"%s\"\n", argv[1]);
// 	printf("Set		: \"%s\"\n", argv[2]);
// 	printf("Trimmed	: \"%s\"\n", result);
// 	free(result);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:02:37 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/11 12:48:56 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ph;

	ph = NULL;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	else
	{
		i = start;
		while ((start + len) > ft_strlen(s))
			len--;
		ph = (char *)malloc((len + 1) * sizeof(char));
		if (!ph)
			return (NULL);
		while (s[i] && i - start < len)
		{
			ph[i - start] = s[i];
			i++;
		}
		ph[i - start] = '\0';
		return (ph);
	}
}
/* 
int main(void)
{
	const char *ft_substr_string = "lorem ipsum dolor sit amet";
	int ft_substr_start[] = {0, 7, 50};
	int ft_substr_len[] = {10, 23, 64, 0};

	printf("========================================\n");
	printf("ft_substr\n");
	printf("========================================\n");
	printf("String: %s\n", ft_substr_string);
	printf("Start: %d\n", ft_substr_start[0]);
	printf("Len: %d\n\n", ft_substr_len[0]);

	printf("New String: %s\n", ft_substr(ft_substr_string, ft_substr_start[0], 
ft_substr_len[0]));
	printf("--------------------\n");

	printf("String: %s\n", ft_substr_string);
	printf("Start: %d\n", 7);
	printf("Len: %d\n\n", 10);

	printf("New String: %s\n", ft_substr(ft_substr_string, 7, 10));
	printf("--------------------\n");

	printf("String: %s\n", ft_substr_string);
	printf("Start: %d\n", ft_substr_start[2]);
	printf("Len: %d\n\n", ft_substr_len[2]);

	printf("New String: %s\n", ft_substr(ft_substr_string, ft_substr_start[2], 
ft_substr_len[2]));
	printf("--------------------\n");

	printf("String: %s\n", ft_substr_string);
	printf("Start: %d\n", ft_substr_start[0]);
	printf("Len: %d\n\n", ft_substr_len[3]);

	printf("New String: %s\n", ft_substr(ft_substr_string, ft_substr_start[0], 
ft_substr_len[3]));
	printf("--------------------\n");

	printf("String: %s\n", ft_substr_string);
	printf("Start: %d\n", 55);
	printf("Len: %d\n\n", ft_substr_len[0]);

	printf("New String: %s\n", ft_substr(ft_substr_string, 55, 
ft_substr_len[0]));
	printf("--------------------\n");
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:32:31 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/11 09:35:16 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*var;

	i = 0;
	var = (unsigned char *)s;
	while (i < n)
	{
		if (var[i] == (unsigned char)c)
			return ((void *)&var[i]);
		else
		{
			i++;
		}
	}
	return (0);
}

/* void print_int_array(int *array, size_t n)
{
	for (size_t i = 0; i < n/4; i++)
        printf("%d ", array[i]);
	printf("\n");
}

int main(void)
{
	char *ft_memchr_string = "Fleshling youth, teach me to 
	communicate in trash talk.";
	int ft_memchr_int[] = {1,0,2,9,3,9,3,6,9,5,2,5,9,3,7,0,3};
	int ft_memchr_char[] = {(int)'\0', (int)'@', (int)'t', 6};

	printf("========================================\n");
	printf("ft_memchr\n");
	printf("========================================\n");
	printf("String: %s\n", ft_memchr_string);
	printf("Char: '%c'\n\n", ft_memchr_char[0]);
	printf("Original: %s\n", (char *)memchr(ft_memchr_string, 
ft_memchr_char[0], 30));
	printf("Recreation: %s\n", (char *)ft_memchr(ft_memchr_string, 
ft_memchr_char[0], 30));
	printf("--------------------\n");

	printf("String: %s\n", ft_memchr_string);
	printf("Char: '%c'\n\n", ft_memchr_char[1]);
	printf("Original: %s\n", (char *)memchr(ft_memchr_string, 
ft_memchr_char[1], 30));
	printf("Recreation: %s\n", (char *)ft_memchr(ft_memchr_string, 
ft_memchr_char[1], 30));
	printf("--------------------\n");

	printf("String: %s\n", ft_memchr_string);
	printf("Char: '%c'\n\n", ft_memchr_char[2]);
	printf("Original: %s\n", (char *)memchr(ft_memchr_string, 
ft_memchr_char[2], 30));
	printf("Recreation: %s\n", (char *)ft_memchr(ft_memchr_string, 
ft_memchr_char[2], 30));
	printf("--------------------\n");

	printf("String: ");
	print_int_array(ft_memchr_int, sizeof(ft_memchr_int));
	printf("Num: %d\n\n", ft_memchr_char[3]);
	printf("Original: ");
	print_int_array((int *)memchr(ft_memchr_int, ft_memchr_char[3], 10), 10);
	printf("Recreation: ");
	print_int_array((int *)ft_memchr(ft_memchr_int, ft_memchr_char[3],10),10);
	printf("--------------------\n");
} */
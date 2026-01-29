/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:00:15 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/11 09:53:49 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ph;

	ph = NULL;
	if (nmemb == 0 || size == 0 || nmemb > LONG_MAX / size)
	{
		return (ph);
	}
	else
	{
		ph = (unsigned char *)malloc(nmemb * size);
		if (!ph)
			return (NULL);
		ft_bzero(ph, nmemb * size);
		return (ph);
	}
}

// void print_int_array(int *array, size_t n)
// {
// 	for (size_t i = 0; i < n; i++)
//         printf("%d ", array[i]);
// 	printf("\n");
// }

// int	main(void)
// {
// 	char *ft_calloc_var1;
// 	int *ft_calloc_var2 = NULL;
// 	size_t size[] = {10, 0, -1};

// 	printf("========================================\n");
// 	printf("ft_calloc\n");
// 	printf("========================================\n");
// 	ft_calloc_var1 = (char *)calloc(size[0], sizeof(char));
// 	printf("Original: %s\n", ft_calloc_var1);
// 	ft_calloc_var1 = (char *)ft_calloc(size[0], sizeof(char));
// 	printf("Recreation: %s\n", ft_calloc_var1);
// 	printf("--------------------\n");

// 	ft_calloc_var1 = (char *)calloc(size[1], sizeof(char));
// 	printf("Original: %s\n", ft_calloc_var1);
// 	ft_calloc_var1 = (char *)ft_calloc(size[1], sizeof(char));
// 	printf("Recreation: %s\n", ft_calloc_var1);
// 	printf("--------------------\n");

// 	ft_calloc_var1 = (char *)calloc(size[2], sizeof(char));
// 	printf("Original: %s\n", ft_calloc_var1);
// 	ft_calloc_var1 = (char *)ft_calloc(size[2], sizeof(char));
// 	printf("Recreation: %s\n", ft_calloc_var1);
// 	printf("--------------------\n");

// 	ft_calloc_var2 = (int *)calloc(size[0], sizeof(int));
// 	printf("Original: ");
// 	print_int_array(ft_calloc_var2, sizeof(ft_calloc_var2));
// 	ft_calloc_var2 = (int *)ft_calloc(size[0], sizeof(int));
// 	printf("Recreation: ");
// 	print_int_array(ft_calloc_var2, sizeof(ft_calloc_var2));
// 	printf("--------------------\n");
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 08:57:03 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/05 16:06:09 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*var1;
	unsigned char	*var2;

	if (n == 0)
		return (dest);
	var1 = (unsigned char *)dest;
	var2 = (unsigned char *)src;
	i = 0;
	i = 0;
	while (i < n)
	{
		var1[i] = var2[i];
		i++;
	}
	return (var1);
}

/* static void print_int_array(int *array)
{
	for (size_t i = 0; i < 10; i++)
        printf("%d ", array[i]);
	printf("\n");
}

int main(void)
{
	char ft_memcpy_var11[] = "Fleshling youth, teach me to 
	communicate in trash talk.";
	char ft_memcpy_var12[] = "I hate you always";
	char ft_memcpy_var21[] = "Fleshling youth, teach me to 
	communicate in trash talk.";
	char ft_memcpy_var22[] = "I hate you always";
	int ft_memcpy_var33[] = {1,2,3,2,4,1,8,7,2,6,4};
	int ft_memcpy_var34[] = {42,42,42,42,42,42,42,42,42,42,42};
	int ft_memcpy_var43[] = {1,2,3,2,4,1,8,7,2,6,4};
	int ft_memcpy_var44[] = {42,42,42,42,42,42,42,42,42,42,42};

	char ft_memcpy_var51[] = "0123456789";
	char ft_memcpy_var52[] = "0123456789";
	size_t ft_memcpy_size = 0;

	printf("========================================\n");
	printf("ft_memcpy\n");
	printf("========================================\n");
	printf("Variable: %s\n", ft_memcpy_var11);
	printf("Replace: %s\n", ft_memcpy_var12);
	printf("Size: '%zu'\n\n", ft_memcpy_size);
	// HERE
	memcpy(ft_memcpy_var11 + 30, ft_memcpy_var12, ft_memcpy_size);
	printf("Original: %s\n", ft_memcpy_var11);

	ft_memcpy(ft_memcpy_var21 + 30, ft_memcpy_var22, ft_memcpy_size);
	printf("Recreation: %s\n", ft_memcpy_var21);
	printf("--------------------\n");

	printf("Variable: ");
	print_int_array(ft_memcpy_var33);
	printf("Replace: ");
	print_int_array(ft_memcpy_var34);
	printf("Size: '%zu'\n\n", ft_memcpy_size);
	// HERE
	memcpy(ft_memcpy_var33 + 5, ft_memcpy_var34,ft_memcpy_size*(sizeof(int)));
	printf("Original: ");
	print_int_array(ft_memcpy_var33);

	ft_memcpy(ft_memcpy_var43+5,ft_memcpy_var44,ft_memcpy_size*(sizeof(int)));
	printf("Recreation: ");
	print_int_array(ft_memcpy_var43);
	printf("--------------------\n");

	printf("Variable: %s\n", ft_memcpy_var51 + 5);
	printf("Replace: %s\n", ft_memcpy_var51);
	printf("Size: '%zu'\n\n", ft_memcpy_size);
	// // HERE
	memcpy(ft_memcpy_var51 + 5, ft_memcpy_var51, ft_memcpy_size);
	printf("  Original: %s\n", ft_memcpy_var51);

	ft_memcpy(ft_memcpy_var52 + 5, ft_memcpy_var52, ft_memcpy_size);
	printf("Recreation: %s\n", ft_memcpy_var52);
	printf("--------------------\n");
} */
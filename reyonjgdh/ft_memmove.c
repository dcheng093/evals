/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:03:41 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/06 09:47:58 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*var1;
	unsigned char	*var2;

	if (n == 0)
		return (dest);
	var1 = (unsigned char *)dest;
	var2 = (unsigned char *)src;
	if (dest > src)
	{
		i = n;
		if (ft_strlen(dest) < n)
			var1[n] = '\0';
		while (i-- > 0)
			var1[i] = var2[i];
	}
	else if (dest < src)
	{
		i = 0;
		while (n--)
			*var1++ = *var2++;
	}
	return (dest);
}

/* 
static void print_int_array(int *array)
{
	for (size_t i = 0; i < 10; i++)
        printf("%d ", array[i]);
	printf("\n");
}

int main(void)
{
	char ft_memmove_var11[] = "Fleshling youth, teach me to 
	communicate in trash talk.";
	char ft_memmove_var12[] = "I hate you always";
	char ft_memmove_var21[] = "Fleshling youth, teach me to 
	communicate in trash talk.";
	char ft_memmove_var22[] = "I hate you always";
	int ft_memmove_var33[] = {1,2,3,2,4,1,8,7,2,6,4};
	int ft_memmove_var34[] = {42,42,42,42,42,42,42,42,42,42,42};
	int ft_memmove_var43[] = {1,2,3,2,4,1,8,7,2,6,4};
	int ft_memmove_var44[] = {42,42,42,42,42,42,42,42,42,42,42};

	char ft_memmove_var51[] = "0123456789";
	char ft_memmove_var52[] = "0123456789";

	char ft_memmove_var61[] = "lorem ipsum dolor sit amet";
	char ft_memmove_var62[] = "lorem ipsum dolor sit amet";
	size_t ft_memmove_size = 8;

	printf("========================================\n");
	printf("ft_memmove\n");
	printf("========================================\n");
	printf("Variable: %s\n", ft_memmove_var11);
	printf("Replace: %s\n", ft_memmove_var12);
	printf("Size: '%zu'\n\n", ft_memmove_size);
	// HERE
	memmove(ft_memmove_var11 + 30, ft_memmove_var12, ft_memmove_size);
	printf("Original: %s\n", ft_memmove_var11);

	ft_memmove(ft_memmove_var21 + 30, ft_memmove_var22, ft_memmove_size);
	printf("Recreation: %s\n", ft_memmove_var21);
	printf("--------------------\n");

	printf("Variable: ");
	print_int_array(ft_memmove_var33);
	printf("Replace: ");
	print_int_array(ft_memmove_var34);
	printf("Size: '%zu'\n\n", ft_memmove_size);
	// HERE
	memmove(ft_memmove_var33+5,ft_memmove_var34,ft_memmove_size*(sizeof(int)));
	printf("Original: ");
	print_int_array(ft_memmove_var33);

ft_memmove(ft_memmove_var43+5,ft_memmove_var44,ft_memmove_size*(sizeof(int)));
	printf("Recreation: ");
	print_int_array(ft_memmove_var43);
	printf("--------------------\n");

	printf("Variable: %s\n", ft_memmove_var51 + 5);
	printf("Replace: %s\n", ft_memmove_var51);
	printf("Size: '%zu'\n\n", ft_memmove_size);
	// // HERE
	memmove(ft_memmove_var51 + 5, ft_memmove_var51, ft_memmove_size);
	printf("Original: %s\n", ft_memmove_var51);

	ft_memmove(ft_memmove_var52 + 5, ft_memmove_var52, ft_memmove_size);
	printf("Recreation: %s\n", ft_memmove_var52);
	printf("--------------------\n");

	printf("Variable: %s\n", ft_memmove_var61);
	printf("Replace: %s\n", ft_memmove_var61 + 1);
	printf("Size: '%zu'\n\n", ft_memmove_size);
	// // HERE
	memmove(ft_memmove_var61, ft_memmove_var61 + 1, ft_memmove_size);
	printf("Original: %s\n", ft_memmove_var61);

	ft_memmove(ft_memmove_var62, ft_memmove_var62 + 1, ft_memmove_size);
	printf("Recreation: %s\n", ft_memmove_var62);
	printf("--------------------\n");
} */
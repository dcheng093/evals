/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 08:37:05 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/11 14:14:33 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	if (n == 0)
		return (s);
	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (ptr);
}

/*static void print_int_array(int *array)
{
	for (size_t i = 0; i < 15; i++)
        printf("%d ", array[i]);
	printf("\n");
}

int main(void)
{
	char ft_memset_var1[] = "Fleshling youth, teach me to communicate in trash talk.";
	char ft_memset_var2[] = "Fleshling youth, teach me to communicate in trash talk.";
	int ft_memset_var3[] = {1,2,3,4,7,6,5,4,3,2,2,3,4,5,6};
	int ft_memset_var4[] = {1,2,3,4,7,6,5,4,3,2,2,3,4,5,6};
	int ft_memset_char[] = {(int)'@', 42};
	size_t ft_memset_size = 8;

	printf("========================================\n");
	printf("ft_memset\n");
	printf("========================================\n");
	printf("Variable: %s\n", ft_memset_var1);
	printf("Replace: '%c'\n", ft_memset_char[0]);
	printf("Size: '%zu'\n\n", ft_memset_size);
	memset(ft_memset_var1 + 10, ft_memset_char[0], ft_memset_size);
	printf("Original: %s\n", ft_memset_var1);
	ft_memset(ft_memset_var2 + 10, ft_memset_char[0],ft_memset_size);
	printf("Recreation: %s\n", ft_memset_var2);
	printf("--------------------\n");

	printf("Variable: ");
	print_int_array(ft_memset_var3);
	printf("Replace: '%c'\n", ft_memset_char[0]);
	printf("Size: '%zu'\n\n", ft_memset_size);
	memset(ft_memset_var3 + 5, ft_memset_char[1], ft_memset_size*sizeof(int));
	printf("Original: ");
	print_int_array(ft_memset_var3);
 	ft_memset(ft_memset_var4+5,ft_memset_char[1],ft_memset_size*sizeof(int));
	printf("Recreation: ");
	print_int_array(ft_memset_var4);
	printf("--------------------\n");
}*/
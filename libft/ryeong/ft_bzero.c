/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 08:42:17 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/05 16:05:31 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

/* int main(void)
{
	char ft_bzero_var1[] = "Fleshling youth, teach me to 
	communicate in trash talk.";
	char ft_bzero_var2[] = "Fleshling youth, teach me to 
	communicate in trash talk.";
	int ft_bzero_var3[] = {1,2,3,2,4,1,8,7,2,6,4};
	int ft_bzero_var4[] = {1,2,3,2,4,1,8,7,2,6,4};
	size_t ft_bzero_size = 8;

	printf("========================================\n");
	printf("ft_bzero\n");
	printf("========================================\n");
	printf("Variable: %s\n", ft_bzero_var1);
	printf("Size: '%zu'\n\n", ft_bzero_size);
	bzero(ft_bzero_var1 + 10, ft_bzero_size);
	printf("Original: %s\n", ft_bzero_var1);
	ft_bzero(ft_bzero_var2 + 10,ft_bzero_size);
	printf("Recreation: %s\n", ft_bzero_var2);
	printf("--------------------\n");

	printf("Variable: ");
	for (size_t i = 0; i < 11; i++)
    {
        printf("%d ", ft_bzero_var3[i]);
    }
	printf("\n");
	printf("Size: '%zu'\n\n", ft_bzero_size);
	bzero(ft_bzero_var3, ft_bzero_size*(sizeof(int)));
	printf("Original: ");
	for (size_t i = 0; i < 11; i++)
    {
        printf("%d ", ft_bzero_var3[i]);
    }
	printf("\n");
	ft_bzero(ft_bzero_var4, ft_bzero_size*(sizeof(int)));
	printf("Recreation: ");
	for (size_t i = 0; i < 11; i++)
    {
        printf("%d ", ft_bzero_var4[i]);
    }
	printf("\n");
	printf("--------------------\n");
} */
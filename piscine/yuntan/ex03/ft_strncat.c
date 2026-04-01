/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:27:02 by yuntan            #+#    #+#             */
/*   Updated: 2025/08/21 13:03:11 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb);

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	dest_len;

	i = 0;
	dest_len = 0;
	while (dest[dest_len] != 0)
		dest_len++;
	while (src[i] != '\0' && i < nb)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

/*#include <stdio.h>

char    *ft_strncat(char *dest, char *src, unsigned int nb);

int main(void)
{
    char dest[50] = "Hello";   // Make sure dest has enough space
    char src[] = " World!";

    printf("Before: %s\n", dest);
    ft_strncat(dest, src, 3);
    printf("After strncat with nb=3: %s\n", dest);
    return 0;
}*/

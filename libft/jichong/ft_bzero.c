/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichong <jichong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:59:54 by jichong           #+#    #+#             */
/*   Updated: 2025/10/25 11:51:13 by jichong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ps;

	ps = ((unsigned char *)s);
	while (n--)
		*ps++ = 0;
}
/*
int    main(void)
{
    char string[] = "abcdef";
    int i = 0;

    ft_bzero(string, 3);
    while (i < 6)
    {
        printf("%d ", string[i]);
        i++;
    }
    printf("\n");
}*/

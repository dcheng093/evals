/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichong <jichong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:59:08 by jichong           #+#    #+#             */
/*   Updated: 2025/10/25 11:17:20 by jichong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	*ps;

	ps = ((unsigned char *)s);
	i = 0;
	while (i < n)
		ps[i++] = ((unsigned char)c);
	return (s);
}
/*
int	main(void)
{
	char	string[]= "1111111111";
	int	numbers[] = {1, 2, 3, 4, 5};
	int	i = 0;

	ft_memset(string, '2', 3);
	printf("%s\n", string);
	ft_memset(numbers + 3, 0, sizeof(numbers));
	while (i < 5)
	{
		printf("%d ", numbers[i]);
		i++;
	}
	printf("\n");
}*/

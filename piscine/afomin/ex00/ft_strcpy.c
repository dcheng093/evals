/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:09:45 by afomin            #+#    #+#             */
/*   Updated: 2025/08/11 15:52:05 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int		i;
	char	*link;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	link = &dest[i];
	*link = '\0';
	return (dest);
}

int	main(void)
{
	char	array1[3];
	char	array2[3];

	array1[0] = 'A';
	array1[1] = 'n';
	array1[2] = 'i';
	ft_strcpy(array2, array1);
	printf("%s", array2);
}

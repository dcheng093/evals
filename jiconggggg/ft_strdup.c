/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichong <jichong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:30:34 by jichong           #+#    #+#             */
/*   Updated: 2025/11/01 14:38:24 by jichong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s);
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, (char *)s, len + 1);
	return (copy);
}
/*
int	main(void)
{
	char	*original = "EREN";
	char	*duplicate = ft_strdup(original);

	printf("Original: %s\n", original);
	printf("Duplicate: %s\n", duplicate);

	free(duplicate);
	return (0);
}*/

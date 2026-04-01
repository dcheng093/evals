/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:36:26 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/11 18:28:39 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*new_string;
	size_t		str_len;

	str_len = ft_strlen(s) + 1;
	new_string = malloc(sizeof(char) * str_len);
	if (new_string == NULL)
		return (NULL);
	ft_strlcpy(new_string, s, str_len);
	return ((char *)(new_string));
}
/*int	main()
{
	char	*s1 = "Hello ";
	printf("Orginal function : %s\n" , strdup(s1));
	printf("My Function : %s\n" , ft_strdup(s1));
	free(new_string);

	return (0);
}*/

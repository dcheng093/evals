/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:25:43 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/10 07:11:43 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ph;
	unsigned int	i;

	i = 0;
	ph = NULL;
	ph = (char *)malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!ph)
		return (NULL);
	while (s[i])
	{
		ph[i] = f(i, s[i]);
		i++;
	}
	ph[i] = '\0';
	return (ph);
}

/* char    test(unsigned int i, char str)
{
	(void)i;
    return (str + 1);
}

int main(void)
{
	char ft_strmapi_string[] = "Fleshling youth, teach me to 
	communicate in trash talk.";
	char *ft_strmapi_string2 = ft_strmapi(ft_strmapi_string, test);

	printf("========================================\n");
	printf("ft_strmapi\n");
	printf("========================================\n");
	printf("String: %s\n", ft_strmapi_string);
	printf("New String: %s\n", ft_strmapi_string2);
	printf("--------------------\n");
	free(ft_strmapi_string2);
} */
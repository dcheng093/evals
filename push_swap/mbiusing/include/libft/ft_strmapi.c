/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiusing <mbiusing@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:41:48 by mbiusing          #+#    #+#             */
/*   Updated: 2025/11/22 16:46:31 by mbiusing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	DESC:	Applies the function f to each character of the
			string s, passing its index as the first argument
			and the character itself as the second. A new
			string is created (using malloc(3)) to collect the
			results from the successive applications of f.
	RETURN:	The string created from the successive applications
			of ’f’.
			Returns NULL if the allocation fails.
	PARAMS;	s: The string on which to iterate.
			f: The function to apply to each character.
*/

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			slen;
	char			*newstr;
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	slen = ft_strlen(s);
	newstr = (char *) malloc(sizeof(char) * (slen + 1));
	if (!newstr)
		return (NULL);
	while (s[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

/*
char    ft_plus1ascii(unsigned int i, char c)
{
    (void)i;
    if (c >= 0 && c <= 126)
        return c + 1;
    return c;
}

#include <stdio.h>
int main(int argc, char *argv[])
{
    char    *test1;

    if (argc != 2)
    {
        printf("Blud can u like.. just put 2 arguments only");
        return (1);
    }
    test1 = ft_strmapi(argv[1] ,ft_plus1ascii); 
    printf("%s", test1);
    free(test1);
    return (0);
}
*/

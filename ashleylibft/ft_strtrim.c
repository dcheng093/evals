/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:06:54 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/15 13:01:37 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION : Allocates with malloc. Returns a copy of 's1' with 'set'
    removed from the beginning and end of strings.
    
	RETURN VALUE : Trimmed copy of *s1; NULL if malloc fails.
*/

#include "libft.h"
//#include <stdio.h>

static int	isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (isset(s1[start], set) && s1[start] != '\0')
		start++;
	while (isset(s1[end - 1], set) && end > start)
		end--;
	return (ft_substr(s1, start, end - start));
}

/*
int	main(void)
{
	
}
*/

/*
static variables: retains value after multiple funct calls. initialized once,
remains undestroyed when value returns. lifetime of variable extends until 
end of program.
*/

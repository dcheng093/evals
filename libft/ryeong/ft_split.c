/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryeong <ryeong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:18:34 by ryeong            #+#    #+#             */
/*   Updated: 2025/11/07 12:37:18 by ryeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countword(char const *s, char c)
{
	int	inword;
	int	result;

	inword = 0;
	result = 0;
	while (*s)
	{
		if (*s == c)
		{
			inword = 0;
		}
		if (*s != c && inword == 0)
		{
			result++;
			inword = 1;
		}
		s++;
	}
	return (result);
}

static void	copystring(char *ph2, size_t *i, char **ph1, size_t *j)
{
	ph2[*i] = '\0';
	*i = 0;
	ph1[*j] = ft_strdup(ph2);
	(*j)++;
}

char	**ft_split(char const *s, char c)
{
	size_t	index[2];
	size_t	wordcount;
	char	**ph1;
	char	*ph2;

	wordcount = countword(s, c);
	ph2 = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	ph1 = (char **)malloc((wordcount + 1) * sizeof(char *));
	index[0] = 0;
	index[1] = 0;
	while (*s && index[1] < wordcount)
	{
		if (*s != c)
		{
			ph2[index[0]++] = *s;
			if (*(s + 1) == '\0')
				copystring(ph2, &index[0], ph1, &index[1]);
		}
		else if (*s == c && index[0] > 0)
			copystring(ph2, &index[0], ph1, &index[1]);
		s++;
	}
	ph1[index[1]] = NULL;
	free (ph2);
	return (ph1);
}

/* void printstrings(char **list)
{
	size_t i = 0;
	// while (list[i] && list[i][0])
	while (list[i] != NULL)
	{
		printf("%s||", list[i]);
		free(list[i]);
		i++;
	}
	free(list);
	printf("\n");
}
int main(void)
{
	const char *ft_split_string1 = "lorem ipsum dolor sit amet, 
	consectetur adipiscing elit. Sed non risus. Suspendisse";
	// char *ft_split_string2[] = {"meep", "meow", "bark"};
	char ft_split_char = ' ';
	char **ft_split_string2 = ft_split(ft_split_string1, ft_split_char);

	printf("========================================\n");
	printf("ft_split\n");
	printf("========================================\n");
	printf("String: %s\n", ft_split_string1);
	printf("Char: '%c'\n\n", ft_split_char);
	printf("New String: ");
	printstrings(ft_split_string2);
	
	// size_t i = 0;
	// while (ft_split_string2[i] != NULL)
	// {
	// 	free(ft_split_string2[i]);
	// 	i++;
	// }
	// free(ft_split_string2);
	printf("--------------------\n");
} */

/*  int main(void)
 {
	printf("%zu\n", countword("meep",' '));
	printf("%zu\n", countword(" meep",' '));
	printf("%zu\n", countword("meep ",' '));
	printf("%zu\n\n", countword(" meep ",' '));
	printf("%zu\n", countword("meep meep",' '));
	printf("%zu\n", countword(" meep meep",' '));
	printf("%zu\n", countword("meep meep ",' '));
	printf("%zu\n\n", countword(" meep meep ",' '));
	printf("%zu\n", countword("meep meep meep",' '));
	printf("%zu\n", countword(" meep meep meep",' '));
	printf("%zu\n", countword("meep meep meep ",' '));
	printf("%zu\n\n", countword(" meep meep meep ",' '));
	printf("%zu\n", countword("meep meep meep meep",' '));
	printf("%zu\n", countword(" meep meep meep meep",' '));
	printf("%zu\n", countword("meep meep meep meep ",' '));
	printf("%zu\n\n", countword(" meep meep meep meep ",' '));
	printf("%zu\n", countword("Fleshling youth, teach me to 
	communicate in trash talk.",' '));
 } */
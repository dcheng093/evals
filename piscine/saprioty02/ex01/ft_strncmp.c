/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 21:58:55 by saprioty          #+#    #+#             */
/*   Updated: 2025/08/21 15:09:11 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] && s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
/*
int main()
{
	char s1[] = "ABCD";
	char s2[] = "ABCE";

	int return_val = ft_strncmp(s1, s2, 4);
	
	if (return_val > 0)
		printf("%s is greater than %s\n", s1, s2);
	else if (return_val < 0)
		printf("%s is smaller than %s\n", s1, s2);
	else
		printf("%s is equal to %s\n", s1, s2);

	return 0;
}*/

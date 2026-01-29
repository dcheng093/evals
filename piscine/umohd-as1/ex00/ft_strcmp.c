/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:17:50 by umohd-as          #+#    #+#             */
/*   Updated: 2025/08/21 13:34:12 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

#include <stdio.h>
int	main(int argc, char *argv[]){
	if (argc != 3) 
		return(1);
	
	{
	int res = ft_strcmp(argv[1], argv[2]);
		if (res == 0)
			printf("str1 and str2 are equal");
		else if (res < 0)
			printf("str 1 less than str2. %d", res);
		else
			printf("str1 is more than str2. %d", res);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:49:32 by umohd-as          #+#    #+#             */
/*   Updated: 2025/08/21 13:35:56 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n > 0)
	{
		while (s1[i] == s2[i] && s1[i] && i < n - 1)
			i++;
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	else
		return (0);
}

#include <stdio.h>
#include <string.h>
int main(){
	char s1[]="hello";
	char s2[]="hdllo";
	printf("%d\n", strncmp(s1, s2, 2));
	printf("%d", ft_strncmp(s1, s2, 2));
}

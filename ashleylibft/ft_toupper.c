/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 08:25:06 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/14 15:32:49 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION : Function converts lowercase characters to uppercase.

	RETURN VALUE : Uppercase equivalent characters.
*/

#include "libft.h"
//#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*
int	main(void)
{
	char c = 'a';

	printf("Before: %c, After: %c", original, ft_toupper(c))
		return (0);
}
*/
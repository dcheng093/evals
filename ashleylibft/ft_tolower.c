/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyeo <asyeo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 08:25:03 by asyeo             #+#    #+#             */
/*   Updated: 2025/11/14 15:32:42 by asyeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION : Function converts uppercase characters to lowercase.

	RETURN VALUE : Lowercase equivalent characters.
*/

#include "libft.h"
//#include <stdio.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*
int	main(void)
{
	char c = 'A';

	printf("Before: %c, After: %c", original, ft_tolower(c))
		return (0);
}
*/
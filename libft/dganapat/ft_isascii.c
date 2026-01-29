/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 08:17:45 by dganapat          #+#    #+#             */
/*   Updated: 2025/10/27 11:57:56 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*#include <stdio.h>
int     main()
{
    char s1 = 'H';
    char s2 = 'û';

    printf("Yes : %d\n" , ft_isascii(s1));
    printf("No : %d\n" , ft_isascii(s2));

    return (0);
}*/

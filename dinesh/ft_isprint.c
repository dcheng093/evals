/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:00:58 by dganapat          #+#    #+#             */
/*   Updated: 2025/10/27 12:17:59 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*#include <stdio.h>
int     main()
{
    char s1 = 'H';
    char s2 = 'û';

    printf("Yes : %d\n" , ft_isprint(s1));
    printf("No : %d\n" , ft_isprint(s2));

    return (0);
}*/

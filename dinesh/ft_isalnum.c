/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:00:40 by dganapat          #+#    #+#             */
/*   Updated: 2025/11/09 14:09:28 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}
/*#include <stdio.h>
int     main()
{
    char s1 = 'H';
    char s2 = ' ';

    printf("Yes : %d\n" , ft_isalnum(s1));
    printf("No : %d\n" , ft_isalnum(s2));

    return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dganapat <dganapat@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 07:52:08 by dganapat          #+#    #+#             */
/*   Updated: 2025/10/27 10:30:30 by dganapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
/*#include <stdio.h>
int     main()
{
    char s1 = 'H';
    char s2 = '5';

    printf("Yes : %d\n" , ft_isalpha(s1));
    printf("No : %d\n" , ft_isalpha(s2));

    return (0);
}*/

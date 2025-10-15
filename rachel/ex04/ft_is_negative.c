=/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:57:25 by raqi              #+#    #+#             */
/*   Updated: 2025/08/07 16:52:16 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_is_negative(int n)
{
	char a ='N' ;
       	char b= 'P' ;
	if (n < 0)
		write (1, &a, 1);
	else
		write (1, &b, 1);
}

int main()
{
	ft_is_negative(-5); //prints N
	ft_is_negative(6); //prints P
	ft_is_negative(0); //prints P		    
	return 0;
}

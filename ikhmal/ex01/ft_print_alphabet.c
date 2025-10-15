/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-ab2 <mbin-ab2@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:31:29 by mbin-ab2          #+#    #+#             */
/*   Updated: 2025/08/07 19:35:20 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_print_alphabet(void);

void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while
		(c <= 'z'){
		write(1, &c, 1);
	c++ ;
}

}


int	main(void)
{
	ft_print_alphabet();
	return (0);
}

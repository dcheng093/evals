/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:29:43 by raqi              #+#    #+#             */
/*   Updated: 2025/08/07 16:42:33 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_alphabet(void)

{
	static char letter = 'a';

	if(letter > 'z')
		return;
	write (1, &letter, 1);
	letter++;
	ft_print_alphabet();
}

int main(void)
{
	ft_print_alphabet();
	return 0;
}



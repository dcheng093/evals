/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:23:36 by raqi              #+#    #+#             */
/*   Updated: 2025/08/07 16:45:24 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_reverse_alphabet(void)

{
	static char letter = 'z';

	if (letter < 'a')
		return;
	write(1, &letter, 1);
	letter--;
	ft_print_reverse_alphabet();
}

int main (void)
{
	ft_print_reverse_alphabet();
	return 0;
}

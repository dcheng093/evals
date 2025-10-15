1/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raqi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:59:31 by raqi              #+#    #+#             */
/*   Updated: 2025/08/07 16:49:26 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void ft_print_numbers(void)
{
	static char digit=0;
	if (digit>9)
		return;

	char c= digit + '0';
	write(1, &c,1);

	digit++;
	ft_print_numbers();
}

int main(void)
{
	ft_print_numbers();
	return 0;
}

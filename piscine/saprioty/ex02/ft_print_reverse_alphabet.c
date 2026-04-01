/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saprioty <saprioty@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:16:12 by saprioty          #+#    #+#             */
/*   Updated: 2025/08/07 17:12:15 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	alphabet;

	alphabet = 'z';
	while (alphabet >= 'a')
	{
		write(1, &alphabet, 1);
		alphabet--;
	}
}

int main()
{
	ft_print_reverse_alphabet();
}

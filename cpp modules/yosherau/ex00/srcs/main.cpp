/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:42:00 by yosherau          #+#    #+#             */
/*   Updated: 2026/01/23 13:26:59 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int	main(void)
{
	ClapTrap clap("BoiBoi");
	ClapTrap clip("Clip");

	for (int iter = 0; iter < 10; iter++)
		clap.attack("Bobby");
	ClapTrap babyBoy(clap);
	babyBoy.attack("BoiBoi");
	babyBoy = clip;
	clap.beRepaired(1);
	babyBoy.attack("Clip");
}
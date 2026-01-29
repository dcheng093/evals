/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:16:32 by yosherau          #+#    #+#             */
/*   Updated: 2026/01/23 14:30:34 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap():
	ClapTrap(100, 100, 30)
{
	std::cout << "FragTrap's default constructor has been called" << std::endl;
}

FragTrap::FragTrap(std::string name):
	ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap's paramaterized constructor has been called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &original):
	ClapTrap(original)
{
	std::cout << "FragTrap's Copy Constructor was called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &original)
{
	std::cout << "FragTraps's assignment operator was called" << std::endl;
	if (this != &original)
		ClapTrap::operator=(original);
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (!canAct())
		return ;
	std::cout << "FragTrap " << name << " requests for high fives 🙌" << std::endl;
}

bool	FragTrap::canAct(void) const
{
	if (hitPoints == 0)
	{
		std::cout << "FragTrap dah mati" << std::endl;
		return (false);
	}
	else if (energyPoints == 0)
	{
		std::cout << "ScavTrap is low on enerji" << std::endl;
		return (false);
	}
	return (true);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTraps's destructor has been called" << std::endl;
}
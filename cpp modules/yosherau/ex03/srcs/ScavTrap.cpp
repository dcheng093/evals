/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:20:00 by yosherau          #+#    #+#             */
/*   Updated: 2026/01/29 17:08:36 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap():
	ClapTrap(100, 50, 20)
{
	std::cout << "ScavTrap's default constructor has been called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &original):
	ClapTrap(original)
{
	std::cout << "ScavTrap's Copy Constructor was called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &original)
{
	std::cout << "ScavTrap's assignment operator was called" << std::endl;
	if (this != &original)
		ClapTrap::operator=(original);
	return (*this);
}

ScavTrap::ScavTrap(std::string name):
	ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap's parameterized constructor has been called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
		std::cout << "ScavTrap is already dieded :/" << std::endl;
	else if (energyPoints == 0)
		std::cout << "ScavTrap sudah pancit :/" << std::endl;
	else
	{
		std::cout << "ScavTrap ";
		std::cout << this->name;
		std::cout << " attacks ";
		std::cout << target;
		std::cout << ", by throwing a scab at it causing ";
		std::cout << this->attackDamage;
		std::cout << " points of damage!!!" << std::endl;
		this->energyPoints--;
	}
}

void	ScavTrap::GuardGate(void)
{
	std::cout << "ScavTrap ";
	std::cout << this->name;
	std::cout << " is now in Gate keeper mode" << std::endl;
}

bool	ScavTrap::canAct(void) const
{
	if (hitPoints == 0)
	{
		std::cout << "ScavTrap is already dieded :/" << std::endl;
		return (false);
	}
	else if (energyPoints == 0)
	{
		std::cout << "ScavTrap sudah pancut :/" << std::endl;
		return (false);
	}
	return (true);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap's destructor has been called" << std::endl;
}
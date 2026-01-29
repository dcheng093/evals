/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 13:34:12 by yosherau          #+#    #+#             */
/*   Updated: 2026/01/29 17:05:24 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap():
	ClapTrap(), FragTrap(), ScavTrap()
{
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap's default constructor was called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name)
{
	std::cout << "DiamondTrap's parameterized constructor was called" << std::endl;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &original):
	ClapTrap(original), FragTrap(original), ScavTrap(original)
{
	std::cout << "DiamondTrap's Copy Constructor was called" << std::endl;
	this->name = original.name;
	this->hitPoints = original.hitPoints;
	this->energyPoints = original.energyPoints;
	this->attackDamage = original.attackDamage;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &original)
{
	std::cout << "DiamondTrap's assignment operator was called" << std::endl;
	if (this != &original)
	{
		ClapTrap::operator=(original);
		this->name = original.name;
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " + this->name << std::endl;
	std::cout << "My ClapTrap name is " + ClapTrap::name << std::endl;
}

bool	DiamondTrap::canAct(void) const
{
	if (hitPoints == 0)
	{
		std::cout << "DiamondTrap has become a diamond 🥀" << std::endl;
		return (false);
	}
	else if (energyPoints == 0)
	{
		std::cout << "DiamondTrap is not feeling so diamond rn" << std::endl;
		return (false);
	}
	return (true);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap's destructor was called" << std::endl;
}
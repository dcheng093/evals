/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:10:09 by yosherau          #+#    #+#             */
/*   Updated: 2026/01/23 14:28:09 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(void):
	name("dflt_"),
	hitPoints(10),
	energyPoints(1),
	attackDamage(0)
{
	std::cout << "Default ClapTrap has spawned" << std::endl;
}

ClapTrap::ClapTrap(std::string name):
	name(name),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << " has spawned" << std::endl;
}

ClapTrap::ClapTrap(unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage):
	name("dflt_"),
	hitPoints(hitPoints),
	energyPoints(energyPoints),
	attackDamage(attackDamage)
{
	std::cout << "ClapTrap " << this->name << " has spawned" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage):
	name(name),
	hitPoints(hitPoints),
	energyPoints(energyPoints),
	attackDamage(attackDamage)
{
	std::cout << "ClapTrap " << this->name << " has spawned" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &original)
{
	this->name = original.name;
	this->hitPoints = original.hitPoints;
	this->energyPoints = original.energyPoints;
	this->attackDamage = original.attackDamage;
	std::cout << "ClapTrap's copy constructor was called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &original)
{
	std::cout << "ClapTrap's assignment operator was called" << std::endl;
	if (this != &original)
	{
		this->name = original.name;
		this->hitPoints = original.hitPoints;
		this->energyPoints = original.energyPoints;
		this->attackDamage = original.attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (canAct() == false)
		return ;
	std::cout << "ClapTrap ";
	std::cout << this->name;
	std::cout << " attacks ";
	std::cout << target;
	std::cout << ", causing ";
	std::cout << this->attackDamage;
	std::cout << " points of damage" << std::endl;
	this->energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap is already cooked :/" << std::endl;
		return ;
	}
	std::cout << this->name << " takes " << amount << " of damage!" << std::endl;
	this->hitPoints = (amount > this->hitPoints) ? 0 : hitPoints - amount;
	std::cout << "ClapTrap " + this->name + "'s new health is " << this->hitPoints << std::endl;	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (canAct() == false)
		return ;
	std::cout << "ClapTrap ";
	std::cout << this->name;
	std::cout << " heals itself for ";
	std::cout << amount;
	std::cout << " of hitpoints" << std::endl;
	this->hitPoints += amount;
	std::cout << "ClapTrap " + this->name + "'s new health is " << this->hitPoints << std::endl;
	this->energyPoints--;
}

bool	ClapTrap::canAct(void) const
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap is already cooked :/" << std::endl;
		return (false);
	}
	else if (energyPoints == 0)
	{
		std::cout << "ClapTrap does not have enough energy points to perform an action :/" << std::endl;
		return (false);
	}
	return (true);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap's destructor has been called" << std::endl;
}
#pragma once
#ifndef __HUMAN_B_HPP__
#define __HUMAN_B_HPP__

#include "Weapon.hpp"
#include <iostream>

class HumanB {
	public:
		void	setWeapon(Weapon &weapon);
		void	attack();

		HumanB(std::string name);

	private:
		Weapon	*_weapon;
		std::string	_name;
};


#endif
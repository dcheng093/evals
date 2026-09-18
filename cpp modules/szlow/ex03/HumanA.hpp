#pragma once
#ifndef __HUMAN_A_HPP__
#define __HUMAN_A_HPP__

#include "Weapon.hpp"
#include <iostream>

class HumanA {
	public:
		void	attack();

		HumanA(std::string name, Weapon &weapon);

	private:
		Weapon	&_weapon;
		std::string	_name;
};


#endif
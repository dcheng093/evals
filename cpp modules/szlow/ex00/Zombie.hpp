#pragma once
#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <string>
#include <iostream>

class Zombie {
	public:
		void	announce(void);

		Zombie(std::string name);
		~Zombie();

	private:
		std::string	name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
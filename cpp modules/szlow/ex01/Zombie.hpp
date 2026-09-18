#pragma once
#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <string>
#include <iostream>

class Zombie {
	public:
		void	announce(void);
		void	set_name(std::string name);

		Zombie();
		~Zombie();

	private:
		std::string	name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
#pragma once
#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <string>

class Weapon {
	public:
		const std::string	&getType() const;
		void	setType(std::string	type);

		Weapon(std::string type);

	private:
		std::string	_type;
};


#endif
#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	setType(type);
}

const std::string	&Weapon::getType() const
{
	return _type;
}

void	Weapon::setType(std::string	type)
{
	_type = type;
}
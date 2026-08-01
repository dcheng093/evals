/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:44:26 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/07/31 15:13:31 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

using std::cout;
using std::endl;

// CATEGORY:	Constructor / Copy Constructor / Deconstructor

AMateria::AMateria(string const &type) : _type(type)
{
	cout << "Constructing AMateria" << endl;
}

AMateria::AMateria(const AMateria& other)
{
	(void)other;
	cout << "You can't copy AMateria!" << endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	cout << "You can't copy assign AMateria!" << endl;
	if (this != &other)
	{
	}
	return (*this);
}

AMateria::~AMateria()
{
	cout << "Deconstructing AMateria" << endl;
}

// CATEGORY:	Member Functions

void			AMateria::setType(string type)
{
	_type = type;
}

string const &	AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter& target)
{
	cout << "Using " << _type << " on " << target.getName() << endl;
}

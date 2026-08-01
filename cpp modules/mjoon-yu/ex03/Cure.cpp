/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:11:41 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/07/29 18:07:28 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

using std::cout;
using std::endl;

// CATEGORY:	Constructor / Copy Constructor / Deconstructor

Cure::Cure() : AMateria("cure")
{
	cout << "Constructing cure" << endl;
}

// Disallow copy constructors and assignment for materias
Cure::Cure(const Cure& other) : AMateria(other)
{
	(void)other;
	cout << "You can't copy cure! Use clone function" << endl;
}

Cure& Cure::operator=(const Cure& other)
{
	cout << "You can't copy assign cure!" << endl;
	if (this != &other)
	{
	}
	return (*this);
}

Cure::~Cure()
{
	cout << "Deconstructing cure" << endl;
}

// CATEGORY:	Member Functions

string const &Cure::getType() const
{
	return AMateria::getType();
}

AMateria*	Cure::clone() const
{
	cout << "Cloning Cure" << endl;
	return (new Cure());
}

void	Cure::use(ICharacter& target)
{
	cout << "* heals " << target.getName() << "'s wounds *" << endl;
}


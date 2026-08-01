/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:11:41 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/07/29 18:07:20 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

using std::cout;
using std::endl;

// CATEGORY:	Constructor / Copy Constructor / Deconstructor

Ice::Ice() : AMateria("ice")
{
	cout << "Constructing ice" << endl;
}

// Disallow copy constructors and assignment for materias
Ice::Ice(const Ice& other) : AMateria(other)
{
	(void)other;
	cout << "You can't copy ice! Use clone function" << endl;
}

Ice& Ice::operator=(const Ice& other)
{
	cout << "You can't copy assign ice!" << endl;
	if (this != &other)
	{
	}
	return (*this);
}

Ice::~Ice()
{
	cout << "Deconstructing ice" << endl;
}

// CATEGORY:	Member Functions

string const &Ice::getType() const
{
	return AMateria::getType();
}

AMateria*	Ice::clone() const
{
	cout << "Cloning Ice" << endl;
	return (new Ice());
}

void	Ice::use(ICharacter& target)
{
	cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
}


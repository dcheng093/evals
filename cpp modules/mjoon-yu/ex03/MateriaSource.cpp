/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 15:55:07 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/07/29 18:04:58 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

using std::cout;
using std::endl;

// CATEGORY:	Constructor / Copy Constructor / Deconstructor

MateriaSource::MateriaSource() : IMateriaSource()
{
	cout << "Constructing Materia Source" << endl;
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) : IMateriaSource(other)
{
	cout << "Copying Materia Source" << endl;
	*this = other;
}

// If source is different, delete all existing materia and copy the 
// corresponding materia, otherwise, NULL
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	cout << "Copy assigning Materia Source" << endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_materia[i])
				delete (_materia[i]);
			if (other._materia[i])
				_materia[i] = other._materia[i]->clone();
			else
				_materia[i] = NULL;
		}
	}
	return (*this);
}

// Deletes materia is exists
MateriaSource::~MateriaSource()
{
	cout << "Deconstructing materia source" << endl;
	for (int i = 0; i < 4; i++)
		if (_materia[i])
			delete(_materia[i]);
}

// CATEGORY:	Member Functions

// Copies the materia passed as parameter and stored in memory.
// At most 4 materias
void		MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] == NULL)
		{
			_materia[i] = materia->clone();
			return ;
		}
	}
	cout << "Source materia slots full" << endl;
}

// Creates a new materia that matches the parameter passed
AMateria*	MateriaSource::createMateria(string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i]->getType() == type)
			return (_materia[i]->clone());
	}
	cout << "No materia type matched" << endl;
	return (0);

}

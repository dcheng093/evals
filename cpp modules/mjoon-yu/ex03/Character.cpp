/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 21:49:17 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/07/31 15:30:55 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

using std::cout;
using std::endl;

// CATEGORY:	Constructor / Copy Constructor / Deconstructor

Character::Character(string name) : ICharacter(), _name(name)
{
	cout << "Constructing Character" << endl;
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

Character::Character(const Character& other) : ICharacter()
{
	cout << "Copying character" << endl;
    for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
	*this = other;
}

// If different Character, delete materia and copies new one
Character& Character::operator=(const Character& other)
{
	cout << "Copy Assigning character" << endl;
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (_materia[i])
				delete (_materia[i]);
			if (other._materia[i])
            {
                _materia[i] = other._materia[i]->clone();
            }
			else
				_materia[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	cout << "Deconstructing character" << endl;
	for (int i = 0; i < 4; i++)
		delete(_materia[i]);
}

// CATEGORY:	Member Functions

string const & Character::getName() const
{
	return (_name);
}

// Equip materia passed to character (Outside still "holds" it)
void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i] == NULL)
		{
			_materia[i] = m;
			return ;
		}
	}
	cout << "Character materia slots full" << endl;
}

// Drop materia, assume outside still holds it (CANNOT DELETE)
void Character::unequip(int idx)
{
	_materia[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (_materia[idx] == NULL)
	{
		cout << _name << " is throwing dust at " << target.getName() << endl;
		return ;
	}
	_materia[idx]->use(target);
}

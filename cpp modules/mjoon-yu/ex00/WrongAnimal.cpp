/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:46:53 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/04/18 21:02:05 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "define.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// CATEGORY:	Constructor / Copy Constructor / Deconstructor

WrongAnimal::WrongAnimal()
{
	cout << MAGENTA;
	cout << "WrongAnimal constructed" << endl;
	cout << WHITE;

}

WrongAnimal::WrongAnimal(string type) : type(type)
{
	cout << MAGENTA;
	cout << "WrongAnimal constructed: " << type << endl;
	cout << WHITE;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	cout << MAGENTA;
	cout << "WrongAnimal copy constructed: " << other.type << endl;
	cout << WHITE;
	*this = other;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	cout << MAGENTA;
	cout << "WrongAnimal copy assignment overload called" << endl;
	cout << WHITE;
	if (this != &other)
		type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	cout << MAGENTA;
	cout << "WrongAnimal deconstructed: " << type << endl;
	cout << WHITE;
}

// CATEGORY: 	Member Function

void	WrongAnimal::makeSound(void) const
{
	cout << MAGENTA;
	cout << "WrongAnimal " << type << " says ???" << endl;
	cout << WHITE;
}

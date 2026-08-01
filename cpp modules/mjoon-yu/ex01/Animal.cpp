/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:46:53 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/06/11 19:44:54 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "define.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// CATEGORY:	Constructor / Copy Constructor / Deconstructor

Animal::Animal() : type("")
{
	cout << "Default Animal constructed" << endl;
}

Animal::Animal(string type) : type(type)
{
	cout << "Animal constructed: " << type << endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
	cout << "Animal copy constructed: " << other.type << endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	cout << "Animal copy assignment overload called" << endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

Animal::~Animal()
{
	cout << "Animal deconstructed: " << type << endl;
}

// CATEGORY: 	Member Function

void	Animal::makeSound(void)	const
{
	cout << "Animal " << type << " says ???" << endl;
}

void	Animal::setIdeas(int slot, string input)
{
	(void)slot;
	(void)input;
	cout << "Animal base class contains no brain" << endl;
}

void	Animal::showIdeas()
{
	cout << "Animal base class contains no brain" << endl;
}

Animal*	Animal::clone()
{
	return (new Animal(*this));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:46:53 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/05/18 14:40:09 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "define.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// CATEGORY:	Constructor / Copy Constructor / Deconstructor

Dog::Dog() : Animal("Dog")
{
	cout << RED;
	cout << "Dog constructed" << endl;
	cout << WHITE;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	cout << RED;
	cout << "Dog copy constructed" << endl;
	cout << WHITE;
	*this = other;
}

Dog&	Dog::operator=(const Dog& other)
{
	cout << RED;
	cout << "Dog copy assignment overload called" << endl;
	cout << WHITE;
	if (this != &other)
	{
	}
	return (*this);
}

Dog::~Dog()
{
	cout << RED;
	cout << "Dog deconstructed" << endl;
	cout << WHITE;
}

// CATEGORY: 	Member Function

void	Dog::makeSound(void) const
{
	cout << RED;
	cout << "Dog says woof" << endl;
	cout << WHITE;
}

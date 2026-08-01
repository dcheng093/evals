/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:46:53 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/05/18 14:39:56 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "define.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// CATEGORY:	Constructor / Copy Constructor / Deconstructor

Cat::Cat() : Animal("Cat")
{
	cout << YELLOW;
	cout << "Cat constructed" << endl;
	cout << WHITE;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	cout << YELLOW;
	cout << "Cat copy constructed" << endl;
	cout << WHITE;
	*this = other;
}

Cat&	Cat::operator=(const Cat& other)
{
	cout << YELLOW;
	cout << "Cat copy assignment overload called" << endl;
	cout << WHITE;
	if (this != &other)
	{
	}
	return (*this);
}

Cat::~Cat()
{
	cout << YELLOW;
	cout << "Cat deconstructed" << endl;
	cout << WHITE;
}

// CATEGORY: 	Member Function

void	Cat::makeSound(void) const
{
	cout << YELLOW;
	cout << "Cat says meow" << endl;
	cout << WHITE;
}

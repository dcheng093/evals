/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:46:53 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/05/20 17:13:37 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "define.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// CATEGORY:	Constructor / Copy Constructor / Deconstructor

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	cout << BLUE;
	cout << "WrongCat constructed" << endl;
	cout << WHITE;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	cout << BLUE;
	cout << "WrongCat copy constructed" << endl;
	cout << WHITE;
	*this = other;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	cout << BLUE;
	cout << "WrongCat copy assignment overload called" << endl;
	cout << WHITE;
	if (this != &other)
	{
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	cout << BLUE;
	cout << "WrongCat deconstructed" << endl;
	cout << WHITE;
}

// CATEGORY: 	Member Function

void	WrongCat::makeSound(void) const
{
	cout << BLUE;
	cout << "WrongCat says wrongmeow" << endl;
	cout << WHITE;
}

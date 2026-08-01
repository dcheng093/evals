/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:46:53 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/06/11 19:50:37 by mjoon-yu         ###   ########.fr       */
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
	brain = new Brain();
}

// NOTE:	Assignment overload removed from copy constructor to prevent
//			unnecessary memory allocation for pointers as well as
//			uninitialized values when deleting allocated memory

Cat::Cat(const Cat& other) : Animal(other)
{
	cout << YELLOW;
	cout << "Cat copy constructed" << endl;
	cout << WHITE;
	brain = new Brain(*other.brain);
}

Cat&	Cat::operator=(const Cat& other)
{
	cout << YELLOW;
	cout << "Cat copy assignment overload called" << endl;
	cout << WHITE;
	if (this != &other)
	{
		delete (brain);
		brain = new Brain(*other.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete (brain);
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

void	Cat::setIdeas(int slot, string input)
{
	brain->setIdeas(slot, input);
}

void	Cat::showIdeas()
{
	brain->showIdeas();
}

Animal*	Cat::clone()
{
	return (new Cat(*this));
}
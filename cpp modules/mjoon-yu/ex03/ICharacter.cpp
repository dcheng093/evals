/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 21:19:07 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/06/11 20:06:11 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include <iostream>

using std::cout;
using std::endl;

// CATEGORY:	Constructor / Copy Constructor / Deconstructor

ICharacter::ICharacter()
{
	cout << "Constructing ICharacter" << endl;
}

ICharacter::ICharacter(const ICharacter& other)
{
	cout << "Copying ICharacter" << endl;
	(void)other;
}

ICharacter& ICharacter::operator=(const ICharacter& other)
{
	cout << "Copy assinging ICharacter" << endl;
	if (this != &other)
	{
	}
	return (*this);
}

ICharacter::~ICharacter()
{
	cout << "Deconstructing ICharacter" << endl;
}

// CATEGORY:	Member Functions


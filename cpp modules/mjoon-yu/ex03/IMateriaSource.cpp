/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:59:52 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/05/25 19:01:57 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include <iostream>

using std::cout;
using std::endl;

// CATEGORY:	Constructor / Copy Constructor / Deconstructor

IMateriaSource::IMateriaSource()
{
	cout << "Constructing IMateria Source" << endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource& other)
{
	cout << "Copying IMateria Source" << endl;
	(void)other;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other)
{
	if (this != &other)
	{
	}
	return (*this);
}

IMateriaSource::~IMateriaSource()
{
	cout << "Decontructing IMateria Source" << endl;
}

// CATEGORY:	Member Functions


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 21:14:49 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/04/25 14:42:15 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

// CATEGORY:	Constructor / Copy Constructor / Deconstructor

Brain::Brain()
{
	cout << "Constructing brain" << endl;
}

Brain::Brain(const Brain& other)
{
	cout << "Copying brain" << endl;
	for(int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];

}

Brain&	Brain::operator=(const Brain& other)
{
	cout << "Copy assignment overload for brain" << endl;
	if (this != &other)
	{
		for(int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	cout << "Deconstructing brain" << endl;
}

// CATEGORY:	Member Function

void	Brain::setIdeas(int slot, string input)
{
	if (slot < 0 || slot > 99)
	{
		cout << "Invalid idea space (Enter 0 - 99)" << endl;
		return ;
	}
	ideas[slot] = input;
	cout << "Idea set to " << slot << endl;
}

void	Brain::showIdeas()
{
	for(int i = 0; i < 100; i++)
	{
		if (ideas[i] != "")
			cout << "Idea " << i << " : " << ideas[i] << endl;
	}
}


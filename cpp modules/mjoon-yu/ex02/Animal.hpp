/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:41:33 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/06/11 19:49:58 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

using std::string;

// INFO:	To make an abstract class, the class has to contain
// 			one or more pure virtual function.
// 			This means a function that is virtual and is assigned 0
// 			Refer to makeSound(void)

class	Animal
{
	protected:
		string	type;
		
		Animal(const Animal& other);
		Animal&	operator=(const Animal& other);

	public:
		Animal();
		Animal(string type);
		virtual ~Animal();

		virtual void	makeSound(void) const = 0;
		virtual void	setIdeas(int slot, string input) = 0;
		virtual void	showIdeas() = 0;
		virtual Animal*	clone() = 0;
};

#endif

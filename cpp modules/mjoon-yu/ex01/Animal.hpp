/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:41:33 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/07/31 14:59:38 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

using std::string;

// Copy constructor and copy assignment for base class to be protected.
// Disallow users to copy Animal class directly (To prevent losing derived information)
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

		virtual void	makeSound(void) const;
		virtual void	setIdeas(int slot, string input);
		virtual void	showIdeas();
		virtual Animal*	clone();
};

#endif

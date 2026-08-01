/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:41:33 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/07/28 17:58:19 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

using std::string;

class	Animal
{
	protected:
		string	type;

	public:
		Animal();
		Animal(string type);
		Animal(const Animal& other);
		Animal&	operator=(const Animal& other);
		virtual ~Animal();

		virtual void	makeSound(void) const;
};

#endif

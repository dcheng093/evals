/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:15:55 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/06/11 20:06:05 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"
# include <string>

class ICharacter	// Inherited by Character
{
	private:

	protected:
		ICharacter();
		ICharacter(const ICharacter& other);
		virtual ICharacter&	operator=(const ICharacter& other);
	public:
		virtual ~ICharacter();
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;	// Equip a new Materia
		virtual void unequip(int idx) = 0;		// Unequip (delete) materia
		virtual void use(int idx, ICharacter& target) = 0;	// Calls AMateria::use
};

#endif

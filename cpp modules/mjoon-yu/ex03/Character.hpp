/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 21:34:43 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/05/25 15:08:01 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

using std::string;

class AMateria;

class Character : public ICharacter
{
	private:
		string		_name;
		AMateria*	_materia[4];

	protected:

	public:
		Character(string name);
		Character(const Character& other);
		Character&	operator=(const Character& other);
		~Character();

		string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:52:23 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/07/31 15:09:44 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include <string>

using std::string;

class ICharacter;

class Cure : public AMateria
{
	private:

	protected:

	public:
		Cure();
		Cure(const Cure& other);
		Cure&	operator=(const Cure& other);
		~Cure();

		string const &		getType() const;	// Returns type
		AMateria*	clone() const;	// Returns another copy of Cure
		void	use(ICharacter& target);	// Use materia on target
};

#endif

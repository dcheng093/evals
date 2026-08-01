/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:52:23 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/07/31 15:09:47 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include <string>

using std::string;

class ICharacter;

class Ice : public AMateria
{
	private:

	protected:

	public:
		Ice();
		Ice(const Ice& other);
		Ice&	operator=(const Ice& other);
		~Ice();

		string const &		getType() const;	// Returns type
		AMateria*	clone() const;	// Returns another copy of Ice
		void	use(ICharacter& target);	// Use materia on target
};

#endif

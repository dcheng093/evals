/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:40:52 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/07/31 15:09:03 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

using std::string;

class ICharacter;

class AMateria
{
	protected:
        string	_type;
		AMateria(const AMateria& other);
		AMateria&	operator=(const AMateria& other);
	public:
		AMateria(string const &type);
		virtual ~AMateria();

		void				setType(string type);
		string const &		getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif

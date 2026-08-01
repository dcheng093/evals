/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 15:20:10 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/05/25 19:34:21 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include <string>

using std::string;

class	AMateria;

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_materia[4];

	protected:

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource&	operator=(const MateriaSource& other);
		~MateriaSource();

		void		learnMateria(AMateria* materia);
		AMateria*	createMateria(string const &type);
};

#endif

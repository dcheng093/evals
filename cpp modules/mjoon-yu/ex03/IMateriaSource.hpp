/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 21:53:36 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/05/25 19:33:46 by mjoon-yu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <string>

class AMateria;

class IMateriaSource
{
	private:

	protected:

	public:
		IMateriaSource();
		IMateriaSource(const IMateriaSource& other);
		IMateriaSource&	operator=(const IMateriaSource& other);
		virtual ~IMateriaSource();

		virtual void		learnMateria(AMateria* materia) = 0;
		virtual AMateria*	createMateria(std::string const &type) = 0;
};

#endif

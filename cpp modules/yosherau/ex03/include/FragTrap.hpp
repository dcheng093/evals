/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:10:06 by yosherau          #+#    #+#             */
/*   Updated: 2026/01/24 12:54:26 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &original);
		FragTrap		&operator=(const FragTrap &original);
		void			highFivesGuys(void);
		virtual bool	canAct(void) const;
};

#endif
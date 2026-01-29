/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 13:34:24 by yosherau          #+#    #+#             */
/*   Updated: 2026/01/25 13:43:34 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: FragTrap, ScavTrap
{
	std::string	name;
	
	public:
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &original);
		DiamondTrap	&operator=(const DiamondTrap &original);
		void		attack(const std::string &target);
		void		whoAmI(void);
		bool		canAct(void) const;
	};

#endif
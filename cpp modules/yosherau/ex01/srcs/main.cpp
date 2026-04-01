/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:42:00 by yosherau          #+#    #+#             */
/*   Updated: 2026/01/29 16:14:31 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "=== CONSTRUCTION TESTS ===" << std::endl;
    std::cout << "\n--- Default ScavTrap ---" << std::endl;
    ScavTrap scav1;
    
    std::cout << "\n--- Named ScavTrap ---" << std::endl;
    ScavTrap scav2("Guardian");
    
    std::cout << "\n--- Copy Constructor ---" << std::endl;
    ScavTrap scav3(scav2);
    
    std::cout << "\n--- Copy Assignment Operator ---" << std::endl;
    ScavTrap scav4;
    scav4 = scav2;
    
    std::cout << "\n=== BASIC ATTACK TESTS ===" << std::endl;
    scav2.attack("enemy");
    
    std::cout << "\n=== GUARD GATE TEST ===" << std::endl;
    scav2.GuardGate();
    
    std::cout << "\n=== DAMAGE AND REPAIR TESTS ===" << std::endl;
    scav2.takeDamage(30);
    scav2.beRepaired(20);
    scav2.takeDamage(200); // Should kill it
    scav2.attack("enemy"); // Should fail - no hit points
    scav2.beRepaired(10); // Should fail - no hit points
    
    std::cout << "\n=== ENERGY DEPLETION TEST ===" << std::endl;
    ScavTrap scav5("Energizer");
    for (int i = 0; i < 51; i++) // ScavTrap should have 50 energy
    {
        scav5.attack("target");
    }
    scav5.attack("target"); // Should fail - no energy
    
    std::cout << "\n=== DESTRUCTION TESTS ===" << std::endl;
    return 0;
}
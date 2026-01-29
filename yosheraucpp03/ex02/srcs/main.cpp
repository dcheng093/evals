#include "../include/FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "=== CONSTRUCTION TESTS ===" << std::endl;
    std::cout << "\n--- Default FragTrap ---" << std::endl;
    FragTrap frag1;
    
    std::cout << "\n--- Named FragTrap ---" << std::endl;
    FragTrap frag2("HighFiver");
    
    std::cout << "\n--- Copy Constructor ---" << std::endl;
    FragTrap frag3(frag2);
    
    std::cout << "\n--- Copy Assignment Operator ---" << std::endl;
    FragTrap frag4;
    frag4 = frag2;
    
    std::cout << "\n=== BASIC ATTACK TESTS ===" << std::endl;
    frag2.attack("enemy"); // Should do 30 damage
    
    std::cout << "\n=== HIGH FIVES TEST ===" << std::endl;
    frag2.highFivesGuys();
    frag1.highFivesGuys();
    
    std::cout << "\n=== DAMAGE AND REPAIR TESTS ===" << std::endl;
    frag2.takeDamage(50);
    frag2.beRepaired(30);
    frag2.takeDamage(150); // Should kill it (100 HP total)
    frag2.attack("enemy"); // Should fail - no hit points
    frag2.highFivesGuys(); // Should still work even when dead?
    frag2.beRepaired(10); // Should fail - no hit points
    
    std::cout << "\n=== ENERGY DEPLETION TEST ===" << std::endl;
    FragTrap frag5("Marathon");
    std::cout << "Attacking 100 times to deplete energy..." << std::endl;
    for (int i = 0; i < 101; i++) // FragTrap should have 100 energy
    {
        if (i % 20 == 0)
            std::cout << "Attack #" << i << std::endl;
        frag5.attack("target");
    }
    frag5.attack("target"); // Should fail - no energy
    frag5.highFivesGuys(); // Should still work - doesn't require energy

    std::cout << "\n=== DESTRUCTION TESTS ===" << std::endl;
    return 0;
}
//
// Created by Kim Taeseon on 2022/05/03.
//

#include "ScavTrap.hpp"

int main()
{
    ScavTrap scavTrap("Wall E");
    std::cout << std::endl;

    scavTrap.attack("Wall A");
    std::cout << std::endl;

    scavTrap.takeDamage(42);
    std::cout << std::endl;

    scavTrap.takeDamage(84);
    std::cout << std::endl;
    
    scavTrap.beRepaired(48);
    std::cout << std::endl;
    
    scavTrap.beRepaired(3);
    std::cout << std::endl;
    
    scavTrap.guardGate();
    std::cout << std::endl;
  return (0);
}


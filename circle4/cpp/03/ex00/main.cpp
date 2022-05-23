//
// Created by Kim Taeseon on 2022/05/03.
//

#include "ClapTrap.hpp"

int main()
{
        {
        ClapTrap clapTrap("Wall A");
        std::cout << std::endl;

        clapTrap.attack("Wall B");
        std::cout << std::endl;

        clapTrap.takeDamage(0);
        std::cout << std::endl;

        clapTrap.takeDamage(1);
        std::cout << std::endl;

        // clapTrap.takeDamage(8);
        // std::cout << std::endl;

        clapTrap.takeDamage(10);
        std::cout << std::endl;

        // clapTrap.takeDamage(5);
        // std::cout << std::endl;
    }

    {
        // ClapTrap wallE("Wall E");

        // wallE.takeDamage(5);
        // std::cout << std::endl;

        // wallE.beRepaired(0);
        // std::cout << std::endl;

        // wallE.beRepaired(4);
        // std::cout << std::endl;

        // wallE.beRepaired(20);
        // std::cout << std::endl;

        // wallE.takeDamage(20);
        // std::cout << std::endl;

        // wallE.beRepaired(10);
        // std::cout << std::endl;
    }
    return (0);
}


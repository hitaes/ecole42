//
// Created by Kim Taeseon on 2022/05/03.
//

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
    randomChump("stack");

    Zombie *heap(newZombie("heap"));
    delete heap;
    return (0);
}


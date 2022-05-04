//
// Created by Kim Taeseon on 2022/05/03.
//

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
    Zombie* horde = zombieHorde(5, "ts");
    for (int i = 0; i < 5; i++)
        horde[i].announce();
    delete[] horde;
    return (0);
}

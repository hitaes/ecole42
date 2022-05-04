#include "Zombie.hpp"

void Zombie::announce(void) const{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(const std::string name) : _name(name){
}

Zombie::~Zombie(){
    std::cout << _name << ": Back to HomeTown..." << std::endl;
}
#include "HumanB.hpp"

HumanB::~HumanB(){}

HumanB::HumanB(std::string name) : _name(name){}

void HumanB::setWeapon(Weapon& weapon){
    _weapon = &weapon;
    return ;
}

void HumanB::attack(void){
    std::cout << _name << " attack with their " << _weapon->getType() << std::endl;   
}
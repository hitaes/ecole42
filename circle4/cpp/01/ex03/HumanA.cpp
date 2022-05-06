#include "HumanA.hpp"

void HumanA::attack(void){
    std::cout << _name << " attack with their " << _weapon.getType() << std::endl;   
}

HumanA::~HumanA(){}

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon){}

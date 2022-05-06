#include "Weapon.hpp"

const std::string& Weapon::getType(void) {
  return _type;
}

void Weapon::setType(const std::string& typeInput) {
  _type = typeInput;
}

Weapon::~Weapon(void){}

Weapon::Weapon(const std::string& type) : _type(type) {}

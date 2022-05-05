#include "Weapon.hpp"

Weapon::~Weapon(void){}

Weapon::Weapon(const std::string& type) : _type(type) {}

const std::string& Weapon::getType(void) {
  return _type;
}

void Weapon::setType(const std::string& typeInput) {
  _type = typeInput;
}
#include "ClapTrap.hpp"

// Constructors

ClapTrap::ClapTrap() : _name("default"), _hit_point(10), _energy_point(10), _attack_damage(0) {
    std::cout << "ClapTrap Default Constructor is called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_point(10), _energy_point(10), _attack_damage(0) {
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Constructor is called. " << _name << " is initialized." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
    std::cout << "Copy Constructor is called" << std::endl;
    *this = src;
}

// Deconstructor

ClapTrap::~ClapTrap() {
    std::cout << "Deconstructor is called. " << _name << " is deconstructed" << std::endl;
    std::cout << "=================================================" << std::endl;
}

// Overloaded Operator

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
    this->_name = src._name;
    this->_attack_damage = src._attack_damage;
    this->_energy_point = src._energy_point;
    this->_hit_point = src._hit_point;
    return *this;
}

// Public Methods
void ClapTrap::attack(const std::string& target)
{
    if (this->_energy_point > 0 && this->_hit_point)
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_point--;
    }
    else if (this->_energy_point == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is not able to attack. " << target << " due to zero energy point" << std::endl;
    }
    else 
    {
        std::cout << "ClapTrap " << this->_name << " is not able to attack. " << target << " due to zero hit_point" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hit_point > amount)
    {
        this->_hit_point -= amount;
        std::cout << "ClapTrap " << this->_name << " is attacked with " << amount << std::endl;
        std::cout << this->_name << " current hitpoint is " << this->_hit_point << std::endl;
    }
    else if (this->_hit_point <= amount)
    {
        this->_hit_point = 0;
        std::cout << "ClapTrap " << this->_name << " is attacked with " << amount << std::endl;
        std::cout << "ClapTrap " << this->_name << " is killed" << std::endl;
    }
    else if (this->_hit_point == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energy_point > 0 && this->_hit_point > 0&& this->_hit_point + amount <= 10)
    {
        this->_hit_point += amount;
        std::cout << "ClapTrap " << this->_name << " is repaired with " << amount << std::endl;
        std::cout << this->_name << "current hitpoint is " << this->_hit_point << std::endl;
        this->_energy_point--;
    }
    else if (this->_energy_point <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " has not enough energy" << std::endl;
    }
    else if (this->_hit_point == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
    }
    else if (this->_hit_point == 10)
    {
        std::cout << "ClapTrap's hit point is max" << std::endl;
    }
}
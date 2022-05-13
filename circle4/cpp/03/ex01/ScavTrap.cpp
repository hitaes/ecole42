#include "ScavTrap.hpp"

// Constructor

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
	this->_guarding_gate = false;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src)
{
    this->_guarding_gate = src._guarding_gate;
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
	this->_guarding_gate = false;
	std::cout << "ScavTrap Constructor" << this->_name << " called" << std::endl;
}

// Deconstructor

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Deconstructor" << this->_name << " called" << std::endl;
}

// Public Methods
void ScavTrap::attack(const std::string& target)
{
    if (this->_energy_point > 0 && this->_hit_point)
    {
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_point--;
    }
    else if (this->_energy_point == 0)
    {
        std::cout << "ScavTrap " << this->_name << " is not able to attack. " << target << "due to zero energy point" << std::endl;
    }
    else 
    {
        std::cout << "ScavTrap " << this->_name << " is not able to attack. " << target << "due to zero hit_point" << std::endl;
    }
}

void	ScavTrap::guardGate(void)
{
	if (this->_guarding_gate == false)
	{
		this->_guarding_gate = true;
		std::cout << "ScavTrap " << this->_name << " is now guarding the gate." << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " is already guarding the gate." << std::endl;
}
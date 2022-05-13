
#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <string>
# include <iostream>

class ClapTrap
{
private:
    // private variables
    std::string _name;
    unsigned int _hit_point;
    unsigned int _energy_point;
    unsigned int _attack_damage;
    
public:
    // public methods
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    // Constructors
    ClapTrap();
    ClapTrap(const std::string name);
    ClapTrap(const ClapTrap& clapTrap);

    // Overloaded Operator
    ClapTrap& operator=(const ClapTrap& src);

    // Deconstructor
    ~ClapTrap();
};

#endif
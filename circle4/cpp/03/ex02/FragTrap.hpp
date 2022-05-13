#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ScavTrap.hpp"
# include <string>
# include <iostream>

class FragTrap : public ClapTrap
{
private:
    /* data */
public:
    // Constructors
	FragTrap();
	FragTrap(const FragTrap &copy);
	FragTrap(std::string name);

	// Deconstructors
    virtual ~FragTrap();

	// Overloaded Operators
	FragTrap &operator=(const FragTrap &src);

    // Public Methods
    void highFivesGuys(void);
};

#endif
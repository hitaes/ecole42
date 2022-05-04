#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string _name;
        
    public:
        void announce(void) const;

        Zombie(const std::string name);
        ~Zombie();
};

#endif

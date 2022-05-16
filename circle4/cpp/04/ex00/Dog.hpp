#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"

class Dog : public Animal
{
private:

public:
// Constructors
    Dog();
    Dog(const Dog &Dog);
// Deconstructor
    ~Dog();
// Overloaded Operators
    Dog &operator=(const Dog &src);
// Public Methods
    void makeSound()const;
};

#endif

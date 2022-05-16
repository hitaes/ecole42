#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"

class Cat : public Animal
{
private:

public:
// Constructors
    Cat();
    Cat(const Cat &Cat);
// Deconstructor
    ~Cat();
// Overloaded Operators
    Cat &operator=(const Cat &src);
// Public Methods
    void makeSound()const;
};

#endif

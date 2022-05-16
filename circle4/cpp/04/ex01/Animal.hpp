#ifndef ANIMAL_H
# define ANIMAL_H

# include <string>
# include <iostream>

class Animal
{
protected:
    std::string _type;
public:
    // Constructors
    Animal();
    Animal(const Animal &Animal);
    virtual ~Animal();

    // Overloaded Operators
	Animal& operator = (const Animal &source);

	// Public Methods
    virtual void makeSound()const;
    std::string getType()const;
};

#endif

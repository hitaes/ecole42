#include "Dog.hpp"

// Constructors

Dog::Dog(): Animal()
{
    std::cout << "Dog Default Constructor is called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog &src) : Animal()
{
    std::cout << "Dog Copy Constructor is called" << std::endl;
    *this = src;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	this->_type = src._type;
	return *this;
}

// Deconstructor

Dog::~Dog()
{
    std::cout << "Dog Deconstructor is called" << std::endl;
}

// Public methods

void Dog::makeSound()const
{
	std::cout << this->getType() << " says: Meong" << std::endl;
}



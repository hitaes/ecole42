#include "Animal.hpp"

// Constructors

Animal::Animal(): _type("default")
{
    std::cout << "Animal Default Constructor is called" << std::endl;
}

Animal::Animal(const Animal &src)
{
    std::cout << "Animal Copy Constructor is called" << std::endl;
    *this = src;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	this->_type = src._type;
	return *this;
}

// Deconstructor

Animal::~Animal()
{
    std::cout << "Animal Deconstructor is called" << std::endl;
}

// Public methods

void Animal::makeSound()const
{
	std::cout << "Animal Prototype doesn't make sound." << std::endl;
}

std::string Animal::getType()const
{
    return (this->_type);
}


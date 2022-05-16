#include "WrongAnimal.hpp"

// Constructors

WrongAnimal::WrongAnimal(): _type("default")
{
    std::cout << "WrongAnimal Default Constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    std::cout << "WrongAnimal Copy Constructor is called" << std::endl;
    *this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "WrongAnimal Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	this->_type = src._type;
	return *this;
}

// Deconstructor

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Deconstructor is called" << std::endl;
}

// Public methods

void WrongAnimal::makeSound()const
{
	std::cout << "WrongAnimal Prototype doesn't make sound." << std::endl;
}

std::string WrongAnimal::getType()const
{
    return (this->_type);
}


#include "WrongCat.hpp"

// Constructors

WrongCat::WrongCat(): WrongAnimal()
{
    std::cout << "WrongCat Default Constructor is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal()
{
    std::cout << "WrongCat Copy Constructor is called" << std::endl;
    *this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	std::cout << "WrongCat Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	this->_type = src._type;
	return *this;
}

// Deconstructor

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Deconstructor is called" << std::endl;
}

// Public methods

void WrongCat::makeSound()const
{
	std::cout << this->getType() << " says: roar!!!!!" << std::endl;
}



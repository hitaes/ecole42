#include "Cat.hpp"

// Constructors

Cat::Cat(): Animal()
{
    std::cout << "Cat Default Constructor is called" << std::endl;
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("Dog Brain allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
}

Cat::Cat(const Cat &src) : Animal()
{
    std::cout << "Cat Copy Constructor is called" << std::endl;
    *this = src;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	this->_type = src._type;
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("Dog Brain allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
	return *this;
}

// Deconstructor

Cat::~Cat()
{
    std::cout << "Cat Deconstructor is called" << std::endl;
}

// Public methods

void Cat::makeSound()const
{
	std::cout << this->getType() << " says: niyaoong" << std::endl;
}



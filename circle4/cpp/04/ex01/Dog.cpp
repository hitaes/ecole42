#include "Dog.hpp"

// Constructors

Dog::Dog(): Animal()
{
    std::cout << "Dog Default Constructor is called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("Dog Brain allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
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

Dog::~Dog()
{
    std::cout << "Dog Deconstructor is called" << std::endl;
}

// Public methods

void Dog::makeSound()const
{
	std::cout << this->getType() << " says: Meong" << std::endl;
}

// Getter
void	Dog::getIdeas(void)const
{
	for (int i = 0; i < 3; i++)// change the 3 to 100 to show all ideas
		std::cout << "\tIdea " << i << " of the Dog is: \"" << this->_brain->getIdea(i) << "\" at the address " << this->_brain->getIdeaAddress(i) << std::endl;
}

// Setter
void	Dog::setIdea(size_t i, std::string idea)
{
		this->_brain->setIdea(i, idea);
}

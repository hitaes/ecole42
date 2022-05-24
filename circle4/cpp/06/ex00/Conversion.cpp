#include "Conversion.hpp"

// Constructor
Conversion::Conversion()
{
	std::cout << "Conversion Default Constructor called" << std::endl;
}

Conversion::Conversion(const std::string input): _input(input)
{
	std::cout << "Conversion Constructor is called with input" << std::endl;
	this->_double = atof(this->getInput().c_str());
	this->convertInput();
	this->printOutput();
}

Conversion::Conversion(const Conversion &copy): _input(copy.getInput())
{
	std::cout << "Conversion Copy Constructor is called" << std::endl;
	*this = copy;
	this->printOutput();
}


// Overloaded Operators
Conversion &Conversion::operator=(const Conversion &src)
{
	std::cout << "Conversion Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	this->_type = src.getType();
	this->_char = src.getChar();
	this->_int = src.getInt();
	this->_float = src.getFloat();
	this->_double = src.getDouble();
	return *this;
}

// Deconstructor
Conversion::~Conversion()
{
	std::cout << "Conversion Deconstructor called" << std::endl;
}

// Exceptions
const char *Conversion::ErrorException::what() const throw()
{
	return ("Error: Impossible to print or input not convertible");
}

// Getter
std::string Conversion::getInput(void)const
{
	return (this->_input);
}

int Conversion::getType(void)const
{
	return (this->_type);
}

char Conversion::getChar(void)const
{
	return (this->_char);
}

int Conversion::getInt(void)const
{
	return (this->_int);
}

float Conversion::getFloat(void)const
{
	return (this->_float);
}

double Conversion::getDouble(void)const
{
	return (this->_double);
}
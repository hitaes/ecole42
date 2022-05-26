#include "Conversion.hpp"

// Canonical Form
Conversion::Conversion(): _error(false), _input(""), _value(0.0)
{
}
Conversion &Conversion::operator=(const Conversion& src)
{
	if (this != &src)
	{
		_error = src.getError();
		*(const_cast<double*>(&_value)) = src.getValue();
		*(const_cast<std::string*>(&_input)) = src.getInput();
	}
	return *this;
}
Conversion::Conversion(const Conversion &copy): _error(copy.getError()), _input(copy.getInput()), _value(copy.getValue())
{
}
Conversion::~Conversion()
{
}

// Public Methods
char Conversion::toChar() const
{
	return static_cast<char>(_value);
}
int Conversion::toInt() const
{
	return static_cast<int>(_value);
}
float Conversion::toFloat()	const
{
	return static_cast<float>(_value);
}
double Conversion::toDouble() const
{
	return static_cast<double>(_value);
}

// Getter
bool Conversion::getError() const
{
	return (_error);
}
const double& Conversion::getValue() const
{
	return (_value);	
}
const std::string& Conversion::getInput() const
{
	return (_input);
}

// Constructor
Conversion::Conversion(const std::string& input): _error(false), _input(input), _value(0.0)
{
	try
	{
		char *ptr = NULL;
    	*(const_cast<double*>(&_value)) = std::strtod(_input.c_str(), &ptr);
    	if (_value == 0.0 && (_input[0] != '-' && _input[0] != '+' && !std::isdigit(_input[0])))
      		throw std::bad_alloc();
    	if (*ptr && std::strcmp(ptr, "f"))
      		throw std::bad_alloc();
	}
	catch(const std::exception& e)
	{
		std::cout << "Error Occurred." << std::endl;
		_error = true;
	}
}

// Static Functions

bool isNotPossible(const double &input)
{
	return (std::isnan(input) || std::isinf(input)) ? true : false;
}

static void displayChar(std::ostream& o, const Conversion& c)
{
	o << "char: ";
	if (isNotPossible(c.getValue()))
		o << "impossible" << std::endl;
	else if (std::isprint(c.toChar()))
		o << "'" << c.toChar() << "'" << std::endl;
	else 
		o << "Non displayable" << std::endl;
}

static void displayInt(std::ostream& o, const Conversion& c)
{
	o << "int: ";
	if (isNotPossible(c.getValue()))
		o << "impossible" << std::endl;
	else
		o << c.toInt() << std::endl;
}

static void display(std::ostream& o, const Conversion& c)
{
	if (isNotPossible(c.getValue()))
	{
		o << "float: " << std::showpos << c.toFloat() << "f" << std::endl;
		o << "double: " << std::showpos << c.toDouble() << std::endl;
		return ;
	}
	if (c.toFloat() == static_cast<long long>(c.toFloat()))
		o << "float: " << c.toFloat() << ".0f" << std::endl;
	else
	 	o << "float: " << std::setprecision(std::numeric_limits<float>::digits10) << c.toFloat() << "f" << std::endl;
	if (c.toDouble() == static_cast<long long>(c.toDouble()))
		o << "double: " << c.toDouble() << ".0" << std::endl;
	else
		o << "double: " << std::setprecision(std::numeric_limits<double>::digits10) << c.toDouble() << std::endl;
}

std::ostream&	operator<<(std::ostream& o, const Conversion& c)
{
	if (c.getError())
	{
		o << "Converting Failed" << std::endl;
		return (o);
	}
	displayChar(o, c);
	displayInt(o, c); 
	display(o, c);
	return (o);
}
#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructing
Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor is called " << 
	this->getName() << " with " << 
	this->getGrade() << std::endl;
}
Bureaucrat::Bureaucrat(int grade): _name("default")
{	
	try
	{
		this->setGrade(grade);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "\033[33mConstructing " << this->getName() <<
		" failed: " << e.what() << std::endl <<
		"Grade now set to 1" << "\033[0m" << std::endl;
		this->setGrade(1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "\033[33mConstructing " << this->getName() <<
		" failed: " << e.what() << std::endl <<
		"Grade now set to 150" << "\033[0m" << std::endl;
		this->setGrade(150);
	}
	std::cout << "Bureaucrat Constructor is called " << 
	this->getName() << " with " << 
	this->getGrade() << std::endl;		
}
Bureaucrat::Bureaucrat(const std::string name): _name(name), _grade(150)
{
	std::cout << "Bureaucrat Default Constructor is called " << 
	this->getName() << " with " << 
	this->getGrade() << std::endl;
}
Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	try
	{
		this->setGrade(grade);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "\033[33mConstructing " << this->getName() <<
		" failed: " << e.what() << std::endl <<
		"Grade now set to 1" << "\033[0m" << std::endl;
		this->setGrade(1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "\033[33mConstructing " << this->getName() <<
		" failed: " << e.what() << std::endl <<
		"Grade now set to 150" << "\033[0m" << std::endl;
		this->setGrade(150);
	}
	std::cout << "Bureaucrat Constructor is called " << 
	this->getName() << " with " << 
	this->getGrade() << std::endl;		
}
Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	std::cout << "Copy Constructor is called " << std::endl;	
	*this = src;
}

// Exceptions
const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}


// Deconstructors
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Deconstructor for " << this->getName() << " called" << std::endl;
}

// Overloaded Operators
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat Assignation operator called" << std::endl;
	this->_grade = src.getGrade();
	return *this;
}

// Public Methods
void	Bureaucrat::incrementGrade(void)
{
	try
	{
		std::cout << "Trying to increment grade of " << this->getName() << std::endl;
		this->setGrade(this->_grade - 1);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "\033[33mIncrementing grade of " << this->getName() <<
		" failed: " << e.what() << "\033[0m" << std::endl;
	}
}

void	Bureaucrat::decrementGrade(void)
{
	try
	{
		std::cout << "Trying to decrement grade of " << this->getName() << std::endl;
		this->setGrade(this->_grade + 1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "\033[33mDecrementing grade of " << this->getName() <<
		" failed: " << e.what() << "\033[0m" << std::endl;
	}
}

// Getter
const std::string	Bureaucrat::getName(void)const
{
	return (this->_name);
}

size_t	Bureaucrat::getGrade(void)const
{
	return (this->_grade);
}

// Setter
void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

void Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
}

void Bureaucrat::executeForm(Form &form)const
{
	form.execute(*this);
}

// ostream Overload
std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << ":\n\tgrade: " << a->getGrade() << std::endl;
	return (o);
}
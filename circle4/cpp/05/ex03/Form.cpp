#include "Form.hpp"

// Constructors
Form::Form(void): _name("default"), _is_signed(false), _grade_for_sign(150), _grade_for_exec(150)
{
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(const Form &src): _name(src.getName() + "_copy"), _is_signed(false), _grade_for_sign(src.getGradeForSign()), _grade_for_exec(src.getGradeForExec())
{
	std::cout << "Form Copy Constructor called to copy " << src.getName() <<
	" into " << this->getName() << std::endl;
	*this = src;
}

Form::Form(int sign_grade, int exec_grade): _name("default"), _is_signed(false), _grade_for_sign(sign_grade), _grade_for_exec(exec_grade)
{
	std::cout << "Form Constructor called for " << this->getName() <<
	" with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade <<
	std::endl;
	const int i = this->getGradeForSign();
	const int j = this->getGradeForExec();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(const std::string name): _name(name), _is_signed(false), _grade_for_sign(150), _grade_for_exec(150)
{
	std::cout << "Form Constructor called for " << this->getName() <<
	" with sign-grade of " << this->getGradeForSign() <<
	" and execution-grade of " << this->getGradeForExec() << std::endl;
}

Form::Form(const std::string name, int sign_grade, int exec_grade): _name(name), _is_signed(false), _grade_for_sign(sign_grade), _grade_for_exec(exec_grade)
{
	std::cout << "Form Constructor called for " << this->getName() <<
	" with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade <<
	std::endl;
	const int i = this->getGradeForSign();
	const int j = this->getGradeForExec();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}

// Deconstructors
Form::~Form()
{
	std::cout << "Form Deconstructor for " << this->getName() << " called" << std::endl;
}

// Overloaded Operators
Form &Form::operator=(const Form &src)
{
	std::cout << "Form Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	//nothing to assign in this class
	return *this;
}

// Public Methods
void Form::beSigned(Bureaucrat &signer)
{
	if ((int)signer.getGrade() > this->getGradeForSign())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getIsSigned() == "not signed")
	{
		this->_is_signed = true;
		std::cout << this->getName() << " Form was signed by " << signer.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " Form is already signed" << std::endl;
}

void Form::execute(Bureaucrat const &executor)const
{
	(void)executor;
}

// Getter
const std::string	Form::getName(void)const
{
	return (this->_name);
}

const std::string	Form::getIsSigned(void)const
{
	if (this->_is_signed)
		return ("signed");
	else
		return ("not signed");
}

bool	Form::isSigned(void)const
{
	return (this->_is_signed);
}

int	Form::getGradeForSign(void)const
{
	return (this->_grade_for_sign);
}

int	Form::getGradeForExec(void)const
{
	return (this->_grade_for_exec);
}

// Exceptions
const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

const char *Form::FormNotSignedException::what(void) const throw()
{
	return ("Form is needed to be signed before executing");
}

// ostream Overload
std::ostream	&operator<<(std::ostream &o, Form *a)
{
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getGradeForSign() <<
	"\n\texec-grade:\t" << a->getGradeForExec() <<
	"\n\tis signed:\t" << a->getIsSigned() <<
	std::endl;
	return (o);
}
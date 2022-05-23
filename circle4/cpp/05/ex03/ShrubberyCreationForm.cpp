#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor for target " << this->getTarget() << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): Form("ShrubberyCreationForm", 145, 137), _target(copy.getTarget())
{
	std::cout << "ShrubberyCreationForm Copy Constructor called to copy " << copy.getName() <<
	" into " << this->getName() << std::endl;

	*this = copy;
}

// Deconstructors
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Deconstructor " << this->getName() << " called" << std::endl;
}

// Overloaded Operators
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
	if (this == &src)
		return *this;
	//nothing to assign in this class, all constants
	return *this;
}

// Public Methods
void	ShrubberyCreationForm::execute(Bureaucrat const &executor)const
{
	if ((int)executor.getGrade() > this->getGradeForExec())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->isSigned() == false)
		throw (Form::FormNotSignedException());
	else
	{
		std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());

		for (int i = 0; i < 5; i++)
		{
			outfile <<
			"         v" << std::endl <<
			"        >X<" << std::endl <<
			"         A" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"       d$$@b" << std::endl <<
			"      d\\$$$ib" << std::endl <<
			"    .d$$$\\$$$b" << std::endl <<
			"  .d$$@$$$$\\$$ib." << std::endl <<
			"      d$$i$$b" << std::endl <<
			"     d\\$$$$@$b" << std::endl <<
			"  .d$@$$\\$$$$$@b." << std::endl <<
			".d$$$$i$$$\\$$$$$$b." << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
			"        ###" << std::endl <<
		std::endl;
		}
		outfile.close();
	}
}

// Getter
std::string	ShrubberyCreationForm::getTarget(void)const
{
	return (this->_target);
}

// Setter

// ostream Overload
std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a)
{
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getGradeForSign() <<
	"\n\texec-grade:\t" << a->getGradeForExec() <<
	"\n\tis signed:\t" << a->getIsSigned() <<
	std::endl;
	return (o);
}
#ifndef SHRUBBERYCREATIONFOM_H
# define SHRUBBERYCREATIONFOM_H

// Includes
#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

// classes

class Bureaucrat;

class From;

class ShrubberyCreationForm: public Form
{
	private:
		const std::string _target;
	// moved the default Constructor to private because subject asks for orthodox canonical form
	// but also asks for the Forms to only have one constructor that takes one argument
		ShrubberyCreationForm(void);
	public:
	// Constructors
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &src);

	// Deconstructors
		~ShrubberyCreationForm();

	// Overloaded Operators
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

	// Public Methods
		void execute(Bureaucrat const &executor)const;
	// Getter
		std::string getTarget(void)const;
	// Setter

};

// // ostream Overload
std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a);

#endif

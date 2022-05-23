#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H
// Includes
# include <string>
# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

// classes
class Bureaucrat;

class From;

class PresidentialPardonForm: public Form
{
	private:
		const std::string _target;
		PresidentialPardonForm(void);
	public:
	// Constructors
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &src);
	// Deconstructors
		~PresidentialPardonForm();
	// Overloaded Operators
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
	// Public Methods
		void execute(Bureaucrat const &executor)const;
	// Getter
		std::string getTarget(void)const;
};

// // ostream Overload
std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a);

#endif
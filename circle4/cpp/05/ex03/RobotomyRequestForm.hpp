#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H
// Includes
# include <string>
# include <iostream>
# include <cstdlib>
# include "Bureaucrat.hpp"
# include "Form.hpp"

// classes
class Bureaucrat;

class From;

class RobotomyRequestForm: public Form
{
	private:
		const std::string _target;
		RobotomyRequestForm(void);
	public:
	// Constructors
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &src);

	// Deconstructors
		~RobotomyRequestForm();

	// Overloaded Operators
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

	// Public Methods
		void execute(Bureaucrat const &executor)const;
	// Getter
		std::string getTarget(void)const;
};

// // ostream Overload
std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a);
#endif

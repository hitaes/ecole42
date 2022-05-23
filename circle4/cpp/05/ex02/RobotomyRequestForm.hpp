#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
    const std::string _target;
    RobotomyRequestForm();
public:
    // Constructor
    RobotomyRequestForm(const std::string target);
    RobotomyRequestForm(RobotomyRequestForm &copy);

    // Overloaded operator
    RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

    // Deconstructor
    ~RobotomyRequestForm();

    // Public Methods
	void execute(Bureaucrat const &executor)const;

    // Getter
    std::string getTarget()const;
};

// ostream Overload
std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a);

#endif
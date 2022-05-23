#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H
# include <string>
# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
    const std::string _target;
    ShrubberyCreationForm();
public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    ~ShrubberyCreationForm();

    // Overloaded Operators
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

	// Public Methods
	void execute(Bureaucrat const &executor)const;
	// Getter
	std::string getTarget(void)const;
};

// // ostream Overload
std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a);
#endif

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

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
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm &copy);

        // Deconstructor
        ~PresidentialPardonForm();

        // Overloaded operator
        PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

        // Public methods
        void execute(Bureaucrat const &executor)const;

        // Getter
        std::string getTarget()const;
};
// ostream Overload
std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm *a);

#endif

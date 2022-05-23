#ifndef FORM_H
# define FORM_H

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

// classes

class Bureaucrat;

class Form
{
protected:
    const std::string _name;
    bool _is_signed;
    const int _grade_for_sign;
    const int _grade_for_exec;
public:
    // Constructors
    Form();
    Form(const Form &copy);
    Form(const std::string name);
    Form(int grade_for_sign, int grade_for_exec);
    Form(const std::string name, int grade_for_sign, int grade_for_exec);

    // DeConstructors
    virtual ~Form();

    // Overloaded operator
    Form &operator=(const Form &src);

    // Public methods
    void beSigned(Bureaucrat &person);
    virtual void execute(Bureaucrat const &executor)const = 0;

    // Getter
    const std::string getName()const ;
    const std::string makeSign(void)const;
    bool isSigned()const ;
    int getGradeForSign()const ;
    int getGradeForExec()const ;

    // Exceptions
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
    class FormNotSignedException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
};
// ostream Overload
std::ostream &operator<<(std::ostream &o, Form *a);

#endif

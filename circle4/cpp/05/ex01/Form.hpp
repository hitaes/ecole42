#ifndef FORM_H
# define FORM_H

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
private:
    const std::string _name;
    bool _is_signed;
    const size_t _grade_to_sign;
    const size_t _grade_to_exec;
public:
    // Constructors
    Form();
    Form(const Form &copy);
    Form(const std::string name);
    Form(size_t grade_to_sign, size_t grade_to_exec);
    Form(const std::string name, size_t grade_to_sign, size_t grade_to_exec);
    // DeConstructor
    ~Form();
    // Overloaded operator
    Form &operator=(const Form &src);

    // Public methods
    void beSigned(Bureaucrat &signer);

    // Getter
    const std::string get_name()const;
    bool get_is_signed()const;
    const size_t get_grade_to_sign()const;
    const size_t get_grade_to_exec()const;

    // Exceptions
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
};

#endif
#include "Form.hpp"

Form::Form() : _name("default"), _is_signed(false), _grade_to_exec(150), _grade_to_sign(150)
{
    std::cout << "Form Default Constructor is called" << std::endl;
}
Form::Form(const Form &copy) : _name(copy.get_name() + "_copy"), _is_signed(false), _grade_to_exec(copy.get_grade_to_exec()), _grade_to_sign(copy.get_grade_to_sign())
{
    std::cout << "Form Copy Constructor is called" << std::endl;
    *this = copy;
}
Form::Form(const std::string name) : _name(name), _is_signed(false), _grade_to_exec(150), _grade_to_sign(150)
{
    std::cout << "Form name Constructor called for " << this->get_name() << 
    " with sign-grade of " << this->get_grade_to_sign() <<
	" and execution-grade of " << this->get_grade_to_exec() << std::endl;
    
}
Form::Form(size_t grade_to_sign, size_t grade_to_exec): _name("defualt"), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
    std::cout << "Form constructor is called with " << 
    grade_to_sign << " and " << 
    grade_to_exec << " values" << std::endl;
    const size_t gts = this->get_grade_to_sign();
    const size_t gte = this->get_grade_to_exec();
    if (gts < 1 || gte < 1)
    {
        throw(Form::GradeTooLowException());
    }
    else if (gts > 150 || gte > 150)
    {
        throw(Form::GradeTooHighException());
    }
}
Form::Form(const std::string name, size_t grade_to_sign, size_t grade_to_exec) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
    std::cout << "Form constructor is called with " << 
    name << " and " << 
    grade_to_sign << " and " << 
    grade_to_exec << " values" << std::endl;

    const size_t gts = this->get_grade_to_sign();
    const size_t gte = this->get_grade_to_exec();
    if (gts < 1 || gte < 1)
    {
        throw(Form::GradeTooLowException());
    }
    else if (gts > 150 || gte > 150)
    {
        throw(Form::GradeTooHighException());
    }
}
// DeConstructo
Form::~Form()
{
    std::cout << "Form Deconstructor is called" << std::endl;
}
// Overloaded operato
Form &Form::operator=(const Form &src)
{
    if (this == &src)
        return *this;
    return *this;
}
// Public method
void Form::beSigned(Bureaucrat &signer)
{}
// Getter
const std::string Form::get_name()const
{}
bool Form::get_is_signed()const
{}
const size_t Form::get_grade_to_sign()const
{}
const size_t Form::get_grade_to_exec()const
{}

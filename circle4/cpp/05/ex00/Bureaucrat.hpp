#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>

class Bureaucrat
{
private:
    const std::string _name;
    size_t _grade;

public:
    // Constructors
    Bureaucrat();
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat(const std::string name);
    Bureaucrat(int grade);
    Bureaucrat(const std::string name, int grade);

    // Overloaded Operators
    Bureaucrat &operator=(const Bureaucrat &src);

    // Deconstructor
    ~Bureaucrat();

    // Public Methods
    void incrementGrade(void);
	void decrementGrade(void);
    // Setter
    void setGrade(int grade);
	// Getter
	const std::string getName(void)const;
	size_t getGrade(void)const;

    //Exceptions
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
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);

#endif
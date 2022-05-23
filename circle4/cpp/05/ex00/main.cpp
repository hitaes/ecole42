#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "\033[36mConstructing\033[0m" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	Bureaucrat *test1 = new Bureaucrat();
	std::cout << std::endl;
	
	std::cout << "\033[34mTesting: Construction - Functional Case\033[0m" << std::endl;
	std::cout << test1;

	std::cout << "\033[34mTesting: Construction - MalFunctional Case(high)\033[0m" << std::endl;
	Bureaucrat *test2 = new Bureaucrat(0);
	std::cout << test2;

	std::cout << "\033[34mTesting: Construction - MalFunctional Case(low)\033[0m" << std::endl;
	Bureaucrat *test3 = new Bureaucrat(151);
	std::cout << test3;

	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "\033[36mExceptions\033[0m" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "\033[34mTesting: Exceptions - Functional Case\033[0m" << std::endl;
	try
	{
		test1->incrementGrade();
		std::cout << test1;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "\033[33mIncrementing grade of " << test1->getName() <<
		" failed: " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "\033[34mTesting: Exceptions - Functional Case\033[0m" << std::endl;
	try
	{
		test1->decrementGrade();
		std::cout << test1;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "\033[33mIncrementing grade of " << test1->getName() <<
		" failed: " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "\033[34mTesting: Exceptions - MalFunctional Case(low)\033[0m" << std::endl;
	try
	{
		test1->decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "\033[33mDecrementing grade of " << test1->getName() <<
		" failed: " << e.what() << "\033[0m" << std::endl;
	}
	
	std::cout << "\033[34mTesting: Exceptions - MalFunctional Case(high)\033[0m" << std::endl;
	test1->setGrade(1);
	try
	{
		test1->incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "\033[33mIncrementing grade of " << test1->getName() <<
		" failed: " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	delete test1;
	delete test2;
	delete test3;
	std::cout << std::endl;
}
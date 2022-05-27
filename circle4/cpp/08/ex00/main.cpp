#include "easyfind.hpp"
#include <list>

int main()
{

    std::list<int> dummy;
    std::list<int>::const_iterator	it;
    bool existing = false;

    dummy.push_back(1);
    dummy.push_back(2);
    dummy.push_back(3);

    //// Functional
    try
    {
        it = easyfind(dummy, 3);
        existing = true;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (existing)
		std::cout << *it << " found" << std::endl;

    //// Functional
    existing = false;
	try
    {
        it = easyfind(dummy, 1);
        existing = true;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (existing)
		std::cout << *it << " found" << std::endl;

    //// MalFunctional
    existing = false;
	try
    {
        it = easyfind(dummy, 4);
        existing = true;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (existing)
		std::cout << *it << " found" << std::endl;

	return (0);
}
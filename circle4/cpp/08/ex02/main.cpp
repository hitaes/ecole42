#include "MutantStack.hpp"

int main()
{
	MutantStack<std::string> mstack_string;
	mstack_string.push("Five");
	mstack_string.push("Three");
	mstack_string.push("Seven hundred thirty-seven");

    MutantStack<std::string>::iterator s_it = mstack_string.begin();
	MutantStack<std::string>::iterator e_it = mstack_string.end();

	++s_it;
	--s_it;
	std::cout << "String Iterator: ";
	while (s_it != e_it)
	{
		std::cout << *s_it << ", ";
		++s_it;
	}

	std::cout << std::endl << std::endl << "Size: " << mstack_string.size() << "\nEmpty: " << (mstack_string.empty() ? "true" : "false") << std::endl;
	mstack_string.pop();
	mstack_string.pop();
	mstack_string.pop();
	std::cout << std::endl << std::endl << "Size: " << mstack_string.size() << "\nEmpty: " << (mstack_string.empty() ? "true" : "false") << std::endl;
    return 0;
}
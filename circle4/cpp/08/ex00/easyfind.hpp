#ifndef EASYFIND_H
# define EASYFIND_H

#include <exception>

class NotFoundException : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return ("Not Found");
        }
};

template< typename T >
typename T::iterator easyfind(T &in, int i)
{
    typename T::iterator	it;
	it = find(in.begin(), in.end(), i);
	if (it == in.end())
	{
		throw (NotFoundException());
	}
	return (it);
}

#endif
#ifndef EASYFIND_H
# define EASYFIND_H

#include <algorithm>
#include <iterator>
#include <iostream>
#include <exception>

class NotFoundException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return ("Not found");
        }
};

template< typename T >
typename T::iterator easyfind(T &arr, int operand)
{
    typename T::iterator result = find(arr.begin(), arr.end(), operand);
    if (result == arr.end())
    {
        throw (NotFoundException());
    }
    return result;
}

#endif
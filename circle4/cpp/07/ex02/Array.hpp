#ifndef ARRAY_H
# define ARRAY_H

#include <cstddef>
#include <exception>
#include <iostream>

template< typename T >
class Array
{
private:
    T *_array;
    unsigned int _size;
public:
// Constructors
    Array(): _size(0)
    {
        std::cout << "Default Constructor called: created empty Array of size 0" << std::endl;
        this->_array = new T[this->_size];
    }
    Array(unsigned int size): _size(size)
    {
        std::cout << "Constructor called: created Array of size " << size << std::endl;
        this->_array = new T[this->_size];
    }
    Array(const Array &src): _size(src.getSize())
    {
        std::cout << "Copy Constructor called" << std::endl;
        this->_array = NULL;
        *this = src;
    }
// Deconstructors
    ~Array()
    {
        if (this->_array != NULL)
            delete [] this->_array;
    }
// Overloaded Operator
    Array &operator=(const Array &src)
    {
        if (this->_array != NULL)
            delete [] this->_array;
        if (src.getSize() != 0)
        {
            this->_size = src.getSize();
            this->_array = new T[this->_size];
            for (unsigned int i = 0; i < this->getSize(); i++)
                this->_array[i] = src._array[i];
        }
        return (*this);
    }

    T &operator[]( unsigned int index )
    {
        if (index >= this->_size || this->_array == NULL)
        {
            std::cout << "index: " << index << std::endl;
            throw Array<T>::InvalidIndexException();
        }
        return (this->_array[index]);
    }

// Exception
    class InvalidIndexException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

// Getter
    unsigned int getSize() const
    {
        return (this->_size);
    }
};

template< typename T >
const char	*Array<T>::InvalidIndexException::what() const throw()
{
	return ("Error: Invalid index");
}

template <typename T>
void test(std::size_t size) {
  Array<T> a(size);

  std::cout << "Value Testing Ascending" << std::endl;
  for (std::size_t i = 0 ; i < size ; ++i) {
    a[i] = static_cast<T>(i + '0');
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Value Testing Descending" << std::endl;
  for (std::size_t i = 0 ; i < size ; ++i) {
    a[i] = static_cast<T>(size - i - 1 + '0');
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Exception Testing" << std::endl;
  try {
    std::cout << a[size] << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}
#endif



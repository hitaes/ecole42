#include "Fixed.hpp"

const int Fixed::_fractionalBit = 8;

Fixed::Fixed() : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed){
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}
Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed &source){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &source) {
        return *this;
    }
    _rawBits = source.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}
void Fixed::setRawBits(int const raw){
     std::cout << "setRawBits member function is called" << std::endl;
    this->_rawBits = raw;
}

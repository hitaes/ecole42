#include "Fixed.hpp"

const int Fixed::_fractionalBit = 8;

Fixed::Fixed() 
    : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) 
    : _rawBits(value << _fractionalBit) {
    std::cout << "Int constructor called" << std::endl;
    this->_rawBits = value << this->_fractionalBit;
}

Fixed::Fixed(const float value) {
  std::cout << "Float constructor called" << std::endl;
  this->_rawBits = roundf(value * (1 << this->_fractionalBit));
}

Fixed::Fixed(const Fixed& fixed){
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

float Fixed::toFloat(void) const {
  return ((float)this->_rawBits / (float)(1 << this->_fractionalBit));
}

int Fixed::toInt(void) const {
  return this->_rawBits >> this->_fractionalBit;
}

int Fixed::getRawBits(void) const {
    return this->_rawBits;
}
void Fixed::setRawBits(int const raw){
    this->_rawBits = raw;
}

std::ostream& operator << (std::ostream& outStream,
                           const Fixed& object) {
  outStream << object.toFloat();
  return outStream;
}
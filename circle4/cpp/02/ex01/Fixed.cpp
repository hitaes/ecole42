#include "Fixed.hpp"

const int Fixed::_fractionalBit = 8;

Fixed::Fixed() 
    : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int& value) 
    : _rawBits(value << _fractionalBit) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float& value) {
  std::cout << "Float constructor called" << std::endl;
  const int scailingFactor(1 << _fractionalBit);
  _rawBits = static_cast<int>(roundf(value * scailingFactor));
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
  const int scailingFactor(1 << _fractionalBit);
  return (static_cast<float>(_rawBits) / scailingFactor);
}

int Fixed::toInt(void) const {
  return _rawBits >> _fractionalBit;
}

int Fixed::getRawBits(void) const {
    return _rawBits;
}
void Fixed::setRawBits(int const raw){
    this->_rawBits = raw;
}

std::ostream& operator << (std::ostream& outStream,
                           const Fixed& object) {
  outStream << object.toFloat();
  return outStream;
}
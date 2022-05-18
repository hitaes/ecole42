#include "Fixed.hpp"

const int Fixed::_fractionalBit = 8;

Fixed::Fixed() 
    : _rawBits(0) {
}

Fixed::Fixed(const int value) 
    : _rawBits(value << _fractionalBit) {
    this->_rawBits = value << this->_fractionalBit;
}

Fixed::Fixed(const float value) {
  this->_rawBits = roundf(value * (1 << this->_fractionalBit));
}

Fixed::Fixed(const Fixed& fixed){
    *this = fixed;
}

Fixed::~Fixed(){
}

Fixed& Fixed::operator = (const Fixed &source){
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

bool Fixed::operator>(Fixed fixed)const
{
    return (this->toFloat() > fixed.toFloat());
}
bool Fixed::operator<(Fixed fixed)const
{
    return (this->toFloat() < fixed.toFloat());
}
bool Fixed::operator>=(Fixed fixed)const
{
    return (this->toFloat() >= fixed.toFloat());
}
bool Fixed::operator<=(Fixed fixed)const
{
    return (this->toFloat() <= fixed.toFloat());
}
bool Fixed::operator==(Fixed fixed)const
{
    return (this->toFloat() == fixed.toFloat());
}
bool Fixed::operator!=(Fixed fixed)const
{
    return (this->toFloat() != fixed.toFloat());
}
float Fixed::operator+(Fixed fixed)const
{
    return (this->toFloat() + fixed.toFloat());
}
float Fixed::operator-(Fixed fixed)const
{
    return (this->toFloat() - fixed.toFloat());
}
float Fixed::operator*(Fixed fixed)const
{
    return (this->toFloat() * fixed.toFloat());
}
float Fixed::operator/(Fixed fixed)const
{
    return (this->toFloat() / fixed.toFloat());
}
Fixed Fixed::operator++()
{
    this->_rawBits++;
    return (*this);
}
Fixed Fixed::operator--()
{
    this->_rawBits--;
    return (*this);
}
Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    ++this->_rawBits;
    return (tmp);
}
Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
	--this->_rawBits;
    return (tmp);
}

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}
#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
private:
    int _rawBits;
    static const int _fractionalBit;

public:
    Fixed();
    Fixed(const int& value);
    Fixed(const float& value);
    Fixed(const Fixed& fixed);
    ~Fixed();

    Fixed& operator = (const Fixed &source);

    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif

std::ostream& operator << (std::ostream& outStream,
                           const Fixed& object);
#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
private:
    int _rawBits;
    static const int _fractionalBit;

public:
    Fixed();
    Fixed(const Fixed &fixed);
    ~Fixed();

    Fixed& operator = (const Fixed &source);

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif

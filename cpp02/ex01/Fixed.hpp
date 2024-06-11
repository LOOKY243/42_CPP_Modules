#ifndef FIXED_HPP
#   define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _num;
        const static int _nFractional;
    public:
        Fixed(void);
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();

        int toInt(void) const;
        float toFloat(void) const;

        std::ostream &print(std::ostream &os) const;

};

std::ostream &operator<<(std::ostream &os, const Fixed &other);

#endif
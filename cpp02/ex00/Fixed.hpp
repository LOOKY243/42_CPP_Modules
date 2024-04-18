#ifndef FIXED_HPP
#   define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int _num;
        const static int _nFractional;
    public:
        Fixed(void);
        Fixed(const int num);
        Fixed(const float num);
        const float &operator=(const float num);

        ~Fixed();
};

#endif
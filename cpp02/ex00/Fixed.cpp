#include "Fixed.hpp"

const int Fixed::_nFractional = 8;

Fixed::Fixed(void): _num(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other): _num(other._num)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &ref)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_num = ref.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _num;
}

void Fixed::setRawBits(int const raw)
{
    _num = raw;
}
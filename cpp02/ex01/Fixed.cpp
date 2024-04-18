#include "Fixed.hpp"

const int Fixed::_nFractional = 8;

Fixed::Fixed(): _num(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num): _num(num << _nFractional)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num): _num(roundf(num * (1 << _nFractional)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_num = other._num;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_num = other._num;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

std::ostream &Fixed::print(std::ostream &os) const {
    os << toFloat();
    return os;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    return fixed.print(os);
}

int Fixed::toInt() const
{
    return _num >> _nFractional;
}

float Fixed::toFloat() const
{
    return static_cast<float>(_num) / (1 << _nFractional);
}
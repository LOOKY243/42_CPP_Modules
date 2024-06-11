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

bool    Fixed::operator>(const Fixed &other) const
{
    return _num > other._num;
}

bool    Fixed::operator<(const Fixed &other) const
{
    return _num < other._num;
}

bool    Fixed::operator==(const Fixed &other) const
{
    return _num == other._num;
}

bool    Fixed::operator!=(const Fixed &other) const
{
    return _num != other._num;
}

bool    Fixed::operator<=(const Fixed &other) const
{
    return _num <= other._num;
}

bool    Fixed::operator>=(const Fixed &other) const
{
    return _num >= other._num;
}

Fixed Fixed::operator+(const Fixed &other)
{
    return toFloat() + other.toFloat();
}

Fixed Fixed::operator-(const Fixed &other)
{
    return toFloat() - other.toFloat();
}

Fixed Fixed::operator*(const Fixed &other)
{
    return toFloat() * other.toFloat();
}

Fixed Fixed::operator/(const Fixed &other)
{
    return toFloat() / other.toFloat();
}

Fixed &Fixed::operator++()
{
    _num++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    _num++;
    return tmp;
}

Fixed &Fixed::operator--()
{
    _num--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    _num--;
    return tmp;
}

const Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) 
{
    return (a > b) ? a : b;
}
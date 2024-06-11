#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat Default constructor has been called" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    type = other.type;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    type = other.type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

void    WrongCat::makeSound() const
{
    std::cout << "Wrong cat sounds..." << std::endl;
}

std::string WrongCat::getType()
{
    return type;
}
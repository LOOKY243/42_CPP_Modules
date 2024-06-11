#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
    std::cout << "WrongCat Default constructor has been called" << std::endl;
}

WrongCat::WrongCat(std::string _type): WrongAnimal(type)
{
    std::cout << "WrongCat parameterized constructor has been called" << std::endl;
}

WrongCat::WrongCat(WrongCat &other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    WrongAnimal::type = other.type;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    WrongAnimal::type = other.type;
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
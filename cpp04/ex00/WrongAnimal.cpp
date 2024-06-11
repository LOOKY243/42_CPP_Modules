#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
    std::cout << "WrongAnimal Default constructor has been called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &other)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    type = other.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    type = other.type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

std::string WrongAnimal::getType()
{
    return type;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "Wrong animal sounds..." << std::endl;
}
#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
    std::cout << "Animal Default constructor has been called" << std::endl;
}

Animal::Animal(Animal &other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    type = other.type;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    type = other.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

void    Animal::makeSound() const 
{
    std::cout << "Unknown Animal Sounds" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}
#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Default constructor has been called" << std::endl;
    type = "Dog";
}

Dog::Dog(Dog &other): Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}
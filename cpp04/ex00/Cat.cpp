#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat Default constructor has been called" << std::endl;
    type = "Cat";
}

Cat::Cat(Cat &other): Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

void    Cat::makeSound() const
{
    std::cout << "Miau Miau" << std::endl;
}
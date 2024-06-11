#include "Ice.hpp"

Ice::Ice()
{
    _type = "ice";
    std::cout << "Ice Default Constructor has been called" << std::endl;
}

Ice::Ice(const Ice &other)
{
    std::cout << "Ice Copy Constructor has been called" << std::endl;
    _type = other._type;
}

Ice &Ice::operator=(const Ice &other)
{
    std::cout << "Ice Copy Assignment operator has been called" << std::endl;
    _type = other._type;
    return (*this);
}

Ice::~Ice()
{
    std::cout << "Ice Destructor has been called" << std::endl;
}

AMateria *Ice::clone() const
{
    return new Ice();
}

void    Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
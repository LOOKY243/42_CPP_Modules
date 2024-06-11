#include "Cure.hpp"

Cure::Cure()
{
    _type = "cure";
    std::cout << "Cure Default Constructor has been called" << std::endl;
}

Cure::Cure(const Cure &other)
{
    _type = other._type;
    std::cout << "Cure Copy Constructor has been called" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
    std::cout << "Cure Copy Assignment operator has been called" << std::endl;
    _type = other._type;
    return (*this);
}

Cure::~Cure()
{
    std::cout << "Cure Destructor has been called" << std::endl;
}

AMateria *Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
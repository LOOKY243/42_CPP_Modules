#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "AMateria Default Constructor has been called" << std::endl;
    _type = "None";
}

AMateria::AMateria(std::string const &type)
{
    std::cout << "AMateria Parameterized constructor has been called" << std::endl;
    _type = type;
}

AMateria::AMateria(const AMateria &other)
{
    std::cout << "AMateria copy constructor has been called" << std::endl;
    _type = other._type;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    std::cout << "AMateria assignement operator has been called" << std::endl;
    _type = other._type;
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria Destructor has been called" << std::endl;
}

std::string const &AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter &target)
{
    (void)target;
}

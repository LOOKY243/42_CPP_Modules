#include "Weapon.hpp"

Weapon::Weapon(void): _type("Default")
{
}

Weapon::Weapon(std::string type)
{
    _type = type;
}

Weapon::~Weapon(void)
{
}

void    Weapon::setType(std::string type)
{
    _type = type;
}

const std::string &Weapon::getType(void) const
{
    return (_type);
}
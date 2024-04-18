#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    weaponB = NULL;
    _name = name;
}

HumanB::~HumanB()
{
}

void    HumanB::attack(void)
{
    std::cout << _name << " attacks with their " << weaponB->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    delete weaponB;
    weaponB = &weapon;
}
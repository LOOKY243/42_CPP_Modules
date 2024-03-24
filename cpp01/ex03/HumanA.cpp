#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
{
    _name = name;
    weaponA = &weapon;
}

HumanA::~HumanA()
{
}

void    HumanA::attack(void)
{
    std::cout << _name << " attacks with their " << weaponA->getType() << std::endl;
}
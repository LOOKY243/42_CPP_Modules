#include "Zombie.hpp"

Zombie::Zombie(void)
{
}

Zombie::Zombie(std::string name)
{
    _name = name;
}

Zombie::~Zombie()
{
    std::cout << _name << " has been destroyed" << std::endl;
}

void    Zombie::announce(void)
{
    if (_name.empty())
        return ;
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
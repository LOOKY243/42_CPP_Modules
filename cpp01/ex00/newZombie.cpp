#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie* nZombie = new Zombie(name);

    nZombie->announce();
    return (nZombie);
}
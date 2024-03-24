#include "Zombie.hpp"

Zombie* ZombieHorde(int N, std::string name)
{
    if (N < 1)
    {
        std::cout << "The Number of zombies can't be less than 1" << std::endl;
        return NULL;
    }
    if (name.empty())
    {
        std::cout << "The name can't be blank" << std::endl;
        return NULL;
    }
    Zombie *Horde = new Zombie[N];
    for (int i = 0; i < N; i++)
        Horde[i] = Zombie(name);
    return Horde;
}
#include "Zombie.hpp"

int main(void)
{
    Zombie MyZombie("Au revoir");
    Zombie* Horde = ZombieHorde(5, "Merci");
    MyZombie.announce();
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << "[" << i << "]";
        Horde[i].announce();
    }
    delete  [] Horde;
    return (0);
}
#include "Zombie.hpp"

int main(void)
{
    int num = 5;
    Zombie MyZombie("Hasboulla");
    Zombie* Horde = ZombieHorde(num, "Abdel");
    
    MyZombie.announce();
    for (int i = 0; i < num; i++)
        Horde[i].announce();
    delete  [] Horde;
    return (0);
}
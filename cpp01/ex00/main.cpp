#include "Zombie.hpp"

int main(void)
{
    Zombie MyZombie("camille");
    Zombie* pZombie = newZombie("chloe");
    MyZombie.announce();
    randomChump("sophia");
    delete(pZombie);
    return (0);
}
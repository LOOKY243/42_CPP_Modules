#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("a", 20, 10, 5);
    ClapTrap b("b", 25, 5, 5);

    b.attack(a.getName());
    a.takeDamage(b.getAd());
    a.attack(b.getName());
    a.beRepaired(1);
}
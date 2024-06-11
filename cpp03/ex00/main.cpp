#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("a", 20, 10, 5);
    ClapTrap b("b", 25, 5, 5);

    b.attack(a.getName());
    a.takeDamage(b.getAd());
    a.attack(b.getName());
    b.takeDamage(a.getAd());
    a.beRepaired(1);
    for (int i = 0; i < 6; i++)
    {
        b.attack(a.getName());
        a.takeDamage(b.getAd());
        std::cout << "hp: " << a.getHpoints() << std::endl;
    }
    b.beRepaired(1);
}
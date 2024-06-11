#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();

    Weapon s_club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(s_club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();

    club.setType("weird gun that doesn't even do any damage...");
    bob.attack();
    return 0;
}
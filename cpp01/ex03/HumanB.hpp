#include "Weapon.hpp"

class HumanB
{
private:
    std::string _name;
    Weapon *weaponB;
public:
    HumanB(std::string name);
    ~HumanB(void);
    void    attack(void);
    void    setWeapon(Weapon weapon);
};

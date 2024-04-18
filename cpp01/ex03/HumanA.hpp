#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon  *weaponA;
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);
        void    attack(void);
};

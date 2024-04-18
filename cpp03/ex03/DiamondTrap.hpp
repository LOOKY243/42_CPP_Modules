#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: virtual public ScavTrap, virtual public FragTrap
{
    private:
        std::string _name;
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &other);
        DiamondTrap &operator=(const DiamondTrap &other);
        ~DiamondTrap();

        void    whoAmI(void);

        using ScavTrap::attack;
        using FragTrap::takeDamage;
        using ClapTrap::beRepaired;
        using FragTrap::highFivesGuys;
        using ScavTrap::guardGate;
};


#endif
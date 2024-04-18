#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap: public ClapTrap
{
    private:
        
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap &other);
        FragTrap &operator=(const FragTrap &other);
        
        ~FragTrap();

        void    highFivesGuys(void);
};


#endif
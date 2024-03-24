#ifndef ZOMBIE_HPP  
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    private:
        std::string _name;

    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie();
        void    announce(void);
};

Zombie* ZombieHorde(int N, std::string name);

#endif
#ifndef WRONGCAT_H
# define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(std::string _type);
        WrongCat(WrongCat &other);
        WrongCat &operator=(const WrongCat &other);

        ~WrongCat();

        void makeSound() const;
};


#endif
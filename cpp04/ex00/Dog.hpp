#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"

class Dog: public Animal
{
    public:
        Dog();
        Dog(Dog &other);
        Dog &operator=(const Dog &other);

        virtual ~Dog();

        void    makeSound() const;
};


#endif
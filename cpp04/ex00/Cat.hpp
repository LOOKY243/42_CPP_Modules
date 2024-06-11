#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"

class Cat: public Animal
{
    public:
        Cat();
        Cat(Cat &other);
        Cat &operator=(const Cat &other);

        virtual ~Cat();

        void makeSound() const;
};


#endif
#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
    private:
        Brain *_dogBrain;
    public:
        Dog();
        Dog(Dog &other);
        Dog &operator=(const Dog &other);

        virtual ~Dog();

        void    makeSound() const;
        void    setIdea(std::string idea, int i) const;
        std::string    getIdea(int i) const;
};

#endif
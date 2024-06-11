#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(Animal &other);
        Animal &operator=(const Animal &other);

        virtual ~Animal();

        virtual void    makeSound() const;
        virtual void    setIdea(std::string idea, int i) const;
        virtual std::string    getIdea(int i) const;
        std::string getType() const;
};

#endif

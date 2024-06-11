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
        Animal(std::string _type);
        Animal(Animal &other);
        Animal &operator=(const Animal &other);

        virtual ~Animal();

        virtual void    makeSound() const = 0;
        virtual void    setIdea(std::string idea, int i) const = 0;
        virtual std::string    getIdea(int i) const = 0;
        std::string getType() const;
};

#endif

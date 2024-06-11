#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(std::string _type);
        WrongAnimal(WrongAnimal &other);
        WrongAnimal &operator=(const WrongAnimal &other);

        virtual ~WrongAnimal();

        void makeSound() const;
};

#endif
#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
    private:
        Brain *_catBrain;
    public:
        Cat();
        Cat(Cat &other);
        Cat &operator=(const Cat &other);

        virtual ~Cat();

        void    makeSound() const;
        void    setIdea(std::string idea, int i) const;
        std::string    getIdea(int i) const;
};


#endif
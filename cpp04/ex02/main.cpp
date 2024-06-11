#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    // Animal bruh;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* x = new WrongCat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << "\nCopy called" << std::endl;
    Dog test;
    Dog tmp = test;

    i->makeSound();
    j->makeSound();
    x->makeSound();

    for (int k = 0; k < 100; k++)
    {
        j->setIdea("Good idea", k);
        i->setIdea("Bad idea", k);
    }
    for (int k = 0; k < 100; k++)
    {
        std::cout << k << j->getIdea(k) << std::endl;
        std::cout << k << i->getIdea(k) << std::endl;
    }
 
    delete j;
    delete i;
    delete x;

    return 0;
}
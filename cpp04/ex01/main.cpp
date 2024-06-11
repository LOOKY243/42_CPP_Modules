#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal bruh;
    std::cout << "---------" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* x = new WrongCat();

    std::cout << "\nCopy called" << std::endl;
    Dog test;
    Dog tmp = test;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();
    x->makeSound();

    for (int k = 0; k < 100; k++)
    {
        j->setIdea("Good idea", k);
        i->setIdea("Bad idea", k);
    }
    std::cout << "--------------------" << std::endl;
    for (int k = 0; k < 100; k++)
    {
        std::cout << k << " " << j->getIdea(k) << std::endl;
        std::cout << k << " " << i->getIdea(k) << std::endl;
    }
    std::cout << "--------------------" << std::endl;
    for (int k = 0; k < 10; k++)
    {
        j->setIdea("BRUH HAS NO IDEA LEFT", k);
    }
    for (int k = 0; k < 11; k++)
    {
        std::cout << k << " " << j->getIdea(k) << std::endl;
        std::cout << k << " " << i->getIdea(k) << std::endl;
    }

    j->setIdea("jciwenwjie", -1);

    delete j;
    delete i;
    delete x;

    return 0;
}
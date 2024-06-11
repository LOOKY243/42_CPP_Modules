#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat Default constructor has been called" << std::endl;
    type = "Cat";
    _catBrain = new Brain();
}

Cat::Cat(Cat &other): Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    _catBrain = new Brain();
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        _catBrain = new Brain();
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
    delete _catBrain;
}

void    Cat::makeSound() const
{
    std::cout << "Miau Miau" << std::endl;
}

void    Cat::setIdea(std::string idea, int i) const
{
    if (i > 99)
    {
        std::cout << "Brain can't handle more than 100 ideas" << std::endl;
        return ;
    }
    _catBrain->setIdea(idea, i);
}

std::string    Cat::getIdea(int i) const
{
    if (i > 99)
    {
        std::cout << "Brain can't handle more than 100 ideas" << std::endl;
        return (NULL);
    }
    return _catBrain->getIdea(i);
}
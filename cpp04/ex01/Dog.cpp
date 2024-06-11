#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Default constructor has been called" << std::endl;
    type = "Dog";
    _dogBrain = new Brain();
}

Dog::Dog(Dog &other): Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    _dogBrain = new Brain();
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        _dogBrain = new Brain();
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
    delete _dogBrain;
}

void    Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}

void    Dog::setIdea(std::string idea, int i) const
{
    if (i > 99)
    {
        std::cout << "Brain can't handle more than 100 ideas" << std::endl;
        return ;
    }
    _dogBrain->setIdea(idea, i);
}

std::string    Dog::getIdea(int i) const
{
    if (i > 99)
    {
        std::cout << "Brain can't handle more than 100 ideas" << std::endl;
        return (NULL);
    }
    return _dogBrain->getIdea(i);
}
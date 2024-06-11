#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default constructor has been called" << std::endl;
}

Brain::Brain(std::string ideas[100])
{
    std::cout << "Brain parameterized constructor has been called" << std::endl;
    for (int i = 0; !ideas[i].empty(); i++)
        _ideas[i] = ideas[i];
}

Brain::Brain(Brain &other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; !other._ideas[i].empty(); i++)
        _ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(Brain &other)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    for (int i = 0; !other._ideas[i].empty(); i++)
        _ideas[i] = other._ideas[i];
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}

void    Brain::setIdea(std::string idea, int i)
{
    if (i >= 100)
    {
        std::cout << "My Brain can only handle 100 ideas or i'll brunout" << std::endl;
        return ;
    }
    if (i < 0)
    {
        std::cout << "Negative number isn't a valid idea slot" << std::endl;
        return ;
    }
    _ideas[i] = idea;
}

std::string    Brain::getIdea(int i)
{
    return _ideas[i];
}
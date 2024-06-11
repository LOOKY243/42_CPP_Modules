#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
    private:
        std::string _ideas[100];
    public:
        Brain();
        Brain(std::string ideas[100]);
        Brain (Brain &other);
        Brain &operator=(Brain &other);

        ~Brain();

        void    setIdea(std::string idea, int i);
        std::string    getIdea(int i);
};

#endif
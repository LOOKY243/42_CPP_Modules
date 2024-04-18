#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl()
{
}

void    Harl::debug(void)
{
    std::cout <<  "I love having extra bacon for my 7XL-double-cheese-triple"
        << "-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money."
        << "You didn't put enough bacon in my burger! "
        << "If you did, I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. "
        << "I've been coming for years whereas you started working here"
        << "since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    void (Harl::*functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int lvl = 4;
    
    for (int i = 0; i < 4; i++)
    {
        if (names[i] == level)
        {
            lvl = i;
            break;
        }
    }
    switch (lvl)
    {
        case 0:
            (*this.*functions[0])();
            (*this.*functions[1])();
            (*this.*functions[2])();
            (*this.*functions[3])();
            break;
        case 1:
            (*this.*functions[1])();
            (*this.*functions[2])();
            (*this.*functions[3])();
            break;
        case 2:
            (*this.*functions[2])();
            (*this.*functions[3])();
            break;
        case 3:
            (*this.*functions[3])();
            break;
    }
}
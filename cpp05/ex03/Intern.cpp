#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(std::string str)
{
    (void)str;
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string forms[4] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        if (i == 3)
            break;
        if (name == forms[i])
            break;
    }
    switch (i)
    {
        case 0:
            std::cout << "Intern creates " + name << std::endl;
            return new ShrubberyCreationForm(target);
            break;
        case 1:
            std::cout << "Intern creates " + name << std::endl;
            return new RobotomyRequestForm(target);
        case 2:
            std::cout << "Intern creates " + name << std::endl;
            return new PresidentialPardonForm(target);
        default:
            std::cout << "Intern can't create " + name << std::endl;
            return NULL;
            break; 
    }
}


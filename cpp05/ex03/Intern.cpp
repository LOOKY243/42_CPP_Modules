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
    if (name == "ShrubberyCreationForm")
    {
        std::cout << "Intern creates " + name << std::endl;
        return new ShrubberyCreationForm(target);
    }
    else if (name == "RobotomyRequestForm")
    {
        std::cout << "Intern creates " + name << std::endl;
        return new RobotomyRequestForm(target);
    }
    else if (name == "PresidentialPardonForm")
    {
        std::cout << "Intern creates " + name << std::endl;
        return new PresidentialPardonForm(target);
    }
    std::cout << "Intern can't create " + name << std::endl;
    return NULL;
}


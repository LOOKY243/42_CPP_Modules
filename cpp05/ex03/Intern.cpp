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

AForm *Intern::newShrubbery(std::string name, std::string target)
{
    std::cout << "Intern creates " + name << std::endl;
    return new ShrubberyCreationForm(target);
}

AForm *Intern::newRobotomy(std::string name, std::string target)
{
    std::cout << "Intern creates " + name << std::endl;
    return new RobotomyRequestForm(target);
}

AForm *Intern::newPresidential(std::string name, std::string target)
{
    std::cout << "Intern creates " + name << std::endl;
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(Intern::*func[3])(std::string name, std::string target) = {&Intern::newShrubbery, &Intern::newRobotomy, &Intern::newPresidential };
    for (int i = 0; i < 3; i++)
    {
        if (name == forms[i])
            return (this->*func[i])(name, target);
    }
    return NULL;
}
#ifndef INTERN_HPP
# define INTERN_HPP

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
    public:

        Intern();
        Intern(std::string str);
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);

        ~Intern();

        AForm *makeForm(std::string name, std::string target);
        AForm *newShrubbery(std::string name, std::string target);
        AForm *newRobotomy(std::string name, std::string target);
        AForm *newPresidential(std::string name, std::string target);
};

#endif
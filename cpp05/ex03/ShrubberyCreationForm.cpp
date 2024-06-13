#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137)
{
    _target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137)
{
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other)
{
    _target = other._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this == &other)
        return *this;
    AForm::operator=(other);
    _target = other._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
    if (executor.getGrade() <= getGradeExec())
    {
        std::ofstream outputFile((_target + "_shrubbery").c_str());
        std::string trees = 
            "         ,@@@@@@@,\n"
            "  ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
            ",&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
            ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
            "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
            "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
            "`&%\\ ` /%&'    |.|        \\ '|8'\n"
            "    |o|        | |         | |\n"
            "    |.|        | |         | |\n"
            " \\\\// ._\\\\//_/__/  ,\\\\_//__\\\\/.  \\\\_//__/_\n";
        if (!outputFile.is_open())
        {
            std::cerr << "Error: Unable to create output file." << std::endl;
            return ;
        }
        outputFile << trees << std::endl;
        outputFile.close();
    }
    else
        std::cout << "Grade isn't high enough to execute the form" << std::endl;
}
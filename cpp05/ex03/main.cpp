#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{
    ShrubberyCreationForm Sform;
    RobotomyRequestForm Rform;
    PresidentialPardonForm Pform;
    Bureaucrat Pablo("Pablo", 1);
    Bureaucrat failure("Failure", 140);

    Sform.beSigned(Pablo);
    Sform.execute(Pablo);
    std::cout << "-----------------------" << std::endl;
    Rform.beSigned(Pablo);
    Rform.execute(Pablo);
    Rform.execute(Pablo);
    Rform.execute(Pablo);
    std::cout << "-----------------------" << std::endl;
    Rform.beSigned(failure);
    Rform.execute(failure);
    std::cout << "-----------------------" << std::endl;
    Pform.beSigned(failure);
    Pform.execute(failure);

    std::cout << "-------------------------\n" << std::endl;
    Intern intern;
    AForm *form1 = intern.makeForm("PresidentialPardonForm", "Yomama");
    form1->beSigned(Pablo);
    form1->execute(Pablo);

    delete form1;
}
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void SNoSign()
{
	try {
		std::cout << "\x1b[1;37m--- Can't Sign ---\x1b[0m" << std::endl;
		Bureaucrat bureaucrat("Michel", 146);
		std::cout << bureaucrat << std::endl;
		ShrubberyCreationForm form("Me");
		std::cout << form << std::endl;
		form.beSigned(bureaucrat);
		form.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
	}
}

void SNoSignExec()
{
	try {
		std::cout << "\x1b[1;37m--- Not Signed ---\x1b[0m" << std::endl;
		Bureaucrat bureaucrat("Michel", 137);
		std::cout << bureaucrat << std::endl;
		ShrubberyCreationForm form("Me");
		std::cout << form << std::endl;
		form.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
	}
}

void SNoExec()
{
	try {
		std::cout << "\x1b[1;37m--- Can't Execute ---\x1b[0m" << std::endl;
		Bureaucrat bureaucrat("Michel", 144);
		std::cout << bureaucrat << std::endl;
		ShrubberyCreationForm form("Me");
		std::cout << form << std::endl;
		form.beSigned(bureaucrat);
		form.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
	}
}

void SNormal()
{
	try {
		std::cout << "\x1b[1;37m--- All Good ---\x1b[0m" << std::endl;
		Bureaucrat bureaucrat("Michel", 137);
		std::cout << bureaucrat << std::endl;
		ShrubberyCreationForm form("Me");
		std::cout << form << std::endl;
		form.beSigned(bureaucrat);
		form.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
	}
}

void RNoSign()
{
	try {
		std::cout << "\x1b[1;37m--- Can't Sign ---\x1b[0m" << std::endl;
		Bureaucrat bureaucrat("Michel", 73);
		std::cout << bureaucrat << std::endl;
		RobotomyRequestForm form("Me");
		std::cout << form << std::endl;
		form.beSigned(bureaucrat);
		form.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
	}
}

void RNoSignExec()
{
	try {
		std::cout << "\x1b[1;37m--- Not Signed ---\x1b[0m" << std::endl;
		Bureaucrat bureaucrat("Michel", 45);
		std::cout << bureaucrat << std::endl;
		RobotomyRequestForm form("Me");
		std::cout << form << std::endl;
		form.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
	}
}

void RNoExec()
{
	try {
		std::cout << "\x1b[1;37m--- Can't Execute ---\x1b[0m" << std::endl;
		Bureaucrat bureaucrat("Michel", 71);
		std::cout << bureaucrat << std::endl;
		RobotomyRequestForm form("Me");
		std::cout << form << std::endl;
		form.beSigned(bureaucrat);
		form.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
	}
}

void RNormal()
{
	try {
		std::cout << "\x1b[1;37m--- All Good ---\x1b[0m" << std::endl;
		Bureaucrat bureaucrat("Michel", 45);
		std::cout << bureaucrat << std::endl;
		RobotomyRequestForm form("Me");
		std::cout << form << std::endl;
		form.beSigned(bureaucrat);
		form.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
	}
}

void PNoSign()
{
	try {
		std::cout << "\x1b[1;37m--- Can't Sign ---\x1b[0m" << std::endl;
		Bureaucrat bureaucrat("Michel", 26);
		std::cout << bureaucrat << std::endl;
		PresidentialPardonForm form("Me");
		std::cout << form << std::endl;
		form.beSigned(bureaucrat);
		form.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
	}
}

void PNoSignExec()
{
	try {
		std::cout << "\x1b[1;37m--- Not Signed ---\x1b[0m" << std::endl;
		Bureaucrat bureaucrat("Michel", 5);
		std::cout << bureaucrat << std::endl;
		PresidentialPardonForm form("Me");
		std::cout << form << std::endl;
		form.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
	}
}

void PNoExec()
{
	try {
		std::cout << "\x1b[1;37m--- Can't Execute ---\x1b[0m" << std::endl;
		Bureaucrat bureaucrat("Michel", 24);
		std::cout << bureaucrat << std::endl;
		PresidentialPardonForm form("Me");
		std::cout << form << std::endl;
		form.beSigned(bureaucrat);
		form.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
	}
}

void PNormal()
{
	try {
		std::cout << "\x1b[1;37m--- All Good ---\x1b[0m" << std::endl;
		Bureaucrat bureaucrat("Michel", 5);
		std::cout << bureaucrat << std::endl;
		PresidentialPardonForm form("Me");
		std::cout << form << std::endl;
		form.beSigned(bureaucrat);
		form.execute(bureaucrat);
	}
	catch (std::exception& e) {
		std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
	}
}

int main()
{
	std::cout << "\x1b[1;37m----- Shrubbery Creation -----\x1b[0m" << std::endl;
	SNoSign();
	std::cout << std::endl;
	SNoExec();
	std::cout << std::endl;
	SNoSignExec();
	std::cout << std::endl;
	SNormal();
	std::cout << std::endl;
	std::cout << "\x1b[1;37m----- Robotomy Request -----\x1b[0m" << std::endl;
	RNoSign();
	std::cout << std::endl;
	RNoExec();
	std::cout << std::endl;
	RNoSignExec();
	std::cout << std::endl;
	RNormal();
	std::cout << std::endl;
	std::cout << "\x1b[1;37m----- Presidential Pardon -----\x1b[0m" << std::endl;
	PNoSign();
	std::cout << std::endl;
	PNoExec();
	std::cout << std::endl;
	PNoSignExec();
	std::cout << std::endl;
	PNormal();
}